#!/bin/bash

# List of selected .c files
selected_files=$(ls | grep '^[^0-9].*\.c$')

# Compile selected .c files into object files
gcc -Wall -Werror -Wextra -pedantic -c $selected_files

# Create the dynamic library
gcc -shared -o liball.so $(ls | grep '^[^0-9].*\.o$')


# Print a success message
echo "Dynamic library liball.so created successfully!"
