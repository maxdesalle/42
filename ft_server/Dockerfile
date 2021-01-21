# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 11:03:12 by mdesalle          #+#    #+#              #
#    Updated: 2021/01/21 13:34:11 by mdesalle         ###   ########.fr        #
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
RUN apt-get -y install php8.0-{mysql, fpm, cli, mbstring}

# Install WordPress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN rm -f latest.tar.gz
RUN mv src/wp-config.php wordpress
RUN chmod +x -R wordpress
RUN mv wordpress var/www/hmtl/

# Listen to the required ports
EXPOSE 80 443
