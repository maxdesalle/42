# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add vsftpd telegraf openrc openssl

# Set up openrc
RUN openrc
RUN touch run/openrc/softlevel

# Copy the required files over to the system
COPY ./srcs/start.sh ./
COPY ./srcs/telegraf.conf /etc/
COPY ./srcs/vsftpd.conf etc/vsftpd/vsftpd.conf

# Add user
RUN adduser -D admin ; echo "admin:admin"  | chpasswd

# Set up openssl
# req and x509 are both utilities needed for the certificate generation.
# C stands for country, ST for state, L for locality, O for organization and CN for "common name".
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/private.key -out /etc/ssl/private/certificate.crt -subj "/C=BE/ST=Belgium/L=Brussels/O=19/CN=virtual-machine"

# Listen to the required port
EXPOSE 20 21 21009-21011

# Start the required services
CMD service telegraf start ; sh ./start.sh
