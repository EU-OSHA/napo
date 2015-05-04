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

  if($node->type == 'napo_video') {
    $referer = isset($_SERVER['HTTP_REFERER']) ? $_SERVER['HTTP_REFERER'] : '';
    $breadcrumb = drupal_get_breadcrumb();

    if (empty($referer) || strpos($referer, $base_url) === FALSE) {
      unset($vars['back_button']);
    }elseif (strpos($referer, 'search') !== FALSE) {
      $vars['back_button'] = l(t('Back to search results'), $referer);
    }elseif (is_array($breadcrumb) && $breadcrumb) {
      $page_title = array_pop($breadcrumb);
      $previous_crumb = array_pop($breadcrumb);
      $vars['back_button'] = l(t('Back to !link', array('!link' => strip_tags($previous_crumb))), $referer);
    }else {
      $vars['back_button'] = l(t('Back'), $referer);
    }
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
  if (in_array($variables['style_name'], array('napo_cover', 'napo_thumbnail'))) {
    $variables['attributes']['class'][] = 'img-responsive';
  }
}
