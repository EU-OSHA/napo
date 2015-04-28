<?php
/**
 * @file
 * osha.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['lang_dropdown-language'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'lang_dropdown',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => '',
        'status' => 0,
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

  $export['lang_dropdown-language_content'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language_content',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'lang_dropdown',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'menu',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => -41,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
