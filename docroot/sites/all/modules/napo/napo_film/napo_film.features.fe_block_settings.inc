<?php
/**
 * @file
 * napo_film.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_film_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['addtoany-addtoany_button'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'addtoany_button',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'addtoany',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['napo_film-napo_films_view_modes'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'napo_films_view_modes',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'napo_film',
    'node_types' => array(),
    'pages' => 'napos-films/films',
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
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['nodeblock-23'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 23,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'nodeblock',
    'node_types' => array(),
    'pages' => 'napos-films/films',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => -33,
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

  $export['views-episode_list-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'episode_list-block',
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
    'title' => 'View episodes',
    'visibility' => 0,
  );

  return $export;
}
