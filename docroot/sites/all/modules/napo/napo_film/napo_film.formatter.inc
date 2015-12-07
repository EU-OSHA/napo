<?php

/**
 * Implements hook_field_formatter_info().
 */
function napo_film_field_formatter_info() {
  $info = array(
    'napo_film_taxonomy_term_facet_link' => array(
      'label' => t('Link with facet'),
      'field types' => array('taxonomy_term_reference', 'text'),
      'settings'    => array(
        'taxonomy_term_separator' => ' | ',
        'search_link' => 'search',
      ),
    ),
  );
  return $info;
}

/**
 * Implements hook_field_formatter_info_alter().
 */
function napo_film_field_formatter_info_alter(&$info) {
  // Define extra fields for settings form to save them.
  $info['title_linked']['settings']['napo_film_title_include_type'] = FALSE;
  $info['title_linked']['settings']['napo_film_title_include_episode_count'] = FALSE;
  $info['title_linked']['settings']['napo_film_title_link_episode_popup'] = FALSE;
  $info['title_linked']['settings']['napo_film_title_link_with_film'] = FALSE;
  $info['title_linked']['settings']['napo_film_title_link_with_film_value'] = '!episode from the film !film';
}


/**
 * Implements hook_field_formatter_settings_form().
 */
function napo_film_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();
  switch ($instance['display'][$view_mode]['type']) {
    case 'napo_film_taxonomy_term_facet_link':
      $element['taxonomy_term_separator'] = array(
        '#title' => t('Separator'),
        '#type' => 'textfield',
        '#description' => t('A separator for multiple fields.'),
        '#default_value' => $settings['taxonomy_term_separator'],
      );
      $element['search_link'] = array(
        '#title' => t('Search path'),
        '#type' => 'textfield',
        '#description' => t('A path to a search page to which to append the fitlers.'),
        '#default_value' => $settings['search_link'],
      );
      break;
  }

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function napo_film_field_formatter_settings_summary($field, $instance, $view_mode) {
  $settings = $instance['display'][$view_mode]['settings'];
  $summary = array();

  if (empty($settings)) {
    return;
  }

  switch ($instance['display'][$view_mode]['type']) {
    case 'napo_film_taxonomy_term_facet_link':
      if (!empty($settings['search_link'])) {
        $summary[] = 'Search path: ' . $settings['search_link'];
      }
      if (!empty($settings['taxonomy_term_separator'])) {
        $summary[] = 'Separator: ' . $settings['taxonomy_term_separator'];
      }
      break;
  }
  return implode('<br />', $summary);
}

/**
 * Implements hook_napo_common_field_formatter_settings_form().
 *
 * Alters the settings form for title_linked formatter.
 */
