<?php

require_once 'theme/menu/menu.inc';

/**
 * Implements hook_preprocess_block().
 */
function napo_frontend_preprocess_block(&$vars) {
  // Use a bare template for the page's main content.
  if ($vars['block_html_id'] == 'block-views-consortium-partners-block') {
    $vars['title_attributes_array']['class'][] = 'hidden-xs';
  }
  elseif ($vars['block_html_id'] == 'block-views-consortium-partners-block-1') {
    $vars['title_attributes_array']['class'][] = 'visible-xs';
    $vars['title_suffix'] = '<span id="consortium-partners-block-1-link" class="visible-xs">' . t('See details') . '</span>';
  }
}

function napo_frontend_text_resize_block() {
  // Add js, css, and library.
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
        ),
      ),
      'library' => array(
        array(
          'system',
          'jquery.cookie',
        ),
      ),
    ),
  );

  $content['#markup'] = t('Set font size');

  if (variable_get('text_resize_reset_button', FALSE) == TRUE) {
    $content['#markup'] .= '<sup>&#x2C4;</sup><a href="javascript:;" class="changer" id="text_resize_increase">A</a> <a href="javascript:;" class="changer" id="text_resize_reset">A</a> <sup>&#x2C5;</sup><a href="javascript:;" class="changer" id="text_resize_decrease">A</a> <div id="text_resize_clear"></div>';
  }
  else {
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
  if ($form_id == 'views_exposed_form' && $form['#id'] == 'views-exposed-form-napo-films-page-list') {
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
 * Implements theme_pager().
**/
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

/**
 * Colorbox theme function to add support for image field caption.
 *
 * @see theme_colorbox_image_formatter
 */
function napo_frontend_colorbox_image_formatter($variables) {
  $item = $variables['item'];
  $entity_type = $variables['entity_type'];
  $entity = $variables['entity'];
  $field = $variables['field'];
  $settings = $variables['display_settings'];
  $image = array(
    'path' => $item['uri'],
    'alt' => isset($item['alt']) ? $item['alt'] : '',
    'title' => isset($item['title']) ? $item['title'] : '',
    'style_name' => $settings['colorbox_node_style'],
  );
  if ($variables['delta'] == 0 && !empty($settings['colorbox_node_style_first'])) {
    $image['style_name'] = $settings['colorbox_node_style_first'];
  }
  if (isset($item['width']) && isset($item['height'])) {
    $image['width'] = $item['width'];
    $image['height'] = $item['height'];
  }
  if (isset($item['attributes'])) {
    $image['attributes'] = $item['attributes'];
  }
  // Allow image attributes to be overridden.
  if (isset($variables['item']['override']['attributes'])) {
    foreach (array('width', 'height', 'alt', 'title') as $key) {
      if (isset($variables['item']['override']['attributes'][$key])) {
        $image[$key] = $variables['item']['override']['attributes'][$key];
        unset($variables['item']['override']['attributes'][$key]);
      }
    }
    if (isset($image['attributes'])) {
      $image['attributes'] = $variables['item']['override']['attributes'] + $image['attributes'];
    }
    else {
      $image['attributes'] = $variables['item']['override']['attributes'];
    }
  }
  $entity_title = entity_label($entity_type, $entity);
  switch ($settings['colorbox_caption']) {
    case 'auto':
      // If the title is empty use alt or the entity title in that order.
      if (!empty($image['title'])) {
        $caption = $image['title'];
      }
      elseif (!empty($image['alt'])) {
        $caption = $image['alt'];
      }
      elseif (!empty($entity_title)) {
        $caption = $entity_title;
      }
      else {
        $caption = '';
      }
      break;

    case 'title':
      $caption = $image['title'];
      break;

    case 'alt':
      $caption = $image['alt'];
      break;

    case 'node_title':
      $caption = $entity_title;
      break;

    case 'custom':
      $caption = token_replace($settings['colorbox_caption_custom'], array(
        $entity_type => $entity,
        'file' => (object) $item,
      ), array('clear' => TRUE));
      break;

    default:
      $caption = '';
      break;
  }
  // If our custom checkbox is used, overwrite caption.
  if (!empty($settings['use_image_caption_field'])) {
    if (!empty($item['image_field_caption']['value'])) {
      $caption = $item['image_field_caption']['value'];
    }
  }
  // Shorten the caption for the ex styles or when caption shortening is active.
  $colorbox_style = variable_get('colorbox_style', 'default');
  $trim_length = variable_get('colorbox_caption_trim_length', 75);
  if (((strpos($colorbox_style, 'colorbox/example') !== FALSE) || variable_get('colorbox_caption_trim', 0)) && (drupal_strlen($caption) > $trim_length)) {
    $caption = drupal_substr($caption, 0, $trim_length - 5) . '...';
  }
  // Build the gallery id.
  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);
  $entity_id = !empty($id) ? $entity_type . '-' . $id : 'entity-id';
  switch ($settings['colorbox_gallery']) {
    case 'post':
      $gallery_id = 'gallery-' . $entity_id;
      break;

    case 'page':
      $gallery_id = 'gallery-all';
      break;

    case 'field_post':
      $gallery_id = 'gallery-' . $entity_id . '-' . $field['field_name'];
      break;

    case 'field_page':
      $gallery_id = 'gallery-' . $field['field_name'];
      break;

    case 'custom':
      $gallery_id = $settings['colorbox_gallery_custom'];
      break;

    default:
      $gallery_id = '';
  }
  if ($style_name = $settings['colorbox_image_style']) {
    $path = image_style_url($style_name, $image['path']);
  }
  else {
    $path = file_create_url($image['path']);
  }
  return theme('colorbox_imagefield', array(
    'image' => $image,
    'path' => $path,
    'title' => $caption,
    'gid' => $gallery_id,
    'entity' => $entity,
  ));
}
/**
 * @see theme_colorbox_imagefield().
 */
function napo_frontend_colorbox_imagefield($variables) {
  // Load the necessary js file for Colorbox activation.
  if (_colorbox_active() && !variable_get('colorbox_inline', 0)) {
    drupal_add_js(drupal_get_path('module', 'colorbox') . '/js/colorbox_inline.js');
  }
  if ($variables['image']['style_name'] == 'hide') {
    $image = '';
    $class[] = 'js-hide';
  }
  elseif (!empty($variables['image']['style_name'])) {
    $image = theme('image_style', $variables['image']);
  }
  else {
    $image = theme('image', $variables['image']);
  }
  $image_vars = array(
    'style_name' => 'large',
    'path' => $variables['image']['path'],
    'alt' => $variables['entity']->title,
  );
  $popup = theme('image_style', $image_vars);
  $caption = $variables['title'] . napo_common_get_share_widget($variables['entity']);

  $width = 'auto';
  $height = 'auto';
  $gallery_id = $variables['gid'];
  $link_options = drupal_parse_url($variables['image']['path']);
  $link_options = array_merge($link_options, array(
    'html' => TRUE,
    'fragment' => 'colorbox-inline-' . md5($variables['image']['path']),
    'query' => array(
      'width' => $width,
      'height' => $height,
      'title' => $caption,
      'inline' => 'true',
    ),
    'attributes' => array(
      'class' => array('colorbox-inline'),
      'rel' => $gallery_id,
    ),
  ));
  // Remove any parameters that aren't set.
  $link_options['query'] = array_filter($link_options['query']);
  $link_tag = l($image, $variables['path'], $link_options);
  return $link_tag . '<div style="display: none;"><div id="colorbox-inline-' . md5($variables['image']['path']) . '">' . $popup . '</div></div>';
}
