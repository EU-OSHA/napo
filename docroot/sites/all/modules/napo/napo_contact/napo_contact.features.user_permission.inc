<?php
/**
 * @file
 * napo_contact.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function napo_contact_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer CAPTCHA settings'.
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'administer recaptcha'.
  $permissions['administer recaptcha'] = array(
    'name' => 'administer recaptcha',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'recaptcha',
  );

  // Exported permission: 'create contact_us_faq content'.
  $permissions['create contact_us_faq content'] = array(
    'name' => 'create contact_us_faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create faq content'.
  $permissions['create faq content'] = array(
    'name' => 'create faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any contact_us_faq content'.
  $permissions['delete any contact_us_faq content'] = array(
    'name' => 'delete any contact_us_faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any faq content'.
  $permissions['delete any faq content'] = array(
    'name' => 'delete any faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own contact_us_faq content'.
  $permissions['delete own contact_us_faq content'] = array(
    'name' => 'delete own contact_us_faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own faq content'.
  $permissions['delete own faq content'] = array(
    'name' => 'delete own faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any contact_us_faq content'.
  $permissions['edit any contact_us_faq content'] = array(
    'name' => 'edit any contact_us_faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any faq content'.
  $permissions['edit any faq content'] = array(
    'name' => 'edit any faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own contact_us_faq content'.
  $permissions['edit own contact_us_faq content'] = array(
    'name' => 'edit own contact_us_faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own faq content'.
  $permissions['edit own faq content'] = array(
    'name' => 'edit own faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'skip CAPTCHA'.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'captcha',
  );

  return $permissions;
}
