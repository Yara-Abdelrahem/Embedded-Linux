#!/bin/bash

if [ -f "$HOME/.bashrc" ]; then
    echo ".bashrc file found. Updating environment variables..."
    echo 'export HELLO=$HOSTNAME' >> "$HOME/.bashrc"
    echo 'export LOCAL=$(whoami)' >> "$HOME/.bashrc"
    echo "Environment variables HELLO and LOCAL have been added to .bashrc"
else
    echo ".bashrc file not found in the home directory."
    exit 1
fi
# Open a new terminal (assumes the default terminal application)
if [ "$(uname)" == "Linux" ]; then
    gnome-terminal & disown
else
    echo "Unsupported OS for opening a new terminal."
fi
echo "Script completed."

