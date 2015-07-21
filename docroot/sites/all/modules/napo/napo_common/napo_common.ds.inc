<?php
/**
 * @file
 * napo_common.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function napo_common_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'back_button';
  $ds_field->label = 'Back button';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '*|default
*|episode_list';
  $ds_field->properties = array();
  $export['back_button'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'share_widget';
  $ds_field->label = 'Share widget';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'article|search_results
napo_video|*
napo_album|default';
  $ds_field->properties = array();
  $export['share_widget'] = $ds_field;

  return $export;
}
