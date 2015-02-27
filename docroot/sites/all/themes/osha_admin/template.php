<?php
/**
 * @file template.php
 */


/**
 * Implements hook_preprocess_HOOK() for theme_file_icon().
 *
 * Change the icon directory to use icons from this theme.
 */
function osha_admin_preprocess_file_icon(&$variables) {
  $variables['icon_directory'] = drupal_get_path('theme', 'osha_frontend') . '/images/file_icons';
}

function osha_admin_preprocess_views_view(&$vars) {
  $view = &$vars['view'];
  // Make sure it's the correct view
  if ($view->name == 'events') {
    // add needed javascript
    drupal_add_js(drupal_get_path('theme', 'osha_admin') . '/../osha_frontend/js/color_events_backend.js');
  }
}
