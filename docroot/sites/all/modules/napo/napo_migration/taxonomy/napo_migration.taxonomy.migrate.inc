<?php

class NapoMultilingualDrupalTerm7Migration extends DrupalTerm7Migration {
  public $extraFields = array();
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Get the fields for taxonomy.
    $bundle = $this->arguments['destination_vocabulary'];
    $fields = field_info_instances('taxonomy_term', $bundle);
    $this->extraFields = array_keys($fields);

    $this->addSimpleMappings($this->extraFields);

    // Add unmigrated fields.
    $unmigrated = array();
    foreach ($this->extraFields as $field_name) {
      $unmigrated[] = $field_name . ':language';
    }
    $unmigrated = array_merge(array(
      'description_field:format',
      'description_field:summary',
    ), $unmigrated);
    $this->addUnmigratedDestinations($unmigrated);
    $this->addUnmigratedSources($unmigrated);
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   */
  public function prepare($entity, $row, $extra_fields = array()) {
    $name_field_lang_key = 'name_field:language';
    $languages = $row->{$name_field_lang_key};
    $entity->language = 'en';
    $migration = Migration::currentMigration();
    $entity_type = $migration->getDestination()->getEntityType();
    $translation_handler = entity_translation_get_handler($entity_type, $entity);
    $entity->translations = $translation_handler->getTranslations();
    $translation_handler->initTranslations();
    // Clear the field and reconstruct it with translations values.
    $entity->name_field = array();
    foreach ($languages as $idx => $language) {
      if (!empty($row->name_field[$idx])) {
        $entity->name_field[$language][0]['value'] = $row->name_field[$idx];
        /* Don't translate en (default) */
        if ($language != 'en' && !isset($entity->translations->data[$language])) {
          $translation_handler->setTranslation(array(
            'translate' => 0,
            'status' => 1,
            'uid' => 1,
            'language' => $language,
            'source' => 'en',
          ));
        }
      }
    }
    $this->mapMultilingualFields($entity, $row);
  }

  public function mapMultilingualFields($entity, $row) {
    foreach ($this->extraFields as $field_name) {
      $field_base = field_info_field($field_name);
      if ($field_base['translatable'] && !empty($row->{$field_name})) {
        $entity->{$field_name} = array();
        $field_lang_key = $field_name . ':language';
        $languages = $row->{$field_lang_key};
        foreach ($languages as $idx => $language) {
          if (!empty($row->{$field_name}[$idx])) {
            $entity->{$field_name}[$language][0]['value'] = $row->{$field_name}[$idx];
          }
        }
      }
    }
  }

  public function complete($entity, $row) {
    $name_field_lang_key = 'name_field:language';
    $languages = $row->{$name_field_lang_key};
    $this->createAliases($entity, $languages);
  }

  /**
   * Create aliases for all languages of the term.
   */
  public static function createAliases($entity, $languages) {
    if (!empty($entity->path['alias'])) {
      foreach ($languages as $language) {
        $args = array(
          'source' => 'taxonomy/term/' . $entity->tid,
          'alias' => $entity->path['alias'],
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
}
