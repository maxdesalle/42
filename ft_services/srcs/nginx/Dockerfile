# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add openssl openrc telegraf

# Set up Nginx
COPY ./srcs/nginx.conf /etc/nginx/conf.d
RUN mkdir -p /run/nginx
RUN rm /etc/nginx/conf.d/default.conf

# openssl setup
RUN mkdir /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/private.key -out /etc/nginx/ssl/certificate.crt -subj "/C=BE/ST=Belgium/L=Brussels/O=19/CN=virtual-machine"

# Set up Telegraf
RUN rm /etc/telegraf.conf
COPY ./srcs/telegraf.conf /etc/telegraf/

# Listen to the required port
EXPOSE	22 80 443

# Start the required services
CMD service telegraf start ; nginx -g 'daemon off;'
