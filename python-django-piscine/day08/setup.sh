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

echo $BLUE
echo "Installing Brew..."
echo $WHITE
curl -s https://brew.42.fr/ | bash &> /dev/null
echo $GREEN
echo "Successfully installed Brew!"
echo ""
echo $BLUE
echo "Installing Nginx..."
echo $WHITE
brew install nginx &> /dev/null
echo $GREEN
echo "Successfully installed Nginx!"
echo ""
echo $BLUE
echo "Setting up Nginx..."
echo $WHITE
mkdir -p ~/.brew/etc/nginx/sites-available &> /dev/null
mkdir -p ~/.brew/etc/nginx/sites-enabled &> /dev/null
cp nginx/default ~/.brew/etc/nginx/sites-available &> /dev/null
ln -s ~/.brew/etc/nginx/sites-available/default ~/.brew/etc/nginx/sites-enabled/ &> /dev/null
echo $GREEN
echo "Successfully installed Nginx!"
echo ""
echo $GREEN
echo "FlashWall is ready! Get started here: https://127.0.0.1"
