#!/bin/bash

########################################################################
### ETNA PROJECT, 2022
### TIC-DVC1/Runner
### File description:
### this script is used to do a deployement of all necessary packages 
### you just need to run it and follow instruction.
########################################################################

packages=( sdl2 sdl2_image sdl2_mixer sdl2_ttf )

install_linux() {
    echo "you choosed installation process for linux"
    echo "sdl2 and sdl2-image installation..." 
    sudo apt install -y make gcc libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
    make install clean
    ./runner
}

install_mac_intel () {
    echo "you choosed installation process for mac with intel-ship"
    echo "sdl2 and sdl2-image installation..." 
    for i in "${packages[@]}"
    do
	    brew install $i
    done
    make install clean
    ./runner
}

install_mac_m1 () {
    echo "you choosed installation process for mac with apple-silicone m1 ship"
    echo "sdl2 and sdl2-image installation..."
    for i in "${packages[@]}"
    do
	    brew install $i
    done
    sed -i '' 's/#LDFLAGS = -I include -L lib -lSDL2/LDFLAGS = -I\/opt\/homebrew\/include -L\/opt\/homebrew\/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer/g' ./Makefile
    make install clean
    ./runner
}

menu_os () {
  echo "Please select the correct archi for proceed with the installation"
  echo "  1)Linux"
  echo "  2)mac-intel"
  echo "  3)mac-m1"

  read archi
  case $archi in
      1) install_linux;;
      2) install_mac_intel;;
      3) install_mac_m1;;
      *) echo "invalid option";;
  esac
}

menu_os
