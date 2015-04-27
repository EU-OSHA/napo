<?php
/**
 * @file
 * napo_breadcrumbs.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function napo_breadcrumbs_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'path_breadcrumbs_truncate_title_length';
  $strongarm->value = '30';
  $export['path_breadcrumbs_truncate_title_length'] = $strongarm;

  return $export;
}
