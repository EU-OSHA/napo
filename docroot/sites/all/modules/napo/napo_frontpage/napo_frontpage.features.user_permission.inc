<?php
/**
 * @file
 * napo_frontpage.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function napo_frontpage_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'update frontpage_carousel_featured entityqueue'.
  $permissions['update frontpage_carousel_featured entityqueue'] = array(
    'name' => 'update frontpage_carousel_featured entityqueue',
    'roles' => array(),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update frontpage_video entityqueue'.
  $permissions['update frontpage_video entityqueue'] = array(
    'name' => 'update frontpage_video entityqueue',
    'roles' => array(),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update more_representative_section entityqueue'.
  $permissions['update more_representative_section entityqueue'] = array(
    'name' => 'update more_representative_section entityqueue',
    'roles' => array(),
    'module' => 'entityqueue',
  );

  return $permissions;
}
