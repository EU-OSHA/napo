<?php

/**
 * Provides the checkbox field to add/remove from cart.
 */
class content_cart_handler_select_in_cart extends views_handler_field {
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
        $checked = '';
        if (napo_film_cart_select_in_cart_selected($node->nid)) {
          $checked = 'checked="checked"';
        }
        $output = '<input name="napo_film_select_in_cart_nids[]" type="checkbox"
          class="napo_film_select_in_cart"
          value="' . $node->nid . '" '. $checked . '/>';
      }
    }
    return $output;
  }
}
