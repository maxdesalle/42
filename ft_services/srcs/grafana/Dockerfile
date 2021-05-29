# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add telegraf grafana influxdb openrc

# Set up openrc
RUN openrc
RUN touch run/openrc/softlevel

# Copy the required files over to the system
COPY ./srcs/start.sh ./
COPY ./srcs/telegraf.conf /etc/

# Copy the datasources, providers and dashboards over to Grafana
COPY ./srcs/datasources/default.yaml /usr/share/grafana/conf/provisioning/datasources/
COPY ./srcs/providers/default.yaml /usr/share/grafana/conf/provisioning/dashboards/
COPY ./srcs/dashboards/ftps-dashboard.json /usr/share/grafana/conf/provisioning/dashboards/
COPY ./srcs/dashboards/grafana-dashboard.json /usr/share/grafana/conf/provisioning/dashboards/
COPY ./srcs/dashboards/influxdb-dashboard.json /usr/share/grafana/conf/provisioning/dashboards/
COPY ./srcs/dashboards/wordpress-dashboard.json /usr/share/grafana/conf/provisioning/dashboards/
COPY ./srcs/dashboards/phpmyadmin-dashboard.json /usr/share/grafana/conf/provisioning/dashboards/
COPY ./srcs/dashboards/mysql-dashboard.json /usr/share/grafana/conf/provisioning/dashboards/
COPY ./srcs/dashboards/nginx-dashboard.json /usr/share/grafana/conf/provisioning/dashboards/

# Listen to the required port
EXPOSE 3000

# Start the required services
CMD service influxdb start ; service telegraf start ; sleep 5 ; sh start.sh
