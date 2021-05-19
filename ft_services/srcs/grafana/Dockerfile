# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add telegraf grafana

# Set up Telegraf
RUN rm /etc/telegraf.conf
COPY ./srcs/telegraf.conf /etc/telegraf/

# Copy the start script over to the system
COPY ./srcs/start.sh .

# Listen to the required port
EXPOSE 3000

# Start the required services
CMD service telegraf start
CMD sh ./start.sh
