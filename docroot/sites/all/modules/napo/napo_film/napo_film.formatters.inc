<?php

/**
 * Implements hook_field_formatter_info().
 */
function napo_film_taxonomy_field_formatter_info() {
  return array(
    'napo_film_taxonomy_term_facet_link' => array(
      'label' => t('Link with facet'),
      'field types' => array('taxonomy_term_reference'),
      'settings'    => array(
        'taxonomy_term_link' => TRUE,
        'taxonomy_term_separator' => ' | ',
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function i18n_taxonomy_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $language = i18n_language_interface();

  // Terms whose tid is 'autocreate' do not exist
  // yet and $item['taxonomy_term'] is not set. Theme such terms as
  // just their name.

  if ($display['type'] == 'ds_taxonomy_separator_localized' && function_exists('i18n_taxonomy_term_name')) {
    $term->name = i18n_taxonomy_term_name($term, $language->language);
  }
  $item_display = check_plain($term->name);
  if ($linked) {
    $uri = entity_uri('taxonomy_term', $term);
    $item_display = l($term->name, $uri['path']);
  }
}
$terms[] = $item_display;
}

if (!empty($terms)) {
  $output = '';
  $separator = $display['settings']['taxonomy_term_separator'];
  $output = implode($separator, $terms);
  $element[0] = array('#markup' => $output);
}

  switch ($display['type']) {
    case 'napo_film_taxonomy_term_facet_link':
      foreach ($items as $delta => $item) {
        $term = $item['taxonomy_term'];
        $uri = entity_uri('taxonomy_term', $term);
        $element[$delta] = array(
          '#type' => 'link',
          '#title' => i18n_taxonomy_term_name($term, $language->language),
          '#href' => $uri['path'],
          '#options' => $uri['options'],
        );
      }
      break;
  }
  return $element;
}
