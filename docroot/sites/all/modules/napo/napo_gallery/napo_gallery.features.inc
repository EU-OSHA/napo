<?php
/**
 * @file
 * napo_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function napo_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function napo_gallery_node_info() {
  $items = array(
    'napo_image' => array(
      'name' => t('Napo Image'),
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
