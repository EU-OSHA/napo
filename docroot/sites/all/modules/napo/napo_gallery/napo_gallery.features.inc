<?php
/**
 * @file
 * napo_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function napo_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_entityqueue_api().
 */
function napo_gallery_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function napo_gallery_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function napo_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: mc_napo_thumbnail.
  $styles['mc_napo_thumbnail'] = array(
    'label' => 'MC Napo Thumbnail (360x275)',
    'effects' => array(
      16 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 360,
          'height' => 275,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'mc_napo_thumbnail',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: napo_cover.
  $styles['napo_cover'] = array(
    'label' => 'Napo Cover (1140x408)',
    'effects' => array(
      11 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1140,
          'height' => 410,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'napo_cover',
        ),
        'weight' => -11,
      ),
    ),
  );

  // Exported image style: napo_large.
  $styles['napo_large'] = array(
    'label' => 'Napo Large (800)',
    'effects' => array(
      17 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => 800,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: napo_thumbnail.
  $styles['napo_thumbnail'] = array(
    'label' => 'Napo Thumbnail (360x275)',
    'effects' => array(
      14 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 450,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
      13 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#1f3695',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 360,
            'height' => 275,
            'xpos' => 'center',
            'ypos' => 'top',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => -9,
      ),
      15 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 360,
          'height' => 275,
          'anchor' => 'center-top',
        ),
        'weight' => -8,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function napo_gallery_node_info() {
  $items = array(
    'napo_album' => array(
      'name' => 'Napo album',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'napo_image' => array(
      'name' => 'Napo image',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
