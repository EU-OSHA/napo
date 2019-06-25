<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
$names = [];
if ($row->node_field_data_field_msds_video_nid) {
  $node = node_load($row->node_field_data_field_msds_video_nid);
  if ($node->field_tags) {
    foreach($node->field_tags['und'] as $tag) {
      $term = taxonomy_term_load($tag['tid']);
      $names[] = $term->name;
    }
  }
}
$label = t('Keyword');
$tags = implode(', ', $names);
$replace = '<span class="keyword-label"><label>' . $label . ':</label></span> <span class="keyword-tag">' . $tags . '</span>';
$output = str_replace('__Tags__', $replace, $output);
print $output;
