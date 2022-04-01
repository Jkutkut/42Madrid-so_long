#!/bin/sh

rm -rf ~/.brewconfig.zsh

echo "remove these lines:"
echo

echo "# Load Homebrew Fix script
source $HOME/.brewconfig.zsh"

vi ~/.zshrc
