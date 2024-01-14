#!/bin/bash

# Function to print colorful messages with boxing
print_boxed_message() {
  color=$1
  message=$2

  len=${#message}
  border=$(printf "%-${len}s" "*")
  
  print_color "$color" "$border"
  print_color "$color" "* $message *"
  print_color "$color" "$border"
}

# Function to print colorful messages
print_color() {
  case $1 in
    red)    echo -e "\e[91m$2\e[0m";;
    green)  echo -e "\e[92m$2\e[0m";;
    yellow) echo -e "\e[93m$2\e[0m";;
    cyan)   echo -e "\e[96m$2\e[0m";;
    *)      echo "$2";;
  esac
}

# Compile and run Java code
print_boxed_message yellow "Compiling ParallelPrime.java..."
javac ParallelPrime.java
print_boxed_message green "Running ParallelPrime.java..."
time java ParallelPrime
print_boxed_message cyan "----------------------------------"

# Run JavaScript code using Node.js
print_boxed_message yellow "Running ParallelPrime.js..."
time node ParallelPrime.js
print_boxed_message cyan "----------------------------------"

# Clean up generated files
print_boxed_message yellow "Cleaning up..."
rm -f ParallelPrime.class

# Print a thank you message
print_boxed_message green "All scripts executed successfully!"
