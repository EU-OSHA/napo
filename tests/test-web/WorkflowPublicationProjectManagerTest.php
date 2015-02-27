<?php

/**
 * Class WorkflowPublicationProjectManagerTest tests PM account workflow.
 */
class WorkflowPublicationProjectManagerTest extends OshaWebTestCase {

  public $nodeTitle1 = 'PHPUnit project manager test item #1';

  /**
   * {@inheritdoc}
   */
  public function setUp() {
    parent::setUp();
  }

  /**
   * Test editor cannot access administrative menu items.
   */
  public function testAccountSecurity() {
    $this->loginAs('project_manager1');
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
  public function testModerateToBeApproved() {
    $this->loginAs('editor1');
    $node = $this->drupalCreateNode(array(
      'language' => 'en',
      'title' => $this->nodeTitle1, 'type' => 'news',
      // Vacancies
      'workbench_access' => 1007,
    ));
    workbench_moderation_moderate($node, 'final_draft');

    $this->loginAs('review_manager1');
    // Set node status To Be Reviewed.
    $options = array(
      'title_field[en][0][value]' => $this->nodeTitle1,
      'workbench_moderation_state_new' => 'needs_review',
    );
    $this->drupalPost("node/{$node->nid}/edit", $options, t('Save'));
    entity_get_controller('node')->resetCache(array($node->nid));
    $node = node_load($node->nid);
    $this->assertEquals('needs_review', $node->workbench_moderation['current']->state);

    // Set the reviewer to project_manager1
    $pm1 = user_load_by_name('project_manager1');
    $options = array(
      'project_manager' => $pm1->uid,
    );
    $this->drupalPost("node/{$node->nid}/review", $options, t('Change'));
    $this->drupalGet("node/{$node->nid}/review");
    $this->assertText('project_manager1');

    // Define the list of approvers.
    // Cannot use drupalPost here.
    $ap1 = user_load_by_name('approver1');
    $ap2 = user_load_by_name('approver2 ');
    $form_state = array(
      'node' => $node,
      'values' => array(
        'rows' => array(
          $ap1->uid => array('weight' => -10),
          $ap2->uid => array('weight' => -11),
        ),
      ),
    );
    module_load_include('inc', 'osha_workflow', 'osha_workflow.admin');
    drupal_form_submit('osha_workflow_node_approval_form', $form_state, $node);

    $this->drupalGet("node/{$node->nid}/approve");
    $this->assertText($ap1->name);
    $this->assertText($ap2->name);

    $this->loginAs('project_manager1');
    $options = array(
      'workbench_moderation_state_new' => 'to_be_approved',
    );
    $this->drupalPost("node/{$node->nid}/edit", $options, t('Save'));
    entity_get_controller('node')->resetCache(array($node->nid));
    $node = node_load($node->nid);
    $this->assertEquals('to_be_approved', $node->workbench_moderation['current']->state);
  }

  /**
   * {@inheritdoc}
   */
  public function cleanup() {
    $nodes = node_load_multiple(array(), array('title' => $this->nodeTitle1), TRUE);
    node_delete_multiple(array_keys($nodes));
  }
}
