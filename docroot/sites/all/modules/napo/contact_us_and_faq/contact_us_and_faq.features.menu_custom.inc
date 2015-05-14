<?php
/**
 * @file
 * contact_us_and_faq.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function contact_us_and_faq_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-menu.
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer menu');


  return $menus;
}
