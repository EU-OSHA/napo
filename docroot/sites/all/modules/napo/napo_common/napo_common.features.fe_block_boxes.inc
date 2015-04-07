<?php
/**
 * @file
 * napo_common.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function napo_common_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Zoom options';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'zoom_options';
  $fe_block_boxes->body = '<p>Set font size <em class="glyphicon glyphicon-menu-up">&nbsp;</em><span style="font-size: medium;"><a class="a_big" onclick="zoomBig()">A</a></span>&nbsp;&nbsp;<span style="font-size: small;"><em class="glyphicon glyphicon-menu-down">&nbsp;</em><a class="a_small" onclick="zoomSmall()">A</a></span></p>';

  $export['zoom_options'] = $fe_block_boxes;

  return $export;
}
