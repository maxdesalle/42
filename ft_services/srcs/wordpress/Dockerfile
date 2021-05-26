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

# Install WordPress
ADD https://wordpress.org/latest.tar.gz .
RUN tar -xzvf latest.tar.gz
RUN rm -f latest.tar.gz
RUN chmod -R 755 wordpress
RUN mv wordpress var/www/

# Copy the required files over to the system
COPY ./srcs/default.conf etc/nginx/conf.d/default.conf
COPY ./srcs/telegraf.conf /etc/
COPY ./srcs/wp-config.php /var/www/wordpress
COPY ./srcs/start.sh .

# Set up MySQL
RUN /etc/init.d/mariadb setup

# Listen to the required ports
EXPOSE 80 5000

# Start the required services
CMD service telegraf start ; service php-fpm7 start ; service mariadb start ; service nginx start ; sleep 5 ; sh ./start.sh ; sleep infinity
