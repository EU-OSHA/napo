<?php
/**
 * @file
 * napo_gallery.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function napo_gallery_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'napos_gallery';
  $queue->label = 'Napo\'s Gallery';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'napo_album' => 'napo_album',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 0,
  );
  $export['napos_gallery'] = $queue;

  return $export;
}
