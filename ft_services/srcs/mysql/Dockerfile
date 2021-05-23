# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add mysql mysql-client telegraf

# Set up MySQL
COPY ./srcs/my.cnf .
RUN mkdir -p /run/mysqld
RUN mv my.cnf /etc/

# Set up Telegraf
RUN rm /etc/telegraf.conf
COPY ./srcs/telegraf.conf /etc/telegraf/

# Listen to the required port
EXPOSE 3306

# Copy the start script over to the system
COPY ./srcs/start.sh ./

# Start the script
CMD ./start.sh
