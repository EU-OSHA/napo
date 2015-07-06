<?php

/**
 * Implements COMMANDFILE_drush_command().
 */
function osha_authentication_drush_command()
{
  $items = array();
  $items['osha-ldap-tests'] = array(
    'description' => 'Run LDAP tests suite',
    'examples' => array(),
    'options' => array(
      'test' => 'Run only the specified test',
      'leave' => 'Do not delete LDAP data, useful for debugging',
    ),
  );
  $items['osha-ldap-sync-sections'] = array(
    'description' => 'Check for new sections in LDAP and bring them in Drupal',
    'examples' => array(
      'drush osha-ldap-sync-sections' => 'Check for new sections, and create the new ones'
    ),
    'options' => array(
      '--dry-run' => 'Only check for new sections, do not create',
    ),
  );
  $items['osha-ldap-sync'] = array(
    'description' => 'Synchronize accounts from LDAP to Drupal and assign appropriate language skills, groups etc.',
    'examples' => array(
      'drush osha-ldap-sync' => 'Synchronize all existing accounts'
    ),
  );
  return $items;
}

function drush_osha_authentication_osha_ldap_tests() {
  require_once dirname(__FILE__) . '/osha_authentication.admin.inc';
  require_once dirname(__FILE__) . '/tests/osha_authentication.tests.inc';
  $test = new OSHALDAPTests();
  $filter = drush_get_option('test');
  $debug = drush_get_option('leave');
  $test->all_tests($filter, $debug);
}

function drush_osha_authentication_osha_ldap_sync_sections() {
  require_once dirname(__FILE__) . '/osha_authentication.admin.inc';
  $dry_run = drush_get_option('dry-run', FALSE);
  $ldap_servers = ldap_servers_get_servers('osha');
  $ldap_server = $ldap_servers['osha'];
  osha_authentication_sync_ldap_sections($ldap_server, $dry_run);
}

function drush_osha_authentication_osha_ldap_sync() {
  require_once dirname(__FILE__) . '/osha_authentication.admin.inc';
  $ldap_servers = ldap_servers_get_servers('osha');
  $ldap_server = $ldap_servers['osha'];
  osha_authentication_ldap_sync($ldap_server);
}
