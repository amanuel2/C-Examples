#!/bin/bash
###############               ############
############### ONLY ON LINUX ############
###############               ############
#Tested on Ubuntu Distro.
echo "_________________________"
echo "|                       |"
echo "|Author : Amanuel Bogale|"
echo "-------------------------"
echo "Building C++ File."

g++ main.cpp -o main.out -pthread -std=c++11

echo "Compiling C++ File."

./main.out

