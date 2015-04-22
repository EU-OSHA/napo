<?php
/**
 * @file
 * napo_film.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function napo_film_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'napo_video_view_episodes';
  $page->task = 'page';
  $page->admin_title = 'Napo Video - View Episodes';
  $page->admin_description = 'Napo Video - View Episodes';
  $page->path = 'node/%node/view-episodes';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_napo_video_view_episodes__panel_context_fa62b18d-5bb2-4946-a01e-f7e1c4eb2ca9';
  $handler->task = 'page';
  $handler->subtask = 'napo_video_view_episodes';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Napo Video - View Episodes',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'napo_video' => 'napo_video',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:napo_video:field_video_type',
          'settings' => array(
            'field_video_type' => array(
              'und' => array(
                0 => array(
                  'tid' => '2727',
                ),
              ),
            ),
            'field_video_type_tid' => array(
              0 => '2727',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title_field';
  $display->uuid = 'b3d8c63e-c841-4c73-8d8f-7c78bcf04f81';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1c458fc4-84f6-4249-8f06-6fa1cd293668';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:title_field';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'title_linked',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'title_style' => 'h1',
        'title_link' => '',
        'title_class' => 'field-name-title-field',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1c458fc4-84f6-4249-8f06-6fa1cd293668';
    $display->content['new-1c458fc4-84f6-4249-8f06-6fa1cd293668'] = $pane;
    $display->panels['center'][0] = 'new-1c458fc4-84f6-4249-8f06-6fa1cd293668';
    $pane = new stdClass();
    $pane->pid = 'new-258aa2b9-fe8a-4f7d-9c8c-59a964ffbe09';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '258aa2b9-fe8a-4f7d-9c8c-59a964ffbe09';
    $display->content['new-258aa2b9-fe8a-4f7d-9c8c-59a964ffbe09'] = $pane;
    $display->panels['center'][1] = 'new-258aa2b9-fe8a-4f7d-9c8c-59a964ffbe09';
    $pane = new stdClass();
    $pane->pid = 'new-083bf1d3-aa0b-4d1d-ad3e-45b3ff4ead4f';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'napo_s_film_episodes';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page',
      'context' => array(
        0 => '',
      ),
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '083bf1d3-aa0b-4d1d-ad3e-45b3ff4ead4f';
    $display->content['new-083bf1d3-aa0b-4d1d-ad3e-45b3ff4ead4f'] = $pane;
    $display->panels['center'][2] = 'new-083bf1d3-aa0b-4d1d-ad3e-45b3ff4ead4f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1c458fc4-84f6-4249-8f06-6fa1cd293668';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['napo_video_view_episodes'] = $page;

  return $pages;

}
