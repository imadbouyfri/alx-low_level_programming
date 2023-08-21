#!/bin/bash

# Get the list of all .c files in the current directory
files=$(ls *.c)

# Create an empty object file
obj_file=liball.o

# Compile each .c file into an object file
for file in $files; do
  gcc -c -fPIC $file -o $obj_file
done

# Create the dynamic library from the object file
gcc -shared -o liball.so $obj_file

# Remove the object file
rm $obj_file
