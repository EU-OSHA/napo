<?php
/**
 * @file
 * napo_frontpage.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function napo_frontpage_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'videojs_autoplay';
  $strongarm->value = 0;
  $export['videojs_autoplay'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'videojs_directory';
  $strongarm->value = 'sites/all/themes/napo_frontend/video-js';
  $export['videojs_directory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'videojs_height';
  $strongarm->value = '675';
  $export['videojs_height'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'videojs_width';
  $strongarm->value = '100%';
  $export['videojs_width'] = $strongarm;

  return $export;
}
