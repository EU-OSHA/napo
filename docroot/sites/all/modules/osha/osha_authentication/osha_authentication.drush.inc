<?php

function osha_authentication_drush_command() {
  return array(
    'osha-ldap-configure' => array(
      'description' => 'Create the LDAP servers defined in config.json',
    )
  );
}

function drush_osha_authentication_osha_ldap_configure() {
  $config = json_decode(file_get_contents(DRUPAL_ROOT . '/../conf/config.json'), TRUE);
  if (!empty($config['ldap'])) {
    module_load_include('inc', 'ldap_user', 'ldap_user.admin');
    module_load_include('inc', 'ldap_authentication', 'ldap_authentication.admin');
    module_load_include('inc', 'ldap_authorization', 'ldap_authorization.admin');

    // admin/config/people/ldap/servers
    $ldap_server = $config['ldap']['server'];
    $sid = $ldap_server['sid'];
    module_load_include('module', 'osha_authentication');
    osha_authentication_create_ldap_server($sid, 'add', $ldap_server);

    // admin/config/people/ldap/authentication
    $auth_conf = new LdapAuthenticationConfAdmin();
    $auth_conf->drupalFormSubmit($config['ldap']['authentication']);


    // admin/config/people/ldap/user
    // $form_state = array('values' => $config['ldap']['user']);
    // $ldap_user_conf = ldap_user_conf('admin');
    // $ldap_user_conf->drupalFormSubmit($form_state['values'], array());

    // admin/config/people/ldap/authorization
    $consumer_type = $config['ldap']['authorization']['consumer_type'];
    $consumer = ldap_authorization_get_consumer_object($consumer_type);
    $consumer_conf = new LdapAuthorizationConsumerConfAdmin($consumer, TRUE);
    $consumer_conf->drupalFormSubmit('add', $config['ldap']['authorization']);
  }
  else {
    drupal_set_message('Cannot find "ldap" configuration key in config.json, LDAP server not created!', 'warning');
  }
}
