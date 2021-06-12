#!/bin/sh

/etc/init.d/mariadb setup
service mariadb start
sleep 5

echo "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql -u root
echo "GRANT ALL ON wordpress.* TO 'admin'@'%' IDENTIFIED BY 'admin';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

sleep infinity
