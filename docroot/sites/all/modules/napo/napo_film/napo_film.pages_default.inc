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
  $page->path = 'node/%node/view-scenes';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
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
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'description' => array(
          'value' => '[node:body]',
        ),
        'abstract' => array(
          'value' => '[node:summary]',
        ),
        'keywords' => array(
          'value' => '[node:field_tags] [node:field_combined_tags]',
        ),
        'canonical' => array(
          'value' => '[node:url]',
        ),
      ),
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_napo_video_view_episodes__panel_context_fa62b18d-5bb2-4946-a01e-f7e1c4eb2ca9';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d059633c-705b-45c8-a50b-5dc376f98e8f';
  $pane->panel = 'center';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'episode_list',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = 'd059633c-705b-45c8-a50b-5dc376f98e8f';
  $display->content['new-d059633c-705b-45c8-a50b-5dc376f98e8f'] = $pane;
  $display->panels['center'][0] = 'new-d059633c-705b-45c8-a50b-5dc376f98e8f';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '083bf1d3-aa0b-4d1d-ad3e-45b3ff4ead4f';
  $display->content['new-083bf1d3-aa0b-4d1d-ad3e-45b3ff4ead4f'] = $pane;
  $display->panels['center'][1] = 'new-083bf1d3-aa0b-4d1d-ad3e-45b3ff4ead4f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['napo_video_view_episodes'] = $page;

  return $pages;

}
