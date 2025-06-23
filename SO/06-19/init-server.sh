#! /bin/bash
make clean

make

clear

echo "Server running on port 8080"

./server -p 8080