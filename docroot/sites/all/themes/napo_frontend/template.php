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
