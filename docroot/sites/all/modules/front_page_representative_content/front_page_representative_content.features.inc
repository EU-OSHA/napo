<?php
/**
 * @file
 * front_page_representative_content.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function front_page_representative_content_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function front_page_representative_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
