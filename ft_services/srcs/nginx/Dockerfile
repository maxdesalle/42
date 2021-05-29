# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add openssl telegraf nginx openrc

# Set up openrc
RUN openrc
RUN touch run/openrc/softlevel

# Copy the required files over to the system
COPY ./srcs/start.sh .
COPY ./srcs/telegraf.conf /etc/
COPY ./srcs/default.conf etc/nginx/conf.d/default.conf
COPY ./srcs/index.html /var/www/

# Set up nginx
RUN mkdir -p /run/nginx

# openssl setup
RUN mkdir /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/private.key -out /etc/nginx/ssl/certificate.crt -subj "/C=BE/ST=Belgium/L=Brussels/O=19/CN=virtual-machine"

# Listen to the required port
EXPOSE 80 443

# Start the required services
CMD service telegraf start ; sh start.sh
