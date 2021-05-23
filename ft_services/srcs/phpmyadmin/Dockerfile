# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add wget telegraf nginx php7 php-mysqli php-fpm php-cli php-mbstring

# Install phpMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
RUN tar -xzvf phpMyAdmin-5.0.4-english.tar.gz
RUN rm -f phpMyAdmin-5.0.4-english.tar.gz
RUN mv phpMyAdmin-5.0.4-english phpmyadmin
COPY ./srcs/config.inc.php phpmyadmin
RUN mv phpmyadmin var/www/

# Set up Nginx
COPY ./srcs/nginx.conf /etc/nginx/conf.d
RUN mkdir -p /run/nginx
RUN rm /etc/nginx/conf.d/default.conf

# Set up Telegraf
RUN rm /etc/telegraf.conf
COPY ./srcs/telegraf.conf /etc/telegraf/

# Listen to the required port
EXPOSE 80 5000

# Copy the start script over to the system
COPY ./srcs/start.sh ./

# Run the start script
CMD ./start.sh
