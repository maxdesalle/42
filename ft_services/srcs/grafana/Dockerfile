# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add wget grafana telegraf

# Set up Telegraf
RUN rm /etc/telegraf.conf
COPY ./srcs/telegraf.conf /etc/telegraf/

# Set up Grafana DB
COPY ./srcs/grafana.db /usr/share/grafana/data/ 

# Listen to the required port
EXPOSE 3000

# Start the required services
CMD service influxdb start ; service telegraf start ; sleep 5 ; sh ./start.sh ; sleep infinity
