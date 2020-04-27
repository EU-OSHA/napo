<?php

/**
 * Implements hook_views_handlers().
 */
function napo_common_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'napo_common'),
    ),
    'handlers' => array(
      'napo_common_views_handler_share_widget' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implements hook_views_data_alter().
 */
function napo_common_views_data_alter(&$data) {
  $data['views']['in_queue'] = array(
    'title' => t('In queue'),
    'help' => t('Filter to ensure a node IS or IS NOT in the related queue'),
    'sort' => array(
      'handler' => 'entityqueue_handler_sort_in_queue',
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function napo_common_views_data() {
  $data = array();
  // Define group.
  $data['napo_common']['table']['group'] = t('Napo common');
  $data['napo_common']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );
  // Add custom fields.
  $data['napo_common']['share_widget'] = array(
    'title' => t('Napo share widget'),
    'help' => t('Provides a share widget.'),
    'field' => array(
      'handler' => 'napo_common_views_handler_share_widget',
    ),
  );
  return $data;
}
