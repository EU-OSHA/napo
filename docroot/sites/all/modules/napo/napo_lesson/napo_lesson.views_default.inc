<?php
/**
 * @file
 * napo_lesson.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function napo_lesson_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'lessons';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Lessons';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Lessons';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
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
  /* Contextual filter: Content: Lesson Toolkit (field_lesson_toolkit) */
  $handler->display->display_options['arguments']['field_lesson_toolkit_target_id']['id'] = 'field_lesson_toolkit_target_id';
  $handler->display->display_options['arguments']['field_lesson_toolkit_target_id']['table'] = 'field_data_field_lesson_toolkit';
  $handler->display->display_options['arguments']['field_lesson_toolkit_target_id']['field'] = 'field_lesson_toolkit_target_id';
  $handler->display->display_options['arguments']['field_lesson_toolkit_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_lesson_toolkit_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_lesson_toolkit_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_lesson_toolkit_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_lesson_toolkit_target_id']['summary_options']['items_per_page'] = '25';
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
    'lesson' => 'lesson',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Related lessons */
  $handler = $view->new_display('block', 'Related lessons', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_lesson_toolkit_target_id']['id'] = 'field_lesson_toolkit_target_id';
  $handler->display->display_options['relationships']['field_lesson_toolkit_target_id']['table'] = 'field_data_field_lesson_toolkit';
  $handler->display->display_options['relationships']['field_lesson_toolkit_target_id']['field'] = 'field_lesson_toolkit_target_id';
  $handler->display->display_options['relationships']['field_lesson_toolkit_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_lesson_toolkit_node']['id'] = 'reverse_field_lesson_toolkit_node';
  $handler->display->display_options['relationships']['reverse_field_lesson_toolkit_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_lesson_toolkit_node']['field'] = 'reverse_field_lesson_toolkit_node';
  $handler->display->display_options['relationships']['reverse_field_lesson_toolkit_node']['relationship'] = 'field_lesson_toolkit_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_lesson_toolkit_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'lesson' => 'lesson',
  );
  $translatables['lessons'] = array(
    t('Master'),
    t('Lessons'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Block'),
    t('Related lessons'),
    t('Content entity referenced from field_lesson_toolkit'),
    t('Content referencing Content from field_lesson_toolkit'),
  );
  $export['lessons'] = $view;

  $view = new view();
  $view->name = 'napo_target_ages';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Napo Target Ages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Napo target ages';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 1;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Taxonomy term: Description */
  $handler->display->display_options['fields']['description_field']['id'] = 'description_field';
  $handler->display->display_options['fields']['description_field']['table'] = 'field_data_description_field';
  $handler->display->display_options['fields']['description_field']['field'] = 'description_field';
  $handler->display->display_options['fields']['description_field']['label'] = '';
  $handler->display->display_options['fields']['description_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description_field']['link_to_entity'] = 0;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'target_ages' => 'target_ages',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['napo_target_ages'] = array(
    t('Master'),
    t('Napo target ages'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
  );
  $export['napo_target_ages'] = $view;

  return $export;
}
