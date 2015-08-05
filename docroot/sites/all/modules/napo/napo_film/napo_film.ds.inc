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
    'back_button' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'share_widget' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'download_video_form' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'episode_list' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'napo_film_title' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'recommended_films' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|napo_video|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|napo_video|episode_full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'napo_video';
  $ds_fieldsetting->view_mode = 'episode_full';
  $ds_fieldsetting->settings = array(
    'share_widget' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'download_video_form' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'episode_list_episode' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'napo_film_title' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|napo_video|episode_full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|napo_video|episode_popup';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'napo_video';
  $ds_fieldsetting->view_mode = 'episode_popup';
  $ds_fieldsetting->settings = array(
    'share_widget' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'download_video_form' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'episode_list_episode' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|napo_video|episode_popup'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function napo_film_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'download_video_form';
  $ds_field->label = 'Download';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'napo_video|*';
  $ds_field->properties = array();
  $export['download_video_form'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'episode_list';
  $ds_field->label = 'Episode list';
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
  $ds_field->field = 'episode_list_episode';
  $ds_field->label = 'Episodes';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'napo_video|episode_full
napo_video|episode_popup';
  $ds_field->properties = array();
  $export['episode_list_episode'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'napo_film_title';
  $ds_field->label = 'Napo Film Title (second title)';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'napo_video|default
napo_video|episode_full';
  $ds_field->properties = array();
  $export['napo_film_title'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'recommended_films';
  $ds_field->label = 'Recommended films';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'napo_video|default
napo_video|full';
  $ds_field->properties = array();
  $export['recommended_films'] = $ds_field;

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
        0 => 'back_button',
        1 => 'title_field',
        2 => 'field_youtube',
        3 => 'field_publication_date',
        4 => 'episode_list',
        5 => 'napo_film_title',
        6 => 'share_widget',
        7 => 'download_video_form',
        8 => 'field_combined_tags',
        9 => 'body',
        10 => 'recommended_films',
      ),
    ),
    'fields' => array(
      'back_button' => 'ds_content',
      'title_field' => 'ds_content',
      'field_youtube' => 'ds_content',
      'field_publication_date' => 'ds_content',
      'episode_list' => 'ds_content',
      'napo_film_title' => 'ds_content',
      'share_widget' => 'ds_content',
      'download_video_form' => 'ds_content',
      'field_combined_tags' => 'ds_content',
      'body' => 'ds_content',
      'recommended_films' => 'ds_content',
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|napo_video|episode_full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'napo_video';
  $ds_layout->view_mode = 'episode_full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'field_youtube',
        2 => 'field_publication_date',
        3 => 'napo_film_title',
        4 => 'download_video_form',
        5 => 'share_widget',
        6 => 'field_combined_tags',
        7 => 'body',
        8 => 'episode_list_episode',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'field_youtube' => 'ds_content',
      'field_publication_date' => 'ds_content',
      'napo_film_title' => 'ds_content',
      'download_video_form' => 'ds_content',
      'share_widget' => 'ds_content',
      'field_combined_tags' => 'ds_content',
      'body' => 'ds_content',
      'episode_list_episode' => 'ds_content',
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
  $export['node|napo_video|episode_full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|napo_video|episode_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'napo_video';
  $ds_layout->view_mode = 'episode_list';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'back_button',
        1 => 'title_field',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'back_button' => 'ds_content',
      'title_field' => 'ds_content',
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
  $export['node|napo_video|episode_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|napo_video|episode_popup';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'napo_video';
  $ds_layout->view_mode = 'episode_popup';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_youtube',
        1 => 'download_video_form',
        2 => 'share_widget',
        3 => 'episode_list_episode',
      ),
    ),
    'fields' => array(
      'field_youtube' => 'ds_content',
      'download_video_form' => 'ds_content',
      'share_widget' => 'ds_content',
      'episode_list_episode' => 'ds_content',
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
  $export['node|napo_video|episode_popup'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|napo_video|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'napo_video';
  $ds_layout->view_mode = 'search_results';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'field_image',
        2 => 'body',
        3 => 'node_link',
        4 => 'download_video_form',
        5 => 'share_widget',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
      'download_video_form' => 'ds_content',
      'share_widget' => 'ds_content',
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
  $export['node|napo_video|search_results'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function napo_film_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'recommended_films';
  $ds_view_mode->label = 'Recommended films';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['recommended_films'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'search_results';
  $ds_view_mode->label = 'Search results';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['search_results'] = $ds_view_mode;

  return $export;
}
