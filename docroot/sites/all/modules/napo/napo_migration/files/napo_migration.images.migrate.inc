<?php

/**
 * Class NapoMigrateImages
 */
class NapoMigrateImages extends Migration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    // Set bundle document.
    $this->destination = new MigrateDestinationFile('image', 'MigrateFileUri');

    $source_file = MigrationUtil::getSourceFile($arguments);

    $this->source = new MigrateSourceList(new NapoMigrateImagesListCSV($source_file),
      new NapoMigrateImagesItemCSV(napo_migration_get_data_dir()),
      array(
        'id' => 'Primary Key (URL pattern)',
        'path' => 'URL pattern without language',
        'language' => 'Row language',
        'workflow_state' => '',
        'creation_date' => '',
        'modification_date' => '',
        'publication_date' => '',
        'creator' => 'Author user id from the old website',
        'aliases' => 'Image redirects',
        'title' => '',
        'description' => '',
        'subject' => 'Categories/Tags',
        'country' => '',
        'subcategory' => 'Merged into categories',
        'multilingual_thesaurus' => '',
        'nace' => 'Nace codes taxonomy',
        'image' => 'Image path',
        'image_uri' => 'Image URI',
        'timestamp' => 'Timestamp',
      )
    );

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 200,
          'not null' => TRUE,
          'description' => 'Image old path',
        ),
      ),
      MigrateDestinationFile::getKeySchema()
    );

    $this->addFieldMapping('source_dir')->defaultValue(napo_migration_get_data_dir());
    $this->addFieldMapping('value', 'image_uri');
    $this->addFieldMapping('destination_file', 'image_uri');
    $this->addFieldMapping('destination_dir')->defaultValue('public://migrated-images');
    $this->addFieldMapping('preserve_files')->defaultValue(FALSE);
    $this->addFieldMapping('file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('timestamp', 'timestamp');
    $this->addFieldMapping('filename', 'title');
    $this->addFieldMapping('field_file_description', 'description');

    $this->addUnmigratedSources(
      array(
        'country',
        'creator',
        'multilingual_thesaurus',
        'nace',
      )
    );

    $this->addUnmigratedDestinations(
      array(
        'uid',
        'field_file_image_alt_text',
        'field_file_image_alt_text:language',
        'field_file_image_title_text',
        'field_file_image_title_text:language',
        'field_nace_codes:create_term',
        'field_nace_codes:ignore_case',
        'field_tags:create_term',
        'field_tags:ignore_case',
        'field_thesaurus:create_term',
        'field_thesaurus:ignore_case',
      )
    );
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
    $row->image_uri = $row->image;
    $row->timestamp = time();

    if (!is_file(napo_migration_get_data_dir() . $row->image)) {
      $this->saveMessage("Image could not be found, ignoring {$row->image}", MigrationBase::MESSAGE_WARNING);
      return FALSE;
    }
    return TRUE;
  }

  public function prepare($entity, $row) {
    $file_language = (!empty($row->language)) ? $row->language : 'en';
    $entity->field_language[LANGUAGE_NONE][0]['value'] = $file_language;
    if (!empty($row->title)) {
      $entity->filename = $row->title;
    }
    if (strpos($row->id, 'napos-gallery') !== FALSE) {
      $entity->field_is_gallery[LANGUAGE_NONE][0]['value'] = 1;
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
    $language = $entity->field_language[LANGUAGE_NONE][0]['value'];
    $path = $row->path;
    if (preg_match('/^\/[A-Za-z]{2}\/.*/', $path)) {
      // Assume path starts with /LL/, so remove language.
      $path = substr($path, 4);
    }
    else {
      // Remove only first /
      $path = substr($path, 1);
    }
    // Existing Path.
    $conditions = array(
      'source' => 'file/' . $entity->fid,
      'language' => LANGUAGE_NONE,
    );
    $existing_path = path_load($conditions);
    // New Path.
    $args = array(
      'source' => 'file/' . $entity->fid,
      'alias' => $path,
      'language' => LANGUAGE_NONE,
    );
    if (empty($existing_path)) {
      // Save the path.
      path_save($args);
    }
    elseif (!empty($existing_path) && $existing_path['alias'] != $path) {
      // If path is changed, move existing to redirect and save the new one.
      path_delete($conditions);
      while (path_load($conditions)) {
        path_delete($conditions);
      }
      $source_redirects = redirect_load_by_source($existing_path['alias'], $language);
      if ($source_redirects == FALSE) {
        $redirect = new stdClass();
        $redirect->source = $existing_path['alias'];
        $redirect->source_options = array();
        $redirect->redirect = 'file/' . $entity->fid;
        $redirect->redirect_options = array();
        $redirect->status_code = 0;
        $redirect->type = 'redirect';
        $redirect->language = LANGUAGE_NONE;
      }
      // Removes redirect if new alias is redirect.
      $new_path_is_redirect = redirect_load_by_source($path, $language);
      if (empty($new_path_is_redirect)) {
        $new_path_is_redirect = redirect_load_by_source($path, LANGUAGE_NONE);
      }
      if (!empty($new_path_is_redirect)) {
        redirect_delete($new_path_is_redirect->rid);
      }
      // Save the new path.
      path_save($args);
    }
    elseif ($existing_path['language'] != LANGUAGE_NONE) {
      // Change the path to und.
      $existing_path['language'] = LANGUAGE_NONE;
      path_save($existing_path);
    }

    // Create redirects from aliases.
    if (!empty($row->aliases)) {
      $aliases = explode(',', $row->aliases);
      foreach ($aliases as $alias) {
        $source = trim($alias);
        if (strpos($source, '/') === 0) {
          $source = substr($source, 1);
        }
        MigrationUtil::createRedirects($entity, trim($source));
      }
    }

    // Add usage to prevent file removal.
    file_usage_add($entity, 'napo_migration_image', 'file_entity', $entity->fid);
  }
}

