<?php
/**
 * @file
 * osha_tmgmt.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_tmgmt_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'content_validators_group';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entity_collection_collections';
  $view->human_name = 'Content validators group';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content validators groups';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage content in translators group entity collections';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a class="button" id="add-translators-group" href="/admin/structure/entity_collection/add/translators_group">Create new group </a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Entity Collection: Rendered Entity Collection */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_entity_collection';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;

  /* Display: List of content validators groups */
  $handler = $view->new_display('page', 'List of content validators groups', 'content_validators_group_page');
  $handler->display->display_options['path'] = 'admin/tmgmt/content-validators';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Content validators groups';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['content_validators_group'] = array(
    t('Master'),
    t('Content validators groups'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a class="button" id="add-translators-group" href="/admin/structure/entity_collection/add/translators_group">Create new group </a>'),
    t('List of content validators groups'),
  );
  $export['content_validators_group'] = $view;

  $view = new view();
  $view->name = 'osha_job_overview_job_items';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'tmgmt_job_item';
  $view->human_name = 'Osha Job Overview Job Items';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Osha Job Overview Job Items';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field-revision_id' => 'title_field-revision_id',
    'label' => 'label',
    'source_language' => 'source_language',
    'target_language' => 'target_language',
    'page_count' => 'page_count',
    'character_count' => 'character_count',
    'type' => 'type',
    'section' => 'section',
    'field_activity-revision_id' => 'field_activity-revision_id',
    'state' => 'state',
    'changed' => 'changed',
    'name' => 'name',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'source_language' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'target_language' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'page_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'character_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'section' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No job items found for your search.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Translation Management Job Item: Content */
  $handler->display->display_options['relationships']['job_item_to_node_revision']['id'] = 'job_item_to_node_revision';
  $handler->display->display_options['relationships']['job_item_to_node_revision']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['relationships']['job_item_to_node_revision']['field'] = 'job_item_to_node_revision';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'job_item_to_node_revision';
  /* Relationship: Translation Management Job Item: Content */
  $handler->display->display_options['relationships']['job_item_to_node']['id'] = 'job_item_to_node';
  $handler->display->display_options['relationships']['job_item_to_node']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['relationships']['job_item_to_node']['field'] = 'job_item_to_node';
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['relationship'] = 'job_item_to_node_revision';
  $handler->display->display_options['fields']['title_field-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field-revision_id']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Translation Management Job Item: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['empty'] = '[title_field-revision_id]';
  /* Field: Translation Management Job Item: Source language */
  $handler->display->display_options['fields']['source_language']['id'] = 'source_language';
  $handler->display->display_options['fields']['source_language']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['source_language']['field'] = 'source_language';
  /* Field: Translation Management Job Item: Job Item Target Language */
  $handler->display->display_options['fields']['target_language']['id'] = 'target_language';
  $handler->display->display_options['fields']['target_language']['table'] = 'views_entity_tmgmt_job_item';
  $handler->display->display_options['fields']['target_language']['field'] = 'target_language';
  $handler->display->display_options['fields']['target_language']['label'] = 'Target Language';
  $handler->display->display_options['fields']['target_language']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['target_language']['format_name'] = 1;
  /* Field: Translation Management Job Item: Page count */
  $handler->display->display_options['fields']['page_count']['id'] = 'page_count';
  $handler->display->display_options['fields']['page_count']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['page_count']['field'] = 'page_count';
  $handler->display->display_options['fields']['page_count']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['page_count']['precision'] = '2';
  $handler->display->display_options['fields']['page_count']['decimal'] = ',';
  $handler->display->display_options['fields']['page_count']['separator'] = '';
  /* Field: Translation Management Job Item: Character count */
  $handler->display->display_options['fields']['character_count']['id'] = 'character_count';
  $handler->display->display_options['fields']['character_count']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['character_count']['field'] = 'character_count';
  /* Field: Translation Management Job Item: Type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  /* Field: Translation Management Job Item: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Translation Management Job Item: Changed date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'osha_day_only';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'year';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Translation Management Job Item: Operations */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  /* Contextual filter: Translation Management Job Item: Tjid */
  $handler->display->display_options['arguments']['tjid']['id'] = 'tjid';
  $handler->display->display_options['arguments']['tjid']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['arguments']['tjid']['field'] = 'tjid';
  $handler->display->display_options['arguments']['tjid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tjid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tjid']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['tjid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tjid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tjid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Translation Management Job Item: State */
  $handler->display->display_options['arguments']['state']['id'] = 'state';
  $handler->display->display_options['arguments']['state']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['arguments']['state']['field'] = 'state';
  $handler->display->display_options['arguments']['state']['exception']['value'] = 'any';
  $handler->display->display_options['arguments']['state']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['state']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['state']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['state']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['state']['specify_validation'] = TRUE;
  /* Contextual filter: Translation Management Job Item: Target language */
  $handler->display->display_options['arguments']['target_language']['id'] = 'target_language';
  $handler->display->display_options['arguments']['target_language']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['arguments']['target_language']['field'] = 'target_language';
  $handler->display->display_options['arguments']['target_language']['exception']['value'] = 'any';
  $handler->display->display_options['arguments']['target_language']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['target_language']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['target_language']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['target_language']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['target_language']['limit'] = '0';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'job_job_items');
  $handler->display->display_options['path'] = 'admin/tmgmt/job-items';
  $translatables['osha_job_overview_job_items'] = array(
    t('Master'),
    t('Osha Job Overview Job Items'),
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
    t('No results'),
    t('No job items found for your search.'),
    t('Content Revision'),
    t('revision user'),
    t('Content'),
    t('Title'),
    t('Label'),
    t('[title_field-revision_id]'),
    t('Source language'),
    t('Target Language'),
    t('Page count'),
    t(','),
    t('Character count'),
    t('Type'),
    t('State'),
    t('Changed date'),
    t('Name'),
    t('Operations'),
    t('All'),
    t('Page'),
  );

  $view = new view();
  $view->name = 'osha_needs_translation_workbench';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'tmgmt_job';
  $view->human_name = 'Osha Needs Translation Workbench';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Osha Needs Translation Workbench';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view untranslated jobs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'label' => 'label',
    'priority' => 'priority',
    'state' => 'state',
    'changed' => 'changed',
    'url' => 'url',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'priority' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'url' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Translation Management Job: Job items */
  $handler->display->display_options['relationships']['job_item']['id'] = 'job_item';
  $handler->display->display_options['relationships']['job_item']['table'] = 'tmgmt_job';
  $handler->display->display_options['relationships']['job_item']['field'] = 'job_item';
  $handler->display->display_options['relationships']['job_item']['required'] = TRUE;
  /* Field: Translation Management Job: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  /* Field: Translation Management Job: Priority */
  $handler->display->display_options['fields']['priority']['id'] = 'priority';
  $handler->display->display_options['fields']['priority']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['priority']['field'] = 'priority';
  /* Field: Translation Management Job: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Translation Management Job: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  /* Field: Translation Management Job: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_tmgmt_job';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['url']['link_to_entity'] = 1;
  /* Sort criterion: Translation Management Job: Changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'tmgmt_job';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['granularity'] = 'minute';
  /* Filter criterion: Translation Management Job Item: Count_pending */
  $handler->display->display_options['filters']['count_pending']['id'] = 'count_pending';
  $handler->display->display_options['filters']['count_pending']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['filters']['count_pending']['field'] = 'count_pending';
  $handler->display->display_options['filters']['count_pending']['relationship'] = 'job_item';
  $handler->display->display_options['filters']['count_pending']['operator'] = '>';
  $handler->display->display_options['filters']['count_pending']['value']['value'] = '0';
  /* Filter criterion: Translation Management Job Item: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'job_item';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
    4 => '4',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/workbench/needs-translation-job';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Needs Translation';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['osha_needs_translation_workbench'] = array(
    t('Master'),
    t('Osha Needs Translation Workbench'),
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
    t('Job items'),
    t('Label'),
    t('Priority'),
    t('State'),
    t('Changed'),
    t('URL'),
    t('View'),
    t('Page'),
  );
  $export['osha_needs_translation_workbench'] = $view;

  $view = new view();
  $view->name = 'osha_translation_job_overview';
  $view->description = 'Gives a bulk operation overview of translation jobs in the system.';
  $view->tag = 'Translation Management';
  $view->base_table = 'tmgmt_job';
  $view->human_name = 'OSHA Translation Job Overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Job overview';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'tmgmt_views_job_access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'label' => 'label',
    'state' => 'state',
    'priority' => 'priority',
    'page_count' => 'page_count',
    'character_count' => 'character_count',
    'progress' => 'progress',
    'changed' => 'changed',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'priority' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'page_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'character_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'progress' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There are no translation jobs that match the specified filter criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Translator */
  $handler->display->display_options['relationships']['translator']['id'] = 'translator';
  $handler->display->display_options['relationships']['translator']['table'] = 'tmgmt_job';
  $handler->display->display_options['relationships']['translator']['field'] = 'translator';
  $handler->display->display_options['relationships']['translator']['ui_name'] = 'Translator';
  $handler->display->display_options['relationships']['translator']['label'] = 'Translator';
  /* Field: Bulk operations */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['ui_name'] = 'Bulk operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_tmgmt_job_accept_translation' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_tmgmt_job_abort_translation' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete Job',
    ),
    'rules_component::rules_tmgmt_job_delete' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['ui_name'] = 'Label';
  /* Field: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['ui_name'] = 'State';
  /* Field: Translation Management Job: Priority */
  $handler->display->display_options['fields']['priority']['id'] = 'priority';
  $handler->display->display_options['fields']['priority']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['priority']['field'] = 'priority';
  /* Field: Translation Management Job: Page count */
  $handler->display->display_options['fields']['page_count']['id'] = 'page_count';
  $handler->display->display_options['fields']['page_count']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['page_count']['field'] = 'page_count';
  $handler->display->display_options['fields']['page_count']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['page_count']['precision'] = '2';
  $handler->display->display_options['fields']['page_count']['decimal'] = ',';
  $handler->display->display_options['fields']['page_count']['separator'] = '';
  /* Field: Translation Management Job: Character count */
  $handler->display->display_options['fields']['character_count']['id'] = 'character_count';
  $handler->display->display_options['fields']['character_count']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['character_count']['field'] = 'character_count';
  /* Field: Translation Management Job: Progress items */
  $handler->display->display_options['fields']['progress_job_items']['id'] = 'progress_job_items';
  $handler->display->display_options['fields']['progress_job_items']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['progress_job_items']['field'] = 'progress_job_items';
  $handler->display->display_options['fields']['progress_job_items']['label'] = 'Progress';
  $handler->display->display_options['fields']['progress_job_items']['element_label_colon'] = FALSE;
  /* Field: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['ui_name'] = 'Changed';
  /* Field: Translation Management Job: Has File uploaded */
  $handler->display->display_options['fields']['has_file_uploaded']['id'] = 'has_file_uploaded';
  $handler->display->display_options['fields']['has_file_uploaded']['table'] = 'views_entity_tmgmt_job';
  $handler->display->display_options['fields']['has_file_uploaded']['field'] = 'has_file_uploaded';
  $handler->display->display_options['fields']['has_file_uploaded']['label'] = 'File uploaded';
  $handler->display->display_options['fields']['has_file_uploaded']['not'] = 0;
  $handler->display->display_options['fields']['has_file_uploaded']['link_to_entity'] = 0;
  /* Field: Translation Management Job: Has File Sent to CDT */
  $handler->display->display_options['fields']['file_sent']['id'] = 'file_sent';
  $handler->display->display_options['fields']['file_sent']['table'] = 'views_entity_tmgmt_job';
  $handler->display->display_options['fields']['file_sent']['field'] = 'file_sent';
  $handler->display->display_options['fields']['file_sent']['label'] = 'File Sent to CDT';
  $handler->display->display_options['fields']['file_sent']['not'] = 0;
  $handler->display->display_options['fields']['file_sent']['link_to_entity'] = 0;
  /* Field: Operations */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['ui_name'] = 'Operations';
  /* Sort criterion: Changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'tmgmt_job';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['ui_name'] = 'Changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Label';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
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
    11 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'label' => 'label',
  );
  /* Filter criterion: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'tmgmt_job';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['ui_name'] = 'State';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  /* Filter criterion: Translation Management Job: Priority */
  $handler->display->display_options['filters']['priority']['id'] = 'priority';
  $handler->display->display_options['filters']['priority']['table'] = 'tmgmt_job';
  $handler->display->display_options['filters']['priority']['field'] = 'priority';
  $handler->display->display_options['filters']['priority']['value'] = array(
    2 => '2',
    1 => '1',
    0 => '0',
  );
  $handler->display->display_options['filters']['priority']['exposed'] = TRUE;
  $handler->display->display_options['filters']['priority']['expose']['operator_id'] = 'priority_op';
  $handler->display->display_options['filters']['priority']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['priority']['expose']['operator'] = 'priority_op';
  $handler->display->display_options['filters']['priority']['expose']['identifier'] = 'priority';
  $handler->display->display_options['filters']['priority']['expose']['remember_roles'] = array(
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
    11 => 0,
  );
  $handler->display->display_options['filters']['priority']['expose']['reduce'] = TRUE;
  /* Filter criterion: Translation Management Job: Has File uploaded */
  $handler->display->display_options['filters']['has_file_uploaded']['id'] = 'has_file_uploaded';
  $handler->display->display_options['filters']['has_file_uploaded']['table'] = 'tmgmt_job';
  $handler->display->display_options['filters']['has_file_uploaded']['field'] = 'has_file_uploaded';
  $handler->display->display_options['filters']['has_file_uploaded']['value'] = 'All';
  $handler->display->display_options['filters']['has_file_uploaded']['exposed'] = TRUE;
  $handler->display->display_options['filters']['has_file_uploaded']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['has_file_uploaded']['expose']['label'] = 'File Uploaded';
  $handler->display->display_options['filters']['has_file_uploaded']['expose']['operator'] = 'has_file_uploaded_op';
  $handler->display->display_options['filters']['has_file_uploaded']['expose']['identifier'] = 'has_file_uploaded';
  $handler->display->display_options['filters']['has_file_uploaded']['expose']['remember_roles'] = array(
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
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Translation Management Job: Has File Sent to CDT */
  $handler->display->display_options['filters']['file_sent']['id'] = 'file_sent';
  $handler->display->display_options['filters']['file_sent']['table'] = 'tmgmt_job';
  $handler->display->display_options['filters']['file_sent']['field'] = 'file_sent';
  $handler->display->display_options['filters']['file_sent']['value'] = 'All';
  $handler->display->display_options['filters']['file_sent']['exposed'] = TRUE;
  $handler->display->display_options['filters']['file_sent']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['file_sent']['expose']['label'] = 'File Sent to CDT';
  $handler->display->display_options['filters']['file_sent']['expose']['operator'] = 'file_sent_op';
  $handler->display->display_options['filters']['file_sent']['expose']['identifier'] = 'file_sent';
  $handler->display->display_options['filters']['file_sent']['expose']['remember_roles'] = array(
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
    11 => 0,
    12 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/tmgmt/overview';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Jobs';
  $handler->display->display_options['menu']['weight'] = '-1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Translation';
  $handler->display->display_options['tab_options']['description'] = 'Translation overview';
  $handler->display->display_options['tab_options']['weight'] = -9;
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['osha_translation_job_overview'] = array(
    t('Master'),
    t('Job overview'),
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
    t('There are no translation jobs that match the specified filter criteria.'),
    t('Translator'),
    t('- Choose an operation -'),
    t('Delete Job'),
    t('Label'),
    t('State'),
    t('Priority'),
    t('Page count'),
    t(','),
    t('Character count'),
    t('.'),
    t('Progress'),
    t('Changed'),
    t('File uploaded'),
    t('File Sent to CDT'),
    t('Operations'),
    t('File Uploaded'),
    t('Page'),
  );
  $export['osha_translation_job_overview'] = $view;

  $view = new view();
  $view->name = 'osha_translation_workbench';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'tmgmt_job_item';
  $view->human_name = 'Osha Translation Workbench';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'On Translation';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view on translation content list';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field-revision_id' => 'title_field-revision_id',
    'tjiid' => 'tjiid',
    'label' => 'label',
    'item_type' => 'item_type',
    'source_language' => 'source_language',
    'target_language' => 'target_language',
    'url' => 'url',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tjiid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'item_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'source_language' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'target_language' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'url' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Translation Management Job Item: Content */
  $handler->display->display_options['relationships']['job_item_to_node_revision']['id'] = 'job_item_to_node_revision';
  $handler->display->display_options['relationships']['job_item_to_node_revision']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['relationships']['job_item_to_node_revision']['field'] = 'job_item_to_node_revision';
  /* Relationship: Translation Management Job Item: Tjid */
  $handler->display->display_options['relationships']['tjid']['id'] = 'tjid';
  $handler->display->display_options['relationships']['tjid']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['relationships']['tjid']['field'] = 'tjid';
  $handler->display->display_options['relationships']['tjid']['required'] = TRUE;
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['relationship'] = 'job_item_to_node_revision';
  $handler->display->display_options['fields']['title_field-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field-revision_id']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Translation Management Job Item: Translation management job item ID */
  $handler->display->display_options['fields']['tjiid']['id'] = 'tjiid';
  $handler->display->display_options['fields']['tjiid']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['tjiid']['field'] = 'tjiid';
  $handler->display->display_options['fields']['tjiid']['label'] = 'Job Item ID';
  $handler->display->display_options['fields']['tjiid']['exclude'] = TRUE;
  /* Field: Translation Management Job Item: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['empty'] = '[title_field-revision_id]';
  /* Field: Translation Management Job Item: Item type */
  $handler->display->display_options['fields']['item_type']['id'] = 'item_type';
  $handler->display->display_options['fields']['item_type']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['item_type']['field'] = 'item_type';
  /* Field: Translation Management Job Item: Source language */
  $handler->display->display_options['fields']['source_language']['id'] = 'source_language';
  $handler->display->display_options['fields']['source_language']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['source_language']['field'] = 'source_language';
  /* Field: Translation Management Job Item: Target language */
  $handler->display->display_options['fields']['target_language']['id'] = 'target_language';
  $handler->display->display_options['fields']['target_language']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['target_language']['field'] = 'target_language';
  /* Field: Translation Management Job: Has File uploaded */
  $handler->display->display_options['fields']['has_file_uploaded']['id'] = 'has_file_uploaded';
  $handler->display->display_options['fields']['has_file_uploaded']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['has_file_uploaded']['field'] = 'has_file_uploaded';
  $handler->display->display_options['fields']['has_file_uploaded']['relationship'] = 'tjid';
  $handler->display->display_options['fields']['has_file_uploaded']['label'] = 'File uploaded';
  $handler->display->display_options['fields']['has_file_uploaded']['not'] = 0;
  /* Field: Translation Management Job Item: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_tmgmt_job_item';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 1;
  /* Sort criterion: Translation Management Job Item: Translation management job item ID */
  $handler->display->display_options['sorts']['tjiid']['id'] = 'tjiid';
  $handler->display->display_options['sorts']['tjiid']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['sorts']['tjiid']['field'] = 'tjiid';
  $handler->display->display_options['sorts']['tjiid']['order'] = 'DESC';
  /* Filter criterion: Translation Management Job Item: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    2 => '2',
    6 => '6',
  );

  /* Display: On Translation */
  $handler = $view->new_display('page', 'On Translation', 'page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Translation Management Job Item: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Translation Management Job: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'tmgmt_job';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['relationship'] = 'tjid';
  $handler->display->display_options['filters']['state_1']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'admin/workbench/on-translation';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'On Translation';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Content Validation */
  $handler = $view->new_display('page', 'Content Validation', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Needs Content Validation';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view needs content validation list';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Translation Management Job Item: Translation Validators */
  $handler->display->display_options['relationships']['osha_tmgmt_job_trans_validators']['id'] = 'osha_tmgmt_job_trans_validators';
  $handler->display->display_options['relationships']['osha_tmgmt_job_trans_validators']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['relationships']['osha_tmgmt_job_trans_validators']['field'] = 'osha_tmgmt_job_trans_validators';
  $handler->display->display_options['relationships']['osha_tmgmt_job_trans_validators']['required'] = TRUE;
  /* Relationship: Translation Management Job Item: Content */
  $handler->display->display_options['relationships']['job_item_to_node_revision']['id'] = 'job_item_to_node_revision';
  $handler->display->display_options['relationships']['job_item_to_node_revision']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['relationships']['job_item_to_node_revision']['field'] = 'job_item_to_node_revision';
  /* Relationship: Translation Management Job Item: Tjid */
  $handler->display->display_options['relationships']['tjid']['id'] = 'tjid';
  $handler->display->display_options['relationships']['tjid']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['relationships']['tjid']['field'] = 'tjid';
  $handler->display->display_options['relationships']['tjid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Translation Validators: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'osha_tmgmt_job_trans_validators';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['relationship'] = 'osha_tmgmt_job_trans_validators';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Translation Management Job Item: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    5 => '5',
  );
  /* Filter criterion: Translation Validators: Next */
  $handler->display->display_options['filters']['next']['id'] = 'next';
  $handler->display->display_options['filters']['next']['table'] = 'osha_tmgmt_job_trans_validators';
  $handler->display->display_options['filters']['next']['field'] = 'next';
  $handler->display->display_options['filters']['next']['relationship'] = 'osha_tmgmt_job_trans_validators';
  $handler->display->display_options['filters']['next']['value']['value'] = '1';
  /* Filter criterion: Translation Validators: Deleted vote */
  $handler->display->display_options['filters']['deleted']['id'] = 'deleted';
  $handler->display->display_options['filters']['deleted']['table'] = 'osha_tmgmt_job_trans_validators';
  $handler->display->display_options['filters']['deleted']['field'] = 'deleted';
  $handler->display->display_options['filters']['deleted']['relationship'] = 'osha_tmgmt_job_trans_validators';
  $handler->display->display_options['filters']['deleted']['value']['value'] = '0';
  /* Filter criterion: Translation Management Job: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'tmgmt_job';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['relationship'] = 'tjid';
  $handler->display->display_options['filters']['state_1']['value'] = array(
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['path'] = 'admin/workbench/needs-content-validation';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Needs Content Validation';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Needs Review TM */
  $handler = $view->new_display('page', 'Needs Review TM', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Needs Review TM';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create translation jobs';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Translation Management Job Item: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    2 => '2',
    6 => '6',
  );
  /* Filter criterion: Translation Management Job: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'tmgmt_job';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['relationship'] = 'tjid';
  $handler->display->display_options['filters']['state_1']['value'] = array(
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['path'] = 'admin/workbench/needs-review-tm';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Needs Review TM';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Needs Review PM */
  $handler = $view->new_display('page', 'Needs Review PM', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Translations Needs Review PM';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'accept job item translation';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Translation Management Job Item: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    7 => '7',
  );
  /* Filter criterion: Translation Management Job: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'tmgmt_job';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['relationship'] = 'tjid';
  $handler->display->display_options['filters']['state_1']['value'] = array(
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['path'] = 'admin/workbench/translation-ready-to-publish';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Translations Needs Review PM';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Translation Overview */
  $handler = $view->new_display('page', 'Translation Overview', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Translation Overview';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create translation jobs';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Translation Management Job Item: Tjid */
  $handler->display->display_options['relationships']['tjid']['id'] = 'tjid';
  $handler->display->display_options['relationships']['tjid']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['relationships']['tjid']['field'] = 'tjid';
  $handler->display->display_options['relationships']['tjid']['required'] = TRUE;
  /* Relationship: Translation Management Job Item: Content */
  $handler->display->display_options['relationships']['job_item_to_node_revision']['id'] = 'job_item_to_node_revision';
  $handler->display->display_options['relationships']['job_item_to_node_revision']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['relationships']['job_item_to_node_revision']['field'] = 'job_item_to_node_revision';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['relationship'] = 'job_item_to_node_revision';
  $handler->display->display_options['fields']['title_field-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field-revision_id']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Translation Management Job Item: Translation management job item ID */
  $handler->display->display_options['fields']['tjiid']['id'] = 'tjiid';
  $handler->display->display_options['fields']['tjiid']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['tjiid']['field'] = 'tjiid';
  $handler->display->display_options['fields']['tjiid']['label'] = 'Job Item ID';
  $handler->display->display_options['fields']['tjiid']['exclude'] = TRUE;
  /* Field: Translation Management Job Item: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['empty'] = '[title_field-revision_id]';
  /* Field: Translation Management Job: Label */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'tmgmt_job';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['relationship'] = 'tjid';
  $handler->display->display_options['fields']['label_1']['label'] = 'Job';
  /* Field: Translation Management Job Item: Item type */
  $handler->display->display_options['fields']['item_type']['id'] = 'item_type';
  $handler->display->display_options['fields']['item_type']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['item_type']['field'] = 'item_type';
  /* Field: Translation Management Job Item: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Translation Management Job Item: Source language */
  $handler->display->display_options['fields']['source_language']['id'] = 'source_language';
  $handler->display->display_options['fields']['source_language']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['source_language']['field'] = 'source_language';
  /* Field: Translation Management Job Item: Target language */
  $handler->display->display_options['fields']['target_language']['id'] = 'target_language';
  $handler->display->display_options['fields']['target_language']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['target_language']['field'] = 'target_language';
  /* Field: Translation Management Job: Has File uploaded */
  $handler->display->display_options['fields']['has_file_uploaded']['id'] = 'has_file_uploaded';
  $handler->display->display_options['fields']['has_file_uploaded']['table'] = 'views_entity_tmgmt_job';
  $handler->display->display_options['fields']['has_file_uploaded']['field'] = 'has_file_uploaded';
  $handler->display->display_options['fields']['has_file_uploaded']['relationship'] = 'tjid';
  $handler->display->display_options['fields']['has_file_uploaded']['not'] = 0;
  $handler->display->display_options['fields']['has_file_uploaded']['link_to_entity'] = 0;
  /* Field: Translation Management Job Item: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_tmgmt_job_item';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 1;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Translation Management Job: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'tmgmt_job';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['relationship'] = 'tjid';
  $handler->display->display_options['filters']['state_1']['value'] = array(
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['path'] = 'admin/workbench/translation-overview';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Translation Overview';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['osha_translation_workbench'] = array(
    t('Master'),
    t('On Translation'),
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
    t('Content Revision'),
    t('Translation Management Job'),
    t('Title'),
    t('Job Item ID'),
    t('.'),
    t(','),
    t('Label'),
    t('[title_field-revision_id]'),
    t('Item type'),
    t('Source language'),
    t('Target language'),
    t('File uploaded'),
    t('URL'),
    t('View'),
    t('Content Validation'),
    t('Needs Content Validation'),
    t('Translation Validators'),
    t('All'),
    t('Needs Review TM'),
    t('Needs Review PM'),
    t('Translations Needs Review PM'),
    t('Translation Overview'),
    t('Job'),
    t('State'),
    t('Has File uploaded'),
  );
  $export['osha_translation_workbench'] = $view;

  $view = new view();
  $view->name = 'tmgmt_node_selection_view';
  $view->description = '';
  $view->tag = 'Workbench';
  $view->base_table = 'node';
  $view->human_name = 'OSHA TMGMT node selection';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'OSHA content selection';
  $handler->display->display_options['css_class'] = 'tmgmt_node_selection_view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create translation jobs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100, 200';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_summary' => 'field_summary',
    'body' => 'body',
    'title_1' => 'title_1',
    'type' => 'type',
    'state' => 'state',
    'name' => 'name',
    'changed' => 'changed',
    'field_character_count' => 'field_character_count',
    'field_page_count' => 'field_page_count',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_summary' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_character_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_page_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results. Please broaden your filters above.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['required'] = TRUE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::tmgmt_node_ui_tmgmt_nodes_add_items_to_cart' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::nodequeue_add_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::scs_views_create_newsletter_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::nodequeue_remove_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_summary']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Type of content';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Workflow state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Character count */
  $handler->display->display_options['fields']['field_character_count']['id'] = 'field_character_count';
  $handler->display->display_options['fields']['field_character_count']['table'] = 'field_data_field_character_count';
  $handler->display->display_options['fields']['field_character_count']['field'] = 'field_character_count';
  $handler->display->display_options['fields']['field_character_count']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Page count */
  $handler->display->display_options['fields']['field_page_count']['id'] = 'field_page_count';
  $handler->display->display_options['fields']['field_page_count']['table'] = 'field_data_field_page_count';
  $handler->display->display_options['fields']['field_page_count']['field'] = 'field_page_count';
  $handler->display->display_options['fields']['field_page_count']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Updated date';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'uid';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Author name';
  /* Sort criterion: Content: Type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'node';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
  $handler->display->display_options['sorts']['type']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['type']['expose']['label'] = 'Type';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'page' => 'page',
    'blog' => 'blog',
    'calls' => 'calls',
    'directive' => 'directive',
    'guideline' => 'guideline',
    'highlight' => 'highlight',
    'job_vacancies' => 'job_vacancies',
    'news' => 'news',
    'press_release' => 'press_release',
    'publication' => 'publication',
    'seminar' => 'seminar',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type of content';
  $handler->display->display_options['filters']['type']['expose']['description'] = 'Use CTRL to select multiple items';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
    11 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Free text';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
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
    11 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_summary' => 'field_summary',
    'body' => 'body',
    'title_1' => 'title_1',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Node ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Entity translation: Translation exists */
  $handler->display->display_options['filters']['translation_exists']['id'] = 'translation_exists';
  $handler->display->display_options['filters']['translation_exists']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['translation_exists']['field'] = 'translation_exists';
  $handler->display->display_options['filters']['translation_exists']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['translation_exists']['operator'] = 'not in';
  $handler->display->display_options['filters']['translation_exists']['value'] = array(
    'bg' => 'bg',
    'cs' => 'cs',
    'da' => 'da',
    'de' => 'de',
    'el' => 'el',
    'es' => 'es',
    'et' => 'et',
    'fi' => 'fi',
    'hr' => 'hr',
    'fr' => 'fr',
    'hu' => 'hu',
    'is' => 'is',
    'it' => 'it',
    'lv' => 'lv',
    'lt' => 'lt',
    'nl' => 'nl',
    'mt' => 'mt',
    'no' => 'no',
    'pl' => 'pl',
    'pt' => 'pt',
    'ro' => 'ro',
    'ru' => 'ru',
    'sk' => 'sk',
    'sl' => 'sl',
    'sv' => 'sv',
    'tr' => 'tr',
  );
  $handler->display->display_options['filters']['translation_exists']['group'] = 1;
  $handler->display->display_options['filters']['translation_exists']['exposed'] = TRUE;
  $handler->display->display_options['filters']['translation_exists']['expose']['operator_id'] = 'translation_exists_op';
  $handler->display->display_options['filters']['translation_exists']['expose']['label'] = 'Not translated in';
  $handler->display->display_options['filters']['translation_exists']['expose']['description'] = 'Use CTRL to select multiple items';
  $handler->display->display_options['filters']['translation_exists']['expose']['operator'] = 'translation_exists_op';
  $handler->display->display_options['filters']['translation_exists']['expose']['identifier'] = 'translation_exists';
  $handler->display->display_options['filters']['translation_exists']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['translation_exists']['expose']['remember_roles'] = array(
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
    11 => 0,
  );
  $handler->display->display_options['filters']['translation_exists']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['translation_exists']['entity_type'] = 'node';
  /* Filter criterion: Content: Activity (field_activity) */
  $handler->display->display_options['filters']['field_activity_tid']['id'] = 'field_activity_tid';
  $handler->display->display_options['filters']['field_activity_tid']['table'] = 'field_data_field_activity';
  $handler->display->display_options['filters']['field_activity_tid']['field'] = 'field_activity_tid';
  $handler->display->display_options['filters']['field_activity_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_tid']['expose']['operator_id'] = 'field_activity_tid_op';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['label'] = 'Activity';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['operator'] = 'field_activity_tid_op';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['identifier'] = 'field_activity_tid';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['remember_roles'] = array(
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
    11 => 0,
  );
  $handler->display->display_options['filters']['field_activity_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_tid']['vocabulary'] = 'activity';
  $handler->display->display_options['filters']['field_activity_tid']['hierarchy'] = 1;
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['group'] = 1;
  $handler->display->display_options['filters']['access_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['access_id']['expose']['operator_id'] = 'access_id_op';
  $handler->display->display_options['filters']['access_id']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['access_id']['expose']['description'] = 'Use CTRL to select multiple items';
  $handler->display->display_options['filters']['access_id']['expose']['operator'] = 'access_id_op';
  $handler->display->display_options['filters']['access_id']['expose']['identifier'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['expose']['remember_roles'] = array(
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
    11 => 0,
  );
  $handler->display->display_options['filters']['access_id']['access_id'] = array();
  $handler->display->display_options['filters']['access_id']['size'] = '5';
  /* Filter criterion: Content: Page count (field_page_count) */
  $handler->display->display_options['filters']['field_page_count_value']['id'] = 'field_page_count_value';
  $handler->display->display_options['filters']['field_page_count_value']['table'] = 'field_data_field_page_count';
  $handler->display->display_options['filters']['field_page_count_value']['field'] = 'field_page_count_value';
  $handler->display->display_options['filters']['field_page_count_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_page_count_value']['group'] = 1;
  $handler->display->display_options['filters']['field_page_count_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_page_count_value']['expose']['operator_id'] = 'field_page_count_value_op';
  $handler->display->display_options['filters']['field_page_count_value']['expose']['label'] = 'Page count';
  $handler->display->display_options['filters']['field_page_count_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_page_count_value']['expose']['operator'] = 'field_page_count_value_op';
  $handler->display->display_options['filters']['field_page_count_value']['expose']['identifier'] = 'field_page_count_value';
  $handler->display->display_options['filters']['field_page_count_value']['expose']['remember_roles'] = array(
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
    11 => 0,
  );
  /* Filter criterion: Content: Character count (field_character_count) */
  $handler->display->display_options['filters']['field_character_count_value']['id'] = 'field_character_count_value';
  $handler->display->display_options['filters']['field_character_count_value']['table'] = 'field_data_field_character_count';
  $handler->display->display_options['filters']['field_character_count_value']['field'] = 'field_character_count_value';
  $handler->display->display_options['filters']['field_character_count_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_character_count_value']['group'] = 1;
  $handler->display->display_options['filters']['field_character_count_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_character_count_value']['expose']['operator_id'] = 'field_character_count_value_op';
  $handler->display->display_options['filters']['field_character_count_value']['expose']['label'] = 'Character count';
  $handler->display->display_options['filters']['field_character_count_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_character_count_value']['expose']['operator'] = 'field_character_count_value_op';
  $handler->display->display_options['filters']['field_character_count_value']['expose']['identifier'] = 'field_character_count_value';
  $handler->display->display_options['filters']['field_character_count_value']['expose']['remember_roles'] = array(
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
    11 => 0,
  );
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'ready_to_publish' => 'ready_to_publish',
    'published' => 'published',
  );
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Workflow state';
  $handler->display->display_options['filters']['state']['expose']['description'] = 'Published includes also items without publishing workflow. Use CTRL to select multiple items';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
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
    11 => 0,
  );
  $handler->display->display_options['filters']['state']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['state']['group_info']['label'] = 'Workflow state';
  $handler->display->display_options['filters']['state']['group_info']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Published',
      'operator' => 'in',
      'value' => array(
        'published' => 'published',
        'all' => 0,
        'draft' => 0,
        'rejected' => 0,
        'approved' => 0,
        'final_draft' => 0,
        'needs_review' => 0,
        'to_be_approved' => 0,
        'ready_to_publish' => 0,
      ),
    ),
    2 => array(
      'title' => 'Ready to Publish',
      'operator' => 'in',
      'value' => array(
        'ready_to_publish' => 'ready_to_publish',
        'all' => 0,
        'draft' => 0,
        'rejected' => 0,
        'approved' => 0,
        'final_draft' => 0,
        'needs_review' => 0,
        'to_be_approved' => 0,
        'published' => 0,
      ),
    ),
  );
  /* Filter criterion: Content revision: Updated date */
  $handler->display->display_options['filters']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['filters']['timestamp_1']['table'] = 'node_revision';
  $handler->display->display_options['filters']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp_1']['operator'] = '>=';
  $handler->display->display_options['filters']['timestamp_1']['group'] = 1;
  $handler->display->display_options['filters']['timestamp_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp_1']['expose']['operator_id'] = 'timestamp_1_op';
  $handler->display->display_options['filters']['timestamp_1']['expose']['label'] = 'Updated after';
  $handler->display->display_options['filters']['timestamp_1']['expose']['operator'] = 'timestamp_1_op';
  $handler->display->display_options['filters']['timestamp_1']['expose']['identifier'] = 'from_date';
  /* Filter criterion: Content revision: Updated date */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = '<=';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Updated before';
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'to_date';

  /* Display: OSHA content selection */
  $handler = $view->new_display('page', 'OSHA content selection', 'tmgmt_node_selection_view_page');
  $handler->display->display_options['path'] = 'admin/tmgmt/sources/osha';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'OSHA content';
  $handler->display->display_options['menu']['weight'] = '-30';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['tmgmt_node_selection_view'] = array(
    t('Master'),
    t('OSHA content selection'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort by'),
    t('Ascending'),
    t('Descending'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('There are no results. Please broaden your filters above.'),
    t('author'),
    t('Translations'),
    t('- Choose an operation -'),
    t('Title'),
    t('Type of content'),
    t('Workflow state'),
    t('Author'),
    t('Updated'),
    t('Character count'),
    t('Page count'),
    t('Post date'),
    t('Updated date'),
    t('Author name'),
    t('Type'),
    t('Use CTRL to select multiple items'),
    t('Free text'),
    t('Node ID'),
    t('Not translated in'),
    t('Activity'),
    t('Section'),
    t('Published includes also items without publishing workflow. Use CTRL to select multiple items'),
    t('Updated after'),
    t('Updated before'),
  );
  $export['tmgmt_node_selection_view'] = $view;

  return $export;
}
