<?php

class NapoMigrationLessonVideos extends NapoMigrationEpisodes {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    Migration::__construct($arguments);

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $source_file = MigrationUtil::getSourceFile($arguments);
    $youtube_source = $arguments['file_name_youtube'];

    $this->source = new MigrateSourceList(
      new NapoLessonsVideoMigrateList($source_file, $youtube_source),
      new NapoLessonVideosMigrateItem());

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 200,
          'not null' => TRUE,
          'description' => 'Item code',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
    $node_options = MigrateDestinationNode::options('en', 'full_html');
    $this->destination = new MigrateDestinationNode('lesson_video', $node_options);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('title_field', 'title_field');
    $this->addFieldMapping('field_youtube', 'youtube');

    $this->addFieldMapping('field_video', 'video');
    $this->addFieldMapping('field_video:language')->defaultValue('und');
    $this->addFieldMapping('field_video:file_replace')->defaultValue(MigrateFileBase::FILE_EXISTS_REUSE);

    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');
    $this->addFieldMapping('uid')->defaultValue(1);

    $this->addUnmigratedDestinations(array(
      'promote',
      'status',
      'sticky',
      'revision',
      'log',
      'language',
      'tnid',
      'translate',
      'revision_uid',
      'is_new',
      'body:summary',
      'field_cover_image',
      'field_tags:create_term',
      'field_tags:ignore_case',
      'field_author:language',
      'comment',
    ));

    $this->addUnmigratedSources(array(
      'path',
    ));
  }

  /**
   * {@inheritdoc}
   */
  public function prepare($entity, $row) {
    parent::prepare($entity, $row);
  }
}

/**
 * Counts the number of source rows.
 *
 * @return int
 *   Number of rows to be migrated from source
 */
class NapoLessonsVideoMigrateList extends MigrateList {

  protected $fileURL;
  protected $fileYoutubeURL;
  public static $episodes;
  public static $csv_film_id_pos = 0;
  public static $csv_ep_id_pos = 5;
  public static $csv_youtube_pos = 12;

  /**
   * {@inheritdoc}
   *
   * @param string $file_url
   *   The location of the file with source raw data
   */
  public function __construct($file_url, $file_url_youtube) {
    parent::__construct();
    $this->fileURL = $file_url;
    $this->fileYoutubeURL = $file_url_youtube;
    if (!file_exists($this->fileURL)) {
      Migration::displayMessage(
        t(
          'Failed to load data file from !fileUrl:',
          array('!fileUrl' => $this->fileURL)
        )
      );
    }
    if (!file_exists($this->fileYoutubeURL)) {
      Migration::displayMessage(
        t(
          'Failed to load data file from !fileUrl:',
          array('!fileUrl' => $this->fileYoutubeURL)
        )
      );
    }
    $this->parseSourceFiles();
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return $this->fileURL;
  }
  /**
   * Parse the source file and populate the local cache.
   */
  protected function parseSourceFiles() {
    if (!is_readable($this->fileURL)) {
      return array();
    }
    self::$episodes = array();

    $films = (array) json_decode(file_get_contents($this->fileURL));
    $langauges = osha_language_list();
    $lang_codes = array_keys($langauges);
    // Get youtube data. The main film videos have episode cell empty.
    // fallback on film id.
    $youtube_data = NapoEpisodesMigrateList::getCSVFile($this->fileYoutubeURL, self::$csv_ep_id_pos, self::$csv_film_id_pos);
    foreach ($films as $film_id => $film) {
      $row = array();
      $row['language'] = 'en';
      foreach ($lang_codes as $lang) {
        NapoEpisodesMigrateList::setTitleDescription($row, $film, $lang);
      }
      // Set videos for film.
      if (!empty($youtube_data[$film_id])) {
        $row['youtube'] = $youtube_data[$film_id][self::$csv_youtube_pos];
      }
      $row['video'][] = urldecode($film->url);
      self::$episodes[$film_id] = $row;
    }
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function getIdList() {
    if (self::$episodes) {
      return array_keys(self::$episodes);
    }
    return array();
  }

  /**
   * Counts the number of source rows.
   *
   * @return int
   *   Number of rows to be migrated from source
   */
  public function computeCount() {
    return count(self::$episodes);
  }
}


/**
 * Class NapoEpisodeMigrateItem
 */
class NapoLessonVideosMigrateItem extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (!empty(NapoLessonsVideoMigrateList::$episodes[$item_id])) {
      return (object) NapoLessonsVideoMigrateList::$episodes[$item_id];
    }
    return NULL;
  }
}
