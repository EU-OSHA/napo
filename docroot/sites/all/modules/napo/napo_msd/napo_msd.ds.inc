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
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'resources_required' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|msds_activities|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|msds_activities|print';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'msds_activities';
  $ds_fieldsetting->view_mode = 'print';
  $ds_fieldsetting->settings = array(
    'resources_required' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|msds_activities|print'] = $ds_fieldsetting;

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
        8 => 'resources_required',
      ),
      'right' => array(
        9 => 'download_block',
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
      'resources_required' => 'left',
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|msds_activities|print';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'msds_activities';
  $ds_layout->view_mode = 'print';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'field_msds_video',
        2 => 'field_introductory_text',
        3 => 'field_learning_objectives',
        4 => 'field_activities',
        5 => 'field_concluding_questions',
        6 => 'field_assessment',
        7 => 'resources_required',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'field_msds_video' => 'ds_content',
      'field_introductory_text' => 'ds_content',
      'field_learning_objectives' => 'ds_content',
      'field_activities' => 'ds_content',
      'field_concluding_questions' => 'ds_content',
      'field_assessment' => 'ds_content',
      'resources_required' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|msds_activities|print'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|msds_activities|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'msds_activities';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|msds_activities|teaser'] = $ds_layout;

  return $export;
}
