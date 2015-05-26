<?php

/**
 * Provides a custom views field.
 */
class napo_film_handler_download_video extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    // do nothing -- to override the parent query.
  }

  function render($data) {
    $output = NULL;
    $field = current($data->_field_data);
    if (!empty($field['entity'])) {
      $node = $field['entity'];
      if ($node->type == 'napo_video') {
        $output = drupal_get_form('napo_film_episode_download_form_' . $node->nid, $node);
      }
    }
    return $output;
  }
}

class napo_film_handler_combined_tags extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    $options['search_link'] = array('default' => 'search');
    $options['taxonomy_term_separator'] = array('default' => ' | ');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['search_link'] = array(
      '#type' => 'textfield',
      '#title' => t('Search link'),
      '#default_value' => $this->options['search_link'],
    );
    $form['taxonomy_term_separator'] = array(
      '#type' => 'textfield',
      '#title' => t('Term separator'),
      '#default_value' => $this->options['taxonomy_term_separator'],
    );
  }

  function query() {
    // do nothing -- to override the parent query.
  }

  function render($data) {
    $output = NULL;
    $field = current($data->_field_data);
    $options = $this->options;
    if (!empty($field['entity'])) {
      $node = $field['entity'];
      // Set display settings.
      $display_settings = array(
        'label' => 'hidden',
        'type' => 'napo_film_taxonomy_term_facet_link',
        'settings' => array(
          'search_link' => $options['search_link'],
          'taxonomy_term_separator' => $options['taxonomy_term_separator'],
        ),
      );
      $output = field_view_field('node', $node, 'field_combined_tags', $display_settings);
    }
    return $output;
  }
}
