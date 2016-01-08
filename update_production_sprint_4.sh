#!/bin/sh

drush cc all
drush fr napo_gallery -y
drush fr napo_film -y
drush cc all
drush updatedb -y
