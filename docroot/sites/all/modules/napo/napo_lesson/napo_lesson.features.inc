<?php
/**
 * @file
 * napo_lesson.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function napo_lesson_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function napo_lesson_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function napo_lesson_node_info() {
  $items = array(
    'lesson' => array(
      'name' => 'Lesson',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'lesson_toolkit' => array(
      'name' => 'Lesson toolkit',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'lesson_video' => array(
      'name' => 'Lesson video',
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
