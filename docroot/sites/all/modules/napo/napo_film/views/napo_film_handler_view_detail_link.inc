<?php

/**
 * Provides a custom views field.
 */
class napo_film_handler_view_detail_link extends views_handler_field {
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
      if ($node->type == 'napo_video') {
        $span = '<span class="glyphicon glyphicon-play-circle view-film-details-icon"></span>';
        $output = l($span, 'node/' . $node->nid,
          array('html' => TRUE, 'attributes' => array('title' => t('View detail'), 'class' => array('napo-film-view-link'))));
      }
    }
    return $output;
  }
}
