<?php
/**
 * @file
 * napo_search.features.inc
 */

/**
 * Implements hook_views_api().
 */
function napo_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function napo_search_default_search_api_index() {
  $items = array();
  $items['default_multilingual_node_index'] = entity_import('search_api_index', '{
    "name" : "Default multilingual node index",
    "machine_name" : "default_multilingual_node_index",
    "description" : "An automatically created search index for indexing multilingual node data. Might be configured to specific needs.",
    "server" : "solr_server",
    "item_type" : "search_api_et_node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "search_api_et" : { "include" : "incomplete", "fallback language" : "" },
      "data_alter_callbacks" : { "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] } },
      "processors" : {
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "strings" : 0 } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\nh2 = 3\\nh3 = 2\\nstrong = 2\\nb = 2\\nem = 1.5\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "spaces" : "[^\\\\p{L}\\\\p{N}]", "ignorable" : "[-]" }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "comment_count" : { "type" : "integer" },
        "created" : { "type" : "date" },
        "field_archived" : { "type" : "boolean" },
        "field_expiration_date" : { "type" : "date" },
        "field_film_video" : { "type" : "integer", "entity_type" : "node" },
        "field_lesson_toolkit" : { "type" : "integer", "entity_type" : "node" },
        "field_lesson_video" : { "type" : "integer", "entity_type" : "node" },
        "field_napo_film" : { "type" : "integer", "entity_type" : "node" },
        "field_publication_date" : { "type" : "date" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target_ages" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_video_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "search_api_et_id" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "title_field" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}