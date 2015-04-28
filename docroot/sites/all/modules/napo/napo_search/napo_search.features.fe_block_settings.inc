<?php
/**
 * @file
 * napo_search.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_search_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'menu',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => -42,
      ),
      'osha_admin' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'osha_admin',
        'weight' => -10,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
