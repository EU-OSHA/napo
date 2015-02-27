<?php

class WorkflowTranslationTest extends OshaWebTestCase {

  public $nodeTitle1 = 'PHPUnit - Translation - News #1';
  public $job;

  /**
   * {@inheritdoc}
   */
  public function cleanup() {
    $nodes = node_load_multiple(array(), array('title' => $this->nodeTitle1), TRUE);
    node_delete_multiple(array_keys($nodes));
//    variable_set('drupal_test_email_collector', '');
  }

  /**
   * Test the content selection screen contains the correct fields & columns.
   */
  public function testNodeContentSelection() {
    $this->loginAsAdmin();

    $this->drupalGet('admin/tmgmt/sources');
    $this->assertRaw('Add to cart');
    $this->assertRaw('Menu link');
    $this->assertRaw('Taxonomy term');
    $this->assertRaw('Literals');
    //@todo: Finish here.
  }

  /**
   * Test adding a node to cart, and check the cart contains the node.
   *
   * 1. Visit node/nid/translate
   * 2. Add to cart
   * 3. Check cart contents at admin/tmgmt/cart
   * 4. Request Translation from Cart
   * 5. Check job created and Node in it in admin/tmgmt/jobs/%tjid
   */
  public function testAddNodeToCart() {
    $this->loginAsAdmin();

    // Create a node in Draft state.
    $options = array(
      'title_field[und][0][value]' => $this->nodeTitle1,
      'workbench_moderation_state_new' => 'published',
    );
    $this->drupalPost('node/add/news', $options, t('Save'));
    $node = $this->drupalGetNodeByTitle($this->nodeTitle1);
    $this->assertEquals('published', $node->workbench_moderation['current']->state);

    $this->drupalGet('node/' . $node->nid . '/translate');
    $this->assertRaw('Add to cart');


    $form_state = array('form_id' => 'tmgmt_entity_ui_translate_form');
    $this->drupalPost('node/' .$node->nid .'/translate', $form_state, t('Add to cart'));

    $this->drupalGet('admin/tmgmt/cart');
    $this->assertText($this->nodeTitle1);

    $tjiid = osha_tmgmt_get_cart_job_item_id('node', $node->nid);

    $form_state = array(
      "form_id" => 'tmgmt_ui_cart_content',
      "priority" => '0',
      "items[$tjiid]" => TRUE,
      "target_language[]" => array('bg', 'ro'),
    );
    $req_translation = $this->drupalPost('admin/tmgmt/cart/', $form_state, t('Request translation'));
    $this->assertContains('Click here to download the XML file', $req_translation);

    $job = osha_tmgmt_job_load_latest();

    $this->drupalGet('admin/tmgmt/jobs/' . $job->tjid);
    $this->assertText($this->nodeTitle1);

  }

  /**
   * Test Job Overview Page
   * 1. Check for table columns
   */
  public function testJobsOverviewPage() {
    $this->loginAsAdmin();

    $this->drupalGet('admin/tmgmt');
    // Check view fields
    $this->assertRaw('views-field-state');
    $this->assertRaw('views-field-priority');
    $this->assertRaw('views-field-page-count');
    $this->assertRaw('views-field-character-count');
    $this->assertRaw('views-field-progress-job-items');
    $this->assertRaw('views-field-changed active');
    $this->assertRaw('views-field-has-file-uploaded');
    $this->assertRaw('views-field-operations');
  }

  /**
   * Test Job Page
   * Check various elements in page (buttons, labels, fields)
   */
  public function testJobPage() {
    $this->loginAsAdmin();

    $job = osha_tmgmt_job_load_latest();
    $this->drupalGet('admin/tmgmt/jobs/' . $job->tjid);

    $this->assertRaw('TRANSLATION VALIDATORS');
    $this->assertRaw('translation_validators[translation_group]');
    $this->assertRaw('Assign');

    $this->assertRaw('JOB ITEMS');
    $this->assertRaw('filter_target_language');
    $this->assertRaw('filter_activity');
    $this->assertRaw('filter_state');
  }
}
