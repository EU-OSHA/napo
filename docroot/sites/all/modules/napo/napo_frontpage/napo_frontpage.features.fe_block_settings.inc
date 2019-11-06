<?php
/**
 * @file
 * napo_frontpage.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_frontpage_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-0a94fa4cf986aebe241c18b626efc720'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '0a94fa4cf986aebe241c18b626efc720',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'slider',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => -43,
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

  $export['views-featured_articles-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'featured_articles-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => -42,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
    ),
    'title' => 'Learning with Napo',
    'visibility' => 1,
  );

  $export['views-frontpage_custom_video-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'frontpage_custom_video-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'slider',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => -44,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}
