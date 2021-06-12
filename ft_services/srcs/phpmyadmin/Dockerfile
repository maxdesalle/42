# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add telegraf nginx openrc mariadb mariadb-common mariadb-client
RUN apk add php7-fpm php7-mbstring php7-json php7-mysqli php7-session php7-cli

# Set up openrc
RUN openrc
RUN touch run/openrc/softlevel

# Install phpMyAdmin
ADD https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz .
RUN tar -xzvf phpMyAdmin-5.0.4-english.tar.gz
RUN rm -f phpMyAdmin-5.0.4-english.tar.gz
RUN mv phpMyAdmin-5.0.4-english phpmyadmin
RUN mv phpmyadmin /var/www/phpmyadmin

# Copy the required files over to the system
COPY ./srcs/default.conf etc/nginx/conf.d/default.conf
COPY ./srcs/telegraf.conf /etc/
COPY ./srcs/config.inc.php /var/www/phpmyadmin
COPY ./srcs/start.sh .

# Set up MySQL
RUN /etc/init.d/mariadb setup

# Listen to the required ports
EXPOSE 80 5000

# Start the required services
CMD service telegraf start ; sh ./start.sh
