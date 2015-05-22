<?php

interface ContentCartInterface {
  public static function getCurrentCart();
  public function addToCart($type, $id, $item);
  public function removeFromCart($type, $id);
  public function getCartContent();
  public function countItems();

}

class ContentCart implements ContentCartInterface {

  public function __construct() {
    if (!isset($_SESSION['drupal_content_cart'])) {
      $_SESSION['drupal_content_cart'] = array();
    }
  }

  public static function getCurrentCart() {
    return new ContentCart();
  }

  public function addToCart($type, $id, $item) {
    $_SESSION['drupal_content_cart'][$type][$id] = $item;
  }

  public function removeFromCart($type, $id = NULL) {
    if (empty($id) && !empty($_SESSION['drupal_content_cart'][$type])) {
      unset($_SESSION['drupal_content_cart'][$type]);
    }
    elseif (is_int($id) && !empty($_SESSION['drupal_content_cart'][$type][$id])) {
      unset($_SESSION['drupal_content_cart'][$type][$id]);
    }
    elseif (is_array($id) && !empty($_SESSION['drupal_content_cart'][$type])) {
      foreach ($id as $identifier) {
        if (!empty($_SESSION['drupal_content_cart'][$type][$identifier])) {
          unset($_SESSION['drupal_content_cart'][$type][$identifier]);
        }
      }
    }
  }

  public function getCartContent() {
    return $_SESSION['drupal_content_cart'];
  }

  public function hasInCart($type, $id) {
    return !empty($_SESSION['drupal_content_cart'][$type][$id]);
  }

  public function countItems($type = NULL) {
    $items = $this->getCartContent();
    $count = 0;
    if (!empty($items)) {
      if (empty($type)) {
        foreach ($items as $type => $items_of_type) {
          $count += count($items_of_type);
        }
      }
      elseif (!empty($items[$type])) {
        $count = count($items[$type]);
      }
    }
    return $count;
  }
}