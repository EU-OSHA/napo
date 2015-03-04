<?php

$aliases['napo.staging'] = array(
  'uri' => 'napo.edw.ro',
  'db-allows-remote' => TRUE,
  'remote-host' => 'Implement this in your aliases.local.php',
  'remote-user' => 'Implement this in your aliases.local.php',
  'root' => 'Implement this in your aliases.local.php',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
  ),
  'command-specific' => array(
    'sql-sync' => array(
      'simulate' => '1',
    ),
  ),
);

// Example of local setting.
// $aliases['napo.local'] = array(
//   'uri' => 'napo.localhost',
//   'root' => '/home/my_user/napo-website/docroot',
// );

// Add your local aliases.
if (file_exists(dirname(__FILE__) . '/aliases.local.php')) {
  include dirname(__FILE__) . '/aliases.local.php';
}
