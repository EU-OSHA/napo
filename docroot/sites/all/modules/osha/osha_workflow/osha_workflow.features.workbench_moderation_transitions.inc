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
    'draft:needs_review' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'name' => 'Reviewing the draft',
    ),
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
    'needs_review:draft' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
      'name' => 'Rejected by PM',
    ),
    'needs_review:ready_to_publish' => array(
      'from_name' => 'needs_review',
      'to_name' => 'ready_to_publish',
      'name' => 'Finish review, skip approval',
    ),
    'ready_to_publish:published' => array(
      'from_name' => 'ready_to_publish',
      'to_name' => 'published',
      'name' => 'Publishing',
    ),
  );
  return $items;
}
