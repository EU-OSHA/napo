<?php
/**
 * @file
 * napo_lesson_resources.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function napo_lesson_resources_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function napo_lesson_resources_node_info() {
  $items = array(
    'lesson_resources' => array(
      'name' => 'Lesson Resources',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
