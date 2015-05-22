<?php

/**
 * Provides the checkbox field to add/remove from cart.
 */
class content_cart_handler_field_checkbox extends views_handler_field {
  var $revision = FALSE;

  function render($values) {
    $entity_id = $values->{$this->view->base_field};
    $entity_type = $this->view->base_table;
    if (empty($entity_id)) {
      return;
    }
    drupal_add_library('system', 'drupal.ajax');
    drupal_add_js(drupal_get_path('module', 'content_cart') . '/js/content_cart.js');
    $checked = '';
    $cart = ContentCart::getCurrentCart();
    if ($cart->hasInCart($entity_type, $entity_id)) {
      $checked = 'checked="checked"';
    }
    return '<input name="entity_ids[]" type="checkbox"
      class="content_cart_checkbox"
      value="' . $entity_type . '-' . $entity_id . '" '. $checked . '/>';
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
}
