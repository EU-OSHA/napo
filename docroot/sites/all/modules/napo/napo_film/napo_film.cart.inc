<?php

/**
 * Implements hook_block_view_alter().
 */
function napo_film_block_view_alter(&$data, $block) {
//  if ($block->delta == 'content_cart_summary') {
//    $cart = ContentCart::getCurrentCart();
//    $label = t('Download centre');
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
  $label = t('Download centre');
  $count = $cart->countItems('node');
  $active_class = '';
  if ($count > 0) {
    $active_class = "contet-cart-has-items";
  }
  $html = '<span class="content_cart_summary_label ' . $active_class . '">' . $label . '</span>';
  $html .= '<span class="content_cart_summary_count ' . $active_class . '">' . $count . '</span>';
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
  global $user;
  if (isset($_SESSION['napo_film_cart_mime'][$id])) {
    unset($_SESSION['napo_film_cart_mime'][$id]);
  }
  if (isset($_SESSION['napo_film_select_in_cart'][$id])) {
    unset($_SESSION['napo_film_select_in_cart'][$id]);
  }
  // Destroy session if empty session.
  if (user_is_anonymous() && !empty($user->sid) && empty($_SESSION)) {
    _drupal_session_destroy($user->sid);
  }
}

/**
 * Form for downloading a field_video file in available formats.
 */
