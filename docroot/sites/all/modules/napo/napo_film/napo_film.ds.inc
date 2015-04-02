<?php
/**
 * @file
 * napo_film.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function napo_film_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|napo_video|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'napo_video';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'combined_tags' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'film' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:5:{s:8:"sanitize";i:1;s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:5:"token";s:7:"subtype";s:16:"node:title-field";}',
        'load_terms' => 0,
      ),
    ),
    'share' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'episode_list' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|napo_video|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function napo_film_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'combined_tags';
  $ds_field->label = 'Combined tags';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'napo_video|default';
  $ds_field->properties = array();
  $export['combined_tags'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'episode_list';
  $ds_field->label = 'Episode List';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'napo_video|default';
  $ds_field->properties = array(
    'block' => 'views|episode_list-block',
    'block_render' => '1',
  );
  $export['episode_list'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'film';
  $ds_field->label = 'Film';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'napo_video|default';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['film'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'share';
  $ds_field->label = 'Share';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'napo_video|default';
  $ds_field->properties = array(
    'block' => 'addtoany|addtoany_button',
    'block_render' => '1',
  );
  $export['share'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function napo_film_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|napo_video|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'napo_video';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'field_youtube',
        2 => 'episode_list',
        3 => 'film',
        4 => 'share',
        5 => 'combined_tags',
        6 => 'body',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'field_youtube' => 'ds_content',
      'episode_list' => 'ds_content',
      'film' => 'ds_content',
      'share' => 'ds_content',
      'combined_tags' => 'ds_content',
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
  $export['node|napo_video|default'] = $ds_layout;

  return $export;
}
