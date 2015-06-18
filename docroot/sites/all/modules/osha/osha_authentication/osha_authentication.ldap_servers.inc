<?php
/**
 * @file
 * osha_authentication.ldap_servers.inc
 */

/**
 * Implements hook_default_ldap_servers().
 */
function osha_authentication_default_ldap_servers() {
  $export = array();

  $ldap_servers_conf = new stdClass();
  $ldap_servers_conf->disabled = FALSE; /* Edit this to true to make a default ldap_servers_conf disabled initially */
  $ldap_servers_conf->api_version = 1;
  $ldap_servers_conf->sid = 'osha';
  $ldap_servers_conf->name = 'osha-ldap';
  $ldap_servers_conf->status = TRUE;
  $ldap_servers_conf->ldap_type = 'openldap';
  $ldap_servers_conf->address = '194.30.59.219';
  $ldap_servers_conf->port = 389;
  $ldap_servers_conf->tls = FALSE;
  $ldap_servers_conf->followrefs = FALSE;
  $ldap_servers_conf->bind_method = 1;
  $ldap_servers_conf->binddn = 'cn=Reader,dc=osha,dc=europa,dc=eu';
  $ldap_servers_conf->bindpw = 'wsU1KJJ3boh0elfQugjk8AmEeCw=';
  $ldap_servers_conf->basedn = array(
    0 => 'ou=people,dc=osha,dc=europa,dc=eu',
    1 => 'ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu',
  );
  $ldap_servers_conf->user_attr = 'uid';
  $ldap_servers_conf->account_name_attr = '';
  $ldap_servers_conf->mail_attr = 'mail';
  $ldap_servers_conf->mail_template = '';
  $ldap_servers_conf->picture_attr = '';
  $ldap_servers_conf->unique_persistent_attr = 'dn';
  $ldap_servers_conf->unique_persistent_attr_binary = FALSE;
  $ldap_servers_conf->user_dn_expression = '';
  $ldap_servers_conf->ldap_to_drupal_user = '';
  $ldap_servers_conf->testing_drupal_username = 'CRomanescu';
  $ldap_servers_conf->testing_drupal_user_dn = 'uid=CRomanescu,ou=Contractors,ou=people,dc=osha,dc=europa,dc=eu';
  $ldap_servers_conf->grp_unused = FALSE;
  $ldap_servers_conf->grp_object_cat = 'posixgroup';
  $ldap_servers_conf->grp_nested = FALSE;
  $ldap_servers_conf->grp_user_memb_attr_exists = FALSE;
  $ldap_servers_conf->grp_user_memb_attr = '';
  $ldap_servers_conf->grp_memb_attr = 'memberuid';
  $ldap_servers_conf->grp_memb_attr_match_user_attr = 'uid';
  $ldap_servers_conf->grp_derive_from_dn = FALSE;
  $ldap_servers_conf->grp_derive_from_dn_attr = '';
  $ldap_servers_conf->grp_test_grp_dn = 'cn=ACCESS_EDT,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu';
  $ldap_servers_conf->grp_test_grp_dn_writeable = 'cn=TEST,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu';
  $ldap_servers_conf->search_pagination = FALSE;
  $ldap_servers_conf->search_page_size = 1000;
  $ldap_servers_conf->weight = 0;
  $export['osha'] = $ldap_servers_conf;

  $ldap_servers_conf = new stdClass();
  $ldap_servers_conf->disabled = FALSE; /* Edit this to true to make a default ldap_servers_conf disabled initially */
  $ldap_servers_conf->api_version = 1;
  $ldap_servers_conf->sid = 'osha-write';
  $ldap_servers_conf->name = 'osha-write';
  $ldap_servers_conf->status = TRUE;
  $ldap_servers_conf->ldap_type = 'openldap';
  $ldap_servers_conf->address = '194.30.59.219';
  $ldap_servers_conf->port = 389;
  $ldap_servers_conf->tls = FALSE;
  $ldap_servers_conf->followrefs = FALSE;
  $ldap_servers_conf->bind_method = 1;
  $ldap_servers_conf->binddn = 'cn=admin,dc=osha,dc=europa,dc=eu';
  $ldap_servers_conf->bindpw = 'Lmy3Jfd90BCZcw9Cny8AdNCGzBZEEg==';
  $ldap_servers_conf->basedn = array();
  $ldap_servers_conf->user_attr = 'uid';
  $ldap_servers_conf->account_name_attr = '';
  $ldap_servers_conf->mail_attr = 'mail';
  $ldap_servers_conf->mail_template = '';
  $ldap_servers_conf->picture_attr = '';
  $ldap_servers_conf->unique_persistent_attr = 'dn';
  $ldap_servers_conf->unique_persistent_attr_binary = FALSE;
  $ldap_servers_conf->user_dn_expression = '';
  $ldap_servers_conf->ldap_to_drupal_user = '';
  $ldap_servers_conf->testing_drupal_username = 'CRomanescu';
  $ldap_servers_conf->testing_drupal_user_dn = 'uid=CRomanescu,ou=Contractors,ou=people,dc=osha,dc=europa,dc=eu';
  $ldap_servers_conf->grp_unused = FALSE;
  $ldap_servers_conf->grp_object_cat = 'posixgroup';
  $ldap_servers_conf->grp_nested = FALSE;
  $ldap_servers_conf->grp_user_memb_attr_exists = FALSE;
  $ldap_servers_conf->grp_user_memb_attr = '';
  $ldap_servers_conf->grp_memb_attr = 'memberuid';
  $ldap_servers_conf->grp_memb_attr_match_user_attr = 'uid';
  $ldap_servers_conf->grp_derive_from_dn = FALSE;
  $ldap_servers_conf->grp_derive_from_dn_attr = '';
  $ldap_servers_conf->grp_test_grp_dn = 'cn=ACCESS_EDT,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu';
  $ldap_servers_conf->grp_test_grp_dn_writeable = 'cn=TEST,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu';
  $ldap_servers_conf->search_pagination = FALSE;
  $ldap_servers_conf->search_page_size = 1000;
  $ldap_servers_conf->weight = 0;
  $export['osha-write'] = $ldap_servers_conf;

  return $export;
}
