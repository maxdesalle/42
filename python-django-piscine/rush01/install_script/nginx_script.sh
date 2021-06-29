#!/bin/bash

S_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
cp "$S_DIR/nginx.conf" ~/.brew/etc/nginx/servers/

mkdir -p ~/rush01/ssl
dir=~/rush01/ssl
keyfile=$dir/${1/"*."/star.}.key
cert=$dir/${1/"*."/star.}.crt

openssl req -new -x509 -days 10000 -sha1 -newkey rsa:1024 \
       -nodes -keyout $keyfile -out $cert -subj /O=$1/OU=/CN=$1
