<?php

class OshaWorkflowPermissionsTest extends OshaWebTestCase {

  public function testUserCanAccessReviewScreen() {
    $this->loginAsAdmin();

    $node = $this->createNodeNews();

    global $user;
    $user = user_load(0);
    $this->assertFalse(OshaWorkflowPermissions::userCanAccessReviewScreen($node, NULL));
    $this->assertFalse(OshaWorkflowPermissions::userCanAccessReviewScreen((object) array(), $user));

    $user = user_load(1);
    $user->roles = array('administrator');
    $this->assertTrue(OshaWorkflowPermissions::userCanAccessReviewScreen($node, $user));

    $user = user_load_by_name('review_manager1');
    $this->assertTrue(OshaWorkflowPermissions::userCanAccessReviewScreen($node, $user));

    $this->drupalLogout();

    node_delete($node->nid);
  }

  public function testUserCanAccessApprovalScreen() {
    $this->loginAsAdmin();
    $node = $this->createNodeNews();

    global $user;
    $user = user_load(0);
    $this->assertFalse(OshaWorkflowPermissions::userCanAccessApprovalScreen($node, NULL));
    $this->assertFalse(OshaWorkflowPermissions::userCanAccessApprovalScreen((object) array(), $user));

    $user = user_load(1);
    $user->roles = array('administrator');
    $this->assertTrue(OshaWorkflowPermissions::userCanAccessApprovalScreen($node, $user));

    $user = user_load_by_name('review_manager1');
    $this->assertTrue(OshaWorkflowPermissions::userCanAccessApprovalScreen($node, $user));

    $this->drupalLogout();

    node_delete($node->nid);
  }

  public function xxtestUserCanEditApprovers() {
    global $user;
    $user = user_load(1);

    $node = $this->drupalCreateNode(array(
      'type' => 'news',
      'language' => 'en',
      'uid' => 1,
      'title' => 'TEST NODE',
    ));

    $user = user_load(0);
    $this->assertFalse(OshaWorkflowPermissions::userCanAccessApprovalScreen($node, NULL));
    $this->assertFalse(OshaWorkflowPermissions::userCanAccessApprovalScreen((object) array(), $user));

    $user = user_load(1);
    $this->assertTrue(OshaWorkflowPermissions::userCanAccessApprovalScreen($node, $user));

    $user = user_load_by_name('review_manager1');
    $this->assertTrue(OshaWorkflowPermissions::userCanAccessApprovalScreen($node, $user));

    $this->drupalLogout();

    node_delete($node->nid);
  }

  public function testUserIsAdministrator() {
    $user = user_load(1);
    $this->assertTrue(OshaWorkflowPermissions::userIsAdministrator($user));

    $user->roles = array('administrator');
    $this->assertTrue(OshaWorkflowPermissions::userIsAdministrator($user));

    $user = NULL;
    $this->assertFalse(OshaWorkflowPermissions::userIsAdministrator($user));
  }

  public function testGetUsersByRole() {
    $role = 'Review Manager';
    $users = OshaWorkflowPermissions::getUsersByRole($role);
    $this->assertNotEmpty($users);

    $role = user_role_load_by_name('Review Manager');
    $users = OshaWorkflowPermissions::getUsersByRole($role->rid);
    $this->assertNotEmpty($users);
  }
}