class NapoMigrateImagesListCSV extends MigrateList {

  protected $fileUrl = '';
  protected $multilingualFields;
  public static $csvData;

  /**
   * Populates csvData with parsed information from $file_url.
   *
   * @param string $file_url
   *   The location of the file with source raw data
   */
  public function __construct($file_url) {
    parent::__construct();
    $this->fileUrl = $file_url;

    self::$csvData = $this->parseMultilingualCSV($this->fileUrl);
  }

  /**
   * Returns the file url.
   *
   * @return string
   *   The file url
   */
  public function __toString() {
    return $this->fileUrl;
  }

  /**
   * Parses the csv $file and molds the data, to best suit our needs.
   *
   * The data is cached
   *
   * @param string $file
   *   The csv file url
   *
   * @return array
   *   Returns assoc array of assoc arrays which represents one source row
   *   array[id][field] -- row
   */
  protected function parseMultilingualCSV($file) {
    if (!is_readable($file)) {
      return array();
    }
    $handle = fopen($file, 'r');
    $fields = $data = fgetcsv($handle, NULL, ';');
    $final = array();
    while (($data = fgetcsv($handle, NULL, ';')) !== FALSE) {
      $row_id = $data[0];
      foreach ($fields as $key => $field) {
        $final[$row_id][$field] = $data[$key];
      }
      $final[$row_id]['id'] = $row_id;
    }

    foreach (array_keys($final) as $row_id) {
      if ($final[$row_id]['workflow_state'] !== 'published' ||
        strlen($final[$row_id]['image']) > 224 ||
        empty($final[$row_id]['image'])
      ) {
        unset($final[$row_id]);
      }
    }
    return $final;
  }

  /**
   * {@inheritdoc}
   */
  public function getIdList() {
    if (self::$csvData) {
      return array_keys(self::$csvData);
    }
    Migration::displayMessage(
      t('Loading of !fileUrl failed:',
        array('!listurl' => $this->fileUrl))
    );
    return NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function computeCount() {
    return count(self::$csvData);
  }
}

class NapoMigrateImagesItemCSV extends MigrateItemFile {

  protected $data;

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (empty($this->data)) {
      $csv_data = NapoMigrateImagesListCSV::$csvData;
      foreach ($csv_data as $csv_id => $item) {
        $this->data[$csv_id] = (object) $item;
      }
    }
    return isset($this->data[$item_id]) ? $this->data[$item_id] : NULL;
  }
}
