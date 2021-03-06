<?php
/**
 * @file
 * napo_contact.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_contact_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['nodeblock-304'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 304,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'nodeblock',
    'node_types' => array(),
    'pages' => 'node/253',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'content',
        'status' => 1,
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
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-faqs-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'faqs-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/253',
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
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['webform-client-block-255'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'client-block-255',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'webform',
    'node_types' => array(),
    'pages' => 'node/253',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => '',
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
    'title' => 'Haven\'t found your answer? CONTACT US',
    'visibility' => 1,
  );

  return $export;
}
