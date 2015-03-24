<?php

define('NAPO_MIGRATE_FILES_DEST_DIR', 'public://migrated-files');
/**
 * Class MigrateOshaPublicationFiles
 */
class NapoMigrateFiles extends Migration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    // Set bundle document.
    $this->destination = new MigrateDestinationFile('document', 'MigrateFileUri');

    $source_file = MigrationUtil::getSourceFile($arguments);
    $white_list_url = $arguments['file_name_whitelist'];

    $this->source = new MigrateSourceList(new NapoMigrateFilesListCSV($source_file, $white_list_url),
      new NapoMigrateFilesItemCSV(napo_migration_get_data_dir()), $this->destination->fields());

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'File old path',
        ),
      ),
      MigrateDestinationFile::getKeySchema()
    );

    $this->addFieldMapping('source_dir')->defaultValue(napo_migration_get_data_dir());
//    $this->addFieldMapping('destination_file', 'file');
    $this->addFieldMapping('value', 'file');
    $this->addFieldMapping('destination_dir')->defaultValue('public://migrated-files');
    $this->addFieldMapping('preserve_files')->defaultValue(FALSE);
    $this->addFieldMapping('file_replace')->defaultValue(MigrateFileBase::FILE_EXISTS_REUSE);
    $this->addFieldMapping('timestamp', 'timestamp');
    $this->addFieldMapping('filename', 'title');
    $this->addFieldMapping('field_file_description', 'description');

    $this->addUnmigratedDestinations(
      array(
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
    $row->file_uri = $row->file;
    $row->timestamp = time();

    if (!is_file(napo_migration_get_data_dir() . $row->file)) {
      $this->saveMessage("File could not be found, ignoring {$row->file}", MigrationBase::MESSAGE_WARNING);
      return FALSE;
    }
    return TRUE;
  }

  public function prepare($entity, $row) {
    $entity->path['pathauto'] = 0;
    $file_language = (!empty($row->language)) ? $row->language : 'en';
    $entity->field_language[LANGUAGE_NONE][0]['value'] = $file_language;
    if (!empty($row->title)) {
      $entity->filename = $row->title;
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
    file_usage_add($entity, 'napo_migration_file', 'file_entity', $entity->fid);
  }

  protected function postRollback() {
    parent::postRollback();
    db_delete('file_usage')->condition('module', 'napo_migration_file');
  }
}

class NapoMigrateFilesListCSV extends MigrateList {

  protected $fileUrl = '';
  private $whiteListURL;
  protected $multilingualFields;
  public static $csvData;
  public static $whiteList;


  /**
   * Populates csvData with parsed information from $file_url.
   *
   * @param string $file_url
   *   The location of the file with source raw data
   */
  public function __construct($file_url, $white_list_url) {
    parent::__construct();
    $this->fileUrl = $file_url;
    $this->whiteListURL = $white_list_url;

    self::$whiteList = json_decode(file_get_contents($this->whiteListURL));
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

  public function isWhitelist($id) {
    $white_list = array_keys(array_flip(self::$whiteList));
    foreach ($white_list as $pattern) {
      if (strpos($id, $pattern) !== FALSE) {
        return TRUE;
      }
    }
    return FALSE;
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
    if (!is_readable($this->fileUrl)) {
      return array();
    }
    $handle = fopen($file, 'r');
    $fields = $data = fgetcsv($handle, 1000, ';');
    $final = array();
    while (($data = fgetcsv($handle, 100000, ';')) !== FALSE) {
      $row_id = $data[0];
      if (!$this->isWhitelist($row_id)) {
        continue;
      }
      foreach ($fields as $key => $field) {
        $final[$row_id][$field] = $data[$key];
      }
      $final[$row_id]['id'] = $row_id;
    }

    foreach (array_keys($final) as $row_id) {
      if ($final[$row_id]['workflow_state'] !== 'published' ||
        strlen($final[$row_id]['file']) > 224 ||
        empty($final[$row_id]['file'])
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

class NapoMigrateFilesItemCSV extends MigrateItemFile {

  protected $data;

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (empty($this->data)) {
      $csv_data = NapoMigrateFilesListCSV::$csvData;
      foreach ($csv_data as $csv_id => $item) {
        $this->data[$csv_id] = (object) $item;
      }
    }
    return isset($this->data[$item_id]) ? $this->data[$item_id] : NULL;
  }
}
