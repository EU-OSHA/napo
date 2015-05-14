<?php

class NapoTagsTermMigration extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->description = t('Import tags terms from NAPO export.');

    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'name' => array(
          'type' => 'varchar',
          'length' => 100,
          'not null' => TRUE,
          'description' => 'Term name',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($arguments['file_name'], array(), array('header_rows' => 1, 'delimiter' => '|'));
    $language = 'en';
    $text_format = 'full_html';
    $term_options = MigrateDestinationTerm::options($language, $text_format);
    $this->destination = new MigrateDestinationTerm('tags', $term_options);

    $this->addSimpleMappings(array('name'));
  }
}
