<?php
/**
 * @file
 * napo_consortium_partner.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function napo_consortium_partner_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function napo_consortium_partner_node_info() {
  $items = array(
    'consortium_partner' => array(
      'name' => t('Consortium Partner'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
