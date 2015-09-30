<?php

/**
 * Provides a custom views field.
 */
class napo_film_handler_view_detail_link extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    $options['napo_film_view_link'] = array('default' => 'icon');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['napo_film_view_link'] = array(
      '#type' => 'select',
      '#title' => t('Film link'),
      '#options' => array('icon' => 'Icon', 'text' => 'Text'),
      '#default_value' => $this->options['napo_film_view_link'],
    );
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
        if ($this->options['napo_film_view_link'] == 'icon') {
          $span = '<span class="glyphicon glyphicon-play-circle view-film-details-icon"></span>';
          $output = l($span, 'node/' . $node->nid,
            array('html' => TRUE, 'attributes' => array('title' => t('View film'), 'class' => array('napo-film-view-link'))));
        }
        else {
          $output = l(t('View film'), 'node/' . $node->nid,
            array('html' => TRUE, 'attributes' => array('class' => array('napo-film-view-text-link'))));
        }
      }
    }
    return $output;
  }
}
