# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add telegraf openssl vsftpd

# Set up Telegraf
RUN rm /etc/telegraf.conf
COPY ./srcs/telegraf.conf /etc/telegraf/

# Set up openssl
# req and x509 are both utilities needed for the certificate generation.
# C stands for country, ST for state, L for locality, O for organization and CN for "common name".
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/private.key -out /etc/ssl/private/certificate.crt -subj "/C=BE/ST=Belgium/L=Brussels/O=19/CN=virtual-machine"

# Set up username and password
RUN echo "admin:$(openssl passwd passwd)" >> /etc/vsftpd/user
RUN chmod 600 /etc/vsftpd/user

# Set up the vsftpd config
COPY ./srcs/vsftpd.conf /etc/vsftpd/

# Listen to the required port
EXPOSE	20 21 21100-21110

# Copy the start script over to the system
COPY ./srcs/start.sh .

# Run the start script
CMD ./start.sh
