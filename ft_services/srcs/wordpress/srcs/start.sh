#!/bin/sh

service php-fpm7 start
service mariadb start
service nginx start
sleep 5

wp core install --url=172.17.0.2:5050 --title=ft_services --admin_user=admin --admin_password=admin --admin_email=admin@ftservices.com --path=/var/www/wordpress
wp user create author author@ftservices.com --role=author --path=/var/www/wordpress
wp user create editor editor@ftservices.com --role=editor --path=/var/www/wordpress

sleep infinity