function napo_film_cart_add_mime_form($form, &$form_state, $node) {

  $mimes = napo_film_get_films_formats_as_options($node);
  $type = napo_film_video_get_type($node);
  $form['mime_type_select'] = array(
    '#title' => t('Download this film as'),
    '#type' => 'radios',
    '#options' => $mimes,
    '#ajax' => array(
      'callback' => 'napo_film_cart_add_mime_callback',
    ),
  );
  if ($type == 'episode') {
    $form['mime_type_select']['#title'] = t('Download this scene as');
  }

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
function napo_film_content_cart_ajax_submit_alter(&$commands, $input_value, $operation) {
  // Add pop-up when addremove from cart.
  drupal_add_js(drupal_get_path('module', 'content_cart') . '/js/jquery.bootstrap-growl.min.js');
  $cart = ContentCart::getCurrentCart();
  $cart_content = $cart->getCartContent();

  $type = $input_value[0];
  $content_id = $input_value[1];

  $growl_args = array('allow_dismiss' => true, 'width' => 'auto', 'delay' => 2000);
  $block_data = array();
  if ($operation == 'add') {
    if (!empty($cart_content['node'])) {
      foreach ($cart_content['node'] as $nid) {
        // Render thumbnails to the pop-up.
        $node = node_load($nid);
        $wrapper = entity_metadata_wrapper($type, $node);
        $title = $wrapper->label();
        $image_vars = array(
          'style_name' => 'thumbnail',
          'path' => $wrapper->field_image->value()['uri'],
        );
        $image = theme('image_style', $image_vars);
        $block_data[$nid] = theme('napo_film_cart_summary_node_view',
          array('title' => $title, 'image' => $image, 'node' => $node));
      }
      // Render the pop-up.
      $content = theme('napo_film_cart_added_ajax_message', array('data' => $block_data));
      $growl_args['type'] = 'success';
    }
  }
  else {
    $node = node_load($content_id);
    $wrapper = entity_metadata_wrapper($type, $node);
    $title = $wrapper->label();
    $image_vars = array(
      'style_name' => 'thumbnail',
      'path' => $wrapper->field_image->value()['uri'],
    );
    $image = theme('image_style', $image_vars);
    $block_data[$content_id] = theme('napo_film_cart_summary_node_view',
      array('title' => $title, 'image' => $image, 'node' => $node));
    $content = theme('napo_film_cart_removed_ajax_message', array('data' => $block_data));
    $growl_args['type'] = 'warning';
  }
  $content = '<div id="napo-film-cart-growl-' . $content_id . '">' . $content . '</div>';
  $commands[] = ajax_command_remove('.bootstrap-growl');
  $commands[] = ajax_command_invoke('body', 'content_cart_growl', array($content, $growl_args));

  // Refresh content cart summary.
  $commands[] = ajax_command_invoke("[id^='edit-refresh']", 'mousedown');
}

/**
 * Download selected/all form for Download centre page.
 */
function napo_film_cart_download_form($form, &$form_state) {
  $count = napo_film_cart_select_in_cart_count();
  $html_count = '<span class="napo_film_cart_select_count">' . $count . '</span>';
  $cart = ContentCart::getCurrentCart();

  $form['#prefix'] = '<div id="napo_film_cart_download_form_container">';
  $form['#suffix'] = '</div>';

  // Show no results message.
  if ($cart->countItems('node') == 0) {
    return $form;
  }
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
  $form['select_all']['#default_value'] = $cart->countItems('node') == napo_film_cart_select_in_cart_count();
  $form_state['input']['select_all'] = $form['select_all']['#default_value'];

  // The form will be submitted with ajax.
  // The file is created on the disk and callbacks returns a link to it.
  $form['download_selected'] = array(
    '#type' => 'submit',
    '#value' => t('Download selected') . $html_count,
    '#ajax' => array(
      'callback' => 'napo_film_cart_select_in_cart_download_selected',
    ),
    '#attributes' => array(
      'class' => array('download-center-submit-selected'),
    ),
  );
  if ($count == 0) {
    $form['download_selected']['#attributes']['disabled'] = "disabled";
  }

  $form['download_all'] = array(
    '#type' => 'submit',
    '#value' => t('Download all'),
    '#ajax' => array(
      'callback' => 'napo_film_cart_select_in_cart_download_all',
    ),
    '#attributes' => array(
      'class' => array('download-center-submit-all'),
    ),
  );

  $form['loading'] = array(
    '#type' => 'markup',
    '#markup' => '<p class="download-center-waiting">' . t('Please wait while we create the download archive...') . '</p>',
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


/**
 * Callback for ajax submit of Download selected button.
 */
function napo_film_cart_select_in_cart_download_selected($form, $form_state) {
  $commands = array();
  if (!empty($_SESSION['napo_film_select_in_cart'])) {
    $selected_nids = $_SESSION['napo_film_select_in_cart'];
    $cart = ContentCart::getCurrentCart();
    // Get the nodes videos by the mime types selected in cart.
    $mime_types = array();
    if (!empty($_SESSION['napo_film_cart_mime'])) {
      $mime_types = $_SESSION['napo_film_cart_mime'];
    }
    $nodes = node_load_multiple($selected_nids);
    $file_path = napo_cart_download_films($nodes, $mime_types);
    // Get the archive drupal scheme path.
    if (empty($file_path)) {
      napo_film_cart_download_error_commands($commands);
    }
    else {
      // Remove from cart selected nodes..
      $cart->removeFromCart('node', $selected_nids);
      foreach ($selected_nids as $nid) {
        unset($_SESSION['napo_film_cart_mime'][$nid]);
      }
      unset($_SESSION['napo_film_select_in_cart']);
      napo_film_cart_download_success_commands($commands, $file_path);
    }
  }
  $page = array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
  return $page;
}

/**
 * Callback for ajax submit of Download all button.
 */
function napo_film_cart_select_in_cart_download_all($form, &$form_state) {
  $cart = ContentCart::getCurrentCart();
  $films = $cart->getCartContent();
  $commands = array();

  if (!empty($films['node'])) {
    // Get the nodes videos by the mime types selected in cart.
    $mime_types = array();
    if (!empty($_SESSION['napo_film_cart_mime'])) {
      $mime_types = $_SESSION['napo_film_cart_mime'];
    }
    $nids = $films['node'];
    $nodes = node_load_multiple($nids);
    $file_path = napo_cart_download_films($nodes, $mime_types);
    // Get the archive drupal scheme path.
    if (empty($file_path)) {
      napo_film_cart_download_error_commands($commands);
    }
    else {
      // Empty the cart, the selection and mime types.
      $cart->removeFromCart('node');
      unset($_SESSION['napo_film_select_in_cart']);
      unset($_SESSION['napo_film_cart_mime']);
      napo_film_cart_download_success_commands($commands, $file_path);
    }
  }
  $page = array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
  return $page;
}

/**
 * Add ajax commands when creating the archive is success.
 */
function napo_film_cart_download_success_commands(&$commands, $file_path) {
  $text = variable_get('napo_film_download_center_success_message',
    'Click here to download your selected videos!');
  $message = theme('napo_film_download_cart_complete', array(
      'file_path' => file_create_url($file_path),
      'message' => t($text),
    )
  );
  // Return the success message and
  // Refresh the Download centre: view, cart summary block and cart form.
  $commands[] = ajax_command_prepend('#block-napo-film-download-cart-form', $message);
  $commands[] = ajax_command_invoke('body', 'napo_film_refresh_download_center');
}

/**
 * Add ajax commands when creating the archive has error.
 */
function napo_film_cart_download_error_commands(&$commands) {
  $error = t('There was an error creating the archive!');
  $message = theme('napo_film_download_cart_error', array('error' => $error));
  $commands[] = ajax_command_remove('.download-center-error', $message);
  $commands[] = ajax_command_prepend('#block-napo-film-download-cart-form', $message);
}

/**
 * Get the file of a mime type from node's field_video.
 *
 * @param stdClass $node
 * @param string $mime
 *   The requested mime type of a file from field_video
 *
 * @return array|null
 *   File entity as an array| If not found - NULL.
 *
 */
function napo_film_cart_node_get_video_by_mime($node, $mime) {
  $file = NULL;
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $videos = $node_wrapper->field_video->value();
  foreach ($videos as $video) {
    if ($video['filemime'] == $mime) {
      return $video;
    }
  }
  return $file;
}

/**
 * Get the archive of videos from a collection of nodes.
 *
 * @param array $nodes
 *   Array of nodes
 * @param array $mime_types
 *   Array of mime types of videos to be added to archive keyed by nid.
 *
 * @return null|string
 *   Archive path (drupal scheme) | NULL if archive was not created.
 */
function napo_cart_download_films($nodes, $mime_types = array()) {
  $download_files = array();
  foreach ($nodes as $node) {
    // Default to video/mp4
    if (empty($mime_types[$node->nid])) {
      $mime = 'video/mp4';
    }
    else {
      $mime = $mime_types[$node->nid];
    }
    $video = napo_film_cart_node_get_video_by_mime($node, $mime);
    if (!empty($video)) {
      $download_files[] = $video;
    }
  }
  // Get the archive drupal scheme path.
  return napo_cart_download_videos($download_files);
}

/**
 * Get the archive of a collection of files.
 *
 * @param array $files
 *   Files objects
 *
 * @return null|string
 *   Archive path (drupal scheme) | NULL if archive was not created
 */
function napo_cart_download_videos($files) {
  if (!empty($files)) {
    $drupal_dir_path = NAPO_FILM_DOWN_CENTER_PATH;
    $dir_path = drupal_realpath($drupal_dir_path);
    // Return if dir don't exists.
    if (!file_prepare_directory($drupal_dir_path, FILE_CREATE_DIRECTORY)) {
      watchdog('napo_film', 'The directory !dir could not be accessed!', array('!dir' => $drupal_dir_path), WATCHDOG_ERROR);
      return NULL;
    }
    // Check if it's enough disks pace to create the archive.
    $files_size = 0;
    foreach ($files as $file) {
      $files_size += $file['filesize'];
      if (disk_free_space($dir_path) < $files_size) {
        watchdog('napo_film', 'There is not enough space to create a zip with files of !size MB!',
          array('!size' => $files_size / pow(1024, 2)), WATCHDOG_ERROR);
        return NULL;
      }
    }

    // Open the archive.
    $archive = new ZipArchive();
    $archive_path = tempnam($dir_path, 'napo_download_') . '.zip';
    $archive->open($archive_path, ZIPARCHIVE::CREATE);
    foreach ($files as $file) {
      $file_path = drupal_realpath($file['uri']);
      $archive->addFile($file_path, drupal_basename($file_path));
    }
    $archive->close();
    // Return drupal scheme file path.
    $archive_name = drupal_basename($archive_path);
    $archive_drupal_path = $drupal_dir_path . '/' . $archive_name;
    return $archive_drupal_path;
  }
  return NULL;
}

function napo_cart_get_archive_name_id() {
  global $user;
  $file_id = str_shuffle($user->sid);
  $file_id = substr($file_id, rand(0, 30), 5);
  $file_id .= time();
  return $file_id;
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
