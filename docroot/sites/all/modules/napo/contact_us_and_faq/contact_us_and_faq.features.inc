<?php
/**
 * @file
 * contact_us_and_faq.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function contact_us_and_faq_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function contact_us_and_faq_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
