<?php
/**
 * @file
 * napo_friend.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function napo_friend_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|napo_friend|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'napo_friend';
  $ds_layout->view_mode = 'search_results';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'field_image',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|napo_friend|search_results'] = $ds_layout;

  return $export;
}
