<?php

require_once 'theme/menu/menu.inc';

/**
 * Implements hook_preprocess_node().
 */
function napo_frontend_preprocess_node(&$vars) {
  napo_frontend_back_button($vars);
  napo_frontend_top_anchor($vars);
}

/**
 * Implements hook_preprocess_block().
 */
function napo_frontend_preprocess_block(&$vars) {
  // Use a bare template for the page's main content.
  if ($vars['block_html_id'] == 'block-views-consortium-partners-block') {
    $vars['title_attributes_array']['class'][] = 'hidden-xs';
  } else if ($vars['block_html_id'] == 'block-views-consortium-partners-block-1') {
    $vars['title_attributes_array']['class'][] = 'visible-xs';
    $vars['title_suffix'] =
      '<span id="consortium-partners-block-1-link" class="visible-xs">'
      .t('See details').'</span>';
  }
}

/**
 * Back button link and text
 */
function napo_frontend_back_button(&$vars){
  global $base_url;
  $node = $vars['node'];

  $referer = isset($_SERVER['HTTP_REFERER']) ? $_SERVER['HTTP_REFERER'] : '';
  $breadcrumb = drupal_get_breadcrumb();
  $options = array(
    'attributes' => array(
      'class' => 'back_button',
    ),
    'html' => TRUE,
  );

  // For view episodes panel, the breadcrumb it's not available here.
  // So it's hardcoded.
  $args = arg();
  if (end($args) == 'view-scenes') {
    $vars['back_button'] = l(t('Back to !link', array('!link' => t('Films'))), 'napos-films/films', $options);
    return;
  }

  if (empty($referer) || strpos($referer, $base_url) === FALSE) {
    unset($vars['back_button']);
  }elseif (strpos($referer, 'search') !== FALSE) {
    $vars['back_button'] = l(t('Back to search results'), $referer, $options);
  }elseif (is_array($breadcrumb) && $breadcrumb) {
    $page_title = array_pop($breadcrumb);
    $previous_crumb = array_pop($breadcrumb);

    $regexp = "<a\s[^>]*href=(\"??)([^\" >]*?)\\1[^>]*>(.*)<\/a>";
    if(preg_match("/$regexp/siU", $previous_crumb, $matches)) {
      $url = strpos($matches[2], $base_url)!== FALSE? $matches[2] : $base_url.$matches[2];
      // The page was accessed from pagination
      if(strpos($referer, 'page=') !== FALSE) {
        $url = $referer;
      }
      $vars['back_button'] = l(t('Back to !link', array('!link' => $matches[3])), $url, $options);
    }else{
      $vars['back_button'] = l(t('Back to !link', array('!link' => strip_tags($previous_crumb))), $referer, $options);
    }
  }else {
    $vars['back_button'] = l(t('Back'), $referer, $options);
  }
}

/**
 * Anchor to top of the page
 */
function napo_frontend_top_anchor(&$vars) {
  $options = array(
    'attributes' => array(
      'class' => 'top_anchor',
    ),
    'external' => TRUE,
    'fragment' => 'top',
    'html' => TRUE,
  );
  $icon_path = drupal_get_path('theme', 'napo_frontend') . '/images/anchor-top.png';
  $image_info = image_get_info($icon_path);
  $image_vars = array(
    'path' => $icon_path,
    'alt' => t('Go to top'),
    'height' => $image_info['height'],
    'width' => $image_info['width'],
  );
  $image = theme('image', $image_vars);
  $vars['top_anchor'] = l($image, '', $options);
}

function napo_frontend_text_resize_block() {
  // Add js, css, and library
  $content = array(
    '#attached' => array(
      'js' => array(
        array(
          'data' => "var text_resize_scope = " . drupal_json_encode(variable_get('text_resize_scope', 'body')) . ";
          var text_resize_minimum = " . drupal_json_encode(variable_get('text_resize_minimum', '12')) . ";
          var text_resize_maximum = " . drupal_json_encode(variable_get('text_resize_maximum', '25')) . ";
          var text_resize_line_height_allow = " . drupal_json_encode(variable_get('text_resize_line_height_allow', FALSE)) . ";
          var text_resize_line_height_min = " . drupal_json_encode(variable_get('text_resize_line_height_min', 16)) . ";
          var text_resize_line_height_max = " . drupal_json_encode(variable_get('text_resize_line_height_max', 36)) . ";",
          'type' => 'inline',
        ),
        array(
          'data' => drupal_get_path('module', 'text_resize') . '/text_resize.js',
          'type' => 'file',
        )
      ),
      'library' => array(
        array('system', 'jquery.cookie')
      ),
    ),
  );

  $content['#markup'] = t('Set font size ');

  if (variable_get('text_resize_reset_button', FALSE) == TRUE) {
    $content['#markup'] .= '<sup>&#x2C4;</sup><a href="javascript:;" class="changer" id="text_resize_increase">A</a> <a href="javascript:;" class="changer" id="text_resize_reset">A</a> <sup>&#x2C5;</sup><a href="javascript:;" class="changer" id="text_resize_decrease">A</a> <div id="text_resize_clear"></div>';
  } else {
    $content['#markup'] .= '<sup>&#x2C4;</sup><a href="javascript:;" class="changer" id="text_resize_increase">A</a> <sup>&#x2C5;</sup><a href="javascript:;" class="changer" id="text_resize_decrease">A</a> <div id="text_resize_clear"></div>';
  }

  return render($content);
}

