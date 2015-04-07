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
  $strongarm->name = 'site_404';
  $strongarm->value = 'node/247';
  $export['site_404'] = $strongarm;

  return $export;
}
