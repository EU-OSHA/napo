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

  // Exported menu link: menu-footer-menu_contact-us--faq:faq-page
  $menu_links['menu-footer-menu_contact-us--faq:faq-page'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'faq-page',
    'router_path' => 'faq-page',
    'link_title' => 'Contact Us & FAQ',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_contact-us--faq:faq-page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contact Us & FAQ');


  return $menu_links;
}
