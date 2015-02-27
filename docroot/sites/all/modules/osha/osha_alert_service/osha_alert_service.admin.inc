<?php

/**
 * Module's configuration form.
 */
function osha_alert_service_admin_form($form, &$form_state) {
  $entity = entity_get_info('osha_alert_service');
  $token_types = array();
  $token_types['osha_alert_service'] = $entity;
  $form['osha_alert_service_mail'] = array(
    '#title' => 'Email Templates',
    '#type' => 'fieldset',
  );
  $form['osha_alert_service_mail']['osha_alert_service_alert_subject'] = array(
    '#title' => 'Alert email subject',
    '#type' => 'textfield',
    '#default_value' => variable_get('osha_alert_service_alert_subject',
      'EU-OSHA alert'),
  );
  $form['osha_alert_service_mail']['osha_alert_service_alert_body'] = array(
    '#title' => t('Alert email body'),
    '#type' => 'textarea',
    '#default_value' => variable_get('osha_alert_service_alert_body', <<<EOT
[osha_alert_service:alert_content]
<p><span style="font-size:11px"><span style="color:#A9A9A9">If you don&#39;t want to receive this alert, you can&nbsp;</span><strong><a href="[unsubscribe_link]"><span style="color:#A9A9A9">usubscribe</span></a><span style="color:#A9A9A9">.</span></strong></span></p>
EOT
    )
  );
  $form['osha_alert_service_mail']['osha_alert_service_subscribe_subject'] = array(
    '#title' => 'Subscribe email subject',
    '#type' => 'textfield',
    '#default_value' => variable_get('osha_alert_service_subscribe_subject',
      'Your subscription to OSHA Alert Service'),
  );
  $form['osha_alert_service_mail']['osha_alert_service_subscribe_body'] = array(
    '#title' => t('Subscribe email body'),
    '#type' => 'textarea',
    '#default_value' => variable_get('osha_alert_service_subscribe_body', <<<EOT
<p>EU-OSHA received a request to start sending alerts to <strong>[osha_alert_service:email]</strong>.</p>

<p>Verify this EU-OSHA alert request: [osha_alert_service:subscribe_conf_link]</p>

<p>Cancel this EU-OSHA alert request: [osha_alert_service:unsubscribe_link]</p>

<p>If you are not able to click on the link, you can cut and paste it into your browser&#39;s address bar.</p>

<p>If you did not initiate this request or believe it was sent in error you can safely ignore this message.</p>

<p>Thanks,</p>
<p><strong>The EU-OSHA alerts Team</strong></p>
EOT
    )
  );

  if (module_exists('token')) {
    $form['tokens'] = array(
      '#title' => 'Replacement tokens',
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['tokens']['token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('osha_alert_service'),
    );
  }
  else {
    $form['token_tree'] = array(
      '#markup' => '<p>' . t('Enable the <a href="@drupal-token">Token module</a> to view the available token browser.', array('@drupal-token' => 'http://drupal.org/project/token')) . '</p>',
    );
  }

  $form['test'] = array(
    '#title' => 'Test',
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['test']['osha_alert_service_test_reset_months'] = array(
    '#title' => 'Months to reset',
    '#type' => 'textfield',
    '#description' => 'Number of months to reset back your last sent alert date.',
    '#default_value' => variable_get('osha_alert_service_test_reset_months', 1),
  );
  $form['test']['test_submit'] = array(
    '#value' => 'Test your alerts',
    '#type' => 'submit',
    '#suffix' => 'This will reset your last send alert time to 1 month ago and runs the Cron! Use it with caution! ',
    '#submit' => array('osha_alert_service_test_my_email_submit'),
  );

  return system_settings_form($form);
}

/**
 * Submit callback to test current user alerts.
 */
function osha_alert_service_test_my_email_submit($form, &$form_state) {
  global $user;
  $months = $form_state['values']['osha_alert_service_test_reset_months'];
  $month_ago = strtotime("-" . $months . " month");
  db_update('osha_alert_service')
    ->fields(array(
      'last_alert' => $month_ago,
    ))
    ->condition('email', $user->mail)
    ->execute();
  drupal_cron_run();
  drupal_set_message('Your subscription last sent was reseted ' . $months . ' months ago!', 'warning');
}
