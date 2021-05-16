# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add wget telegraf nginx php7 php-mysqli php-fpm php-cli php-mbstring

# Install WordPress
RUN wget https://wordpress.org/latest.tar.gz
RUN	tar -xzvf latest.tar.gz
RUN	rm -f latest.tar.gz
COPY ./srcs/wp-config.php wordpress/
RUN	chmod -R 755 wordpress
RUN	mv wordpress var/www/

# Set up Nginx
COPY ./srcs/nginx.conf /etc/nginx/conf.d
RUN mkdir -p /run/nginx
RUN rm /etc/nginx/conf.d/default.conf

# Set up Telegraf
RUN rm /etc/telegraf.conf
COPY ./srcs/telegraf.conf /etc/telegraf/

# Listen to the required port
EXPOSE 5050

# Start the required services
CMD service telegraf start ; service php-fpm start ; service nginx start ; sleep infinity
