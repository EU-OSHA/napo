<?php
/**
 * @file
 * napo_msd.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_msd_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['napo_msd-related_resources'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'related_resources',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'napo_msd',
    'node_types' => array(
      0 => 'msds_activities',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'content',
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
    'title' => 'Related resources',
    'visibility' => 0,
  );

  $export['views-lesson_related_lesson-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'lesson_related_lesson-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(
      0 => 'lesson',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'content',
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
    'title' => 'Related lesson',
    'visibility' => 0,
  );

  $export['views-msd_related_resources-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'msd_related_resources-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(
      0 => 'msds_activities',
    ),
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
    'title' => 'Related resources',
    'visibility' => 0,
  );

  return $export;
}
