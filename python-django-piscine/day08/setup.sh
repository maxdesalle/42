#!/bin/sh

# Some nice little colors
GREEN='\033[0;32m'
BLUE='\033[0;34m'
WHITE='\033[0;37m'

# Print ascii art
echo $WHITE
echo "  _____ _           _  __        __    _ _ "
echo " |  ___| | __ _ ___| |_\ \      / /_ _| | |"
echo " | |_  | |/ _\` / __| '_ \ \ /\ / / _\` | | |"
echo " |  _| | | (_| \__ \ | | \ V  V / (_| | | |"
echo " |_|   |_|\__,_|___/_| |_|\_/\_/ \__,_|_|_|"
echo $WHITE

# Virtual environment setup
echo $BLUE
echo "Setting up the virtual environment"
echo $WHITE
python3 -m venv .virtualenv > /dev/null
source .virtualenv/bin/activate > /dev/null
pip3 install -r requirements.txt > /dev/null
echo $GREEN
echo "Successfully set up the virtual environment!"

# Brew setup
echo $BLUE
echo "Installing Brew..."
echo $WHITE
curl -s https://brew.42.fr/ | bash > /dev/null
echo $GREEN
echo "Successfully installed Brew!"

# Nginx installation
echo $BLUE
echo "Installing Nginx..."
echo $WHITE
brew install nginx > /dev/null
echo $GREEN
echo "Successfully installed Nginx!"

# Nginx setup
echo $BLUE
echo "Setting up Nginx..."
echo $WHITE
sed -i "" "s/USER/$USER/g" nginx/nginx.conf
cp nginx/nginx.conf ~/.brew/etc/nginx/servers > /dev/null
echo $GREEN
echo "Successfully installed Nginx!"

# Nginx sart up
echo $BLUE
echo "Starting up Nginx..."
echo $WHITE
brew services restart nginx > /dev/null
echo $GREEN
echo "Successfully started Nginx!"

# Ready message
echo $GREEN
echo "FlashWall is ready! Get started here: https://127.0.0.1"

# Gunicorn sart up
echo $BLUE
echo "Starting up Gunicorn..."
echo $GREEN
echo "Successfully started Gunicorn!"
echo $WHITE
gunicorn -c gunicorn/gunicorn.conf.py project.wsgi:application > /dev/null
