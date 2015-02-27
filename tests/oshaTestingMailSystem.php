<?php

require_once '../docroot/includes/mail.inc';
require_once '../docroot/modules/system/system.mail.inc';
/**
 * A mail sending implementation that captures sent messages to a variable.
 *
 * This class is for running tests or for development.
 */
class oshaTestingMailSystem extends DefaultMailSystem implements MailSystemInterface {

  /**
   * Accept an e-mail message and store it in a variable.
   *
   * @param array $message
   *
   * @return bool
   */
  public function mail(array $message) {
    $captured_emails = variable_get('drupal_test_email_collector', array());
    foreach ($message['params'] as $key => $param) {
      if (is_object($param) && get_class($param) !== 'stdClass') {
        unset($message['params'][$key]);
      }
    }
    $captured_emails[] = $message;
    variable_set('drupal_test_email_collector', $captured_emails);
    return TRUE;
  }
}