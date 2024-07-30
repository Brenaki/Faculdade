#!/bin/bash

echo "What subject do you want to create?"
read main

cd $main

echo "Folder name?"
read folder

mkdir $folder

cd $folder 

echo "Name file?"
read file

echo "Extension file?"
read ext

touch $file.$ext

echo "Project Create!"
sleep 2
clear


