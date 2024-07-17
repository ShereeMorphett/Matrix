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
    if [ -f matrix_vector_test ]; then
        rm matrix_vector_test
        print_color "cyan" "Deleted compiled executable 'matrix_vector_test'."
    else
        print_color "yellow" "No compiled executable found ('matrix_vector_test')."
    fi
    exit 0
fi

# Compile the C++ code
g++ -o matrix_vector_test ex07.cpp -I.

if [ $? -ne 0 ]; then
    print_color "red" "Compilation failed!"
    exit 1
fi

# Run the executable and capture the output
output=$(./matrix_vector_test)

# Define the expected outputs for each test
declare -a expected_outputs=(
    "Expected Output: 
[4.0]    [2.0]
[4, 2]"
    "Expected Output: 
[8.0]    [4.0]
[8, 4]"
    "Expected Output: 
[4.0]    [-4.0]
[4, -4]"
)

# Extract actual outputs from the program's output
IFS=$'\n' read -r -d '' -a actual_outputs < <(echo "$output" && printf '\0')

# Run individual tests
all_tests_passed=true
for i in "${!expected_outputs[@]}"; do
    expected="${expected_outputs[$i]}"
    actual="${actual_outputs[$i]}"
    test_num=$((i+1))

    if [ "$actual" == "$expected" ]; then
        print_color "yellow" "Expected:"
        echo "$expected"
        print_color "yellow" "Got:"
        echo "$actual"
        print_color "green" "Test $test_num passed!"
    else
        print_color "red" "Test $test_num failed!"
        print_color "yellow" "Expected:"
        echo "$expected"
        print_color "yellow" "Got:"
        echo "$actual"
        all_tests_passed=false
    fi
done

if $all_tests_passed; then
    print_color "green" "All tests passed!"
else
    print_color "red" "Some tests failed."
fi
