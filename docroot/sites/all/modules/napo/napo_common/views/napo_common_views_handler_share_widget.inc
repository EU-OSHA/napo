<?php

class napo_common_views_handler_share_widget extends views_handler_field {
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
      $output = napo_common_get_share_widget($node);
    }
    return $output;
  }
}
