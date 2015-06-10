<?php

require_once 'theme/menu/menu.inc';

/**
 * Implements hook_preprocess_node().
 */
function napo_frontend_preprocess_node(&$vars) {
  napo_frontend_back_button($vars);
}

/**
 * Back button link and text
 */
function napo_frontend_back_button(&$vars){
  global $base_url;
  $node = $vars['node'];

  $referer = isset($_SERVER['HTTP_REFERER']) ? $_SERVER['HTTP_REFERER'] : '';
  $breadcrumb = drupal_get_breadcrumb();
  $options = array(
    'attributes' => array(
      'class' => 'back_button',
    ),
    'html' => TRUE,
  );

  if (empty($referer) || strpos($referer, $base_url) === FALSE) {
    unset($vars['back_button']);
  }elseif (strpos($referer, 'search') !== FALSE) {
    $vars['back_button'] = l(t('Back to search results'), $referer, $options);
  }elseif (is_array($breadcrumb) && $breadcrumb) {
    $page_title = array_pop($breadcrumb);
    $previous_crumb = array_pop($breadcrumb);

    $regexp = "<a\s[^>]*href=(\"??)([^\" >]*?)\\1[^>]*>(.*)<\/a>";
    if(preg_match("/$regexp/siU", $previous_crumb, $matches)) {
      $vars['back_button'] = l(t('Back to !link', array('!link' => $matches[3])), $base_url.$matches[2], $options);
    }else{
      $vars['back_button'] = l(t('Back to !link', array('!link' => strip_tags($previous_crumb))), $referer, $options);
    }
  }else {
    $vars['back_button'] = l(t('Back'), $referer, $options);
  }
}

function napo_frontend_text_resize_block() {
  // Add js, css, and library
  $content = array(
    '#attached' => array(
      'js' => array(
        array(
          'data' => "var text_resize_scope = " . drupal_json_encode(variable_get('text_resize_scope', 'body')) . ";
          var text_resize_minimum = " . drupal_json_encode(variable_get('text_resize_minimum', '12')) . ";
          var text_resize_maximum = " . drupal_json_encode(variable_get('text_resize_maximum', '25')) . ";
          var text_resize_line_height_allow = " . drupal_json_encode(variable_get('text_resize_line_height_allow', FALSE)) . ";
          var text_resize_line_height_min = " . drupal_json_encode(variable_get('text_resize_line_height_min', 16)) . ";
          var text_resize_line_height_max = " . drupal_json_encode(variable_get('text_resize_line_height_max', 36)) . ";",
          'type' => 'inline',
        ),
        array(
          'data' => drupal_get_path('module', 'text_resize') . '/text_resize.js',
          'type' => 'file',
        )
      ),
      'library' => array(
        array('system', 'jquery.cookie')
      ),
    ),
  );

  $content['#markup'] = t('Set font size ');

  if (variable_get('text_resize_reset_button', FALSE) == TRUE) {
    $content['#markup'] .= '<sup>&#x2C4</sup><a href="javascript:;" class="changer" id="text_resize_increase">A</a> <a href="javascript:;" class="changer" id="text_resize_reset">A</a> <sup>&#x2C5</sup><a href="javascript:;" class="changer" id="text_resize_decrease">A</a> <div id="text_resize_clear"></div>';
  } else {
    $content['#markup'] .= '<sup>&#x2C4</sup><a href="javascript:;" class="changer" id="text_resize_increase">A</a> <sup>&#x2C5</sup><a href="javascript:;" class="changer" id="text_resize_decrease">A</a> <div id="text_resize_clear"></div>';
  }

  return render($content);
}

function napo_frontend_preprocess_image_style(&$variables) {
  $variables['attributes']['class'][] = 'img-responsive';
}

function napo_frontend_form_alter(&$form, &$form_state, $form_id) {
  if($form_id == 'views_exposed_form' && $form['#id'] == 'views-exposed-form-napo-films-page-list') {
    $form['search_api_views_fulltext']['#attributes']['placeholder'] = t('Search');
  }
}

function napo_frontend_napo_film_tag_facet_link($variables) {
  $icon = '<span class="glyphicon glyphicon-remove"></span>';
  $options = array(
    'attributes' => array(
      'class' => array('napo-film-search-tag-filter'),
    ),
    'html' => TRUE,
  );
  return l($icon . $variables['name'], $variables['link'], $options);
}
