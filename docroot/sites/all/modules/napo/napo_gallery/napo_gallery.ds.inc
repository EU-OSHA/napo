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
    'gallery_cover_image' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'back_button' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'share_widget' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|napo_album|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function napo_gallery_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'gallery_cover_image';
  $ds_field->label = 'gallery_cover_image';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'napo_album|*';
  $ds_field->properties = array();
  $export['gallery_cover_image'] = $ds_field;

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
        1 => 'gallery_cover_image',
        2 => 'body',
        3 => 'share_widget',
        4 => 'field_images',
      ),
    ),
    'fields' => array(
      'back_button' => 'ds_content',
      'gallery_cover_image' => 'ds_content',
      'body' => 'ds_content',
      'share_widget' => 'ds_content',
      'field_images' => 'ds_content',
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
