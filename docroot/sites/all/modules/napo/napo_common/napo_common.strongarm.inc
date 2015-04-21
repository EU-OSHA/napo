<?php
/**
 * @file
 * napo_common.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function napo_common_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'no_translation_exceptions';
  $strongarm->value = '41';
  $export['no_translation_exceptions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'no_translation_nid';
  $strongarm->value = '248';
  $export['no_translation_nid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'no_translation_type_exceptions';
  $strongarm->value = '';
  $export['no_translation_type_exceptions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_404';
  $strongarm->value = 'node/247';
  $export['site_404'] = $strongarm;

  return $export;
}
