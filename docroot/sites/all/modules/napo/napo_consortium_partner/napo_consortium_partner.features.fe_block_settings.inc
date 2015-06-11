<?php
/**
 * @file
 * napo_consortium_partner.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_consortium_partner_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-consortium_partners-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'consortium_partners-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'napo_frontend' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'napo_frontend',
        'weight' => -31,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
    ),
    'title' => 'Napo is an initiative of:',
    'visibility' => 0,
  );

  return $export;
}
