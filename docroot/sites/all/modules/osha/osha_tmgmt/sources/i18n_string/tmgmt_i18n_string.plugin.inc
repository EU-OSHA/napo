<?php

/**
 * @file
 * Provides the i18n string source controller.
 */

/**
 * Translation plugin controller for i18n strings.
 */
class OSHATMGMTI18nStringSourcePluginController extends TMGMTI18nStringSourcePluginController {

  /**
   * {@inheritdoc}
   */
  public function saveTranslation(TMGMTJobItem $job_item) {
    $job = tmgmt_job_load($job_item->tjid);
    $data = array_filter(tmgmt_flatten_data($job_item->getData()), '_tmgmt_filter_data');
    foreach ($data as $i18n_string => $item) {
      if (isset($item['#translation']['#text'])) {
        i18n_string_translation_update($i18n_string, $item['#translation']['#text'], $job_item->target_language);
      }
    }

    // We just saved the translation, set the state of the job item to
    // 'finished'.
    $job_item->accepted();
  }
}
