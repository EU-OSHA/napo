NAPO
====

Build scripts and source code for the NAPO project

## Pre-requisites

1. Install Drush (7.0-dev):

   * Install composer (```curl -sS https://getcomposer.org/installer | php```) somwhere in the PATH, and rename ```composer.phar``` to ```composer```.
   * Clone drush repo in your working directory (i.e. ~/Work) - ```git clone git@github.com:drush-ops/drush.git ~/Work/drush```)
   * ```cd ~/Work/drush```
   * ```composer install``` - install drush w/composer
   * ```sudo ln -s ~/Work/drush/drush /usr/bin/``` - add to PATH

2. Virtual host for your Drupal instance that points to the docroot/ directory from this repo

## Quick start ##

1. Copy [conf/config.template.json](https://github.com/EU-OSHA/osha-website/blob/master/conf/config.template.json)
to `config.json` and customize to suit your environment

    ```json
    {
        "db" : {
            "host": "database server ip or name, ex: localhost",
            "username" : "database username, ex. user1",
            "password" : "database password, ex. password1",
            "port": 3306,
            "database" : "database name, ex. osha_test",
            "root_username": "root",
            "root_password": "s3cr3t"
        },
        "admin" : {
            "username": "admin",
            "password": "admin",
            "email": "your.email@domain.org"
        },
        "uri": "http://you-vh.localhost",
        "solr_server": {
            "name": "Apache Solr server",
            "enabled": 1,
            "description": "",
            "scheme": "http",
            "host": "localhost",
            "port": 8080,
            "path": "/solr",
            "http_user": "",
            "http_password": "",
            "excerpt": 1,
            "retrieve_data": 1,
            "highlight_data": 1,
            "skip_schema_check": null,
            "solr_version": "",
            "http_method": "AUTO",
            "apachesolr_read_only": null,
            "apachesolr_direct_commit": 1,
            "apachesolr_soft_commit": 1
        },
        "variables": {
            "site_mail": "your.email@domain.org",
            "site_name": "NAPO",
            "napo_data_dir": "/home/napo/data",
            "file_temporary_path": "/tmp"
        }
    }
    ```

2. Copy the following code into `~/.drush/drushrc.php` (create if necessary)

    ```php
        <?php
            $repo_dir = drush_get_option('root') ? drush_get_option('root') : getcwd();
            $success = drush_shell_exec('cd %s && git rev-parse --show-toplevel 2> ' . drush_bit_bucket(), $repo_dir);
            if ($success) {
                $output = drush_shell_exec_output();
                $repo = $output[0];
                $options['config'] = $repo . '/drush/drushrc.php';
                $options['include'] = $repo . '/drush/commands';
                $options['alias-path'] = $repo . '/drush/aliases';
            }
    ```

3 Create file drush/aliases/aliases.local.php and define your drush local alias (see example in drush/aliases/napo.aliases.drushrc.php)
  Redefine your napo.staging alias as you need. Default one might not be accessible to you.

4 Run install_from_staging.sh
  ex: ./install_from_staging.sh
  ex: ./install_from_staging.sh -b update_s4_before.sh -a update_s4_after.sh


Updating an existing instance
=============================

To update an existing instance without reinstalling (and loosing existing content):

* Update the code repository from Github (`git pull [origin develop]`)
* Run drush osha_build -y

The output of the console should look like this:


Running tests
=============

See tests/readme.md for more details


## Repository Layout ##
Breakdown for what each directory/file is used for. See also readme inside directories.

* [conf](https://github.com/EU-OSHA/napo/tree/master/conf)
 * Project specific configuration files
* [docroot](https://github.com/EU-OSHA/napo/tree/master/docroot)
 * Drupal root directory
* [drush](https://github.com/EU-OSHA/napo/tree/master/drush)
 * Contains project specific drush commands, aliases, and configurations.
* [results](https://github.com/EU-OSHA/napo/tree/master/results)
 * This directory is just used to export test results to. A good example of this
   is when running drush test-run with the --xml option. You can export the xml
   to this directory for parsing by external tools.
* [scripts](https://github.com/EU-OSHA/napo/tree/master/scripts)
 * A directory for project-specific scripts.
* [test](https://github.com/EU-OSHA/napo/tree/master/tests)
 * A directory for external tests. This is great for non drupal specific tests
 such as selenium, qunit, casperjs.
* [.gitignore](https://github.com/EU-OSHA/napo/blob/master/.gitignore)
 * Contains the a list of the most common excluded files.

## Branches ##

This repo branching model follows the article ["A successful Git branching model"](http://nvie.com/posts/a-successful-git-branching-model)

Summary:

* _master_ - The production branch, updated with each release.
* _develop_ - Main development branch. Tests are performed on this branch
* _release-_* - Release branches

## Translation workflow ##

* Module page - https://www.drupal.org/project/tmgmt
* FAQs: https://www.drupal.org/node/1547632

-- edw
