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
    if [ -f ex03_test ]; then
        rm ex03_test
        print_color "cyan" "Deleted compiled executable 'ex03_test'."
    else
        print_color "yellow" "No compiled executable found ('ex03_test')."
    fi
    exit 0
fi

# Compile the C++ code with ex03.cpp
g++ -o ex03_test ex03.cpp -I.

if [ $? -ne 0 ]; then
    print_color "red" "Compilation failed!"
    exit 1
fi

# Run the executable and capture the output
output=$(./ex03_test)

# Define the expected outputs for each test
declare -a expected_outputs=(
    "Dot product of u and v: 32"
)

# Extract actual outputs from the program's output
IFS=$'\n' read -r -d '' -a actual_outputs < <(echo "$output" && printf '\0')

# Run individual tests
all_tests_passed=true
test_counter=1

for expected in "${expected_outputs[@]}"; do
    # Compare each test block individually
    expected=$(echo "$expected" | tr -d '\r')
    actual=$(echo "${actual_outputs[@]}" | tr -d '\r')
    
    if [[ "$actual" == *"$expected"* ]]; then
        print_color "green" "Test $test_counter passed!"
    else
        print_color "red" "Test $test_counter failed!"
        print_color "yellow" "Expected:"
        echo "$expected"
        print_color "yellow" "Got:"
        echo "$actual"
        all_tests_passed=false
    fi
    ((test_counter++))
done

if $all_tests_passed; then
    print_color "green" "All tests passed!"
else
    print_color "red" "Some tests failed."
fi
