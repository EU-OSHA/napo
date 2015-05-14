<?php

/**
 * Implements hook_drush_command().
 */
function napo_migration_drush_command() {
  $items = array();

  $items['assign-tags-to-films'] = array(
    'description' => 'Assign tags for NAPO films.',
    'callback' => 'drush_assign_tags_to_films',
  );

  $items['clean-tags-of-films'] = array(
    'description' => 'Remove tags of NAPO films.',
    'callback' => 'drush_clean_tags_of_films',
  );

  $items['assign-tags-to-episodes'] = array(
    'description' => 'Assign tags for NAPO episodes.',
    'callback' => 'drush_assign_tags_to_episodes',
  );

  $items['clean-tags-of-episodes'] = array(
    'description' => 'Assign tags for NAPO episodes.',
    'callback' => 'drush_clean_tags_of_episodes',
  );

  return $items;
}

function drush_assign_tags_to_films(){
  $terms = taxonomy_get_term_by_name('Film video','video_type');
  $tid = array_keys($terms)[0];

  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'napo_video')
    ->fieldCondition('field_video_type', 'tid', $tid);
  $result = $query->execute();
  $napo_film_list = entity_load('node', array_keys($result['node']));
  $napo_films = array();

  foreach ($napo_film_list as $nid => $napo_film) {
    if (array_key_exists($napo_film->title,$napo_films)) {
      watchdog('drush_assign_tags_to_films', 'Duplicate film title in array.');
    } else {
      $napo_films[$napo_film->title] = $napo_film;
    }
  }

  $data_export_path = napo_migration_get_data_dir();
  $file_name = $data_export_path . '/napo_film_tags.csv';
  $handle = fopen($file_name,'r');

  while ( ($data = fgetcsv($handle,null,'|') ) !== FALSE ) {
    // film_title, field_main_tag, field_tags_1, field_tags_2, field_tags_3
    if (array_key_exists(trim($data[0]),$napo_films)) {
      $title = trim($data[0]);
      $main_tag = trim($data[1]);
      $secondary_tag_1 = trim($data[2]);
      $secondary_tag_2 = trim($data[3]);
      $secondary_tag_3 = trim($data[4]);
      echo "Film found: ".$title."\n";

      assign_tag_to_node($napo_films[$title],'field_main_tag',array($main_tag));
      assign_tag_to_node($napo_films[$title],'field_tags',array($secondary_tag_1,$secondary_tag_2,$secondary_tag_3));

      node_save($napo_films[$title]);
    } else {
      echo "Film not found: ".$data[0]."\n";
    }
  }

  echo "Tags assigned for films!\n";
}

function drush_clean_tags_of_films(){
  $terms = taxonomy_get_term_by_name('Film video','video_type');
  $tid = array_keys($terms)[0];

  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'napo_video')
    ->fieldCondition('field_video_type', 'tid', $tid);
  $result = $query->execute();
  $napo_film_list = entity_load('node', array_keys($result['node']));

  foreach ($napo_film_list as $nid => $napo_film) {
    $napo_film->field_main_tag = array();
    $napo_film->field_tags = array();
    node_save($napo_film);
    echo "Tags of film $napo_film->title were removed!\n";
  }
}

function drush_assign_tags_to_episodes(){
  $terms = taxonomy_get_term_by_name('Episode video','video_type');
  $tid = array_keys($terms)[0];

  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'napo_video')
    ->fieldCondition('field_video_type', 'tid', $tid);
  $result = $query->execute();
  $napo_episodes_list = entity_load('node', array_keys($result['node']));
  $napo_episodes = array();


  foreach ($napo_episodes_list as $nid => $napo_episode) {
    $key_title = trim($napo_episode->title);
    if (array_key_exists($key_title,$napo_episodes)) {
      watchdog('drush_assign_tags_to_episodes', 'Duplicate episode title in array.');
    } else {
      $napo_episodes[$key_title] = $napo_episode;
    }
  }

  $data_export_path = napo_migration_get_data_dir();
  $file_name = $data_export_path . '/napo_episode_tags.csv';
  $handle = fopen($file_name,'r');

  while ( ($data = fgetcsv($handle,null,'|') ) !== FALSE ) {
    // episode_title, field_main_tag, field_tags_1, field_tags_2, field_tags_3
    if (array_key_exists(trim($data[0]), $napo_episodes)) {
      $title = trim($data[0]);
      $main_tag = trim($data[1]);
      $secondary_tag_1 = trim($data[2]);
      $secondary_tag_2 = trim($data[3]);
      $secondary_tag_3 = trim($data[4]);
      echo "Episode found: " . $title . " and has main tag: " . $main_tag . " and secondary tags: '" . $secondary_tag_1 . "', '". $secondary_tag_2 . "', '". $secondary_tag_3 . "'\n";

      assign_tag_to_node($napo_episodes[$title], 'field_main_tag', array($main_tag));
      assign_tag_to_node($napo_episodes[$title], 'field_tags', array(
        $secondary_tag_1,
        $secondary_tag_2,
        $secondary_tag_3
      ));

      node_save($napo_episodes[$title]);
    } else {
      echo "Episode not found: " . $data[0] . "\n";
    }
  }

  echo "Tags assigned for episodes!\n";
}

function drush_clean_tags_of_episodes(){
  $terms = taxonomy_get_term_by_name('Episode video','video_type');
  $tid = array_keys($terms)[0];

  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'napo_video')
    ->fieldCondition('field_video_type', 'tid', $tid);
  $result = $query->execute();
  $napo_episodes_list = entity_load('node', array_keys($result['node']));

  foreach ($napo_episodes_list as $nid => $napo_episode) {
    $napo_episode->field_main_tag = array();
    $napo_episode->field_tags = array();
    node_save($napo_episode);
    echo "Tags of episode '$napo_episode->title' were removed!\n";
  }
}

function assign_tag_to_node($node, $field_name, $term_names){
  $count = 0;
  foreach($term_names as $key=>$term_name){
    if ($term_name != "") {
      echo "Tag #$key: ".$term_name."\n";
      $tag_term = taxonomy_get_term_by_name($term_name,'tags');
      if (!empty($tag_term)) {
        $tag_tid = array_keys($tag_term)[0];
        echo "Term id for tag #$key found: ".$tag_tid."\n";
        $node->{$field_name}[LANGUAGE_NONE][$count++]['tid'] = $tag_tid;
      } else {
        echo "Term id for tag #$key not found.\n";
      }
    } else {
      echo "Tag #$key is empty for this film.\n";
    }
  }
}
