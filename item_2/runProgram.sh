#!/bin/sh
rm -f a.out
echo "Compiling..."
g++ main.cpp src/*.cpp

echo "Running program... \n"
./a.out
