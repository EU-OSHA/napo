<?php
/**
 * @file
 * napo_gallery.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function napo_gallery_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|napo_album|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'napo_album';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'back_button' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|napo_album|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function napo_gallery_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|napo_album|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'napo_album';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'back_button',
        1 => 'field_image',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'back_button' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|napo_album|default'] = $ds_layout;

  return $export;
}
