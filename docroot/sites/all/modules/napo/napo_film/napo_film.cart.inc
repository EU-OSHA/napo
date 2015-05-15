<?php

/**
 * Implements hook_block_view_alter().
 */
function napo_film_block_view_alter(&$data, $block) {
//  if ($block->delta == 'content_cart_summary') {
//    $cart = ContentCart::getCurrentCart();
//    $label = t('Download center');
//    $count = $cart->countItems('node');
//    $html = '<span class="content_cart_summary_label">' . $label . '</span>';
//    $html .= '<span class="content_cart_summary_count">' . $count . '</span>';
//    $link = l($html, 'download-center', array('html' => TRUE));
//    $content['content_cart_summary'] = array(
//      '#prefix' => '<div id="content_cart_summary_container">',
//      '#markup' => $link,
//      '#suffix' => '</div>',
//    );
//    $data['content'] = $content;
//  }
}

function napo_film_cart_summary_content_alter(&$content) {
  $cart = ContentCart::getCurrentCart();
  $label = t('Download center');
  $count = $cart->countItems('node');
  $html = '<span class="content_cart_summary_label">' . $label . '</span>';
  $html .= '<span class="content_cart_summary_count">' . $count . '</span>';
  $link = l($html, 'download-center', array('html' => TRUE));
  $content['content_cart_summary'] = array(
    '#prefix' => '<div id="content_cart_summary_container">',
    '#markup' => $link,
    '#suffix' => '</div>',
  );
}

function napo_film_cart_add_mime_callback($form, $form_state) {
  $node = $form_state['build_info']['args'][0];
  $cart = ContentCart::getCurrentCart();
  $cart_content = $cart->getCartContent();
  $mime = $form_state['values']['mime_type_select'];
  if (isset($cart_content['node'][$node->nid])) {
    $_SESSION['napo_film_cart_mime'][$node->nid] = $mime;
  }
  return;
//  return $form['checkboxes_fieldset'];
}

function napo_film_cart_get_stored_mime($nid) {
  $mime = NULL;
  if (isset($_SESSION['napo_film_cart_mime'][$nid])) {
    $mime = $_SESSION['napo_film_cart_mime'][$nid];
  }
  return $mime;
}

function napo_film_content_cart_remove_item($type, $id) {
  if (isset($_SESSION['napo_film_cart_mime'][$id])) {
    unset($_SESSION['napo_film_cart_mime'][$id]);
  }
  if (isset($_SESSION['napo_film_select_in_cart'][$id])) {
    unset($_SESSION['napo_film_select_in_cart'][$id]);
  }
}

/**
 * Form for downloading a field_video file in available formats.
 */
function napo_film_cart_add_mime_form($form, &$form_state, $node) {

  $mimes = napo_film_get_films_formats_as_options($node);
  $form['mime_type_select'] = array(
    '#title' => t('Download this film as'),
    '#type' => 'radios',
    '#options' => $mimes,
    '#ajax' => array(
      'callback' => 'napo_film_cart_add_mime_callback',
    ),
  );
  if ($default_mime = napo_film_cart_get_stored_mime($node->nid)) {
    $form['mime_type_select']['#default_value'] = $default_mime;
  }
  elseif (isset($mimes['video/mp4'])) {
    $form['mime_type_select']['#default_value'] = 'video/mp4';
  }
  else {
    $form['mime_type_select']['#default_value'] = current(array_keys($mimes));
  }
  return $form;
}

/**
 * Implements hook_content_cart_ajax_submit_alter().
 */
function napo_film_content_cart_ajax_submit_alter(&$commands, $input_value) {
  // Refresh the download block when changing the cart.
  $commands[] = ajax_command_invoke("[id^='edit-refresh']", 'mousedown');
}


