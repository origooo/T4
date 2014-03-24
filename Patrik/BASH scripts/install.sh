#!/bin/sh

# Install latest build-essentials
sudo apt-get install build-essential

# Install bash 4.0
wget http://ftp.gnu.org/gnu/bash/bash-4.0.tar.gz

tar xf bash-4.0.tar.gz
cd bash-4.0
./configure
make
sudo make install
cd ..
rm -i Bash-4.0
rm -i bash-4.0.tar.gz

# Install xdotool
sudo apt-get install xdotool

# Install wmctrl
sudo apt-get install wmctrl