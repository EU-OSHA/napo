<?php
/**
 * @file
 * napo_film.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function napo_film_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__napo_video_napo_film_tag';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Napo Video - Napo film tag',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'napo_video_napo_film_tag',
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
  $display->uuid = '64df5710-040c-4a5b-b50a-d7a290276ca4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-435df4d5-4e36-410b-9042-c9991c76dcfb';
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
    $pane->uuid = '435df4d5-4e36-410b-9042-c9991c76dcfb';
    $display->content['new-435df4d5-4e36-410b-9042-c9991c76dcfb'] = $pane;
    $display->panels['center'][0] = 'new-435df4d5-4e36-410b-9042-c9991c76dcfb';
    $pane = new stdClass();
    $pane->pid = 'new-1584eadc-9386-4f24-bcbc-2f32ba167057';
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
    $pane->uuid = '1584eadc-9386-4f24-bcbc-2f32ba167057';
    $display->content['new-1584eadc-9386-4f24-bcbc-2f32ba167057'] = $pane;
    $display->panels['center'][1] = 'new-1584eadc-9386-4f24-bcbc-2f32ba167057';
    $pane = new stdClass();
    $pane->pid = 'new-c3184190-8098-4830-9b7e-5f583876e446';
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
    $pane->uuid = 'c3184190-8098-4830-9b7e-5f583876e446';
    $display->content['new-c3184190-8098-4830-9b7e-5f583876e446'] = $pane;
    $display->panels['center'][2] = 'new-c3184190-8098-4830-9b7e-5f583876e446';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1584eadc-9386-4f24-bcbc-2f32ba167057';
  $handler->conf['display'] = $display;
  $export['node_view__napo_video_napo_film_tag'] = $handler;

  return $export;
}