/**
 * Implements hook_preprocess_page().
 */
function napo_frontend_preprocess_page(&$vars) {
  // Render the logo with theme image to provide alt, width and height attr.
  $logo_path = drupal_get_path('theme', 'napo_frontend') . '/logo.png';
  $image_info = image_get_info($logo_path);
  $image_vars = array(
    'path' => $logo_path,
    'alt' => t('Napo'),
    'height' => $image_info['height'],
    'width' => $image_info['width'],
  );
  $vars['logo'] = theme('image', $image_vars);
}

/**
 * Implements hook_preporcess_image_style().
 */
function napo_frontend_preprocess_image_style(&$variables) {
  $variables['attributes']['class'][] = 'img-responsive';
  // Add default width and height attr.
  if (empty($variables['width']) && empty($variables['height'])) {
    $image_info = image_get_info($variables['path']);
    if (!empty($image_info)) {
      $variables['width'] = $image_info['width'];
      $variables['height'] = $image_info['height'];
    }
  }
  // Add an alt attribute.
  if (empty($variables['alt'])) {
    $variables['alt'] = drupal_basename($variables['path']);
  }
}

function napo_frontend_form_alter(&$form, &$form_state, $form_id) {
  if($form_id == 'views_exposed_form' && $form['#id'] == 'views-exposed-form-napo-films-page-list') {
    $form['search_api_views_fulltext']['#attributes']['placeholder'] = t('Search');
  }
}

function napo_frontend_napo_film_tag_facet_link($variables) {
  $icon = '<span class="glyphicon glyphicon-remove"></span>';
  $options = array(
    'attributes' => array(
      'class' => array('napo-film-search-tag-filter'),
    ),
    'html' => TRUE,
  );
  return l($icon . $variables['name'], $variables['link'], $options);
}

function napo_frontend_napo_film_remove_search_word_link($variables) {
  $icon = '<span class="glyphicon glyphicon-remove"></span>';
  $options = array(
    'attributes' => array(
      'class' => array('napo-film-search-remove-word'),
    ),
    'html' => TRUE,
  );
  return l($icon, $variables['link'], $options);
}

/**
+ * Implements theme_pager().
+ */
function napo_frontend_pager($variables) {
  // Overwrite pager links.
  $variables['tags'][0] = '«';
  $variables['tags'][1] = '‹';
  $variables['tags'][3] = '›';
  $variables['tags'][4] = '»';

  $pager_html = theme_pager($variables);
  $pager_html = str_replace(array('<h2', '</h2>'), array('<h3', '</h3>'), $pager_html);

  return $pager_html;
}

/**
 * Overwrite the video render func ot add preload metadata attribute.
 */
function napo_frontend_file_entity_file_video($variables) {
  $files = $variables['files'];
  $output = '';

  $video_attributes = array();
  if ($variables['controls']) {
    $video_attributes['controls'] = 'controls';
  }
  if ($variables['autoplay']) {
    $video_attributes['autoplay'] = 'autoplay';
  }
  if ($variables['loop']) {
    $video_attributes['loop'] = 'loop';
  }
  if ($variables['muted']) {
    $video_attributes['muted'] = 'muted';
  }
  if ($variables['width']) {
    $video_attributes['width'] = $variables['width'];
  }
  if ($variables['height']) {
    $video_attributes['height'] = $variables['height'];
  }

  $output .= '<video preload="metadata"' . drupal_attributes($video_attributes) . '>';
  foreach ($files as $delta => $file) {
    $source_attributes = array(
      'src' => file_create_url($file['uri']),
      'type' => $file['filemime'],
    );
    $output .= '<source' . drupal_attributes($source_attributes) . ' />';
  }
  $output .= '</video>';
  return $output;
}
