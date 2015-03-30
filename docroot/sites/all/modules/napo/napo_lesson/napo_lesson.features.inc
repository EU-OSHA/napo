<?php
/**
 * @file
 * napo_lesson.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function napo_lesson_ctools_plugin_api($module = NULL, $api = NULL) {
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
      'name' => t('Lesson'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'lesson_toolkit' => array(
      'name' => t('Lesson toolkit'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'lesson_video' => array(
      'name' => t('Lesson video'),
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
