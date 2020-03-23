<?php
/**
 * @file
 * napo_msd.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function napo_msd_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'conversation_started';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conversation started';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['css_class'] = 'related-lessons-item';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'related-lessons-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_msds_video_target_id']['id'] = 'field_msds_video_target_id';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['table'] = 'field_data_field_msds_video';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['field'] = 'field_msds_video_target_id';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['label'] = 'MSDs Video';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['required'] = TRUE;
  /* Field: Content: Conversation starters cover */
  $handler->display->display_options['fields']['field_conversation_starters_cove']['id'] = 'field_conversation_starters_cove';
  $handler->display->display_options['fields']['field_conversation_starters_cove']['table'] = 'field_data_field_conversation_starters_cove';
  $handler->display->display_options['fields']['field_conversation_starters_cove']['field'] = 'field_conversation_starters_cove';
  $handler->display->display_options['fields']['field_conversation_starters_cove']['label'] = '';
  $handler->display->display_options['fields']['field_conversation_starters_cove']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_conversation_starters_cove']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_conversation_starters_cove']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_conversation_starters_cove']['settings'] = array(
    'image_style' => 'starters_cover',
    'image_link' => '',
  );
  /* Field: Content: Conversation starters */
  $handler->display->display_options['fields']['field_conversation_started']['id'] = 'field_conversation_started';
  $handler->display->display_options['fields']['field_conversation_started']['table'] = 'field_data_field_conversation_started';
  $handler->display->display_options['fields']['field_conversation_started']['field'] = 'field_conversation_started';
  $handler->display->display_options['fields']['field_conversation_started']['label'] = '';
  $handler->display->display_options['fields']['field_conversation_started']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_conversation_started']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_conversation_started']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_conversation_started']['type'] = 'msd_starter';
  $handler->display->display_options['fields']['field_conversation_started']['settings'] = array(
    'title_style' => '_none',
    'title_link' => '',
    'title_class' => '',
    'napo_common_title_prefix' => '',
    'title_archived_label' => 0,
    'napo_film_title_include_type' => 0,
    'napo_film_title_include_episode_count' => 0,
    'napo_film_title_link_episode_popup' => 0,
    'napo_film_title_link_with_film' => 0,
    'napo_film_title_include_icon' => 0,
    'napo_film_title_link_with_film_value' => '',
  );
  $handler->display->display_options['fields']['field_conversation_started']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_conversation_started']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="__link__" target="_blank">[field_conversation_starters_cove]</a>
