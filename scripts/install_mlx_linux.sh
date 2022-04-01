#!/bin/sh

sudo apt update &&
sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev &&
echo "Ready! Just run make on the lib!" ||
echo "Failed"
