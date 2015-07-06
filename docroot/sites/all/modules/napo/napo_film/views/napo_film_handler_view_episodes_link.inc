<?php

/**
 * Provides a custom views field.
 */
class napo_film_handler_view_episodes_link extends views_handler_field {
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
      if ($node->type == 'napo_video' && napo_film_video_get_type($node) == 'film') {
        // Show link only if the film has episodes.
        $episodes = napo_film_get_episodes($node);
        if (!empty($episodes)) {
          $output = l(t('View episodes'), 'node/' . $node->nid . '/view-episodes',
            array('attributes' => array('class' => array('napo-film-view-episodes-link'))));
        }
      }
    }
    return $output;
  }
}
