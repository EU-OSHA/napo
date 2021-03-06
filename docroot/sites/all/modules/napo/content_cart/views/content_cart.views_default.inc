<?php

/**
 * Implements hook_views_default_views().
 */
function content_cart_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'content_cart';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content cart';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content cart';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content Cart: Remove from cart link */
  $handler->display->display_options['fields']['content_cart_remove']['id'] = 'content_cart_remove';
  $handler->display->display_options['fields']['content_cart_remove']['table'] = 'node';
  $handler->display->display_options['fields']['content_cart_remove']['field'] = 'content_cart_remove';
  $handler->display->display_options['fields']['content_cart_remove']['label'] = '';
  $handler->display->display_options['fields']['content_cart_remove']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content Cart: Is in Cart */
  $handler->display->display_options['filters']['content_cart_is_in_cart']['id'] = 'content_cart_is_in_cart';
  $handler->display->display_options['filters']['content_cart_is_in_cart']['table'] = 'node';
  $handler->display->display_options['filters']['content_cart_is_in_cart']['field'] = 'content_cart_is_in_cart';
  $handler->display->display_options['filters']['content_cart_is_in_cart']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'content-cart';
  $translatables['content_cart'] = array(
    t('Master'),
    t('Content cart'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
  );

  $export['content_cart'] = $view;

  return $export;
}