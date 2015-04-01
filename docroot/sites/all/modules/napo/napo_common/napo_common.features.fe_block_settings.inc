<?php
/**
 * @file
 * napo_commonn.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_common_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['napo_common-no_translation'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'no_translation',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'napo_common',
    'node_types' => array(),
    'pages' => 'node/242',
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
