# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 11:03:12 by mdesalle          #+#    #+#              #
#    Updated: 2020/12/27 11:14:25 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Linux distribution & version
FROM debian:buster

# Maintainer (because MAINTAINER is deprecated)
LABEL maintainer="mdesalle@student.s19.be"

# Update and install the required dependencies
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install wget nginx -y

# Listen to the required ports
EXPOSE 80 443
