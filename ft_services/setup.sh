#!/bin/bash

# Some nice little colors
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
BLUE="\e[94m"
PURPLE="\e[95m"
CYAN="\e[96m"
WHITE="\e[97m"

# Print ascii art
echo -e $WHITE
echo "  __ _                         _               "
echo " / _| |                       (_)              "
echo "| |_| |_   ___  ___ _ ____   ___  ___ ___  ___ "
echo "|  _| __| / __|/ _ \ '__\ \ / / |/ __/ _ \/ __|"
echo "| | | |_  \__ \  __/ |   \ V /| | (_|  __/\__ \\"
echo "|_|  \__| |___/\___|_|    \_/ |_|\___\___||___/"
echo "      ______                                   "
echo "     |______|                                  "
echo -e $WHITE


# Delete a potential previous instance and start a new one with required addons
minikube delete
minikube start --driver=docker --cpus=2
minikube addons enable dashboard
minikube addons enable metallb

# Required to fix the latest tag issue in Dockerfile
eval $(minikube docker-env)

# Set up metallb
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.6/manifests/namespace.yaml &> /dev/null
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.6/manifests/metallb.yaml &> /dev/null
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" &> /dev/null

# If the metallb config map exists, apply it with kubectl
if [ -e srcs/metallb/metallb-configmap.yaml ]
then
	kubectl apply -f srcs/metallb/metallb-configmap.yaml &> /dev/null
	echo -en $GREEN
	echo "Successfully deployed metallb configuration map"
	echo -en $WHITE
	echo ""
	echo ""
fi

# Build for each service the Dockerfile (if it exists), and apply the existing yaml files
for service in phpmyadmin influxdb mysql grafana wordpress ftps nginx
do
	if [ -e srcs/$service/Dockerfile ]
	then
		echo -en $BLUE
		echo "Building $service..."
		echo -en $WHITE
		docker build -t my_${service} srcs/$service/ | grep "Step"
		echo -en $GREEN
		echo "Successfully set up the Docker container for $service"
		echo -e $WHITE
	fi
	if [ -e srcs/$service/srcs/$service-deployment.yaml ]
	then
		echo -en $BLUE
		echo "Deploying $service..."
		echo -en $WHITE
		kubectl apply -f srcs/$service/srcs/$service-deployment.yaml &> /dev/null
		echo -en $GREEN
		echo "Successfully deployed $service"
		echo ""
		echo -en $WHITE
	fi
	if [ -e srcs/$service/srcs/$service-service.yaml ]
	then
		echo -en $BLUE
		echo "Exposing $service..."
		echo -en $WHITE
		kubectl apply -f srcs/$service/srcs/$service-service.yaml &> /dev/null
		echo -en $GREEN
		echo "Successfully exposed $service"
		echo ""
		echo -en $WHITE
	fi
	if [ -e srcs/$service/srcs/$service-volume.yaml ]
	then
		echo -en $BLUE
		echo "Creating $service volume..."
		echo -en $WHITE
		kubectl apply -f srcs/$service/srcs/$service-volume.yaml &> /dev/null
		echo -en $GREEN
		echo "Successfully created $service volume"
		echo ""
		echo -en $WHITE
	fi
	echo ""
done

# Success message
echo -en $GREEN
echo "Kubernetes cluster is ready to use!"
echo -en $WHITE
