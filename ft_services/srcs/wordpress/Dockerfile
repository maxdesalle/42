# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add wget nginx php7.3 php-mysql php-fpm php-cli php-mbstring

# Install WordPress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN rm -f latest.tar.gz
COPY wp-config.php wordpress/
RUN chmod -R 755 wordpress
RUN mv wordpress var/www/localhost

EXPOSE 5050