<?php

class WorkflowPublicationTest extends OshaWebTestCase {


  public function setUp() {
    parent::setUp();
    $this->loginAsAdmin();
  }

  /**
   * Test access to the project managers configuration per section.
   */
  public function testProjectManagersScreen() {
    $pms = osha_workflow_access_pm_get_pm('main-menu', 'menu');
    if (!empty($pms)) {
      reset($pms);
      $pm = current($pms);
      $this->drupalGet('admin/config/workbench/access/managers');
      $this->assertText('Main menu');
      $options = array( "users[{$pm->uid}][remove]" => 1 );
      $this->drupalPost('admin/config/workbench/access/managers/menu/main-menu', $options, t('Update Project Manager'));
      $this->assertText('No active project managers have been found.');
    }

    $pm2 = user_load_by_name('project_manager2');
    $options = array("add_user" => $pm2->uid);
    $this->drupalPost('admin/config/workbench/access/managers/menu/main-menu', $options, t('Update Project Manager'));

    $this->drupalGet('admin/config/workbench/access/managers/menu/main-menu');
    $this->assertText('project_manager2');
  }

  public function test_osha_workflow_workbench_project_managers_form() {
    $_GET['q'] = 'admin/config/workbench/access/managers';
    module_load_include('inc', 'osha_workflow', 'osha_workflow.admin');
    $form = drupal_get_form('osha_workflow_workbench_project_managers_form');
    $this->assertNotNull($form);
    $this->assertArrayHasKey('main-menu', $form['rows']);
  }


  public function test_osha_workflow_workbench_project_managers() {
    $form = osha_workflow_workbench_project_managers();
    $this->assertNotNull($form);
  }

  public function test_osha_workflow_node_approvers() {
    $node = $this->createNodeNews();

    osha_workflow_set_node_approvers($node->nid, array());
    $this->assertEmpty(osha_workflow_get_node_approvers($node->nid, FALSE));

    $ap3 = user_load_by_name('approver3');
    $moderators = array(-10 => $ap3->uid);
    osha_workflow_set_node_approvers($node->nid, $moderators);
    $this->assertEquals(1, count(osha_workflow_get_node_approvers($node->nid)));

    $this->assertTrue(osha_workflow_is_next_approver($node->nid, $ap3));
    $this->assertTrue(osha_workflow_is_last_approver($node, $ap3));

    node_delete($node->nid);
  }

  public function test_osha_workflow_get_default_project_manager() {
    $this->assertNotEmpty(osha_workflow_get_default_project_manager('main-menu'));
  }

  public function test_osha_workflow_get_set_project_manager() {
    $this->assertNull(osha_workflow_get_project_manager(-1));

    $node = $this->createNodeNews();
    $pm3 = user_load_by_name('project_manager3');
    osha_workflow_set_project_manager($node->nid, $pm3->uid);

    $pm = osha_workflow_get_project_manager($node->nid);
    $this->assertEquals($pm3->uid, $pm->uid);

    $this->assertFalse(osha_workflow_is_assigned_project_manager($node->nid));

    $this->loginAs('project_manager3');
    $this->assertTrue(osha_workflow_is_assigned_project_manager($node->nid));

    node_delete($node->nid);
  }
}
