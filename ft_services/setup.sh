#!/bin/bash

minikube start --driver=virtualbox

kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.6/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.6/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

for service in phpmyadmin influxdb mysql grafana wordpress ftps nginx 
do
	docker build -t ${service}_custom srcs/$service/
	kubectl apply -f srcs/$service/$service.yaml
done

kubectl apply -f srcs/metallb/metallb.yaml 

minikube dashboard