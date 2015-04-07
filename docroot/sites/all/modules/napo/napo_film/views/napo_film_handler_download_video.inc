<?php

/**
 * Provides a custom views field.
 */
class napo_film_handler_download_video extends views_handler_field {
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
        $output = drupal_get_form('napo_film_episode_download_form_' . $node->nid, $node);
      }
    }
    return $output;
  }
}

class napo_film_handler_combined_tags extends views_handler_field {
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
        $output = napo_film_combined_tags_view_field($node);
      }
    }
    return $output;
  }
}
