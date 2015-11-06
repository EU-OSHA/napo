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
    'lessons_note' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'back_button' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'top_anchor' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'download_whole_lesson' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'right_menu' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'toolkit_title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'top_menu' => array(
      'weight' => '6',
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
  $ds_field->field = 'download_whole_lesson';
  $ds_field->label = 'Download whole lesson';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'lesson|default';
  $ds_field->properties = array();
  $export['download_whole_lesson'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'lessons_note';
  $ds_field->label = 'lessons_note';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'lesson|*';
  $ds_field->properties = array();
  $export['lessons_note'] = $ds_field;

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

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'toolkit_title';
  $ds_field->label = 'Toolkit title';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'lesson|default';
  $ds_field->properties = array();
  $export['toolkit_title'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'top_menu';
  $ds_field->label = 'Top menu';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'lesson|default';
  $ds_field->properties = array();
  $export['top_menu'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function napo_lesson_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson_toolkit|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson_toolkit';
  $ds_layout->view_mode = 'search_results';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'body',
        2 => 'field_target_ages',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'body' => 'ds_content',
      'field_target_ages' => 'ds_content',
      'node_link' => 'ds_content',
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
  $export['node|lesson_toolkit|search_results'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson_video|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson_video';
  $ds_layout->view_mode = 'search_results';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title_field',
        2 => 'body',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title_field' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
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
  $export['node|lesson_video|search_results'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title_field',
        1 => 'back_button',
        2 => 'toolkit_title',
        3 => 'lessons_note',
      ),
      'left' => array(
        4 => 'right_menu',
        5 => 'field_file',
      ),
      'right' => array(
        6 => 'top_menu',
        7 => 'field_lesson_toolkit',
        8 => 'body',
        9 => 'field_lesson_video',
        10 => 'download_whole_lesson',
        11 => 'top_anchor',
      ),
    ),
    'fields' => array(
      'title_field' => 'header',
      'back_button' => 'header',
      'toolkit_title' => 'header',
      'lessons_note' => 'header',
      'right_menu' => 'left',
      'field_file' => 'left',
      'top_menu' => 'right',
      'field_lesson_toolkit' => 'right',
      'body' => 'right',
      'field_lesson_video' => 'right',
      'download_whole_lesson' => 'right',
      'top_anchor' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|lesson|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lesson|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lesson';
  $ds_layout->view_mode = 'search_results';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'share_widget',
        1 => 'title_field',
        2 => 'body',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'share_widget' => 'ds_content',
      'title_field' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
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
  $export['node|lesson|search_results'] = $ds_layout;

  return $export;
}
