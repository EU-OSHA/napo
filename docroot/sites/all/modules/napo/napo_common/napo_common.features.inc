<?php
/**
 * @file
 * napo_common.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function napo_common_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function napo_common_image_default_styles() {
  $styles = array();

  // Exported image style: medium2.
  $styles['medium2'] = array(
    'name' => 'medium2',
    'label' => 'Medium 2 (320x320)',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 320,
          'height' => 320,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: napo_original.
  $styles['napo_original'] = array(
    'name' => 'napo_original',
    'label' => 'Original image style',
    'effects' => array(),
  );

  return $styles;
}
