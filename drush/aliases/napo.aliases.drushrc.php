<?php

$aliases['napo.staging'] = array(
  'uri' => '',
  'db-allows-remote' => TRUE,
  'remote-host' => '',
  'remote-user' => '',
  'root' => '',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
  ),
  'command-specific' => array(
    'sql-sync' => array(
      'simulate' => '1',
    ),
  ),
);

$aliases['napo.staging.edw'] = array(
  'uri' => '',
  'db-allows-remote' => TRUE,
  'remote-host' => '',
  'remote-user' => '',
  'root' => '',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
  ),
);

// This alias is used in install and update scripts.
// Rewrite it in your aliases.local.php as you need.
$aliases['napo.staging.sync'] = $aliases['napo.staging.edw'];

// Example of local setting.
// $aliases['osha.local'] = array(
//   'uri' => 'osha.localhost',
//   'root' => '/home/my_user/osha-website/docroot',
// );

// Add your local aliases.
if (file_exists(dirname(__FILE__) . '/aliases.local.php')) {
  include dirname(__FILE__) . '/aliases.local.php';
}
