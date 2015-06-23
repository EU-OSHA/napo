<?php
/**
 * @file
 * osha_workflow.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function osha_workflow_workbench_moderation_export_states() {
  $items = array(
    'draft' => array(
      'name' => 'draft',
      'label' => 'Draft',
      'description' => 'Admins and RM can add and edit content in state draft',
      'weight' => -10,
    ),
    'needs_review' => FALSE,
    'published' => array(
      'name' => 'published',
      'label' => 'Published',
      'description' => 'Web team set the content from Ready To Publish to Published',
      'weight' => -3,
    ),
    'ready_to_publish' => array(
      'name' => 'ready_to_publish',
      'label' => 'Ready To Publish',
      'description' => 'When Review is done, content is ready to be published',
      'weight' => -4,
    ),
  );
  return $items;
}
