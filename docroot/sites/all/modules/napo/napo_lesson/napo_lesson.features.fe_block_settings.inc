<?php
/**
 * @file
 * napo_lesson.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_lesson_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-lesson_toolkit_reorder-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'lesson_toolkit_reorder-block_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/16',
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
    'title' => '',
    'visibility' => 1,
  );

  $export['views-lessons-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'lessons-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(
      0 => 'lesson_toolkit',
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
    'title' => '',
    'visibility' => 0,
  );

  $export['views-lessons-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'lessons-block_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
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

  $export['views-napo_target_ages-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'napo_target_ages-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/16',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'napo_frontend',
        'weight' => 1,
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
