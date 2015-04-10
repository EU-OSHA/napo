<?php
/**
 * @file
 * napo_common.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_common_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-zoom_options'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'machine_name' => 'zoom_options',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'header_top_bar',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => 0,
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

  $export['napo_common-no_translation'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'no_translation',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'napo_common',
    'node_types' => array(),
    'pages' => 'node/248',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => -34,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['napo_common-page_not_found'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'page_not_found',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'napo_common',
    'node_types' => array(),
    'pages' => 'node/247',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => -34,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}