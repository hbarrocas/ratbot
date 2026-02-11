#!/bin/sh
#
# Temporary setup script - installs required packages

# if [ ! -x /usr/local/bin/arduino-cli ]; then
#   curl ---- to install arduino dev 
# fi

arduino-cli lib update-index && \
   arduino-cli lib install as5600