function napo_film_napo_common_field_formatter_settings_form_alter($field, $instance, $view_mode, &$form, &$form_state) {

  $settings = $instance['display'][$view_mode]['settings'];
  $form['napo_film_title_include_type'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include film/episode type'),
    '#default_value' => $settings['napo_film_title_include_type'],
  );
  $form['napo_film_title_include_episode_count'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include episode count'),
    '#default_value' => $settings['napo_film_title_include_episode_count'],
  );
  $form['napo_film_title_link_episode_popup'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show episode popup'),
    '#default_value' => $settings['napo_film_title_link_episode_popup'],
  );
  $form['napo_film_title_link_with_film'] = array(
    '#type' => 'checkbox',
    '#title' => t("Show episode title with it's film"),
    '#default_value' => $settings['napo_film_title_link_with_film'],
  );
  $form['napo_film_title_link_with_film_value'] = array(
    '#type' => 'textfield',
    '#title' => t('The value of episode title'),
    '#default_value' => $settings['napo_film_title_link_with_film_value'],
    '#description' => t('You can use !episode and !film placeholders'),
    '#states' => array(
      'visible' => array(
        ':input[name$="napo_film_title_link_episode_title_with_film]"]' => array('checked' => TRUE),
      ),
      'invisible' => array(
        ':input[name$="napo_film_title_link_episode_title_with_film]"]' => array('checked' => FALSE),
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function napo_film_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $settings = $display['settings'];

  //Highlight the searched text on search page.
  $view = views_get_current_view();
  if ($view) {
    if ($view->name == 'search') {
      foreach ($view->result as $result) {
        if ($result->entity->nid != $entity->nid) {
          continue;
        }
        $title = $result->_entity_properties['title_field'];
        if ($title) {
          $items[0]['safe_value'] = $title;
        }
        break;
      }
    }
  }

  switch ($display['type']) {
    case 'napo_film_episode_title_linked':
      $output = isset($items[0]) ? $items[0]['safe_value'] : '';

      if (!empty($output) && $settings['title_link'] == 'content') {
        $uri = entity_uri($entity_type, $entity);
        if (napo_film_video_get_type($entity) == 'episode') {
          $attributes['class'] = array(
            'napo_film_episode_link',
          );
          drupal_add_library('system', 'drupal.ajax');
          drupal_add_js(drupal_get_path('module', 'napo_film') . '/js/napo_film.js');
          $attributes['data-nid'] = $entity->nid;
        }
        $output = l($output, $uri['path'], array('attributes' => $attributes));
      }

      $wrap_tag = empty($settings['title_style']) ? '_none' : $settings['title_style'];

      if ($wrap_tag != '_none') {
        $element = array(
          'element' => array(
            '#tag' => $wrap_tag,
            '#value' => $output,
          ),
        );

        if (!empty($settings['title_class'])) {
          $element['#attributes'] = array('class' => $settings['title_class']);
        }

        $output = theme('html_tag', $element);
      }

      $element = array(
        array(
          '#markup' => $output,
        ),
      );
      break;

    case 'napo_film_taxonomy_term_facet_link':
      $links = array();
      foreach ($items as $tid) {
        $term = taxonomy_term_load($tid['tid']);
        $query = array(
          'f' => array(
            $field['field_name'] . ':' . $term->tid,
          ),
        );
        $links[] = l($term->name, $settings['search_link'], array('query' => $query));
      }
      $element = array(
        array(
          '#markup' => implode($settings['taxonomy_term_separator'], $links),
        ),
      );
      break;

    case 'title_linked':
      $output = isset($items[0]) ? $items[0]['safe_value'] : '';
      $type = napo_film_video_get_type($entity);

      // Add Film or Episode label for nodes.
      if (!empty($output) && !empty($settings['napo_film_title_include_type'])) {
        switch ($type) {
          case 'episode':
            if (!empty($settings['napo_film_title_include_episode_count'])) {
              $weight = napo_film_get_episode_number($entity) + 1;
              $output = '<span class="napo-film-video-type napo-film-video-type-episode">' . t('Scene @weight', array('@weight' => sprintf('%02d', $weight))) . '</span>' . $output;
            }
            else {
              $output = '<span class="napo-film-video-type napo-film-video-type-episode">' . t('Scene') . '</span>' . $output;
            }
            break;

          case 'film':
            $output = '<span class="napo-film-video-type napo-film-video-type-film">' . t('Film') . '</span>' . $output;
            break;
        }
      }

      // Render the episode title as in defined format.
      if (!empty($settings['napo_film_title_link_with_film'])
        && !empty($settings['napo_film_title_link_with_film_value'])) {
        $film = field_get_items('node', $entity, 'field_napo_film');
        if (!empty($film)) {
          $film = current($film)['target_id'];
          $film_node = node_load($film);
          $film_wrapper = entity_metadata_wrapper('node', $film_node);
          $film_title = l($film_wrapper->title->value(), 'node/' . $film_node->nid);
          $output = t($settings['napo_film_title_link_with_film_value'], array(
            '!episode' => '<span class="epsiode-title">' . $output . '</span>',
            '!film' => '<span class="film-title">' . $film_title . '</span>',
          ));
        }
      }

      // Link to episode popup.
      if (!empty($output) && !empty($settings['napo_film_title_link_episode_popup']) && $type == 'episode') {
        $uri = entity_uri($entity_type, $entity);
        $attributes['class'] = array(
          'napo_film_episode_link',
        );
        drupal_add_library('system', 'drupal.ajax');
        drupal_add_js(drupal_get_path('module', 'napo_film') . '/js/napo_film.js');
        $attributes['data-nid'] = $entity->nid;
        $output = l($output, $uri['path'], array('attributes' => $attributes, 'html' => TRUE));
      }
      elseif (!empty($output) && $settings['title_link'] == 'content') {
        $uri = entity_uri($entity_type, $entity);
        $output = l($output, $uri['path'], array('html' => TRUE));
      }

      $wrap_tag = empty($settings['title_style']) ? '_none' : $settings['title_style'];

      if ($wrap_tag != '_none') {
        $element = array(
          'element' => array(
            '#tag' => $wrap_tag,
            '#value' => $output,
          ),
        );

        if (!empty($settings['title_class'])) {
          $element['element']['#attributes'] = array('class' => $settings['title_class']);
        }

        $output = theme('html_tag', $element);
      }

      $element = array(
        array(
          '#markup' => $output,
        ),
      );
      break;
  }
  return $element;
}
