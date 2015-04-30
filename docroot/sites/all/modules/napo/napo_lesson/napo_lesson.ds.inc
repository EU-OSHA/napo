<?php
/**
 * @file
 * napo_lesson.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function napo_lesson_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lesson|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lesson';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'right_menu' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|lesson|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function napo_lesson_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'right_menu';
  $ds_field->label = 'Right menu';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'lesson|default';
  $ds_field->properties = array();
  $export['right_menu'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function napo_lesson_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'right_menu',
        1 => 'field_file',
      ),
      'right' => array(
        2 => 'title_field',
        3 => 'field_lesson_toolkit',
        4 => 'body',
        5 => 'field_lesson_video',
      ),
    ),
    'fields' => array(
      'right_menu' => 'left',
      'field_file' => 'left',
      'title_field' => 'right',
      'field_lesson_toolkit' => 'right',
      'body' => 'right',
      'field_lesson_video' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|lesson|default'] = $ds_layout;

  return $export;
}
