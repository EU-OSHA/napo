<?php
/**
 * @file
 * napo_breadcrumbs.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function napo_breadcrumbs_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'download_center';
  $path_breadcrumb->name = 'Download centre';
  $path_breadcrumb->path = 'download-center';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -95;
  $export['download_center'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'napo_episode_full';
  $path_breadcrumb->name = 'Napo Episode Full';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => 'Scenes',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '%node:field-napo-film:url/view-episodes',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:napo_video:field_video_type',
          'settings' => array(
            'field_video_type' => array(
              'und' => array(
                0 => array(
                  'tid' => '2726',
                ),
              ),
            ),
            'field_video_type_tid' => array(
              0 => '2726',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -93;
  $export['napo_episode_full'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'napo_films_episodes';
  $path_breadcrumb->name = 'Napo films episodes';
  $path_breadcrumb->path = 'napos-films/films';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Napo\'s films',
      1 => 'Films',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -98;
  $export['napo_films_episodes'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'napo_for_teachers';
  $path_breadcrumb->name = 'Napo for teachers';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'using-napo/napo-for-teachers',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -96;
  $export['napo_for_teachers'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'napo_gallery';
  $path_breadcrumb->name = 'Napo Gallery';
  $path_breadcrumb->path = 'about-napo/napos-gallery';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -97;
  $export['napo_gallery'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'napo_s_film_episodes_panel';
  $path_breadcrumb->name = 'Napo\'s film episodes - panel';
  $path_breadcrumb->path = 'node/%node/view-episodes';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'napo_video' => 'napo_video',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:napo_video:field_video_type',
          'settings' => array(
            'field_video_type' => array(
              'und' => array(
                0 => array(
                  'tid' => '2727',
                ),
              ),
            ),
            'field_video_type_tid' => array(
              0 => '2727',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -100;
  $export['napo_s_film_episodes_panel'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'napos_friends';
  $path_breadcrumb->name = 'Napo Friends';
  $path_breadcrumb->path = 'about-napo/napo-and-friends';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -99;
  $export['napos_friends'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'node_breadcrumbs';
  $path_breadcrumb->name = 'Node breadcrumbs';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:napo_video:field_video_type',
          'settings' => array(
            'field_video_type' => array(
              'und' => array(
                0 => array(
                  'tid' => '2726',
                ),
              ),
            ),
            'field_video_type_tid' => array(
              0 => '2726',
            ),
          ),
          'context' => 'node',
          'not' => TRUE,
        ),
        1 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'using-napo/rights-and-permissions',
          ),
          'context' => 'empty',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -92;
  $export['node_breadcrumbs'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'rights_and_permissions';
  $path_breadcrumb->name = 'Rights and permissions';
  $path_breadcrumb->path = 'node/26';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Using Napo',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['rights_and_permissions'] = $path_breadcrumb;

  return $export;
}
