<?php
/**
 * @file
 * napo_friend.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function napo_friend_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'napos_friends';
  $queue->label = 'Napo\'s friends';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'napo_friend' => 'napo_friend',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 0,
  );
  $export['napos_friends'] = $queue;

  return $export;
}
