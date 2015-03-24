<?php

/**
 * Class NapoMigrationGallery migrates page
 */
class NapoMigrationGallery extends Migration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $source_file = MigrationUtil::getSourceFile($arguments);
    $white_list_url = $arguments['file_name_whitelist'];
    $data_export_path = napo_migration_get_data_dir();

    $this->source = new MigrateSourceList(
      new NapoGalleryMigrateList($source_file, $white_list_url),
      new NapoGalleryMigrateItem(),
      array(
        'id' => 'Unique entity path, language independent',
        'path' => 'URL pattern without language',
        'creation_date' => 'Node creation date',
        'modification_date' => 'Last modification date',
        'publication_date' => 'Node publication date',
        'title' => 'Node title',
        'text' => 'Node body',
      )
    );

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
    $this->destination = new MigrateDestinationNode('napo_image', $node_options);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'text');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('field_image', 'image');
    $this->addFieldMapping('field_image:source_dir')->defaultValue($data_export_path . DIRECTORY_SEPARATOR);
    $this->addFieldMapping('field_image:file_replace')->defaultValue(MigrateFileBase::FILE_EXISTS_REUSE);
    $this->addFieldMapping('field_image:language')->defaultValue('en');
    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');
    $this->addFieldMapping('uid')->defaultValue(1);

    // TODO check in migrate ui for unmigrated destination/ source messages.
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
      'field_image:destination_file',
      'field_cover_image',
      'field_nace_codes:create_term',
      'field_nace_codes:ignore_case',
      'field_tags:create_term',
      'field_tags:ignore_case',
      'field_thesaurus:create_term',
      'field_thesaurus:ignore_case',
      'field_author:language',
      'comment',
    ));

    $this->addUnmigratedSources(array(
      'path',
      'relatedItems',
      'multilingual_thesaurus',
      'nace',
      'expiration_date',
      'creator',
      'archived',
      'is_default_page',
    ));
  }

  /**
   * Prepares the source row before migration.
   *
   * @param object $row
   *   One source $row as returned by getItem
   *
   * @return bool
   *   TRUE if row is valid
   */
  public function prepareRow($row) {
    if (MigrationUtil::entityRowValidator($row, $this) === FALSE) {
      return FALSE;
    }
    $row->language = 'en';
    // Format date according to UTC timezone.
    $row->expiration_date = MigrationUtil::getUTCTimestamp($row->expiration_date);
    $row->modification_date = strtotime($row->modification_date);
    return TRUE;
  }

  /**
   * Called by destination right before saving.
   *
   * @param object $entity
   *   Entity to save
   * @param object $row
   *   Source row
   */
  public function prepare($entity, $row) {
    $entity->path['pathauto'] = 1;
    $migration = Migration::currentMigration();
    $languages = array_keys(language_list());
    $entity_type = $migration->getDestination()->getEntityType();

    $translation_handler = entity_translation_get_handler($entity_type, $entity);
    $entity->translations = $translation_handler->getTranslations();

    foreach ($languages as $language) {
      $has_translation = FALSE;
      if (!empty($row->title_field[$language])) {
        $entity->title_field[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->title_field[$language]);
        $has_translation = TRUE;
      }
      $entity->body[$language] = array();
      if (!empty($row->description[$language])) {
        $entity->body[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->description[$language]);
        $entity->body[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if ($has_translation) {
        MigrationUtil::setTranslation($translation_handler, $entity, $row, $language);
      }
    }
  }

  /**
   * Sets the node aliases after the migration, nid is available.
   *
   * @param object $entity
   *   Entity to be saved
   * @param object $row
   *   Source row
   */
  public function complete($entity, $row) {
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
    foreach ($row->path as $path) {
      if ($path_auto['alias'] != $path) {
        MigrationUtil::createRedirects($entity, $path);
      }
    }
    if ($path_auto['alias'] != $row->id) {
      MigrationUtil::createRedirects($entity, $row->id);
    }
    // Create redirects from aliases.
    MigrationUtil::createRedirectsFromAliases($entity, $row);
  }
}

/**
 * Class NapoGalleryMigrateList
 */
class NapoGalleryMigrateList extends MigrateList {

  private $fileURL;
  public static $data;
  public static $white_list;
  private $whiteListURL;

  /**
   * {@inheritdoc}
   *
   * @param string $file_url
   *   The location of the file with source raw data
   */
  public function __construct($file_url, $white_list_url) {
    parent::__construct();
    $this->fileURL = $file_url;
    $this->whiteListURL = $white_list_url;
    if (!file_exists($this->fileURL)) {
      Migration::displayMessage(
        t(
          'Failed to load data file from !fileUrl:',
          array('!fileUrl' => $this->fileURL)
        )
      );
    }
    $this->parseSourceFile();
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return $this->fileURL;
  }

  public function isGalleryPath($path) {
    if (strpos($path, 'napos-gallery') === 0) {
      return TRUE;
    }
    return FALSE;
  }
  /**
   * Parse the source file and populate the local cache.
   */
  protected function parseSourceFile() {
    if (!is_readable($this->fileURL)) {
      return array();
    }
    if (!is_readable($this->fileURL)) {
      return array();
    }
    $handle = fopen($this->fileURL, 'r');
    $fields = $raw_data = fgetcsv($handle, NULL, ';');
    $final = array();
    while (($raw_data = fgetcsv($handle, NULL, ';')) !== FALSE) {
      $path = MigrationUtil::getIDFromSourceRow($raw_data);
      $language = !empty($raw_data[1]) ? $raw_data[1] : 'en';

      if (!$this->isGalleryPath($path)) {
        continue;
      }
      self::$data[$path]['id'] = $path;
      foreach ($fields as $key => $field) {
        switch ($field) {
          case 'title':
            if ($language == 'en') {
              self::$data[$path]['title'] = MigrationUtil::decodeHTMLText($raw_data[$key]);
            }
            self::$data[$path]['title_field'][$language] = $raw_data[$key];
            break;

          case 'path':
            $path_language = explode('/', $raw_data[$key], 3);
            self::$data[$path][$field][$language] = $path_language[2];
            break;

          case 'description':
          case 'aliases':
            self::$data[$path][$field][$language] = $raw_data[$key];
            break;

          default:
            if ($language == 'en') {
              self::$data[$path][$field] = $raw_data[$key];
            }
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getIdList() {
    if (self::$data) {
      return array_keys(self::$data);
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
    return count(self::$data);
  }
}

/**
 * Class NapoGalleryMigrateItem
 */
class NapoGalleryMigrateItem extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (!empty(NapoGalleryMigrateList::$data[$item_id])) {
      return (object) NapoGalleryMigrateList::$data[$item_id];
    }
    return NULL;
  }
}
