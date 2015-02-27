<?php
/**
 * Author: Cristian Romanescu <cristi _at_ eaudeweb dot ro>
 * Created: 201412171900
 */

/*
 * Initialize our environment at the start of each run (i.e. suite).
 */
function upal_init() {
  // UNISH_DRUSH value can come from phpunit.xml or `which drush`.
  if (!defined('UNISH_DRUSH')) {
    // Let the UNISH_DRUSH environment variable override if set.
    $unish_drush = isset($_SERVER['UNISH_DRUSH']) ? $_SERVER['UNISH_DRUSH'] : NULL;
    $unish_drush = isset($GLOBALS['UNISH_DRUSH']) ? $GLOBALS['UNISH_DRUSH'] : $unish_drush;
    if (empty($unish_drush)) {
      // $unish_drush = Drush_TestCase::is_windows() ? exec('for %i in (drush) do @echo.   %~$PATH:i') : trim(`which drush`);
      $unish_drush = trim(`which drush`);
    }
    define('UNISH_DRUSH', $unish_drush);
  }

  // We read from globals here because env can be empty and ini did not work in quick test.
  define('UPAL_DB_URL', getenv('UPAL_DB_URL') ? getenv('UPAL_DB_URL') : (!empty($GLOBALS['UPAL_DB_URL']) ? $GLOBALS['UPAL_DB_URL'] : 'mysql://root:@127.0.0.1/upal'));

  // Make sure we use the right Drupal codebase.
  define('UPAL_ROOT', getenv('UPAL_ROOT') ? getenv('UPAL_ROOT') : (isset($GLOBALS['UPAL_ROOT']) ? $GLOBALS['UPAL_ROOT'] : realpath('.')));
  chdir(UPAL_ROOT);

  // The URL that browser based tests should use.
  define('UPAL_WEB_URL', getenv('UPAL_WEB_URL') ? getenv('UPAL_WEB_URL') : (isset($GLOBALS['UPAL_WEB_URL']) ? $GLOBALS['UPAL_WEB_URL'] : 'http://upal'));

  define('DRUPAL_CORE_VERSION', getenv('DRUPAL_CORE_VERSION') ? getenv('DRUPAL_CORE_VERSION') :(isset($GLOBALS['DRUPAL_CORE_VERSION']) ? $GLOBALS['DRUPAL_CORE_VERSION'] : "8"));

  define('UPAL_TMP', getenv('UPAL_TMP') ? getenv('UPAL_TMP') : (isset($GLOBALS['UPAL_TMP']) ? $GLOBALS['UPAL_TMP'] : sys_get_temp_dir()));
  // define('UNISH_SANDBOX', UNISH_TMP . '/drush-sandbox');

  // Cache dir lives outside the sandbox so that we get persistence across classes.
  define('UPAL_CACHE', UPAL_TMP . DIRECTORY_SEPARATOR . 'upal-cache');
  putenv("CACHE_PREFIX=" . UPAL_CACHE);
  // Wipe at beginning of run.
  if (file_exists(UPAL_CACHE)) {
    // TODO: We no longer clean up cache dir between runs. Much faster, but we
    // we should watch for subtle problems. To manually clean up, delete the
    // UNISH_TMP/drush-cache directory.
    // unish_file_delete_recursive($cache);
  }
  else {
    $ret = mkdir(UPAL_CACHE, 0777, TRUE);
  }

  // Set the env vars that Drupal expects. Largely copied from drush.
  $url = parse_url(UPAL_WEB_URL);
  global $base_url;
  $base_url = UPAL_WEB_URL;

  if (array_key_exists('path', $url)) {
    $_SERVER['PHP_SELF'] = $url['path'] . '/index.php';
  }
  else {
    $_SERVER['PHP_SELF'] = '/index.php';
  }

  $_SERVER['REQUEST_URI'] = $_SERVER['SCRIPT_NAME'] = $_SERVER['PHP_SELF'];
  $_SERVER['REMOTE_ADDR'] = '127.0.0.1';
  $_SERVER['REQUEST_METHOD']  = NULL;

  $_SERVER['SERVER_SOFTWARE'] = NULL;
  $_SERVER['HTTP_USER_AGENT'] = NULL;

  $_SERVER['HTTP_HOST'] = $url['host'];
  $_SERVER['SERVER_PORT'] = array_key_exists('port', $url) ? $url['port'] : NULL;
}

// This code is in global scope.
// TODO: I would rather this code at top of file, but I get Fatal error: Class 'Drush_TestCase' not found
upal_init();

require_once 'drupal_test_case.php';
