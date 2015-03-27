<?php
/**
 * @file
 * napo_film.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function napo_film_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'frontpage_video';
  $queue->label = 'Frontpage Video';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'napo_video' => 'napo_video',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 1,
  );
  $export['frontpage_video'] = $queue;

  return $export;
}
