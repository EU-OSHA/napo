<?php

function osha_workflow_permissions_download_file_entities() {
  return array(
    'download any audio files',
    'download any document files',
    'download any image files',
    'download any video files',
    'download own audio files',
    'download own document files',
    'download own image files',
    'download own video files',
  );
}

function osha_workflow_permissions_manage_content() {
  return array(

    'edit any article content',
    'edit any consortium_partner content',
    'edit any faq content',
    'edit any home_video content',
    'edit any lesson content',
    'edit any lesson_toolkit content',
    'edit any napo_album content',
    'edit any napo_friend content',
    'edit any napo_image content',
    'edit any napo_video content',

    'edit own article content',
    'edit own consortium_partner content',
    'edit own faq content',
    'edit own home_video content',
    'edit own lesson content',
    'edit own lesson_toolkit content',
    'edit own napo_album content',
    'edit own napo_friend content',
    'edit own napo_image content',
    'edit own napo_video content',

    'create url aliases',
    'delete own audio files',
    'delete own document files',
    'delete own image files',
    'delete own video files',

    'edit any audio files',
    'edit any document files',
    'edit any image files',
    'edit any video files',

    'edit meta tags',

    'edit own audio files',
    'edit own document files',
    'edit own image files',
    'edit own video files',

    'access media browser',

    'view files',
    'view own files',

    'view private files',
    'view own private files',
  );
}

function osha_workflow_permissions_common() {
  return array(
    'access content',
    'view osh content tab',

    'search content',
    'use advanced search',
    'use Search Autocomplete',

    'use text format filtered_html',
    'use text format full_html',

  );
}

function osha_worfklow_permissions_moderator() {
  return array(
    // Important for everyone (editor ... to ... admin) to have it, otherwise
    // they cannot access unpublished content.
    'access workbench access by role',

    'access administration pages',
    'access contextual links',
    'access dashboard',
    'access toolbar',
    'view the administration theme',

    'access workbench',
    'use workbench_moderation my drafts tab',
    'view moderation messages',
    'view revisions',
    'view workbench access information',
    'view moderation history',

    'view own unpublished content',
    'view all unpublished content',
  );
}

/**
 * Array of permissions for the Editor role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_editor() {
  $ret = array_merge(
    array(
      'edit any content in draft',
      'edit any content in published',

      'moderate content from draft to final_draft',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}

/**
 * Array of permissions for the Review Manager role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_review_manager() {
  $ret = array_merge(
    array(
      'create article content',
      'create consortium_partner content',
      'create faq content',
      'create home_video content',
      'create lesson content',
      'create lesson_toolkit content',
      'create napo_album content',
      'create napo_friend content',
      'create napo_image content',
      'create napo_video content',

      'view osh review manager needs review tab',
      'access content overview',
      'assign workbench access',

      'access site in maintenance mode',
      'accept translation jobs',
      'administer files',
      'administer nodes',
      'administer taxonomy',
      'bypass workbench moderation',
      'create translation jobs',
      'submit translation jobs',

      'edit any content in draft',
      'edit any content in needs_review',
      'edit any content in ready_to_publish',
      'edit any content in published',

      'moderate content from draft to ready_to_publish',
      'moderate content from draft to published',
      'moderate content from needs_review to draft',
      'moderate content from ready_to_publish to published',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}


/**
 * Array of permissions for the Project Manager role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_project_manager() {
  $ret = array_merge(
    array(
      'view osh project manager needs review tab',
      'mark access section as reviewed',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}

/**
 * Array of permissions for the Approver role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_approver() {
  $ret = array_merge(
    array(
      'edit any content in to_be_approved',
      'view osh approver needs review tab',

      'moderate content from to_be_approved to approved',
      'moderate content from to_be_approved to rejected',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}
