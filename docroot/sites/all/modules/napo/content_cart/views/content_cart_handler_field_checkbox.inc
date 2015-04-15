<?php

/**
 * Provides the checkbox field to tick the view rows and set them as field values.
 */
class content_cart_handler_field_checkbox extends views_handler_field {
  var $revision = FALSE;

  function render($values) {
    $entity_id = $values->{$this->view->base_field};
    if (empty($entity_id)) {
      return;
    }
    drupal_add_library('system', 'drupal.ajax');
    drupal_add_js(drupal_get_path('module', 'content_cart') . '/js/content_cart.js');
    $checked = '';
    $cart = ContentCart::getCurrentCart();
    $entity_type = 'node';
    if ($cart->hasInCart($entity_type, $entity_id)) {
      $checked = 'checked="checked"';
    }
    return '<input name="entity_ids[]" type="checkbox" class="content_cart_checkbox" value="' . $entity_type . '-' . $entity_id . '" '. $checked . '/>';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['ervw'] = array(
      'contains' => array(
        'force_single' => array('default' => FALSE),
      ),
    );
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
}

/**
 * Filters product nodes .
 */
class content_cart_handler_filter_product extends views_handler_filter_boolean_operator {

  /**
   * Overrides views_handler_field::query().
   */
  function query() {
    $type = $this->query->base_table;
    $cart = ContentCart::getCurrentCart();
    $content = $cart->getCartContent();
    if (!empty($content[$type])) {
      $ids = array_keys($content[$type]);
    }
    $condition = db_and()->condition($this->query->base_field, $ids, 'IN');
    $this->query->add_where(0, $condition);
  }
}