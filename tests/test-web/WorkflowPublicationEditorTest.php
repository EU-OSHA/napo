<?php

/**
 * Class WorkflowPublicationEditorTest tests editor account workflow.
 */
class WorkflowPublicationEditorTest extends OshaWebTestCase {

  public $nodeTitle1 = 'PHPUnit news item #1';

  /**
   * {@inheritdoc}
   */
  public function setUp() {
    parent::setUp();
    $this->loginAs('editor1');
  }

  /**
   * Test editor cannot access administrative menu items.
   */
  public function testAccountSecurity() {
    $this->drupalGet('admin/structure');
    $this->assertText('You do not have any administrative items.');

    $this->drupalGet('admin/config');
    $this->assertNoText('Site information');
  }

  /**
   * Test node creation by editor.
   *
   * 1. Editor creates Draft node
   * 2. Editor set status from Draft to Final Draft
   * 3. The node appears in the users's overview screen.
   */
  public function testCreateNode() {
    $this->drupalGet('node/add/news');
    $this->assertRaw('Current: Draft');
    $this->assertRaw('Final Draft');
    $this->assertNoRaw('Rejected');
    $this->assertNoRaw('Approved');
    $this->assertNoRaw('To Be Reviewed');
    $this->assertNoRaw('To Be Approved');
    $this->assertNoRaw('Ready To Publish');
    $this->assertNoRaw('Published');

    // Create a node in Draft state.
    $options = array('title_field[und][0][value]' => $this->nodeTitle1);
    $this->drupalPost('node/add/news', $options, t('Save'));
    $node = $this->drupalGetNodeByTitle($this->nodeTitle1);
    $nid = $node->nid;
    $this->assertEquals('draft', $node->workbench_moderation['current']->state);

    // Moderate to Final Draft.
    $options = array(
      'title_field[en][0][value]' => $this->nodeTitle1,
      'workbench_moderation_state_new' => 'final_draft',
    );
    $this->drupalPost("node/$nid/edit", $options, t('Save'));

    // Reset the cache sice we are using node_load().
    entity_get_controller('node')->resetCache(array($node->nid));
    $node = node_load($nid);
    $this->assertEquals('final_draft', $node->workbench_moderation['current']->state);

    // Test the node appears in user's overview screen.
    $this->drupalGet('admin/workbench');
    $this->assertText($this->nodeTitle1);
  }

  /**
   * {@inheritdoc}
   */
  public function cleanup() {
    $nodes = node_load_multiple(array(), array('title' => $this->nodeTitle1), TRUE);
    node_delete_multiple(array_keys($nodes));
  }
}
