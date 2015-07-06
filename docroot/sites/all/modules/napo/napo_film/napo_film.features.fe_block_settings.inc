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

  $export['content_cart-content_cart_summary'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'content_cart_summary',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'content_cart',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'header_top_bar',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['napo_film-download_cart_form'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'download_cart_form',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'napo_film',
    'node_types' => array(),
    'pages' => 'download-center',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => -39,
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
        'weight' => -40,
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
    'visibility' => 1,
  );

  $export['views--exp-napo_films-page_list'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-napo_films-page_list',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'napos-films/films',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'content',
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

  $export['views-napo_s_film_episodes-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'napo_s_film_episodes-block',
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

  return $export;
}
