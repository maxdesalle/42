# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add influxdb telegraf

# Set up Telegraf
RUN rm /etc/telegraf.conf
COPY ./srcs/telegraf.conf /etc/telegraf/

# Set up start.sh file
COPY ./srcs/start.sh ./

# Listen to the required port
EXPOSE 8086

# Run the starting script
CMD ./start.sh
