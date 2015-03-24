<?php

class NapoMigrationEpisodes extends Migration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $source_file = MigrationUtil::getSourceFile($arguments);
    $youtube_source = $arguments['file_name_youtube'];
    // Films dependency.
//    $this->dependencies = array('Films');

    $this->source = new MigrateSourceList(
      new NapoEpisodesMigrateList($source_file, $youtube_source),
      new NapoEpisodeMigrateItem());

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
    $this->destination = new MigrateDestinationNode('napo_video', $node_options);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('title_field', 'title_field');
    $this->addFieldMapping('field_youtube', 'youtube');
//    $this->addFieldMapping('field_tags', 'subject');
//    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_image', 'image');
    $this->addFieldMapping('field_image:file_replace')->defaultValue(MigrateFileBase::FILE_EXISTS_REUSE);
    $this->addFieldMapping('field_image:language')->defaultValue('en');

    $this->addFieldMapping('field_video', 'video');
    $this->addFieldMapping('field_video:language')->defaultValue('und');
    $this->addFieldMapping('field_video:file_replace')->defaultValue(MigrateFileBase::FILE_EXISTS_REUSE);

    $this->addFieldMapping('field_napo_film', 'film_id')
      ->sourceMigration(array('Episodes'));

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

    // Get the imported films, to be used in Episodes Migration.
    if (db_table_exists('migrate_map_films')) {
      $this->migrateMapFilms = db_select('migrate_map_films', 'f')
        ->fields('f', array('sourceid1', 'destid1'))
        ->execute()->fetchAllKeyed(0);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    if (empty($row->title)) {
      return FALSE;
    }
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function prepare($entity, $row) {
    $migration = Migration::currentMigration();
    $languages = array_keys(osha_language_list());
    $entity_type = $migration->getDestination()->getEntityType();

    $translation_handler = entity_translation_get_handler($entity_type, $entity);
    $entity->translations = $translation_handler->getTranslations();

    if ($row->main_video) {
      // Set the term for film main video.
      $term = taxonomy_get_term_by_name('Film video');
      if (!empty($term)) {
        $term = current($term);
        $entity->field_video_type[LANGUAGE_NONE][0]['tid'] = $term->tid;
      }
    }
    else {
      $term = taxonomy_get_term_by_name('Episode video');
      if (!empty($term)) {
        $term = current($term);
        $entity->field_video_type[LANGUAGE_NONE][0]['tid'] = $term->tid;
      }
    }

    foreach ($languages as $language) {
      $has_translation = FALSE;
      if (!empty($row->title_field[$language])) {
        $entity->title_field[$language] = array();
        $entity->title_field[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->title_field[$language]);
        $has_translation = TRUE;
      }
      if (!empty($row->description[$language])) {
        $entity->body[$language] = array();
        $entity->body[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->description[$language]);
        $entity->body[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if ($has_translation) {
        MigrationUtil::setTranslation($translation_handler, $entity, $row, $language);
      }
    }
    // Store film ref and unset the ref because it gives form validation error
    // Set the ref on complete.
    $entity->temp_napo_film = $entity->field_napo_film;
    unset($entity->field_napo_film);
  }

  /**
   * {@inheritdoc}
   */
  public function complete($entity, $row) {
    // Set the ref to napo film.
    if (!empty($entity->temp_napo_film)) {
      $entity->field_napo_film = $entity->temp_napo_film;
      unset($entity->temp_napo_film);
      node_save($entity);
    }
    // Save the new alias for translated languages.
    $languages = array_keys($entity->translations->data);
    $args = array(
      'source' => 'node/' . $entity->nid,
      'language' => 'en',
    );
    $path_auto = path_load($args);
    if (!empty($path_auto)) {
      // Create alias for new path.
      foreach ($languages as $language) {
        $args = array(
          'source' => 'node/' . $entity->nid,
          'alias' => $path_auto['alias'],
          'language' => $language,
        );
        // Check if path already exists.
        $existing_path = path_load($args);
        if (empty($existing_path)) {
          path_save($args);
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function createStub(Migration $migration, array $source_id) {
    // Create stub for film node.
    $node = new stdClass();
    $node->title = t('Stub for @id', array('@id' => $source_id[0]));
    $node->body[LANGUAGE_NONE][0]['value'] = t('Stub body');
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    $node->status = 0;
    node_save($node);
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }
}

/**
 * Counts the number of source rows.
 *
 * @return int
 *   Number of rows to be migrated from source
 */
class NapoEpisodesMigrateList extends MigrateList {

  protected $fileURL;
  protected $fileYoutubeURL;
  protected $multilingualFields;
  public static $films;
  public static $episodes;
  public static $formats = array('avi', 'ogv', 'webm', 'wmv');
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
   * Sets the title and body from source object to target row.
   */
  public static function setTitleDescription(&$row, $obj, $lang) {
    $row['title'] = $obj->title_en;
    if (!empty($obj->{'title_' . $lang})) {
      $row['title_field'][$lang] = $obj->{'title_' . $lang};
      if (!empty($obj->{'description_' . $lang})) {
        $row['description'][$lang] = $obj->{'description_' . $lang};
      }
    }
  }

  /**
   * Sets the videos from source object to target row.
   */
  public function setVideos(&$row, $obj) {
    $row['video'] = array();
    foreach (self::$formats as $format) {
      if (!empty($obj->{'video_' . $format})) {
        $row['video'][] = urldecode($obj->{'video_' . $format});
      }
    }
  }

  /**
   * Parse the source file and populate the local cache.
   */
  protected function parseSourceFiles() {
    if (!is_readable($this->fileURL)) {
      return array();
    }
    self::$films = array();
    self::$episodes = array();

    $films = (array) json_decode(file_get_contents($this->fileURL));
    $langauges = osha_language_list();
    $lang_codes = array_keys($langauges);
    // Get youtube data. The main film videos have episode cell empty.
    // fallback on film id.
    $youtube_data = $this->getCSVFile($this->fileYoutubeURL, self::$csv_ep_id_pos, self::$csv_film_id_pos);
    foreach ($films as $film_id => $film) {
      $row = array();
      $row['language'] = 'en';
      foreach ($lang_codes as $lang) {
        $this->setTitleDescription($row, $film, $lang);
      }
      foreach ($film->episodes as $episode_id => $episode) {
        $episode_row = array();
        $episode_row['language'] = 'en';
        $episode_row['film_id'] = $film_id;
        foreach ($lang_codes as $lang) {
          $this->setTitleDescription($episode_row, $episode, $lang);
        }
        if (!empty($episode->image)) {
          $episode_row['image'] = $episode->image;
        }
        $this->setVideos($episode_row, $episode);
        // Set the youtube link.
        if (!empty($youtube_data[$episode_id])) {
          $episode_row['youtube'] = $youtube_data[$episode_id][self::$csv_youtube_pos];
        }
        self::$episodes[$episode_id] = $episode_row;
      }
      // Set videos for film.
      if (!empty($youtube_data[$film_id])) {
        $row['youtube'] = $youtube_data[$film_id][self::$csv_youtube_pos];
      }
      $this->setVideos($row, $film);
      $row['main_video'] = TRUE;
      self::$episodes[$film_id] = $row;
    }
    return TRUE;
  }

  /**
   * Get an array from a csv,indexed by $index_key or $index_key_fallback.
   */
  public static function getCSVFile($file, $index_key, $index_key_fallback) {
    if (!file_exists($file)) {
      Migration::displayMessage(
        t(
          'Failed to load data file from !fileUrl:',
          array('!fileUrl' => $file)
        )
      );
    }
    $file = fopen($file, 'r');
    $csv = array();
    $head = fgetcsv($file);
    while (($line = fgetcsv($file)) !== FALSE) {
      $key = $line[$index_key];
      if (empty($line[$index_key])) {
        $key = $line[$index_key_fallback];
      }
      $csv[$key] = $line;
    }
    fclose($file);
    return $csv;
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
class NapoEpisodeMigrateItem extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (!empty(NapoEpisodesMigrateList::$episodes[$item_id])) {
      return (object) NapoEpisodesMigrateList::$episodes[$item_id];
    }
    return NULL;
  }
}


