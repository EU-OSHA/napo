<?php
/**
 * @file
 * napo_msd.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function napo_msd_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|msds_activities|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'msds_activities';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'back_button' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'download_block' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|msds_activities|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function napo_msd_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|msds_activities|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'msds_activities';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title_field',
        6 => 'field_introductory_text',
      ),
      'left' => array(
        1 => 'field_learning_objectives',
        2 => 'field_activities',
        3 => 'field_concluding_questions',
        4 => 'field_assessment',
        5 => 'field_msds_resources_required',
      ),
    ),
    'fields' => array(
      'title_field' => 'header',
      'field_learning_objectives' => 'left',
      'field_activities' => 'left',
      'field_concluding_questions' => 'left',
      'field_assessment' => 'left',
      'field_msds_resources_required' => 'left',
      'field_introductory_text' => 'header',
    ),
    'classes' => array(
      'layout_class' => array(
        'detail--text--block' => 'detail--text--block',
      ),
      'left' => array(
        'acordion--block acordion--items--block' => 'acordion--block acordion--items--block',
      ),
      'right' => array(
        'download--section--block' => 'download--section--block',
      ),
    ),
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
    'layout_disable_css' => 0,
  );
  $export['node|msds_activities|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|msds_activities|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'msds_activities';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'back_button',
        1 => 'title_field',
        2 => 'field_msds_video',
        3 => 'field_introductory_text',
      ),
      'left' => array(
        4 => 'field_learning_objectives',
        5 => 'field_activities',
        6 => 'field_concluding_questions',
        7 => 'field_assessment',
      ),
      'right' => array(
        8 => 'download_block',
      ),
    ),
    'fields' => array(
      'back_button' => 'header',
      'title_field' => 'header',
      'field_msds_video' => 'header',
      'field_introductory_text' => 'header',
      'field_learning_objectives' => 'left',
      'field_activities' => 'left',
      'field_concluding_questions' => 'left',
      'field_assessment' => 'left',
      'download_block' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'header' => array(
        'detail--text--block' => 'detail--text--block',
      ),
      'left' => array(
        'acordion--block acordion--items--block' => 'acordion--block acordion--items--block',
      ),
      'right' => array(
        'download--section--block' => 'download--section--block',
      ),
    ),
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
    'layout_disable_css' => 0,
  );
  $export['node|msds_activities|full'] = $ds_layout;

  return $export;
}
