#!/bin/bash

# Go to docroot/
cd docroot/

pre_update=  post_update=
while getopts b:a: opt; do
  case $opt in
  b)
      pre_update=$OPTARG
      ;;
  a)
      post_update=$OPTARG
      ;;
  esac
done

# Sync from edw staging
drush downsync_sql @osha.staging.sync @osha.local -y

if [ ! -z "$pre_update" ]; then
echo "Run pre update"
../$pre_update
fi

# Build the site
drush osha_build -y

# Devify - development settings
drush devify --yes
drush devify_solr

drush cc all

if [ ! -z "$post_update" ]; then
echo "Run post update"
../$post_update
fi

drush cc all
