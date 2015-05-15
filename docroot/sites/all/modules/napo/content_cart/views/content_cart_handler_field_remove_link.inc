<?php

/**
 * Provides the Remove link to remove a content from cart.
 */
class content_cart_handler_field_remove_link extends views_handler_field {
  var $revision = FALSE;

  function render($values) {
    $entity_id = $values->{$this->view->base_field};
    $entity_type = $this->view->base_table;
    if (empty($entity_id)) {
      return;
    }
    drupal_add_library('system', 'drupal.ajax');
    drupal_add_js(drupal_get_path('module', 'content_cart') . '/js/content_cart.js');
    $view_name = $this->view->name . '-' . $this->view->current_display;
    // TODO add settings for views field (label, classes, wrapper etc.)
    return '<button class="btn content_cart_remove"
      data-value="' . $entity_type . '-' . $entity_id . '"
      data-view="' . $view_name . '">' . t('Remove') . '</button>';
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
}
