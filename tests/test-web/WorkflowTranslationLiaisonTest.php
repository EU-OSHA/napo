<?php

class WorkflowTranslationLiaisonTest extends OshaWebTestCase {

  public $nodeTitle1 = 'PHPUnit - Translation Liaison - News #1';
  public $job;

  /**
   * Test access to the Translation Pages for Liaison.
   * Test Translation XML Download.
   */
  public function testTranslationPagesAccess() {
    $this->loginAs('tliaison1');

    $this->drupalGet('admin');
    $this->assertText('My Workbench');
    $this->assertText('Translation');

    $this->drupalGet('admin/tmgmt');
    $this->assertRaw('views-field-label');

    $this->drupalGet('admin/workbench');
    $this->assertRaw('MY CONTENT');

    $this->drupalGet('admin/workbench/needs-translation-job');
    $this->assertRaw('views-field-label');

    $job = osha_tmgmt_job_load_latest();
    $this->drupalGet('admin/tmgmt/jobs/' . $job->tjid);
    $this->assertRaw('views-field-label');

    $path = "sites/default/files/tmgmt_file/translation_job_id_" .
      $job->tjid . "_request.xml";
    $this->assertRaw($path);

    // Test File Download
    global $base_url;
    $this->drupalGet($base_url . '/' . $path);
    $this->assertRaw('<TransactionIdentifier>' . $job->tjid . '</TransactionIdentifier>');
  }
}
