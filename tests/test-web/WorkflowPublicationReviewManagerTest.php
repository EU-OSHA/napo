<?php

/**
 * Class WorkflowPublicationReviewManagerTest tests RM account workflow.
 */
class WorkflowPublicationReviewManagerTest extends OshaWebTestCase {

  public $nodeTitle1 = 'PHPUnit review manager test item #1';
  public $nodeTitle2 = 'PHPUnit review manager test item #2';

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
    $this->loginAs('review_manager1');
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
  public function testModerateToNeedsReview() {
    $this->loginAs('editor1');
    $this->drupalGet('node/add/news');
    $this->assertRaw('Current: Draft');
    $this->assertRaw('Final Draft');
    $this->assertNoRaw('Rejected');
    $this->assertNoRaw('Approved');
    $this->assertNoRaw('To Be Reviewed');
    $this->assertNoRaw('To Be Approved');
    $this->assertNoRaw('Ready To Publish');
    $this->assertNoRaw('Published');

    // Create a node1, node2 in Final draft state.
    $options = array(
      'title_field[und][0][value]' => $this->nodeTitle1,
      'workbench_moderation_state_new' => 'final_draft',
    );
    $this->drupalPost('node/add/news', $options, t('Save'));
    $node1 = $this->drupalGetNodeByTitle($this->nodeTitle1);
    $this->assertEquals('final_draft', $node1->workbench_moderation['current']->state);

    $options = array(
      'title_field[und][0][value]' => $this->nodeTitle2,
      'workbench_moderation_state_new' => 'final_draft',
    );
    $this->drupalPost('node/add/news', $options, t('Save'));
    $node2 = $this->drupalGetNodeByTitle($this->nodeTitle2);
    $this->assertEquals('final_draft', $node1->workbench_moderation['current']->state);

    $this->loginAs('review_manager1');

    // Moderate node1 to Needs Review.
    $nid1 = $node1->nid;
    $options = array(
      'title_field[en][0][value]' => $this->nodeTitle1,
      'workbench_moderation_state_new' => 'needs_review',
    );
    $this->drupalPost("node/$nid1/edit", $options, t('Save'));

    // Moderate node2 to Draft.
    $nid2 = $node2->nid;
    $options = array(
      'title_field[en][0][value]' => $this->nodeTitle2,
      'workbench_moderation_state_new' => 'draft',
    );
    $this->drupalPost("node/$nid2/edit", $options, t('Save'));

    // Reset the cache sice we are using node_load().
    entity_get_controller('node')->resetCache(array($node1->nid, $node2->nid));
    $node1 = node_load($nid1);
    $node2 = node_load($nid2);
    $this->assertEquals('needs_review', $node1->workbench_moderation['current']->state);
    $this->assertEquals('draft', $node2->workbench_moderation['current']->state);

    // Test the node appears in user's needs review.
    $this->drupalGet('admin/workbench');
    $this->assertText($this->nodeTitle1);
    $this->assertText($this->nodeTitle2);
  }

  /**
   * {@inheritdoc}
   */
  public function cleanup() {
    $nodes = node_load_multiple(array(), array('title' => $this->nodeTitle1), TRUE);
    node_delete_multiple(array_keys($nodes));

    $nodes = node_load_multiple(array(), array('title' => $this->nodeTitle2), TRUE);
    node_delete_multiple(array_keys($nodes));
  }
}
