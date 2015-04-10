<?php

/**
 * Implements hook_views_handlers().
 */
function napo_film_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'napo_film'),
    ),
    'handlers' => array(
      'napo_film_handler_download_video' => array(
        'parent' => 'views_handler_field',
      ),
      'napo_film_handler_combined_tags' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function napo_film_views_data() {
  $data = array();
  // Define group.
  $data['napo_film']['table']['group'] = t('Napo film');
  $data['napo_film']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );
  // Add custom fields.
  $data['napo_film']['download_video'] = array(
    'title' => t('Download video'),
    'help' => t('Provides a download video form.'),
    'field' => array(
      'handler' => 'napo_film_handler_download_video',
    ),
  );
  $data['napo_film']['combined_tags'] = array(
    'title' => t('Combined tags'),
    'help' => t('Provides a combined field_tags and field_main_tag output.'),
    'field' => array(
      'handler' => 'napo_film_handler_combined_tags',
    ),
  );
  return $data;
}