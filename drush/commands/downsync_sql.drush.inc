<?php

/**
 * @file
 * Downsync_sql command for Drush
 *
 * Copied from downsync - removed rsync.
 */

/**
 * Implements hook_drush_command().
 */
function downsync_sql_drush_command() {
  $items = array();
  $items['downsync_sql'] = array(
    'description' => "Sync one environment's db and files to another.",
    'arguments' => array(
      'source-alias' => 'Alias of the source site to copy from.',
      'destination-alias' => 'Alias of the destination site to copy to.',
    ),
    'examples' => array(
      'drush downsync_sql @prod @local' => 'sql-sync the database from @prod to @local',
    ),
    'aliases' => array('dsyncsql'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'drush dependencies' => array('sql', 'core'),
  );
  return $items;
}

/**
 * Actual function run by the downsync command.
 */
function drush_downsync_sql($source = NULL, $destination = NULL) {
  // Make sure we have the source-dump and target-dump options.
  $source_dump = drush_get_option('source-dump');
  if (!isset($source_dump)) {
    drush_set_option('source-dump', '/tmp/source-dump.sql');
  }

  $target_dump = drush_get_option('target-dump');
  if (!isset($target_dump)) {
    drush_set_option('target-dump', '/tmp/target-dump.sql.gz');
  }

  // Execute a drush sql-sync
  print dt('SQL Sync running... NOTE: if you do not have ssh passwordless logins setup, you may be asked for your password multiple times.');

  drush_invoke('sql-sync', array($source, $destination));
}
