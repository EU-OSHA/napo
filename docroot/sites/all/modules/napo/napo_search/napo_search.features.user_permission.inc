<?php
/**
 * @file
 * napo_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function napo_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer Search Autocomplete'.
  $permissions['administer Search Autocomplete'] = array(
    'name' => 'administer Search Autocomplete',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_autocomplete',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use Search Autocomplete'.
  $permissions['use Search Autocomplete'] = array(
    'name' => 'use Search Autocomplete',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'search_autocomplete',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  return $permissions;
}
