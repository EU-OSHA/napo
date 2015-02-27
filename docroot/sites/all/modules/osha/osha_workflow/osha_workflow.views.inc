<?php

/**
 * Implements hook_views_query_alter().
 *
 * {@inheritdoc}
 */
function osha_workflow_views_query_alter(&$view, &$query) {
  if ($view->name == 'workbench_moderation' && $view->current_display == 'drafts_page') {
    $query->where[1]['conditions'][2]['value'][0] = OSHA_WORKFLOW_STATE_DRAFT;
    $query->where[1]['conditions'][2]['operator'] = 'in';
  }


  if ($view->name == 'osh_workflow_admin') {
    // Alter the query for views from Workflow Dashboard.
    // Get the latest state of nodes, not just the published ones.
    if (!empty($query->table_queue['node_revision'])
        && $view->current_display != 'my_content_non_moderated') {
      $query->table_queue['node_revision']['join']->field = 'nid';
      $query->table_queue['node_revision']['join']->left_field = 'nid';
    }
    if ($view->current_display == 'my_content') {
      // Fix My Content View - Add conditions to show distinct content that has
      // some transitions made by current user
      // Fix to show current revisions Title (revision published or not).
      $new_join = new views_join();
      $new_join->table = 'workbench_moderation_node_history';
      $new_join->left_table = 'workbench_moderation_node_history';
      $new_join->left_field = 'nid';
      $new_join->field = 'nid';
      $new_join->type = 'INNER';
      $query->table_queue['workbench_moderation_node_history_workbench_moderation_node_history'] = array(
        'table' => 'workbench_moderation_node_history',
        'alias' => 'workbench_moderation_node_history_workbench_moderation_node_history',
        'num' => 1,
        'join' => $new_join,
      );
      global $user;
      $query->where[1]['conditions'][] = array(
        'field' => 'workbench_moderation_node_history_workbench_moderation_node_history.uid',
        'value' => $user->uid,
        'operator' => '=',
      );
    }
  }
}

/**
 * Implements hook_views_post_execute().
 */
function osha_workflow_views_post_execute(&$view) {
  if ($view->name == 'osh_workflow_admin') {
    // Add correct author of the node.
    foreach ($view->result as &$row) {
      if (!empty($row->users_node_uid)) {
        $row->users_node_uid = osha_workflow_get_node_owner($row->nid, $row->users_node_uid);
        $row->users_node_name = user_load($row->users_node_uid)->name;
      }
    }
  }
}

/**
 * Implements hook_views_data_alter().
 */
function osha_workflow_views_data_alter(&$data) {
  $data['workbench_moderation_node_history']['uid']['filter'] = array(
    'title' => t('Moderation Author'),
    'handler' => 'views_handler_filter_user_current',
    'real field' => 'uid',
  );
}
