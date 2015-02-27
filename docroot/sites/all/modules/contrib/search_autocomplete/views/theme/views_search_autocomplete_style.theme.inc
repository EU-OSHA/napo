<?php

/**
 * @file
 * Views theme to render view fields as JSON.
 *
 * - $view: The view in use.
 * - $rows: Array of row objects as rendered by
 * _search_autocomplete_render_fields
 * - $options: The options for the style passed in from the UI.
 *
 * @ingroup views_templates
 * @see search_autocomplete.views.inc
 */


function template_preprocess_views_search_autocomplete_style(&$vars) {
global $base_root;

  $view = $vars['view'];
  $rows = $vars['rows'];
  $style_options = $vars['options'];

  $arg = '';
  if (array_key_exists(0, $view->args)) {
    $arg = $view->args[0] ? $view->args[0] : '';
  }

  $objects = array();

  $vars['bitmask'] = NULL;

  foreach ($rows as $row) {

    $object = array();

    /* ----------------
     * Build the link...
     * ----------------  */

    // Extract the URL...
    $regexp = "<a\s[^>]*href=(\"??)([^\" >]*?)\\1[^>]*>(.*)<\/a>";
    if (preg_match("/$regexp/siU", htmlspecialchars_decode($row[$style_options['input_link']]->content, ENT_QUOTES), $matches)) {
      $link = $base_root . $matches[2];
      // And build the link object.
      $object['link'] = trim($link);
    } else {
      $object['link'] = $row[$style_options['input_link']]->content;
    }

    /* ----------------
     * Build the value...
     * ----------------  */
    $object['value'] = trim(strip_tags($row[$style_options['input_label']]->content));

    /* ----------------
     * Build the array of output fields...
     * ----------------  */
    $object['fields'] = array();
    foreach ($style_options['output_fields'] as $field_name) {
      // Add the field if the value is not null.
      if (array_key_exists($field_name, $row) && $row[$field_name] && $row[$field_name]->content) {
        $object['fields'][$field_name] = trim($row[$field_name]->label . ' ' . $row[$field_name]->content);
      }
    }

    if ($style_options['group_by']) {
      $group_type = $style_options['group_by'];
      $group_name = $row[$group_type]->content;
      if (!isset($objects[$group_name])) {
        $objects[$group_name] = array();
      }
      $objects[$group_name][] = $object;
    } else{
      $objects[] = $object;
    }
  }

//   if ($style_options['group_by']) {
//     array_multisort($key_objects, SORT_ASC, $objects);
//   }

  $returns = array();
  if ($style_options['group_by']) {
    foreach ($objects as $group_name => $group) {
      $group[0]['group']['group_id'] = preg_replace('/\W+/','',strtolower(strip_tags($group_name)));;
      $group[0]['group']['group_name'] = trim($group_name);
      $returns = array_merge($returns, $group);
    }
    $vars["rows"] = $returns;
  } else {
    // Check if user wants nested arrays.
    $vars["rows"] = $objects;
  }
}
