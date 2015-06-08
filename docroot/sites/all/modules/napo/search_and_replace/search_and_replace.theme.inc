<?php

/**
 * The the search results.
 */
function theme_search_and_replace_results($results) {
  $header = array('Title', 'Type', 'Snippet', 'Count', 'Languages');
  $rows = array();
  $output = NULL;
  if (!empty($results)) {
    $total = count($results);
    drupal_set_message('<p>Found matches in ' . $total . ' nodes. <a href="#search-and-replace-results">See results</a></p>');
    foreach ($results as $item) {
      $row = array(
        l($item['title'], 'node/' . $item['nid']),
        $item['type'],
      );
      $output = '';
      foreach ($item['text'] as $field_name => $text) {
        $output .= '<span class="scanner-info">[One or more matches in <strong>' . $field_name . '</strong>:]</span><br />';
        $output .= '<span class="scanner-text">' . $text . '</span>';
      }
      $row[] = $output;
      $row[] = $item['count'];
      $row[] = implode(', ', $item['languages']);
      $rows[] = $row;
    }
  }
  else {
    drupal_set_message(t('Sorry, we found no matches.'));
  }
  $vars = array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'search-and-replace-results'),
  );
  return theme('table', $vars);
}
