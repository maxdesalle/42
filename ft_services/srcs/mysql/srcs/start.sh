#!/bin/sh

mysql_install_db -u root
/usr/bin/mysqld -u root &
mysql -u root -e 'CREATE DATABASE wordpress'

sleep 5

echo "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql -u root
echo "GRANT ALL ON wordpress.* TO 'wordpress_user'@'%' IDENTIFIED BY 'password';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

sleep 5

telegraf &
mysqld -u root &
sleep infinity
