#!/bin/sh

brew update &&
brew install glfw &&
echo "Ready! Just run make on the lib!" ||
echo "Failed"
