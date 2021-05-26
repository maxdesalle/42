# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add telegraf openrc mariadb mariadb-common mariadb-client

# Set up openrc
RUN openrc
RUN touch run/openrc/softlevel

# Copy the required files over to the system
COPY ./srcs/start.sh ./
COPY ./srcs/telegraf.conf /etc/
COPY ./srcs/my.cnf /etc/my.cnf

# Listen to the required port
EXPOSE 3306

# Start the required services
CMD /etc/init.d/mariadb setup ; service mariadb start ; sh ./start.sh ; service telegraf start ; sleep infinity
