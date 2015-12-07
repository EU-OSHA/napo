<?php

/**
 * Provides the checkbox field to add/remove from cart.
 */
class content_cart_handler_add_to_cart extends views_handler_field {
  var $revision = FALSE;

  function render($values) {
    if (!empty($values->_field_data) && !empty($values)) {
      reset($values->_field_data);
      $field = current($values->_field_data);
      $entity_type = $field['entity_type'];
      $info = entity_get_info($entity_type);
      $key = $info['entity keys']['id'];
      $entity_id = $field['entity']->{$key};

      drupal_add_library('system', 'drupal.ajax');
      drupal_add_js(drupal_get_path('module', 'content_cart') . '/js/content_cart.js');
      $options = $this->options;
      $label = $add_label = t($options['contant_add_to_cart_button_label']);
      $remove_label = t($options['contant_remove_from_cart_button_label']);

      $incart_message = t('Added to download centre');
      $outofcart_message = t('Removed from download centre');

      $in_cart = '';
      $cart = ContentCart::getCurrentCart();
      if ($cart->hasInCart($entity_type, $entity_id)) {
        $in_cart = 'node_in_content_cart';
        $label = $remove_label;
      }
      return '<button title="' . $label . '" class="btn content-cart-add-to-cart-btn ' .
        $in_cart . '" data-incart="'.$incart_message.'" data-outofcart="'.$outofcart_message.'" data-value="' . $entity_type . '-' . $entity_id . '"' .
        ' data-addtitle="' . $add_label . '" data-removetitle="' . $remove_label . '">'
        . $label . '</button>';
    }
  }

  function query() {
    // do nothing -- to override the parent query.
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['contant_add_to_cart_button_label'] = array('default' => 'Add to cart');
    $options['contant_remove_from_cart_button_label'] = array('default' => 'Remove from cart');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['contant_add_to_cart_button_label'] = array(
      '#type' => 'textfield',
      '#title' => t('Button text'),
      '#default_value' => $this->options['contant_add_to_cart_button_label'],
    );
    $form['contant_remove_from_cart_button_label'] = array(
      '#type' => 'textfield',
      '#title' => t('Remove button text'),
      '#default_value' => $this->options['contant_remove_from_cart_button_label'],
    );
  }
}
