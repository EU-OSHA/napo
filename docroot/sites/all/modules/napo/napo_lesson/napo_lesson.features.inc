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
 * Implements hook_image_default_styles().
 */
function napo_lesson_image_default_styles() {
  $styles = array();

  // Exported image style: lesson_poster_image.
  $styles['lesson_poster_image'] = array(
    'label' => 'Lesson poster image 768x675',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 675,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: poster_image.
  $styles['poster_image'] = array(
    'label' => 'Poster image 1280×720',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1280,
          'height' => 720,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
