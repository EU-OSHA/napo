<?php
/**
 * @file
 * napo_gallery.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_gallery_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  return $export;
}
