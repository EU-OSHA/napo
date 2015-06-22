<?php
/**
 * @file
 * osha_workflow.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function osha_workflow_workbench_moderation_export_transitions() {
  $items = array(
    'draft:published' => array(
      'from_name' => 'draft',
      'to_name' => 'published',
      'name' => 'Publishing',
    ),
    'draft:ready_to_publish' => array(
      'from_name' => 'draft',
      'to_name' => 'ready_to_publish',
      'name' => 'Ready to Publish',
    ),
    'ready_to_publish:published' => array(
      'from_name' => 'ready_to_publish',
      'to_name' => 'published',
      'name' => 'Publishing',
    ),
  );
  return $items;
}
