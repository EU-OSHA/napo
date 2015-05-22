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

  $export['views-napos_gallery-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'napos_gallery-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(
      0 => 'napo_album',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => -30,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
