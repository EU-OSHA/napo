<?php

/**
 * Copy this settings at the end of your settings.php file and modify to fit
 * your environment.
 */
$conf['cache_backends'][] = 'sites/all/modules/contrib/memcache_storage/memcache_storage.inc';
$conf['cache_default_class'] = 'MemcacheStorage';
$conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
$conf['memcache_storage_key_prefix'] = 'napo-staging';
$conf['memcache_storage_compress_data'] = TRUE;
$conf['memcache_storage_debug'] = FALSE;
$conf['memcache_servers'] = array(
  'some-server:11211' => 'default',
);
// Configure Memcache Storage module.
$conf['memcache_storage_wildcard_invalidate'] = 60 * 60; // 1 hour

// Varnish cache configuration.
$conf['cache_backends'][] = 'sites/all/modules/contrib/varnish/varnish.cache.inc';
$conf['cache_class_cache_page'] = 'VarnishCache';

$conf['page_cache_invoke_hooks'] = False;
$conf['reverse_proxy'] = True;
$conf['cache_lifetime'] = 0;
$conf['page_cache_maximum_age'] = 21600;
$conf['reverse_proxy_header'] = 'HTTP_X_FORWARDED_FOR';
$conf['reverse_proxy_addresses'] = array('127.0.0.1');
$conf['omit_vary_cookie'] = True;
