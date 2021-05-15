#!/bin/bash

RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
BLUE="\e[94m"
PURPLE="\e[95m"
CYAN="\e[96m"
WHITE="\e[97m"

minikube delete
minikube start --driver=docker --cpus=2
minikube addons enable metrics-server
minikube addons enable dashboard
minikube addons enable metallb

if [ -e srcs/metallb/metallb-configmap.yaml ]
then
	echo -en $WHITE
	kubectl apply -f srcs/metallb/metallb-configmap.yaml
	echo -en $GREEN
	echo "Successfully deployed metallb configuration map"
	echo -en $WHITE
fi

eval $(minikube docker-env)

kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.6/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.6/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

for service in phpmyadmin influxdb mysql grafana wordpress ftps nginx metallb
do
	if [ -e srcs/$service/Dockerfile ]
	then
		echo -en $WHITE
		docker build -t my_${service} srcs/$service/
		echo -en $GREEN
		echo "Successfully set up the Docker container for $service"
		echo -e $WHITE
	elif [ -e srcs/$service/srcs/$service-deployment.yaml ]
	then
		kubectl apply -f srcs/$service/srcs/$service-deployment.yaml
		echo -en $GREEN
		echo "Successfully deployed $service"
		echo -en $WHITE
	elif [ -e srcs/$service/srcs/$service-service.yaml ]
	then
		kubectl apply -f srcs/$service/srcs/$service-service.yaml
		echo -en $GREEN
		echo "Successfully exposed $service"
		echo -en $WHITE
	elif [ -e srcs/$service/srcs/$service-volume.yaml ]
	then
		kubectl apply -f srcs/$service/srcs/$service-volume.yaml
		echo -en $GREEN
		echo "Successfully created $service volume"
		echo -en $WHITE
	fi
done

minikube dashboard
