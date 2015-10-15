<?php

/**
 * Implements THEMENAME_menu_tree__MENU_NAME().
 */
function napo_frontend_menu_tree__menu_footer_menu(&$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

/**
 * Implements THEMENAME_menu_tree__MENU_NAME().
 */
function napo_frontend_menu_tree__menu_social_media_menu(&$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_link().
 */
function napo_frontend_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      $element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
//      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
      $element['#localized_options']['attributes']['role'] = 'button';
      $element['#localized_options']['attributes']['aria-haspopup'] = 'true';
      $element['#localized_options']['attributes']['aria-expanded'] = 'false';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }

  // Add image to menu item
  if (isset($variables['element']['#href']) && isset($element['#localized_options']['content']['image'])) {
    $image_vars = array(
      'style_name' => 'napo_original',
      'path' => $element['#localized_options']['content']['image'],
      'alt' => $element['#title'],
    );
    $image = theme('image_style', $image_vars);
    $link = l($image, $element['#href'],
      array('html' => TRUE, 'attributes' => $element['#localized_options']['attributes'])
    );
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $link . "</li>\n";
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements theme_menu_link__menu_block().
 */
function napo_frontend_menu_link__menu_block($variables) {
  $element = &$variables['element'];
  $delta = $element['#bid']['delta'];

  $element = $variables['element'];
  $attr = $element['#attributes'];
  if (isset($variables['element']['#href']) &&
    $variables['element']['#href'] == '<front>' &&
    isset($element['#localized_options']['content']['image'])
  ) {
    $image_vars = array(
      'path' => $element['#localized_options']['content']['image'],
      'style_name' => 'napo_original',
      'alt' => $element['#title'],
    );
    $image = theme('image_style', $image_vars);
    $link = l($image, $element['#href'], array_merge(array('html' => TRUE), $element['#localized_options']));
    return sprintf("\n<li %s>%s</li>", drupal_attributes($attr), $link);
  }

  // Render or not the Menu Image.
  // Get the variable provided by osha_menu module.
  $render_img = variable_get('menu_block_' . $delta . '_' . OSHA_MENU_RENDER_IMG_VAR_NAME, 0);
  if (!$render_img) {
    return napo_frontend_menu_link($variables);
  }
  $output_link = l($element['#title'], $element['#href'], $element['#localized_options']);

  $output_image = "";
  if (!empty($element['#localized_options']['content']['image'])) {
    $image_vars = array(
      'path' => $element['#localized_options']['content']['image'],
      'style_name' => 'napo_original',
      'alt' => $element['#title'],
    );
    $image = theme('image_style', $image_vars);
    $output_image = l($image, $element['#href'], array_merge(array('html' => TRUE), $element['#localized_options']));
  }

  return '<li' . drupal_attributes($attr) . '>
    <div class="introduction-title">' . $output_link . '</div>
    <div class="introduction-image">' . $output_image . '</div>
    </li>';
}
