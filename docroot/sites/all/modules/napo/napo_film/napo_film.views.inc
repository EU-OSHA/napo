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
      'napo_film_handler_view_episodes_link' => array(
        'parent' => 'views_handler_field',
      ),
      'napo_film_handler_view_detail_link' => array(
        'parent' => 'views_handler_field',
      ),
      'napo_film_handler_add_mime_to_cart' => array(
        'parent' => 'views_handler_field',
      ),
      'content_cart_handler_select_in_cart' => array(
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
  $data['napo_film']['table']['group'] = 'Napo film';
  $data['napo_film']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );
  // Add custom fields.
  $data['napo_film']['download_video'] = array(
    'title' => 'Download video',
    'help' => 'Provides a download video form.',
    'field' => array(
      'handler' => 'napo_film_handler_download_video',
    ),
  );
  $data['napo_film']['combined_tags'] = array(
    'title' => 'Combined tags',
    'help' => 'Provides a combined field_tags and field_main_tag output.',
    'field' => array(
      'handler' => 'napo_film_handler_combined_tags',
    ),
  );
  $data['napo_film']['view_episodes_link'] = array(
    'title' => 'View episodes link',
    'help' => 'Provides a link to view episodes mode of a film.',
    'field' => array(
      'handler' => 'napo_film_handler_view_episodes_link',
    ),
  );
  $data['napo_film']['view_detail_link'] = array(
    'title' => 'View detail link',
    'help' => 'Provides a link to view detail of a film.',
    'field' => array(
      'handler' => 'napo_film_handler_view_detail_link',
    ),
  );
  $data['napo_film']['content_cart_downlad_as'] = array(
    'title' => 'Downlad this as (cart)',
    'help' => 'Mime types to download the film in cart',
    'field' => array(
      'handler' => 'napo_film_handler_add_mime_to_cart',
    ),
  );
  $data['napo_film']['content_cart_select_in_cart'] = array(
    'title' => 'Select in cart',
    'help' => 'Checkbox to select film in cart.',
    'field' => array(
      'handler' => 'content_cart_handler_select_in_cart',
    ),
  );
  return $data;
}
