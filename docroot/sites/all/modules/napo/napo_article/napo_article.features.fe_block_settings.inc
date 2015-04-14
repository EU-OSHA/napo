<?php
/**
 * @file
 * napo_article.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function napo_article_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  return $export;
}
