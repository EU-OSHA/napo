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

# Sync from edw staging
drush downsync_sql @napo.staging @self -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "downsync_sql has returned an error"
  exit ${ecode};
fi


drush osha-reset-variables
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Reset variables has returned an error"
  exit ${ecode};
fi


drush devify_solr
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Devify Solr has returned an error"
  exit ${ecode};
fi

drush devify_ldap
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Devify LDAP has returned an error"
  exit ${ecode};
fi

echo "Run drush rsync"
drush rsync @staging:%files @self:%files --chmod=ug+w -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "rsync has returned an error"
  exit ${ecode};
fi
