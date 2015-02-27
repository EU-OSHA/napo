<?php
/**
 * @file
 * osha_alert_service.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function osha_alert_service_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_blog';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'node/883' => 'node/883',
      ),
    ),
    'views' => array(
      'values' => array(
        'blog' => 'blog',
        'blog:page_1' => 'blog:page_1',
        'blog:page_2' => 'blog:page_2',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;
  $export['context_blog'] = $context;

  return $export;
}
