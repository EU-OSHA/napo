<?php

require_once 'theme/menu/menu.inc';

/**
 * Implements hook_preprocess_node().
 */
function napo_frontend_preprocess_node(&$vars) {
  $node = $vars['node'];

  if($node->type == 'napo_video') {
    $vars['back_button'] = l(t('Back to Napo\'s Films'), '/napos-films/films');
  }
}
