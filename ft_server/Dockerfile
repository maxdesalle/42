# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 11:03:12 by mdesalle          #+#    #+#              #
#    Updated: 2021/01/22 08:15:42 by mdesalle         ###   ########.fr        #
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
COPY ./src/config.inc.php phpmyadmin
RUN mv phpmyadmin var/www/html/

# Install WordPress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN rm -f latest.tar.gz
COPY ./src/wp-config.php wordpress
RUN chmod -R 755 wordpress
RUN mv wordpress var/www/hmtl/

# Install mkcert
RUN mkdir ~/mkcert
RUN cd ~/mkcert
RUN wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.3/mkcert-v1.4.3-linux-amd64
RUN mv mkcert-v1.4.3-linux-amd64 mkcert
RUN chmod 755 mkcert
RUN ./mkcert -install
RUN ./mkcert localhost
RUN cd
RUN mv ~/mkcert var/www/html/

# Listen to the required ports
EXPOSE 80 443
