<?php

/**
 * Implements hook_field_formatter_info().
 */
function napo_film_field_formatter_info() {
  $info = array(
    'napo_film_episode_title_linked' => array(
      'label' => t('Episode Linked and wrapped'),
      'field types' => array('text'),
      'settings' => array('title_style' => '', 'title_link' => '', 'title_class' => ''),
    ),
  );
  return $info;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function napo_film_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();

  $wrap_tags = array(
    '_none' => t('- None -'),
    'div' => t('DIV'),
    'h1' => t('H1'),
    'h2' => t('H2'),
    'h3' => t('H3'),
    'h4' => t('H4'),
    'h5' => t('H5'),
    'h6' => t('H6'),
    'span' => t('SPAN'),
  );
  $element['title_style'] = array(
    '#title' => t('Wrap title in tag'),
    '#type' => 'select',
    '#default_value' => !empty($settings['title_style']) ? $settings['title_style'] : '_none',
    '#options' => $wrap_tags,
  );

  $link_types = array(
    'content' => t('Content'),
  );
  $element['title_link'] = array(
    '#title' => t('Link title to'),
    '#type' => 'select',
    '#default_value' => $settings['title_link'],
    '#empty_option' => t('Nothing'),
    '#options' => $link_types,
  );

  $element['title_class'] = array(
    '#title' => t('Tag classes'),
    '#type' => 'textfield',
    '#description' => t('A CSS class to use in the wrapper tag for the title.'),
    '#default_value' => $settings['title_class'],
    '#element_validate' => array('_title_validate_class'),
  );

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
  $tag = isset($settings['title_style']) && $settings['title_style'] != '' && $settings['title_style'] != '_none' ? $settings['title_style'] : t('- None -');
  $summary[] = t('Title wrap tag: @tag', array('@tag' => $tag));

  $link_types = array(
    'content' => t('Linked to content'),
  );
  // Display this setting only if field is linked.
  if (isset($link_types[$settings['title_link']])) {
    $summary[] = $link_types[$settings['title_link']];
  }

  // Display this setting only if wrapper has a class.
  if (isset($settings['title_class']) && $settings['title_class'] != '_none' && $settings['title_class'] != '') {
    $summary[] = t('Wrap tag classes: @classes', array('@classes' => $settings['title_class']));
  }

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_view().
 */
function napo_film_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  switch ($display['type']) {
    case 'napo_film_episode_title_linked':
      $settings = $display['settings'];
      $output = isset($items[0]) ? $items[0]['safe_value'] : '';

      if (!empty($output) && $settings['title_link'] == 'content') {
        $uri = entity_uri($entity_type, $entity);
        $attributes['class'] = array(
          'napo_film_episode_link',
        );
        $attributes['data-nid'] = $entity->nid;
        $output = l($output, $uri['path'], array('attributes' => $attributes));
        drupal_add_library('system', 'drupal.ajax');
        drupal_add_js(drupal_get_path('module', 'napo_film') . '/js/napo_film.js');
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
  }
  return $element;
}
