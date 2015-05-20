<?php

/**
 * Provides the checkbox field to add/remove from cart.
 */
class napo_film_handler_add_mime_to_cart extends views_handler_field {
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
    if (!empty($data->_field_data['nid']['entity'])) {
      $node = $data->_field_data['nid']['entity'];
      if ($node->type == 'napo_video') {
        drupal_add_library('system', 'drupal.ajax');
        drupal_add_js(drupal_get_path('module', 'napo_film') . '/js/napo_film_content_cart.js');
        $output = drupal_get_form('napo_film_cart_add_mime_form_' . $node->nid, $node);
      }
    }
    return $output;
  }
}
