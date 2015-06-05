<?php

/**
 * The the search results.
 */
function theme_search_and_replace_results($variables) {
  $results = $variables['results'];
  $output = NULL;
  if (is_array($results)) {
    $total = count($results);
    $output = '<p>Found matches in ' . $total . ' nodes:</p>';
    $output .= '<ol class="search-and-replace-results scanner-search-results">';
    foreach ($results as $item) {
      $output .= theme('search_and_replace_item', array('item' => $item));
    }
    $output .= '</ol>';
  }
  else {
    drupal_set_message(t('Sorry, we found no matches.'));
  }

  return $output;
}

function theme_search_and_replace_item($variables) {
  $output = '';
  $item = $variables['item'];
  $output .= '<li class="scanner-result">';
  $output .=   '<span class="scanner-title">' . l($item['title'], 'node/' . $item['nid']) . '</span><br />';
  foreach ($item['text'] as $field_name => $text) {
    $output .= '<span class="scanner-info">[One or more matches in <strong>' . $item['type'] . ' ' . $field_name . '</strong>:]</span><br />';
    $output .= '<span class="scanner-text">' . $text . '</span>';
  }
  $output .= '</li>';
  return $output;
}