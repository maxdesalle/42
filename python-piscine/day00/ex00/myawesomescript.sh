#!/bin/sh

curl -sLI $1 | grep -m 1 Location | cut -c11-