function napo_film_cart_download_form($form, &$form_state) {
  $count = napo_film_cart_select_in_cart_count();
  $html_count = '<span class="napo_film_cart_select_count">' . $count . '</span>';

  $form['#prefix'] = '<div id="napo_film_cart_download_form_container">';
  $form['#suffix'] = '</div>';
  $form['select_all'] = array(
    '#title' => t('Select all'),
    '#type' => 'checkbox',
    '#attributes' => array(
      'onchange' => 'napo_film_cart_select_all(this)',
    ),
    '#ajax' => array(
      'callback' => 'napo_film_cart_download_form_select_all_callback',
      'wrapper' => 'napo_film_cart_download_form_container',
      'method' => 'replace',
    ),
  );
  $cart = ContentCart::getCurrentCart();
  $form['select_all']['#default_value'] = $cart->countItems('node') == napo_film_cart_select_in_cart_count();
  $form_state['input']['select_all'] = $form['select_all']['#default_value'];

  $form['download_selected'] = array(
    '#type' => 'submit',
    '#value' => t('Download selected') . $html_count,
    '#submit' => array('napo_film_cart_select_in_cart_download_selected'),
  );

  $form['download_all'] = array(
    '#type' => 'submit',
    '#value' => t('Download all'),
    '#submit' => array('napo_film_cart_select_in_cart_download_all'),
  );

  $form['refresh'] = array(
    '#type' => 'submit',
    '#value' => t('Refresh'),
    '#submit' => array('napo_film_cart_download_form_refresh_callback'),
    '#ajax' => array(
      'callback' => 'napo_film_cart_download_form_refresh_callback',
      'wrapper' => 'napo_film_cart_download_form_container',
      'method' => 'replace',
    ),
    '#attributes' => array('style' => 'display: none;'),
  );

  return $form;
}

function napo_film_cart_select_in_cart_callback($nid) {
  if (empty($_SESSION['napo_film_select_in_cart'][$nid])) {
    $_SESSION['napo_film_select_in_cart'][$nid] = $nid;
  }
  else {
    unset($_SESSION['napo_film_select_in_cart'][$nid]);
  }
  $commands[] = ajax_command_invoke("[id^='edit-refresh']", 'mousedown');
  $page = array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
  ajax_deliver($page);
}

function napo_film_cart_select_in_cart_add($nid) {
  if (empty($_SESSION['napo_film_select_in_cart'][$nid])) {
    $_SESSION['napo_film_select_in_cart'][$nid] = $nid;
  }
}

function napo_film_cart_select_in_cart_remove($nid) {
  if (!empty($_SESSION['napo_film_select_in_cart'][$nid])) {
    unset($_SESSION['napo_film_select_in_cart'][$nid]);
  }
}

function napo_film_cart_select_in_cart_selected($nid) {
  return !empty($_SESSION['napo_film_select_in_cart'][$nid]);
}

function napo_film_cart_select_in_cart_count() {
  $count = 0;
  if (!empty($_SESSION['napo_film_select_in_cart'])) {
    $count = count($_SESSION['napo_film_select_in_cart']);
  }
  return $count;
}

function napo_film_cart_select_in_cart_download_selected($form, $form_state) {
  unset($_SESSION['napo_film_select_in_cart']);
}

function napo_film_cart_select_in_cart_download_all($form, $form_state) {
  $cart = ContentCart::getCurrentCart();
  $films = $cart->getCartContent();
}

function napo_film_cart_download_form_refresh_callback($form, &$form_state) {
  return drupal_rebuild_form('napo_film_cart_download_form', $form_state, $form);
}

function napo_film_cart_download_form_select_all_callback($form, &$form_state) {
  if ($form_state['values']['select_all']) {
    napo_film_cart_download_form_select_all();
  }
  else {
    napo_film_cart_download_form_remove_all();
  }
  return napo_film_cart_download_form_refresh_callback($form, $form_state);
}

function napo_film_cart_download_form_select_all() {
  $cart = ContentCart::getCurrentCart();
  $cart_content = $cart->getCartContent();
  if (!empty($cart_content['node'])) {
    foreach ($cart_content['node'] as $nid) {
      napo_film_cart_select_in_cart_add($nid);
    }
  }
}

function napo_film_cart_download_form_remove_all() {
  $cart = ContentCart::getCurrentCart();
  $cart_content = $cart->getCartContent();
  if (!empty($cart_content['node'])) {
    foreach ($cart_content['node'] as $nid) {
      napo_film_cart_select_in_cart_remove($nid);
    }
  }
}