<div class="related-item-content">
<h3>[field_conversation_started]</h3>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'msds_activities' => 'msds_activities',
  );
  /* Filter criterion: Content: Conversation starters (field_conversation_started:fid) */
  $handler->display->display_options['filters']['field_conversation_started_fid']['id'] = 'field_conversation_started_fid';
  $handler->display->display_options['filters']['field_conversation_started_fid']['table'] = 'field_data_field_conversation_started';
  $handler->display->display_options['filters']['field_conversation_started_fid']['field'] = 'field_conversation_started_fid';
  $handler->display->display_options['filters']['field_conversation_started_fid']['operator'] = 'not empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['conversation_started'] = array(
    t('Master'),
    t('<none>'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('MSDs Video'),
    t('<a href="__link__" target="_blank">[field_conversation_starters_cove]</a>
<div class="related-item-content">
<h3>[field_conversation_started]</h3>
</div>'),
    t('All'),
    t('Block'),
  );
  $export['conversation_started'] = $view;

  $view = new view();
  $view->name = 'msd_related_resources';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'MSD Related resources';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related resources';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'related-lessons-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resources_related_target_id']['id'] = 'field_resources_related_target_id';
  $handler->display->display_options['relationships']['field_resources_related_target_id']['table'] = 'field_data_field_resources_related';
  $handler->display->display_options['relationships']['field_resources_related_target_id']['field'] = 'field_resources_related_target_id';
  $handler->display->display_options['relationships']['field_resources_related_target_id']['label'] = 'Related resources';
  $handler->display->display_options['relationships']['field_resources_related_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_msds_video_target_id']['id'] = 'field_msds_video_target_id';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['table'] = 'field_data_field_msds_video';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['field'] = 'field_msds_video_target_id';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['relationship'] = 'field_resources_related_target_id';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['label'] = 'MSDs Video';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_msds_video_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_resources_related_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['relationship'] = 'field_resources_related_target_id';
  $handler->display->display_options['fields']['field_tags']['label'] = 'Keyword';
  $handler->display->display_options['fields']['field_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_image] 
<div class="related-item-content">
<h3>[title_1]</h3>
<p class="keyword-list">
<span class="keyword-label"><label>Keyword:</label></span><span class="keyword-tag">[field_tags]</span>
</p>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'msds_activities' => 'msds_activities',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_msds_video_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'lessons_grid_image',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_resources_related_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['relationship'] = 'field_resources_related_target_id';
  $handler->display->display_options['fields']['field_tags']['label'] = 'Keyword';
  $handler->display->display_options['fields']['field_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="__link__">[field_image]</a>
<div class="related-item-content">
<h3>[title_1]</h3>
<p class="keyword-list">
<span class="keyword-label"><label>Keyword:</label></span><span class="keyword-tag">[field_tags]</span>
</p>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_resources_related_target_id';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'MSD related resources';
  $translatables['msd_related_resources'] = array(
    t('Master'),
    t('Related resources'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('MSDs Video'),
    t('Keyword'),
    t('[field_image] 
<div class="related-item-content">
<h3>[title_1]</h3>
<p class="keyword-list">
<span class="keyword-label"><label>Keyword:</label></span><span class="keyword-tag">[field_tags]</span>
</p>
</div>'),
    t('All'),
    t('Block'),
    t('<a href="__link__">[field_image]</a>
<div class="related-item-content">
<h3>[title_1]</h3>
<p class="keyword-list">
<span class="keyword-label"><label>Keyword:</label></span><span class="keyword-tag">[field_tags]</span>
</p>
</div>'),
    t('MSD related resources'),
  );
  $export['msd_related_resources'] = $view;

  $view = new view();
  $view->name = 'napo_workplaces';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'napo-workplaces';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Napo in the workplace';
  $handler->display->display_options['css_class'] = 'lessons--items--grid';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'lessons-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total';
  /* Footer: Entity: Rendered entity */
  $handler->display->display_options['footer']['entity']['id'] = 'entity';
  $handler->display->display_options['footer']['entity']['table'] = 'entity__global';
  $handler->display->display_options['footer']['entity']['field'] = 'entity';
  $handler->display->display_options['footer']['entity']['entity_id'] = '430';
  $handler->display->display_options['footer']['entity']['view_mode'] = 'teaser';
  $handler->display->display_options['footer']['entity']['bypass_access'] = 0;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_msds_video_target_id']['id'] = 'field_msds_video_target_id';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['table'] = 'field_data_field_msds_video';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['field'] = 'field_msds_video_target_id';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['label'] = 'MSDs video';
  $handler->display->display_options['relationships']['field_msds_video_target_id']['required'] = TRUE;
  /* Relationship: Field: Tags (field_tags) */
  $handler->display->display_options['relationships']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['label'] = 'Tags';
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
    'title_link' => '',
    'title_class' => '',
    'napo_common_title_prefix' => '',
    'title_archived_label' => 0,
    'napo_film_title_include_type' => 0,
    'napo_film_title_include_episode_count' => 0,
    'napo_film_title_link_episode_popup' => 0,
    'napo_film_title_link_with_film' => 0,
    'napo_film_title_include_icon' => 0,
    'napo_film_title_link_with_film_value' => '!episode from the film !film',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field_1']['id'] = 'title_field_1';
  $handler->display->display_options['fields']['title_field_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_1']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field_1']['label'] = '';
  $handler->display->display_options['fields']['title_field_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field_1']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field_1']['link_to_entity'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '15',
    'trim_type' => 'words',
    'trim_suffix' => '',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 'text',
    ),
    'trim_preserve_tags' => '',
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_msds_video_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'lessons_grid_image',
    'image_link' => '',
  );
  /* Field: Title and tags */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Title and tags';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="lessons-item-content">
<h3>[title_field]</h3>
<p class="keyword-list">
__Tags__
</p>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Activities */
  $handler->display->display_options['fields']['field_activities']['id'] = 'field_activities';
  $handler->display->display_options['fields']['field_activities']['table'] = 'field_data_field_activities';
  $handler->display->display_options['fields']['field_activities']['field'] = 'field_activities';
  $handler->display->display_options['fields']['field_activities']['label'] = '';
  $handler->display->display_options['fields']['field_activities']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_activities']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activities']['type'] = 'text_plain';
  /* Field: Content: Assessment */
  $handler->display->display_options['fields']['field_assessment']['id'] = 'field_assessment';
  $handler->display->display_options['fields']['field_assessment']['table'] = 'field_data_field_assessment';
  $handler->display->display_options['fields']['field_assessment']['field'] = 'field_assessment';
  $handler->display->display_options['fields']['field_assessment']['label'] = '';
  $handler->display->display_options['fields']['field_assessment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_assessment']['element_label_colon'] = FALSE;
  /* Field: Content: Concluding questions */
  $handler->display->display_options['fields']['field_concluding_questions']['id'] = 'field_concluding_questions';
  $handler->display->display_options['fields']['field_concluding_questions']['table'] = 'field_data_field_concluding_questions';
  $handler->display->display_options['fields']['field_concluding_questions']['field'] = 'field_concluding_questions';
  $handler->display->display_options['fields']['field_concluding_questions']['label'] = '';
  $handler->display->display_options['fields']['field_concluding_questions']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_concluding_questions']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_concluding_questions']['type'] = 'text_plain';
  /* Field: Content: Introductory text */
  $handler->display->display_options['fields']['field_introductory_text']['id'] = 'field_introductory_text';
  $handler->display->display_options['fields']['field_introductory_text']['table'] = 'field_data_field_introductory_text';
  $handler->display->display_options['fields']['field_introductory_text']['field'] = 'field_introductory_text';
  $handler->display->display_options['fields']['field_introductory_text']['label'] = '';
  $handler->display->display_options['fields']['field_introductory_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_introductory_text']['element_label_colon'] = FALSE;
  /* Field: Content: Learning Objectives */
  $handler->display->display_options['fields']['field_learning_objectives']['id'] = 'field_learning_objectives';
  $handler->display->display_options['fields']['field_learning_objectives']['table'] = 'field_data_field_learning_objectives';
  $handler->display->display_options['fields']['field_learning_objectives']['field'] = 'field_learning_objectives';
  $handler->display->display_options['fields']['field_learning_objectives']['label'] = '';
  $handler->display->display_options['fields']['field_learning_objectives']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_learning_objectives']['element_label_colon'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'msds_activities' => 'msds_activities',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'allwords';
  $handler->display->display_options['filters']['combine']['group'] = 2;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['combine']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['combine']['expose']['autocomplete_min_chars'] = '3';
  $handler->display->display_options['filters']['combine']['expose']['autocomplete_raw_suggestion'] = 0;
  $handler->display->display_options['filters']['combine']['expose']['autocomplete_raw_dropdown'] = 0;
  $handler->display->display_options['filters']['combine']['expose']['autocomplete_dependent'] = 1;
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title_field_1' => 'title_field_1',
    'field_activities' => 'field_activities',
    'field_assessment' => 'field_assessment',
    'field_concluding_questions' => 'field_concluding_questions',
    'field_introductory_text' => 'field_introductory_text',
    'field_learning_objectives' => 'field_learning_objectives',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Entity: Rendered entity */
  $handler->display->display_options['footer']['entity']['id'] = 'entity';
  $handler->display->display_options['footer']['entity']['table'] = 'entity__global';
  $handler->display->display_options['footer']['entity']['field'] = 'entity';
  $handler->display->display_options['footer']['entity']['entity_id'] = '430';
  $handler->display->display_options['footer']['entity']['view_mode'] = 'teaser';
  $handler->display->display_options['footer']['entity']['bypass_access'] = 0;
  $handler->display->display_options['path'] = 'learning-with-napo/napo-in-the-workplace';
  $translatables['napo_workplaces'] = array(
    t('Master'),
    t('Napo in the workplace'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('@total'),
    t('No results'),
    t('MSDs video'),
    t('Tags'),
    t('<div class="lessons-item-content">
<h3>[title_field]</h3>
<p class="keyword-list">
__Tags__
</p>
</div>'),
    t('Search'),
    t('Page'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
  );
  $export['napo_workplaces'] = $view;

  return $export;
}