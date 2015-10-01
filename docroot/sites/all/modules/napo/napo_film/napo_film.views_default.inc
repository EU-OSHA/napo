<?php
/**
 * @file
 * napo_film.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function napo_film_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'download_center';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Download centre';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Download centre';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'row';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Napo film: Select in cart */
  $handler->display->display_options['fields']['content_cart_select_in_cart']['id'] = 'content_cart_select_in_cart';
  $handler->display->display_options['fields']['content_cart_select_in_cart']['table'] = 'napo_film';
  $handler->display->display_options['fields']['content_cart_select_in_cart']['field'] = 'content_cart_select_in_cart';
  $handler->display->display_options['fields']['content_cart_select_in_cart']['label'] = '';
  $handler->display->display_options['fields']['content_cart_select_in_cart']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'col-md-3';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
    'title_archived_label' => 0,
    'napo_film_title_include_type' => 1,
    'napo_film_title_include_episode_count' => 0,
    'napo_film_title_link_episode_popup' => 0,
    'napo_film_title_link_with_film' => 0,
    'napo_film_title_link_with_film_value' => '!episode from the film !film',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
  );
  /* Field: Content Cart: Remove from cart link */
  $handler->display->display_options['fields']['content_cart_remove']['id'] = 'content_cart_remove';
  $handler->display->display_options['fields']['content_cart_remove']['table'] = 'node';
  $handler->display->display_options['fields']['content_cart_remove']['field'] = 'content_cart_remove';
  $handler->display->display_options['fields']['content_cart_remove']['label'] = '';
  $handler->display->display_options['fields']['content_cart_remove']['exclude'] = TRUE;
  $handler->display->display_options['fields']['content_cart_remove']['element_label_colon'] = FALSE;
  /* Field: Napo film: Downlad this as (cart) */
  $handler->display->display_options['fields']['content_cart_downlad_as']['id'] = 'content_cart_downlad_as';
  $handler->display->display_options['fields']['content_cart_downlad_as']['table'] = 'napo_film';
  $handler->display->display_options['fields']['content_cart_downlad_as']['field'] = 'content_cart_downlad_as';
  $handler->display->display_options['fields']['content_cart_downlad_as']['label'] = '';
  $handler->display->display_options['fields']['content_cart_downlad_as']['exclude'] = TRUE;
  $handler->display->display_options['fields']['content_cart_downlad_as']['element_label_colon'] = FALSE;
  /* Field: Napo film: Download video */
  $handler->display->display_options['fields']['download_video']['id'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['table'] = 'napo_film';
  $handler->display->display_options['fields']['download_video']['field'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['label'] = '';
  $handler->display->display_options['fields']['download_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['download_video']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title_field]
[body]
[content_cart_downlad_as]
[download_video] 
[content_cart_remove]
';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'col-md-9';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['path'] = 'download-center';
  $translatables['download_center'] = array(
    t('Master'),
    t('Download centre'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('[title_field]
[body]
[content_cart_downlad_as]
[download_video] 
[content_cart_remove]
'),
    t('Page'),
  );
  $export['download_center'] = $view;

  $view = new view();
  $view->name = 'entity_references';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Film Entity References';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Entity Reference View Widget Checkbox: Content */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'node';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = '';
  $handler->display->display_options['fields']['entityreference_view_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'napo_video' => 'napo_video',
  );
  /* Filter criterion: Content: Video Type (field_video_type) */
  $handler->display->display_options['filters']['field_video_type_tid']['id'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['table'] = 'field_data_field_video_type';
  $handler->display->display_options['filters']['field_video_type_tid']['field'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['value'] = array(
    2727 => '2727',
  );
  $handler->display->display_options['filters']['field_video_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_video_type_tid']['vocabulary'] = 'video_type';

  /* Display: Lesson video List */
  $handler = $view->new_display('entityreference', 'Lesson video List', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Lesson video list';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'entityreference_view_widget' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lesson_video' => 'lesson_video',
  );

  /* Display: Episode video List */
  $handler = $view->new_display('entityreference', 'Episode video List', 'entityreference_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Episode videos list';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'entityreference_view_widget' => 'entityreference_view_widget',
    'title' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'napo_video' => 'napo_video',
  );
  /* Filter criterion: Content: Video Type (field_video_type) */
  $handler->display->display_options['filters']['field_video_type_tid']['id'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['table'] = 'field_data_field_video_type';
  $handler->display->display_options['filters']['field_video_type_tid']['field'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['value'] = array(
    2726 => '2726',
  );
  $handler->display->display_options['filters']['field_video_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_video_type_tid']['vocabulary'] = 'video_type';

  /* Display: Film video List */
  $handler = $view->new_display('entityreference', 'Film video List', 'entityreference_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Film video list';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'entityreference_view_widget' => 'entityreference_view_widget',
    'title' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['entity_references'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Lesson video List'),
    t('Lesson video list'),
    t('Episode video List'),
    t('Episode videos list'),
    t('Film video List'),
    t('Film video list'),
  );
  $export['entity_references'] = $view;

  $view = new view();
  $view->name = 'episode_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Episode List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Episode list (episode)';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any napo_video content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['visible'] = '5';
  $handler->display->display_options['style_options']['responsive'] = 1;
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_class'] = 'napo_film_episode_link';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
    'title_archived_label' => 1,
    'napo_film_title_include_type' => 1,
    'napo_film_title_include_episode_count' => 1,
    'napo_film_title_link_episode_popup' => 1,
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'napo_film_episode_link';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium2',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title_field]
<a href="[path]" class="napo_film_episode_link" data-nid="[nid]">[field_image]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'episode_list:page_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Contextual filter: Content: Napo film (field_napo_film) */
  $handler->display->display_options['arguments']['field_napo_film_target_id']['id'] = 'field_napo_film_target_id';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['table'] = 'field_data_field_napo_film';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['field'] = 'field_napo_film_target_id';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'napo_video' => 'napo_video',
  );
  /* Filter criterion: Content: Video Type (field_video_type) */
  $handler->display->display_options['filters']['field_video_type_tid']['id'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['table'] = 'field_data_field_video_type';
  $handler->display->display_options['filters']['field_video_type_tid']['field'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['value'] = array(
    2726 => '2726',
  );
  $handler->display->display_options['filters']['field_video_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_video_type_tid']['vocabulary'] = 'video_type';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Episode list (film)';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['relationships'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Reorder episodes';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'field_image' => 'field_image',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_class'] = 'napo_film_episode_link';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'napo_film_episode_title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'episode_list:page_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Napo film (field_napo_film) */
  $handler->display->display_options['arguments']['field_napo_film_target_id']['id'] = 'field_napo_film_target_id';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['table'] = 'field_data_field_napo_film';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['field'] = 'field_napo_film_target_id';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'napo_video' => 'napo_video',
  );
  /* Filter criterion: Content: Video Type (field_video_type) */
  $handler->display->display_options['filters']['field_video_type_tid']['id'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['table'] = 'field_data_field_video_type';
  $handler->display->display_options['filters']['field_video_type_tid']['field'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['value'] = array(
    2726 => '2726',
  );
  $handler->display->display_options['filters']['field_video_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_video_type_tid']['vocabulary'] = 'video_type';
  $handler->display->display_options['path'] = 'node/%/reorder_episodes';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Reorder episodes';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block 2 */
  $handler = $view->new_display('block', 'Block 2', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Episode list (episode full)';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
    'title_archived_label' => 1,
    'napo_film_title_include_type' => 1,
    'napo_film_title_include_episode_count' => 1,
    'napo_film_title_link_episode_popup' => 0,
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'napo_film_episode_link';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium2',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]" class="napo_film_episode_link" data-nid="[nid]">[field_image]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Napo film (field_napo_film) */
  $handler->display->display_options['arguments']['field_napo_film_target_id']['id'] = 'field_napo_film_target_id';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['table'] = 'field_data_field_napo_film';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['field'] = 'field_napo_film_target_id';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['validate_options']['types'] = array(
    'napo_video' => 'napo_video',
  );
  $translatables['episode_list'] = array(
    t('Master'),
    t('Episode list (episode)'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('[title_field]
<a href="[path]" class="napo_film_episode_link" data-nid="[nid]">[field_image]</a>'),
    t('All'),
    t('Block'),
    t('Episode list (film)'),
    t('Page'),
    t('Reorder episodes'),
    t('Content'),
    t('Block 2'),
    t('Episode list (episode full)'),
    t('<a href="[path]" class="napo_film_episode_link" data-nid="[nid]">[field_image]</a>'),
  );
  $export['episode_list'] = $view;

  $view = new view();
  $view->name = 'napo_films';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_multilingual_node_index';
  $view->human_name = 'Napo films';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'napo-film-list-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'row';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  /* Field: Indexed Multilingual Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = 'Film [counter]';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Indexed Multilingual Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '<h3 class="title-field">[counter]: [title_field]</h3>';
  $handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'h3',
    'title_link' => 'content',
    'title_class' => 'title',
  );
  /* Field: Indexed Multilingual Node: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Field: Napo film: View episodes link */
  $handler->display->display_options['fields']['view_episodes_link']['id'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['table'] = 'napo_film';
  $handler->display->display_options['fields']['view_episodes_link']['field'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['label'] = '';
  $handler->display->display_options['fields']['view_episodes_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_episodes_link']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_image][view_episodes_link]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'col-md-4 napo-film-image-container';
  /* Field: Indexed Multilingual Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'napo-film-grid-body';
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
  );
  /* Field: Napo film: Combined tags */
  $handler->display->display_options['fields']['combined_tags']['id'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['table'] = 'napo_film';
  $handler->display->display_options['fields']['combined_tags']['field'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['label'] = '';
  $handler->display->display_options['fields']['combined_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['combined_tags']['element_label_colon'] = FALSE;
  /* Field: Napo film: Download video */
  $handler->display->display_options['fields']['download_video']['id'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['table'] = 'napo_film';
  $handler->display->display_options['fields']['download_video']['field'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['label'] = '';
  $handler->display->display_options['fields']['download_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['download_video']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '<span class="glyphicon glyphicon-play-circle view-film-details-icon"></span>';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="napo-film-list-details-container">[combined_tags][view_episodes_link][url][download_video]</div>';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Content Cart: Add to cart */
  $handler->display->display_options['fields']['content_cart']['id'] = 'content_cart';
  $handler->display->display_options['fields']['content_cart']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['content_cart']['field'] = 'content_cart';
  $handler->display->display_options['fields']['content_cart']['label'] = '';
  $handler->display->display_options['fields']['content_cart']['exclude'] = TRUE;
  $handler->display->display_options['fields']['content_cart']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['content_cart']['contant_add_to_cart_button_label'] = 'Add to download centre';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title_field][body][nothing_2][content_cart]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'col-md-8 napo-film-content-container';
  /* Sort criterion: Indexed Multilingual Node: Publication date */
  $handler->display->display_options['sorts']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['order'] = 'DESC';
  /* Filter criterion: Indexed Multilingual Node: Video Type */
  $handler->display->display_options['filters']['field_video_type']['id'] = 'field_video_type';
  $handler->display->display_options['filters']['field_video_type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_video_type']['field'] = 'field_video_type';
  $handler->display->display_options['filters']['field_video_type']['value'] = array(
    2727 => '2727',
  );
  $handler->display->display_options['filters']['field_video_type']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'napo_video' => 'napo_video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_word';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'field_main_tag:name' => 'field_main_tag:name',
    'field_main_tag:name_field' => 'field_main_tag:name_field',
    'field_tags:name' => 'field_tags:name',
    'field_tags:name_field' => 'field_tags:name_field',
    'title' => 'title',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Multilingual Node: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'page_list');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'h3',
    'title_link' => 'content',
    'title_class' => '',
    'napo_common_title_prefix' => '',
    'title_archived_label' => 1,
    'napo_film_title_include_type' => 1,
    'napo_film_title_include_episode_count' => 0,
    'napo_film_title_link_episode_popup' => 0,
    'napo_film_title_link_with_film' => 1,
    'napo_film_title_link_with_film_value' => '!episode from the film !film',
  );
  /* Field: Content Cart: Add to cart */
  $handler->display->display_options['fields']['content_cart']['id'] = 'content_cart';
  $handler->display->display_options['fields']['content_cart']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['content_cart']['field'] = 'content_cart';
  $handler->display->display_options['fields']['content_cart']['label'] = '';
  $handler->display->display_options['fields']['content_cart']['exclude'] = TRUE;
  $handler->display->display_options['fields']['content_cart']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['content_cart']['contant_add_to_cart_button_label'] = 'Add to download centre';
  $handler->display->display_options['fields']['content_cart']['contant_remove_from_cart_button_label'] = 'Remove from download centre';
  /* Field: Indexed Multilingual Node: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'film_list',
    'image_link' => 'content',
  );
  /* Field: Napo film: View episodes link */
  $handler->display->display_options['fields']['view_episodes_link']['id'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['table'] = 'napo_film';
  $handler->display->display_options['fields']['view_episodes_link']['field'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['label'] = '';
  $handler->display->display_options['fields']['view_episodes_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_episodes_link']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[content_cart]<div class="napo-film-list-image">[field_image]</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'col-md-4 napo-film-image-container';
  /* Field: Indexed Multilingual Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'napo-film-grid-body';
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '250',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Field: Napo film: Combined tags */
  $handler->display->display_options['fields']['combined_tags']['id'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['table'] = 'napo_film';
  $handler->display->display_options['fields']['combined_tags']['field'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['label'] = '';
  $handler->display->display_options['fields']['combined_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['combined_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['combined_tags']['search_link'] = 'napos-films/films';
  /* Field: Napo film: Download video */
  $handler->display->display_options['fields']['download_video']['id'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['table'] = 'napo_film';
  $handler->display->display_options['fields']['download_video']['field'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['label'] = '';
  $handler->display->display_options['fields']['download_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['download_video']['element_label_colon'] = FALSE;
  /* Field: Napo film: View detail link */
  $handler->display->display_options['fields']['view_detail_link']['id'] = 'view_detail_link';
  $handler->display->display_options['fields']['view_detail_link']['table'] = 'napo_film';
  $handler->display->display_options['fields']['view_detail_link']['field'] = 'view_detail_link';
  $handler->display->display_options['fields']['view_detail_link']['label'] = '';
  $handler->display->display_options['fields']['view_detail_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_detail_link']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Node: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="napo-film-list-details-container">[combined_tags][download_video][view_detail_link][view_episodes_link]</div>';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title_field][field_publication_date][body][nothing_2]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'col-md-8 napo-film-content-container';
  $handler->display->display_options['path'] = 'napos-films/films-list';

  /* Display: Grid */
  $handler = $view->new_display('page', 'Grid', 'page_grid');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'napo-film-grid-view';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'h3',
    'title_link' => 'content',
    'title_class' => 'title',
    'napo_common_title_prefix' => '',
    'title_archived_label' => 1,
    'napo_film_title_include_type' => 1,
    'napo_film_title_include_episode_count' => 0,
    'napo_film_title_link_episode_popup' => 0,
    'napo_film_title_link_with_film' => 1,
    'napo_film_title_link_with_film_value' => '!episode from the film !film',
  );
  /* Field: Content Cart: Add to cart */
  $handler->display->display_options['fields']['content_cart']['id'] = 'content_cart';
  $handler->display->display_options['fields']['content_cart']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['content_cart']['field'] = 'content_cart';
  $handler->display->display_options['fields']['content_cart']['label'] = '';
  $handler->display->display_options['fields']['content_cart']['exclude'] = TRUE;
  $handler->display->display_options['fields']['content_cart']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['content_cart']['contant_add_to_cart_button_label'] = 'Add to download centre';
  $handler->display->display_options['fields']['content_cart']['contant_remove_from_cart_button_label'] = 'Remove from download centre';
  /* Field: Napo film: Download video */
  $handler->display->display_options['fields']['download_video']['id'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['table'] = 'napo_film';
  $handler->display->display_options['fields']['download_video']['field'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['label'] = '';
  $handler->display->display_options['fields']['download_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['download_video']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[title_field][content_cart][download_video]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'napo-film-title-container';
  /* Field: Indexed Multilingual Node: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'film_list',
    'image_link' => 'content',
  );
  /* Field: Indexed Multilingual Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
  );
  /* Field: Napo film: View detail link */
  $handler->display->display_options['fields']['view_detail_link']['id'] = 'view_detail_link';
  $handler->display->display_options['fields']['view_detail_link']['table'] = 'napo_film';
  $handler->display->display_options['fields']['view_detail_link']['field'] = 'view_detail_link';
  $handler->display->display_options['fields']['view_detail_link']['label'] = '';
  $handler->display->display_options['fields']['view_detail_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_detail_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_detail_link']['napo_film_view_link'] = 'text';
  /* Field: Napo film: Combined tags */
  $handler->display->display_options['fields']['combined_tags']['id'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['table'] = 'napo_film';
  $handler->display->display_options['fields']['combined_tags']['field'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['label'] = '';
  $handler->display->display_options['fields']['combined_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['combined_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['combined_tags']['search_link'] = 'napos-films/films';
  /* Field: Napo film: View episodes link */
  $handler->display->display_options['fields']['view_episodes_link']['id'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['table'] = 'napo_film';
  $handler->display->display_options['fields']['view_episodes_link']['field'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['label'] = '';
  $handler->display->display_options['fields']['view_episodes_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_episodes_link']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Node: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_publication_date][body][combined_tags][view_detail_link][view_episodes_link]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'napo-film-content-container';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Multilingual Node: Video Type */
  $handler->display->display_options['filters']['field_video_type']['id'] = 'field_video_type';
  $handler->display->display_options['filters']['field_video_type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_video_type']['field'] = 'field_video_type';
  $handler->display->display_options['filters']['field_video_type']['value'] = array(
    2727 => '2727',
  );
  $handler->display->display_options['filters']['field_video_type']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'napo_video' => 'napo_video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_word';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'title' => 'title',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Multilingual Node: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 2;
  /* Filter criterion: Indexed Multilingual Node: Item language */
  $handler->display->display_options['filters']['search_api_language_1']['id'] = 'search_api_language_1';
  $handler->display->display_options['filters']['search_api_language_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language_1']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language_1']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['search_api_language_1']['group'] = 2;
  $handler->display->display_options['path'] = 'napos-films/films-grid';
  $translatables['napo_films'] = array(
    t('Master'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No results'),
    t('.'),
    t('Film [counter]'),
    t('<h3 class="title-field">[counter]: [title_field]</h3>'),
    t('[field_image][view_episodes_link]'),
    t('<span class="glyphicon glyphicon-play-circle view-film-details-icon"></span>'),
    t('<div class="napo-film-list-details-container">[combined_tags][view_episodes_link][url][download_video]</div>'),
    t('[title_field][body][nothing_2][content_cart]'),
    t('List'),
    t('[content_cart]<div class="napo-film-list-image">[field_image]</div>'),
    t('<div class="napo-film-list-details-container">[combined_tags][download_video][view_detail_link][view_episodes_link]</div>'),
    t('[title_field][field_publication_date][body][nothing_2]'),
    t('Grid'),
    t('[title_field][content_cart][download_video]'),
    t('[field_publication_date][body][combined_tags][view_detail_link][view_episodes_link]'),
  );
  $export['napo_films'] = $view;

  $view = new view();
  $view->name = 'napo_films_node';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Napo films';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'napo-film-list-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'row';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'h3',
    'title_link' => 'content',
    'title_class' => '',
    'title_archived_label' => 1,
    'napo_film_title_include_type' => 1,
    'napo_film_title_include_episode_count' => 0,
    'napo_film_title_link_episode_popup' => 0,
    'napo_film_title_link_with_film' => 0,
    'napo_film_title_link_with_film_value' => '!episode from the film !film',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'film_list',
    'image_link' => 'content',
  );
  /* Field: Content Cart: Add to cart button */
  $handler->display->display_options['fields']['content_add_to_cart']['id'] = 'content_add_to_cart';
  $handler->display->display_options['fields']['content_add_to_cart']['table'] = 'node';
  $handler->display->display_options['fields']['content_add_to_cart']['field'] = 'content_add_to_cart';
  $handler->display->display_options['fields']['content_add_to_cart']['label'] = '';
  $handler->display->display_options['fields']['content_add_to_cart']['exclude'] = TRUE;
  $handler->display->display_options['fields']['content_add_to_cart']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['content_add_to_cart']['contant_add_to_cart_button_label'] = 'Add to download centre';
  $handler->display->display_options['fields']['content_add_to_cart']['contant_remove_from_cart_button_label'] = 'Remove from download centre';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[content_add_to_cart][field_image]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'col-md-4 napo-film-image-container';
  /* Field: Napo film: View episodes link */
  $handler->display->display_options['fields']['view_episodes_link']['id'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['table'] = 'napo_film';
  $handler->display->display_options['fields']['view_episodes_link']['field'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['label'] = '';
  $handler->display->display_options['fields']['view_episodes_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_episodes_link']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'napo-film-grid-body';
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '250',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Field: Napo film: Combined tags */
  $handler->display->display_options['fields']['combined_tags']['id'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['table'] = 'napo_film';
  $handler->display->display_options['fields']['combined_tags']['field'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['label'] = '';
  $handler->display->display_options['fields']['combined_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['combined_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['combined_tags']['search_link'] = 'napos-films/films';
  /* Field: Napo film: Download video */
  $handler->display->display_options['fields']['download_video']['id'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['table'] = 'napo_film';
  $handler->display->display_options['fields']['download_video']['field'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['label'] = '';
  $handler->display->display_options['fields']['download_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['download_video']['element_label_colon'] = FALSE;
  /* Field: Napo film: View detail link */
  $handler->display->display_options['fields']['view_detail_link']['id'] = 'view_detail_link';
  $handler->display->display_options['fields']['view_detail_link']['table'] = 'napo_film';
  $handler->display->display_options['fields']['view_detail_link']['field'] = 'view_detail_link';
  $handler->display->display_options['fields']['view_detail_link']['label'] = '';
  $handler->display->display_options['fields']['view_detail_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_detail_link']['element_label_colon'] = FALSE;
  /* Field: Content: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="napo-film-list-details-container">[combined_tags][view_episodes_link][view_detail_link][download_video]</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[title_field][field_publication_date][body][nothing_1]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_2']['element_wrapper_class'] = 'col-md-8 napo-film-content-container';
  /* Sort criterion: Content: Publication date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'napo_video' => 'napo_video',
  );
  /* Filter criterion: Content: Video Type (field_video_type) */
  $handler->display->display_options['filters']['field_video_type_tid']['id'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['table'] = 'field_data_field_video_type';
  $handler->display->display_options['filters']['field_video_type_tid']['field'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['value'] = array(
    2727 => '2727',
  );
  $handler->display->display_options['filters']['field_video_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_video_type_tid']['vocabulary'] = 'video_type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_list');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'h3',
    'title_link' => 'content',
    'title_class' => '',
    'title_archived_label' => 1,
    'napo_film_title_include_type' => 1,
    'napo_film_title_include_episode_count' => 0,
    'napo_film_title_link_episode_popup' => 0,
    'napo_film_title_link_with_film' => 0,
    'napo_film_title_link_with_film_value' => '!episode from the film !film',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'film_list',
    'image_link' => 'content',
  );
  /* Field: Content Cart: Add to cart button */
  $handler->display->display_options['fields']['content_add_to_cart']['id'] = 'content_add_to_cart';
  $handler->display->display_options['fields']['content_add_to_cart']['table'] = 'node';
  $handler->display->display_options['fields']['content_add_to_cart']['field'] = 'content_add_to_cart';
  $handler->display->display_options['fields']['content_add_to_cart']['label'] = '';
  $handler->display->display_options['fields']['content_add_to_cart']['exclude'] = TRUE;
  $handler->display->display_options['fields']['content_add_to_cart']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['content_add_to_cart']['contant_add_to_cart_button_label'] = 'Add to download centre';
  $handler->display->display_options['fields']['content_add_to_cart']['contant_remove_from_cart_button_label'] = 'Remove from download centre';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[content_add_to_cart]<div class="napo-film-list-image">[field_image]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'col-md-4 napo-film-image-container';
  /* Field: Napo film: View episodes link */
  $handler->display->display_options['fields']['view_episodes_link']['id'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['table'] = 'napo_film';
  $handler->display->display_options['fields']['view_episodes_link']['field'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['label'] = '';
  $handler->display->display_options['fields']['view_episodes_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_episodes_link']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'napo-film-grid-body';
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '250',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Field: Napo film: Combined tags */
  $handler->display->display_options['fields']['combined_tags']['id'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['table'] = 'napo_film';
  $handler->display->display_options['fields']['combined_tags']['field'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['label'] = '';
  $handler->display->display_options['fields']['combined_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['combined_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['combined_tags']['search_link'] = 'napos-films/films';
  /* Field: Napo film: Download video */
  $handler->display->display_options['fields']['download_video']['id'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['table'] = 'napo_film';
  $handler->display->display_options['fields']['download_video']['field'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['label'] = '';
  $handler->display->display_options['fields']['download_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['download_video']['element_label_colon'] = FALSE;
  /* Field: Napo film: View detail link */
  $handler->display->display_options['fields']['view_detail_link']['id'] = 'view_detail_link';
  $handler->display->display_options['fields']['view_detail_link']['table'] = 'napo_film';
  $handler->display->display_options['fields']['view_detail_link']['field'] = 'view_detail_link';
  $handler->display->display_options['fields']['view_detail_link']['label'] = '';
  $handler->display->display_options['fields']['view_detail_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_detail_link']['element_label_colon'] = FALSE;
  /* Field: Content: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="napo-film-list-details-container">[combined_tags][download_video][view_detail_link][view_episodes_link]</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[title_field][field_publication_date][body][nothing_1]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_2']['element_wrapper_class'] = 'col-md-8 napo-film-content-container';
  $handler->display->display_options['path'] = 'napo-films/node-films';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_grid');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'h3',
    'title_link' => 'content',
    'title_class' => '',
    'title_archived_label' => 1,
    'napo_film_title_include_type' => 1,
    'napo_film_title_include_episode_count' => 0,
    'napo_film_title_link_episode_popup' => 0,
    'napo_film_title_link_with_film' => 0,
    'napo_film_title_link_with_film_value' => '!episode from the film !film',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content Cart: Add to cart button */
  $handler->display->display_options['fields']['content_add_to_cart']['id'] = 'content_add_to_cart';
  $handler->display->display_options['fields']['content_add_to_cart']['table'] = 'node';
  $handler->display->display_options['fields']['content_add_to_cart']['field'] = 'content_add_to_cart';
  $handler->display->display_options['fields']['content_add_to_cart']['label'] = '';
  $handler->display->display_options['fields']['content_add_to_cart']['exclude'] = TRUE;
  $handler->display->display_options['fields']['content_add_to_cart']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['content_add_to_cart']['contant_add_to_cart_button_label'] = 'Add to download centre';
  $handler->display->display_options['fields']['content_add_to_cart']['contant_remove_from_cart_button_label'] = 'Remove from download centre';
  /* Field: Napo film: Download video */
  $handler->display->display_options['fields']['download_video']['id'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['table'] = 'napo_film';
  $handler->display->display_options['fields']['download_video']['field'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['label'] = '';
  $handler->display->display_options['fields']['download_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['download_video']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[title_field][content_add_to_cart][download_video]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'napo-film-title-container';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'film_list',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'napo-film-grid-body';
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '250',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Field: Napo film: View detail link */
  $handler->display->display_options['fields']['view_detail_link']['id'] = 'view_detail_link';
  $handler->display->display_options['fields']['view_detail_link']['table'] = 'napo_film';
  $handler->display->display_options['fields']['view_detail_link']['field'] = 'view_detail_link';
  $handler->display->display_options['fields']['view_detail_link']['label'] = '';
  $handler->display->display_options['fields']['view_detail_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_detail_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_detail_link']['napo_film_view_link'] = 'text';
  /* Field: Napo film: Combined tags */
  $handler->display->display_options['fields']['combined_tags']['id'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['table'] = 'napo_film';
  $handler->display->display_options['fields']['combined_tags']['field'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['label'] = '';
  $handler->display->display_options['fields']['combined_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['combined_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['combined_tags']['search_link'] = 'napos-films/films';
  /* Field: Napo film: View episodes link */
  $handler->display->display_options['fields']['view_episodes_link']['id'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['table'] = 'napo_film';
  $handler->display->display_options['fields']['view_episodes_link']['field'] = 'view_episodes_link';
  $handler->display->display_options['fields']['view_episodes_link']['label'] = '';
  $handler->display->display_options['fields']['view_episodes_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_episodes_link']['element_label_colon'] = FALSE;
  /* Field: Content: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_publication_date][body][combined_tags][view_detail_link][view_episodes_link]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'napo-film-content-container';
  $handler->display->display_options['path'] = 'napo-films/node-films-grid';
  $translatables['napo_films_node'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('[content_add_to_cart][field_image]'),
    t('<div class="napo-film-list-details-container">[combined_tags][view_episodes_link][view_detail_link][download_video]</div>'),
    t('[title_field][field_publication_date][body][nothing_1]'),
    t('Page'),
    t('[content_add_to_cart]<div class="napo-film-list-image">[field_image]</div>'),
    t('<div class="napo-film-list-details-container">[combined_tags][download_video][view_detail_link][view_episodes_link]</div>'),
    t('[title_field][content_add_to_cart][download_video]'),
    t('[field_publication_date][body][combined_tags][view_detail_link][view_episodes_link]'),
  );
  $export['napo_films_node'] = $view;

  $view = new view();
  $view->name = 'napo_s_film_episodes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Napo\'s film episodes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Napo\'s film episodes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'row';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'napo_film_episode_title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Napo film: Combined tags */
  $handler->display->display_options['fields']['combined_tags']['id'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['table'] = 'napo_film';
  $handler->display->display_options['fields']['combined_tags']['field'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['label'] = '';
  $handler->display->display_options['fields']['combined_tags']['element_label_colon'] = FALSE;
  /* Field: Napo film: Download video */
  $handler->display->display_options['fields']['download_video']['id'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['table'] = 'napo_film';
  $handler->display->display_options['fields']['download_video']['field'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['label'] = '';
  $handler->display->display_options['fields']['download_video']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = '<span class="glyphicon glyphicon-play-circle"></span>';
  $handler->display->display_options['fields']['path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'episode_list:page_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Contextual filter: Content: Napo film (field_napo_film) */
  $handler->display->display_options['arguments']['field_napo_film_target_id']['id'] = 'field_napo_film_target_id';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['table'] = 'field_data_field_napo_film';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['field'] = 'field_napo_film_target_id';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_napo_film_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'napo_video' => 'napo_video',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
    'title_archived_label' => 1,
    'napo_film_title_include_type' => 1,
    'napo_film_title_include_episode_count' => 1,
    'napo_film_title_link_episode_popup' => 0,
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content Cart: Add to cart button */
  $handler->display->display_options['fields']['content_add_to_cart']['id'] = 'content_add_to_cart';
  $handler->display->display_options['fields']['content_add_to_cart']['table'] = 'node';
  $handler->display->display_options['fields']['content_add_to_cart']['field'] = 'content_add_to_cart';
  $handler->display->display_options['fields']['content_add_to_cart']['label'] = '';
  $handler->display->display_options['fields']['content_add_to_cart']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['content_add_to_cart']['contant_add_to_cart_button_label'] = 'Add to download centre';
  $handler->display->display_options['fields']['content_add_to_cart']['contant_remove_from_cart_button_label'] = 'Remove from download centre';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'col-sm-3';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Field: Content: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Napo film: Download video */
  $handler->display->display_options['fields']['download_video']['id'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['table'] = 'napo_film';
  $handler->display->display_options['fields']['download_video']['field'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['label'] = '';
  $handler->display->display_options['fields']['download_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['download_video']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = '<span class="glyphicon glyphicon-play-circle"></span>';
  $handler->display->display_options['fields']['path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_combined_tags']['id'] = 'field_combined_tags';
  $handler->display->display_options['fields']['field_combined_tags']['table'] = 'field_data_field_combined_tags';
  $handler->display->display_options['fields']['field_combined_tags']['field'] = 'field_combined_tags';
  $handler->display->display_options['fields']['field_combined_tags']['label'] = '';
  $handler->display->display_options['fields']['field_combined_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_combined_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_combined_tags']['type'] = 'napo_film_taxonomy_term_facet_link';
  $handler->display->display_options['fields']['field_combined_tags']['settings'] = array(
    'taxonomy_term_separator' => ' | ',
    'search_link' => 'napos-films/films',
  );
  $handler->display->display_options['fields']['field_combined_tags']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3>[title_field]</h3>
[field_publication_date]
<div class="episode-list-details-container">
<div class="tags">[field_combined_tags]</div>
<div class="buttons">[download_video][path]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'col-sm-9';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'napo_video' => 'napo_video',
  );
  /* Filter criterion: Content: Video Type (field_video_type) */
  $handler->display->display_options['filters']['field_video_type_tid']['id'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['table'] = 'field_data_field_video_type';
  $handler->display->display_options['filters']['field_video_type_tid']['field'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['value'] = array(
    2726 => '2726',
  );
  $handler->display->display_options['filters']['field_video_type_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_video_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_video_type_tid']['vocabulary'] = 'video_type';
  $handler->display->display_options['path'] = 'napo-s-film-episodes';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['napo_s_film_episodes'] = array(
    t('Master'),
    t('Napo\'s film episodes'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<span class="glyphicon glyphicon-play-circle"></span>'),
    t('All'),
    t('Page'),
    t('<h3>[title_field]</h3>
[field_publication_date]
<div class="episode-list-details-container">
<div class="tags">[field_combined_tags]</div>
<div class="buttons">[download_video][path]</div>
</div>'),
    t('Block'),
  );
  $export['napo_s_film_episodes'] = $view;

  $view = new view();
  $view->name = 'napos_films';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Napo\'s films';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '7';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
  );
  /* Field: Napo film: Download video */
  $handler->display->display_options['fields']['download_video']['id'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['table'] = 'napo_film';
  $handler->display->display_options['fields']['download_video']['field'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['label'] = '';
  $handler->display->display_options['fields']['download_video']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Publication date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'napo_video' => 'napo_video',
  );
  /* Filter criterion: Content: Video Type (field_video_type) */
  $handler->display->display_options['filters']['field_video_type_tid']['id'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['table'] = 'field_data_field_video_type';
  $handler->display->display_options['filters']['field_video_type_tid']['field'] = 'field_video_type_tid';
  $handler->display->display_options['filters']['field_video_type_tid']['value'] = array(
    2727 => '2727',
  );
  $handler->display->display_options['filters']['field_video_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_video_type_tid']['vocabulary'] = 'video_type';

  /* Display: List view */
  $handler = $view->new_display('page', 'List view', 'page_list');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content Cart: Toggle (add/remove) cart checkbox */
  $handler->display->display_options['fields']['content_cart']['id'] = 'content_cart';
  $handler->display->display_options['fields']['content_cart']['table'] = 'node';
  $handler->display->display_options['fields']['content_cart']['field'] = 'content_cart';
  $handler->display->display_options['fields']['content_cart']['label'] = '';
  $handler->display->display_options['fields']['content_cart']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
  );
  /* Field: Napo film: Combined tags */
  $handler->display->display_options['fields']['combined_tags']['id'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['table'] = 'napo_film';
  $handler->display->display_options['fields']['combined_tags']['field'] = 'combined_tags';
  $handler->display->display_options['fields']['combined_tags']['label'] = '';
  $handler->display->display_options['fields']['combined_tags']['element_label_colon'] = FALSE;
  /* Field: Napo film: Download video */
  $handler->display->display_options['fields']['download_video']['id'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['table'] = 'napo_film';
  $handler->display->display_options['fields']['download_video']['field'] = 'download_video';
  $handler->display->display_options['fields']['download_video']['label'] = '';
  $handler->display->display_options['fields']['download_video']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path_1']['id'] = 'path_1';
  $handler->display->display_options['fields']['path_1']['table'] = 'node';
  $handler->display->display_options['fields']['path_1']['field'] = 'path';
  $handler->display->display_options['fields']['path_1']['label'] = '';
  $handler->display->display_options['fields']['path_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path_1']['alter']['text'] = '<span class="glyphicon glyphicon-play-circle"></span>';
  $handler->display->display_options['fields']['path_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['path_1']['alter']['path'] = '[path_1]';
  $handler->display->display_options['fields']['path_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path_1']['absolute'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = 'View scenes <span class="glyphicon glyphicon-circle-arrow-right"></span>';
  $handler->display->display_options['fields']['path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['path'] = '[path]/view-episodes';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  $handler->display->display_options['path'] = 'napos-films/filmss';

  /* Display: Gallery view */
  $handler = $view->new_display('mode', 'Gallery view', 'mode_gallery');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'page_list' => 'page_list',
    'page_episodes' => 0,
  );
  $handler->display->display_options['mode_id'] = 'gallery';
  $handler->display->display_options['mode_name'] = 'Gallery view';
  $translatables['napos_films'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('List view'),
    t('<span class="glyphicon glyphicon-play-circle"></span>'),
    t('View scenes <span class="glyphicon glyphicon-circle-arrow-right"></span>'),
    t('Gallery view'),
  );
  $export['napos_films'] = $view;

  return $export;
}
