#!/bin/sh

chmod +x tester
while true
do
	./tester $1
	sleep 1
done
