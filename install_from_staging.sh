#!/bin/bash

# Go to docroot/
cd docroot/

# Drop all tables (including non-drupal)
drush sql-drop -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Error cleaning database"
  exit ${ecode};
fi

pre_update=  post_update= files=
while getopts b:a:f opt; do
  case $opt in
  b)
      pre_update=$OPTARG
      ;;
  a)
      post_update=$OPTARG
      ;;
  f) files="files"
  esac
done

# Sync from edw staging
drush downsync_sql @napo.staging @self -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "downsync_sql has returned an error"
  exit ${ecode};
fi

if [ ! -z "$pre_update" ]; then
echo "Run pre update"
../$pre_update
fi

# Devify - development settings
drush devify --yes
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Devify has returned an error"
  exit ${ecode};
fi

drush devify_solr
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Devify Solr has returned an error"
  exit ${ecode};
fi

# Build the site
drush osha_build -y
if [ ${ecode} != 0 ]; then
  echo "osha_build has returned an error"
  exit ${ecode};
fi

drush devify_ldap

if [ ! -z "$post_update" ]; then
echo "Run post update"
  ../$post_update
  drush cc all
fi

if [ ! -z "$files" ]; then
echo "Run drush rsync"
drush rsync @staging:%files @self:%files --chmod=ug+w
fi

ecode=$?
if [ ${ecode} != 0 ]; then
  echo "rsync has returned an error"
  exit ${ecode};
fi
