<?php

/**
 * Filters product nodes .
 */
class content_cart_handler_filter_cart extends views_handler_filter_boolean_operator {

  /**
   * Overrides views_handler_field::query().
   */
  function query() {
    $type = $this->query->base_table;
    $cart = ContentCart::getCurrentCart();
    $content = $cart->getCartContent();
    if (!empty($content[$type])) {
      $ids = array_keys($content[$type]);
      if ($this->value) {
        $condition = db_and()->condition($this->query->base_field, $ids, 'IN');
      }
      else {
        $condition = db_and()->condition($this->query->base_field, $ids, 'NOT IN');
      }
      $this->query->add_where(0, $condition);
    }
  }
}