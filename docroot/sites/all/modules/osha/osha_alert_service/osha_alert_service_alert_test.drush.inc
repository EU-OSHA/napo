<?php

/**
 * Implements hook_COMMAND_drush_command().
 */
function osha_alert_service_alert_test_drush_command() {
  $items = array();
  $items['osha-alert-test'] = array(
    'description' => 'Simulate a translation workflow',
    'aliases' => array('oshast'),
    'examples' => array(),
    'arguments' => array(
      'email' => 'Email to send the alert',
    ),
    'options' => array(),
    'sections' => array(),
  );
  return $items;
}

function drush_osha_alert_service_alert_test_osha_alert_test($email = NULL) {
  if ($email) {
    $entity = entity_create(
      'osha_alert_service',
      array(
        'email' => $email,
        'filters' => '{"section":["0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35"],"type":["article"],"languages":["de"]}',
        'schedule' => 'monthly',
        'created' => '1355757801',
        'token' => 'fa5358bcd7d82c729fba15410630ed4986631f87',
        'confirmed' => 1,
        // 2012-12-17 17:23:21
        'last_alert' => '1355757801',
      )
    );
    entity_save('osha_alert_service', $entity);
    echo "Running cron ....\n";
    drupal_cron_run();
    echo "Check your email ...\n";
    //entity_delete('osha_alert_service', $entity->id);
  }
  else {
    drush_log("Usage: drush osha-alert-test email", "error");
  }
}
