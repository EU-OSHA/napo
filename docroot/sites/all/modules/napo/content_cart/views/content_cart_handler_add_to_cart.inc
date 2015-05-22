<?php

/**
 * Provides the checkbox field to add/remove from cart.
 */
class content_cart_handler_add_to_cart extends views_handler_field {
  var $revision = FALSE;

  function render($values) {
//    $entity_id = $values->{$this->view->base_field};
//    $entity_type = $this->view->base_table;
    if (!empty($values->_field_data) && !empty($values)) {
      reset($values->_field_data);
      $field = current($values->_field_data);
      $entity_type = $field['entity_type'];
      $info = entity_get_info($entity_type);
      $key = $info['entity keys']['id'];
      $entity_id = $field['entity']->{$key};

      drupal_add_library('system', 'drupal.ajax');
      drupal_add_js(drupal_get_path('module', 'content_cart') . '/js/content_cart.js');
      $disabled = '';
      $cart = ContentCart::getCurrentCart();
      if ($cart->hasInCart($entity_type, $entity_id)) {
        $disabled = 'disabled="disabled"';
      }
      $options = $this->options;
      $label = $options['contant_add_to_cart_button_label'];
      return '<button class="btn content-cart-add-to-cart-btn" data-value="' . $entity_type . '-' . $entity_id . '" ' . $disabled . '>'
        . $label . '</button>';
    }
  }

  function query() {
    // do nothing -- to override the parent query.
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['contant_add_to_cart_button_label'] = array('default' => 'Add to cart');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['contant_add_to_cart_button_label'] = array(
      '#type' => 'textfield',
      '#title' => t('Button text'),
    );
  }
}