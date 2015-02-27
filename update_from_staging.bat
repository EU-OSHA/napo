@echo off

rem Go to docroot/
cd docroot/

call drush site-install -y

rem Sync from edw staging
call drush downsync_sql @osha.staging.sync @osha.local -y -v

rem Build the site
call drush osha_build -y

rem Devify - development settings
call drush devify --yes
call drush devify_solr

call drush cc all

rem echo "Running cron to cleanup ..."
rem call drush cron

call drush cc all
