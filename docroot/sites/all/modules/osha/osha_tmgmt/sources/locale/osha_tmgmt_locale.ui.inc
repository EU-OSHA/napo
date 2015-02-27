<?php

class OSHATMGMTLocaleSourceUIController extends TMGMTLocaleSourceUIController {

  /**
   * Gets locale strings.
   *
   * @param string $textgroup
   *   The locale textgroup.
   * @param string $search_label
   *   Label to search for.
   * @param string $missing_target_language
   *   Missing translation language.
   *
   * @return array
   *   List of i18n strings data.
   */
  function getStrings($textgroup, $search_label = NULL, $missing_target_language = NULL, $page_size = 50) {
    $languages = drupal_map_assoc(array_keys(language_list()));
    $select = db_select('locales_source', 'ls')
      ->fields('ls', array('lid', 'source'))
      ->condition('ls.location', db_like('field:field_character_count:') . '%' . db_like(':description'), 'NOT LIKE')
      ->condition('ls.location', db_like('field:field_page_count:') . '%' . db_like(':description'), 'NOT LIKE')
      ->condition('ls.location', db_like('field:comment_body:comment_') . '%', 'NOT LIKE')
      ->condition('ls.location', '%' . db_like(':image:description'), 'NOT LIKE')
      ->groupBy('ls.source')
      ->orderBy('ls.source');

    // Hide Drupal internal strings and show only the OSHA strings
    $strings = module_invoke_all('osha_tmgmt_i18n_string_list');
    if (!empty($strings)) {
      //$or = db_or()->condition('ls.textgroup', array('menu', 'taxonomy'), 'not in');
      //$or->condition('ls.source', $strings, 'in');
      // $select->condition($or);
      $select->condition('ls.source', $strings, 'in');

    }
    // Intersect with the cart and remove items already added to the cart
    $cart = tmgmt_ui_cart_get();
    $job_items = $cart->getJobItemsFromCart();
    $cart_ids = array();
    $cart_strings = array();
    foreach ($job_items as $job_item) {
      if ($job_item->item_type == 'default') {
        $cart_ids[] = $job_item->item_id;
        $string = $job_item->getSourceData();
        $cart_strings[] = $string['singular']['#text'];
      }
    }
    if (!empty($cart_ids)) {
      $select->condition('ls.lid', $cart_ids, 'not in');
    }
    if (!empty($cart_strings)) {
      $select->condition('ls.source', $cart_strings, 'not in');
    }
    if (!empty($search_label)) {
      $select->where('LOWER(CAST(ls.source AS CHAR)) LIKE :search',
        array(':search' => "%" . db_like(strtolower($search_label)) . "%"));
    }
    if (!empty($missing_target_language) && in_array($missing_target_language, $languages)) {
      $select->isNull("lt_$missing_target_language.language");
    }
    foreach ($languages as $langcode) {
      $langcode = str_replace('-', '', $langcode);
      $select->leftJoin('locales_target', "lt_$langcode", "ls.lid = %alias.lid AND %alias.language = '$langcode'");
      $select->addField("lt_$langcode", 'language', "lang_$langcode");
    }
    if ($page_size) {
      $select = $select->extend('PagerDefault')->limit(variable_get('tmgmt_source_list_limit', $page_size));
    }
    return $select->execute()->fetchAll();
  }

  /**
   * Helper function to create translation data list for the sources page list.
   *
   * @param array $strings
   *   Result of the search query returned by tmgmt_i18n_string_get_strings().
   * @param string $type
   *   I18n object type.
   *
   * @return array
   *   Structured array with translation data.
   */
  protected function getTranslationData($strings, $type) {
    $objects = array();
    // Source language of locale strings is always english.
    $source_language = 'en';

    foreach ($strings as $string) {
      $id = $string->lid;
      // Get existing translations and current job items for the entity
      // to determine translation statuses
      $current_job_items = osha_tmgmt_job_item_load_latest('locale', $type, $id, $source_language);
      $objects[$id] = array(
        'id' => $id,
        'object' => $string
      );
      // Load entity translation specific data.
      foreach (language_list() as $langcode => $language) {
        $langcode = str_replace('-', '', $langcode);

        $translation_status = 'current';

        if ($langcode == $source_language) {
          $translation_status = 'original';
        }
        elseif ($string->{'lang_' . $langcode} === NULL) {
          $translation_status = 'missing';
        }

        $objects[$id]['current_job_items'][$langcode] = isset($current_job_items[$langcode]) ? $current_job_items[$langcode] : NULL;
        $objects[$id]['translation_statuses'][$langcode] = $translation_status;
      }
    }
    return $objects;
  }

  /**
   * Gets submitted search params.
   *
   * @return array
   */
  public function getSearchFormSubmittedParams() {
    $params = array(
      'label' => NULL,
      'missing_target_language' => NULL,
      'page_size' => 50,
    );

    if (isset($_GET['label'])) {
      $params['label'] = $_GET['label'];
    }
    if (isset($_GET['missing_target_language'])) {
      $params['missing_target_language'] = $_GET['missing_target_language'];
    }
    if (isset($_GET['page_size'])) {
      $params['page_size'] = $_GET['page_size'];
    }

    return $params;
  }

  public function overviewSearchFormPart($form, &$form_state, $type) {
    $ret = parent::overviewSearchFormPart($form, $form_state, $type);
    $default_values = $this->getSearchFormSubmittedParams();

    $form['search_wrapper']['search']['label']['#weight'] = 0;
    $form['search_wrapper']['search']['missing_target_language'] = 5;
    $form['search_wrapper']['search_submit'] = 10;
    $ret['search_wrapper']['search']['page_size'] = array(
      '#type' => 'select',
      '#title' => t('Items per page'),
      '#options' => array('' => '-- All --', 50 => '50', '100' => 100),
      '#empty_option' => '- All -',
      '#default_value' => isset($default_values['page_size']) ? $default_values['page_size'] : 50,
      '#weight' => 8,
    );
    return $ret;
  }

  /**
   * Implements TMGMTSourceUIControllerInterface::overviewForm().
   */
  public function overviewForm($form, &$form_state, $type) {
    $form += $this->overviewSearchFormPart($form, $form_state, $type);

    $form['items'] = array(
      '#type' => 'tableselect',
      '#header' => $this->overviewFormHeader($type),
      '#empty' => t('No strings matching given criteria have been found.')
    );

    $search_data = $this->getSearchFormSubmittedParams();

    $strings = $this->getStrings($type, $search_data['label'], $search_data['missing_target_language'], $search_data['page_size']);

    foreach ($this->getTranslationData($strings, $type) as $id => $data) {
      $form['items']['#options'][$id] = $this->overviewRow($type, $data);
    }

    $form['pager'] = array('#markup' => theme('pager', array('tags' => NULL)));

    return $form;
  }

  /**
   * Builds a table row for overview form.
   *
   * @param string $type
   *   i18n type.
   * @param array $data
   *   Data needed to build the list row.
   *
   * @return array
   */
  public function overviewRow($type, $data) {
    // Set the default item key, assume it's the first.
    $source = $data['object'];

    $row = array(
      'id' => $data['id'],
      'source' => check_plain($source->source),
    );

    foreach (language_list() as $langcode => $language) {
      $langcode = str_replace('-', '', $langcode);
      $row['langcode-' . $langcode] = theme('osha_tmgmt_ui_translation_language_status_single', array(
        'translation_status' => $data['translation_statuses'][$langcode],
        'job_item' => isset($data['current_job_items'][$langcode]) ? $data['current_job_items'][$langcode] : NULL,
      ));
    }

    return $row;
  }
}
