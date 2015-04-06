<?php
/**
 * @file
 * napo_film.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function napo_film_default_cer() {
  $items = array();
  $items['node:napo_video:field_napo_film*node:napo_video:field_episodes'] = entity_import('cer', '{
    "identifier" : "node:napo_video:field_napo_film*node:napo_video:field_episodes",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:napo_video:field_napo_film" } ] },
    "cer_right" : { "und" : [ { "path" : "node:napo_video:field_episodes" } ] },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function napo_film_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_entityqueue_api().
 */
function napo_film_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function napo_film_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function napo_film_node_info() {
  $items = array(
    'napo_video' => array(
      'name' => t('Napo video'),
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
