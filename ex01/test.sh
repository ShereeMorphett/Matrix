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
    # Clean operation: delete compiled executable
    if [ -f ex01_test ]; then
        rm ex01_test
        print_color "cyan" "Deleted compiled executable 'ex01_test'."
    else
        print_color "yellow" "No compiled executable found ('ex01_test')."
    fi
    exit 0
fi

# Compile the C++ code
g++ -o ex01_test ex01.cpp -I.

if [ $? -ne 0 ]; then
    print_color "red" "Compilation failed!"
    exit 1
fi

# Run the executable and capture the output
output=$(./ex01_test)

# Define the expected output
expected_output1="[ 10, -2, 0.5 ]"
expected_output2="[ 10, 0, 230 ]"

# Function to strip and compare output lines
strip_and_compare() {
    local actual="$1"
    local expected="$2"
    actual=$(echo "$actual" | sed 's/[[:space:]]//g')
    expected=$(echo "$expected" | sed 's/[[:space:]]//g')
    if [[ "$actual" == "$expected" ]]; then
        return 0
    else
        return 1
    fi
}

# Extract actual output lines
actual_output1=$(echo "$output" | sed -n '1p')
actual_output2=$(echo "$output" | sed -n '2p')

# Compare actual output with expected output
strip_and_compare "$actual_output1" "$expected_output1"
result1=$?

strip_and_compare "$actual_output2" "$expected_output2"
result2=$?

print_color "yellow" "Expected:"
echo -e "$expected_output1\n$expected_output2"
print_color "yellow" "Got:"
echo "$output"

if [ $result1 -eq 0 ] && [ $result2 -eq 0 ]; then
    print_color "green" "Test passed!"
else
    print_color "red" "Test failed!"
fi
