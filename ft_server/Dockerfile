# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 11:03:12 by mdesalle          #+#    #+#              #
#    Updated: 2021/01/24 11:33:01 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Linux distribution & version
FROM debian:buster

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apt-get -y update
RUN apt-get -y upgrade

# Install the required tools
RUN apt-get -y install wget nginx mariadb-server

# Install PHP
RUN apt-get -y install php7.3 php-mysql php-fpm php-cli php-mbstring

# Install phpMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
RUN tar -xzvf phpMyAdmin-5.0.4-english.tar.gz
RUN rm -f phpMyAdmin-5.0.4-english.tar.gz
RUN mv phpMyAdmin-5.0.4-english phpmyadmin
COPY ./srcs/config.inc.php phpmyadmin
RUN mv phpmyadmin var/www/

# Install WordPress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN rm -f latest.tar.gz
COPY ./srcs/wp-config.php wordpress/
RUN chmod -R 755 wordpress
RUN mv wordpress var/www/

# Install mkcert
RUN mkdir mkcert
RUN wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.3/mkcert-v1.4.3-linux-amd64
RUN chmod 755 mkcert-v1.4.3-linux-amd64 
RUN mv mkcert-v1.4.3-linux-amd64 mkcert/mkcert
RUN mkcert/mkcert -install
RUN mkcert/mkcert localhost
RUN mv localhost-key.pem localhost.pem mkcert 
RUN mv mkcert var/www/

# Set up Nginx
RUN rm -f /etc/nginx/sites-available/default
COPY ./srcs/default /etc/nginx/sites-available

# Set up MySQL
RUN service mysql start
RUN chmod -R 755 /var/lib/mysql/
RUN mkdir var/www/mysql
COPY ./srcs/mysql_setup.sql /var/www/mysql
RUN service mysql start && mysql -u root mysql < /var/www/mysql/mysql_setup.sql

# Listen to the required ports
EXPOSE 80 443

# Start the required services
RUN service php7.3-fpm start
RUN service nginx start
