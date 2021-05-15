#!/bin/bash

minikube start --driver=virtualbox

kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.6/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.6/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

for service in phpmyadmin influxdb mysql grafana wordpress ftps nginx metallb
do
	if [ -e srcs/$service/Dockerfile ]
	then
		docker build -t my_${service} srcs/$service/
	elif [ -e srcs/$service/$service-deployment.yaml ]
	then
	kubectl apply -f srcs/$service/$service-deployment.yaml
	elif [ -e srcs/$service/$service-service.yaml ]
	then
	kubectl apply -f srcs/$service/$service-service.yaml
	elif [ -e srcs/$service/$service-volume.yaml ]
	then
	kubectl apply -f srcs/$service/$service-volume.yaml
	elif [ -e srcs/$service/$service-configmap.yaml ]
	then
	kubectl apply -f srcs/$service/$service-configmap.yaml
	fi
done

minikube dashboard
