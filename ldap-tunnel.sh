#!/bin/sh
echo "LDAP running tunneled to localhost:1389"
ssh -N root@osha-corp-staging03.mainstrat.com -L 1389:194.30.59.219:389
