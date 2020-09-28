#!/bin/sh
echo "Compiling..."
g++ tests/main.cpp src/*.cpp

echo "Running tests... \n"
./a.out
