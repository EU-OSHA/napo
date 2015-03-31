<?php
/**
 * @file
 * napo_article.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_article_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

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

  return $export;
}
