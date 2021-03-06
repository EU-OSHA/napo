<?php

/**
 * Class NapoMigrationPages migrates page
 */
class NapoMigrationPages extends Migration {

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

    $this->source = new MigrateSourceList(
      new NapoPagesMigrateList($source_file, $white_list_url),
      new NapoPagesMigrateItem(),
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
    $this->destination = new MigrateDestinationNode('article', $node_options);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'text');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('field_publication_date', 'publication_date');
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
    $row->publication_date = MigrationUtil::getUTCTimestamp($row->publication_date);
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
    $entity->path['pathauto'] = 0;
    if (isset($entity->field_publication_date) && empty($entity->field_publication_date[LANGUAGE_NONE][0]['value'])) {
      unset($entity->field_publication_date[LANGUAGE_NONE]);
    }
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
      if (!empty($row->text[$language])) {
        $entity->body[$language] = array();
        $text = MigrationUtil::decodeHTMLText($row->text[$language]);
        $text = str_replace("\n", '', $text);
        $tidy = new tidy();
        $tidy_conf = array(
          'clean' => TRUE,
          'drop-empty-paras' => TRUE,
        );
        $text = $tidy->repairString($text, $tidy_conf, 'utf8');
        // Remove first h1 tag because it's the same with title.
        $text = $this->removeTags($text, 'h1', 0);
        switch ($row->id) {
          case 'who-is-napo/who-is-napo':
            // Remove napo image from text.
            $text = $this->removeNapoImage($text);
            break;

          case 'napos-films/napos-films':
            // Only the first 3 paragraphs are the page content.
            $text = $this->getFirstParagraphs($text, 3);
            break;

          case 'rights-and-permissions/rights-and-permissions':
            // Remove first h3 - the same with title.
            $text = $this->removeTags($text, 'h3', 0);
            break;

          case 'napo-for-teachers/resources/resource-library':
            // Remove first h3 - the same with title.
            $text = $this->removeTags($text, 'h2', 0);
            break;
        }
        // Clean again after parsing.
        $text = $tidy->repairString($text, $tidy_conf, 'utf8');
        $text = str_replace("\n", ' ', $text);
        $entity->body[$language][0]['value'] = $text;
        $entity->body[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if ($has_translation) {
        MigrationUtil::setTranslation($translation_handler, $entity, $row, $language);
      }
    }
  }

  /**
   * Removes the div containing the napo image.
   */
  public function removeNapoImage($text) {
    // Remove the link to old fop pages.
    $doc = new DOMDocument();
    $body_html = mb_convert_encoding($text, 'HTML-ENTITIES', "UTF-8");
    $doc->loadHTML($body_html);
    $divs = $doc->getElementsByTagName('div');
    $text_changed = FALSE;
    if ($divs->length > 0) {
      foreach ($divs as $key => $elem) {
        $div = $doc->getElementsByTagName('div')->item($key);
        foreach ($div->attributes as $attr) {
          if ($attr->name == 'id' && $attr->value == 'napomain') {
            $div->parentNode->removeChild($div);
            $text_changed = TRUE;
          }
        }
      }
    }
    if ($text_changed) {
      $text = $doc->saveHTML();
    }
    return $text;
  }

  /**
   * Removes from text the $tags_name from position $index.
   */
  public function removeTags($text, $tag_name, $index) {
    $doc = new DOMDocument();
    $body_html = mb_convert_encoding($text, 'HTML-ENTITIES', "UTF-8");
    $doc->loadHTML($body_html);
    $tags = $doc->getElementsByTagName($tag_name);
    $text_changed = FALSE;
    if ($tags->length > 0) {
      $tag = $doc->getElementsByTagName($tag_name)->item($index);
      $tag->parentNode->removeChild($tag);
      $text_changed = TRUE;
    }
    if ($text_changed) {
      $text = $doc->saveHTML();
    }
    return $text;
  }

  /**
   * Returns the first $no paragraphs from text.
   */
  public function getFirstParagraphs($text, $no = 1) {
    $doc = new DOMDocument();
    $body_html = mb_convert_encoding($text, 'HTML-ENTITIES', "UTF-8");
    $doc->loadHTML($body_html);
    if ($doc->getElementsByTagName('p')->length > $no) {
      $text = '';
      for ($i = 0; $i < $no; $i++) {
        $text .= '<p>' . $doc->getElementsByTagName('p')->item($i)->nodeValue . '</p>';
      }
    }
    return $text;
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
    if (isset($row->language) && !in_array($row->language, $languages)) {
      $languages[] = $row->language;
    }
    // Create alias from new path.
    foreach ($languages as $language) {
      $args = array(
        'source' => 'node/' . $entity->nid,
        'alias' => $row->new_path,
        'language' => $language,
      );
      // Check if path already exists.
      $existing_path = path_load($args);
      if (empty($existing_path)) {
        path_save($args);
      }
    }
    // For default pages, redirect the path without the last part.
    if ($row->is_default_page) {
      $parts = explode('/', $row->id);
      array_pop($parts);
      $section_redirect = implode('/', $parts);
      if ($row->new_path != $section_redirect) {
        MigrationUtil::createRedirects($entity, $section_redirect);
      }
    }
    // Create redirect from old path.
    if ($row->new_path != $row->id) {
      MigrationUtil::createRedirects($entity, $row->id);
    }
    // Create redirects from aliases.
    MigrationUtil::createRedirectsFromAliases($entity, $row);
  }
}

/**
 * Class PublicationMigrateList
 */
class NapoPagesMigrateList extends MigrateList {

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
    if (!file_exists($this->whiteListURL)) {
      Migration::displayMessage(
        t(
          'Failed to load data file from !fileUrl:',
          array('!fileUrl' => $this->whiteListURL)
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

  /**
   * Parse the source file and populate the local cache.
   */
  protected function parseSourceFile() {
    if (!is_readable($this->fileURL)) {
      return array();
    }

    $handle = fopen($this->fileURL, 'r');
    $fields = $raw_data = fgetcsv($handle, NULL, ';');
    $work_flow_key = array_search('workflow_state', $fields);
    $white_list = (array) json_decode(file_get_contents($this->whiteListURL));
    self::$white_list = $white_list;

    self::$data = array();
    while (($raw_data = fgetcsv($handle, NULL, ';')) !== FALSE) {
      $path = MigrationUtil::getIDFromSourceRow($raw_data);
      $language = !empty($raw_data[1]) ? $raw_data[1] : 'en';

      if (!in_array($path, array_keys($white_list))) {
        continue;
      }
      self::$data[$path]['id'] = $white_list[$path]->path;
      // Set the new path.
      self::$data[$path]['new_path'] = $white_list[$path]->path;
      // Skip the private translations.
      if (!in_array($raw_data[$work_flow_key],
        array('published', 'checked', 'to_amend'))) {
        continue;
      }
      foreach ($fields as $key => $field) {
        switch ($field) {
          case 'title':
            if ($language == 'en') {
              self::$data[$path]['title'] = MigrationUtil::decodeHTMLText($raw_data[$key]);
            }
            self::$data[$path]['title_field'][$language] = $raw_data[$key];
            break;

          case 'text':
          case 'aliases':
            self::$data[$path][$field][$language] = $raw_data[$key];
            break;

          case 'path':
            $path_language = explode('/', $raw_data[$key], 3);
            self::$data[$path][$field][$language] = $path_language[2];
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
 * Class NapoPagesMigrateItem
 */
class NapoPagesMigrateItem extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (!empty(NapoPagesMigrateList::$data[$item_id])) {
      return (object) NapoPagesMigrateList::$data[$item_id];
    }
    return NULL;
  }
}
