#!/bin/bash

# Function to print colored output
print_color() {
    case $1 in
        "red") color_code="\033[31m" ;;
        "green") color_code="\033[32m" ;;
        "yellow") color_code="\033[33m" ;;
        "blue") color_code="\033[34m" ;;
        "cyan") color_code="\033[36m" ;;
        "reset") color_code="\033[0m" ;;
        *) color_code="\033[0m" ;;  # Default to reset
    esac
    echo -e "${color_code}$2${color_code}\033[0m"
}

# Check if argument is "clean"
if [ "$1" == "clean" ]; then
    # Clean operation: delete compiled executables
    if [ -f ex07_test ]; then
        rm ex07_test
        print_color "cyan" "Deleted compiled executable 'ex07_test'."
    else
        print_color "yellow" "No compiled executable found ('ex07_test')."
    fi
    exit 0
fi

# Compile the C++ code with ex07.cpp
c++ -o ex07_test ex07.cpp -I.

if [ $? -ne 0 ]; then
    print_color "red" "Compilation failed!"
    exit 1
fi

# Run the executable and capture the output
output=$(./ex07_test)

echo $output