<?php
/**
 * @file
 * napo_contact.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function napo_contact_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu_contact-us--faq:node/262
  $menu_links['menu-footer-menu_contact-us--faq:node/262'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/262',
    'router_path' => 'node/%',
    'link_title' => 'Contact Us & FAQ',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-menu_contact-us--faq:node/262',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => 'f1e23f9a-89c7-40fd-aff4-f32f41be6db7',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contact Us & FAQ');


  return $menu_links;
}
