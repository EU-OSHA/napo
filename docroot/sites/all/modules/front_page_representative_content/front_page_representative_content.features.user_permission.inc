<?php
/**
 * @file
 * front_page_representative_content.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function front_page_representative_content_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'update more_representative_section entityqueue'.
  $permissions['update more_representative_section entityqueue'] = array(
    'name' => 'update more_representative_section entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  return $permissions;
}
