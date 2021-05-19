# Linux distribution & version
FROM alpine:latest

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apk update
RUN apk upgrade

# Install the required tools
RUN apk add telegraf

RUN wget https://dl.grafana.com/enterprise/release/grafana-enterprise-7.5.3.linux-amd64.tar.gz ; tar -zxvf grafana-enterprise-7.5.3.linux-amd64.tar.gz ; rm grafana-enterprise-7.5.3.linux-amd64.tar.gz

# Set up Telegraf
RUN rm /etc/telegraf.conf
COPY ./srcs/telegraf.conf /etc/telegraf/

COPY ./srcs/start.sh .

# Listen to the required port
EXPOSE 3000

# Start the required services
CMD service telegraf start ; sleep 5; sh ./start.sh; sleep infinity
