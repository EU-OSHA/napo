<?php
/**
 * @file
 * Simple test that shows that PHPUnit works.
 */

/**
 * Author: Cristian Romanescu <cristi _at_ eaudeweb dot ro>
 * Created: 201412151936
 */

class FrameworkBootstrapTest extends OshaWebTestCase {

  /**
   * Test Drupal API availability.
   */
  public function testBootstrap() {
    $this->assertNotNull(user_load(1));
  }

  /**
   * Test administrator login.
   */
  public function testLogin() {
    $this->loginAsAdmin();
    $this->drupalGet('admin/config');
    $this->assertText('Multilingual settings');
  }

  public function testCreateNode() {
    $this->loginAsAdmin();
    $node = $this->drupalCreateNode(
      array('uid' => 1, 'language' => 'en')
    );
    $this->assertNotNull($node);
    $this->assertTrue($node->nid > 0);
    node_delete($node->nid);
  }
}
