<?php
/**
 * @file
 * napo_frontpage.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function napo_frontpage_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_ctools_plugin_api().
 */
function napo_frontpage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function napo_frontpage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
