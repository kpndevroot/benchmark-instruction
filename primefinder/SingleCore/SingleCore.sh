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

# Compile and run C code
print_boxed_message yellow "Compiling Prime.c..."
gcc Prime.c -o Prime_c
print_boxed_message green "Running Prime.c..."
time ./Prime_c
print_boxed_message cyan "----------------------------------"

# Compile and run C++ code
print_boxed_message yellow "Compiling Prime.cpp..."
g++ Prime.cpp -o Prime_cpp
print_boxed_message green "Running Prime.cpp..."
time ./Prime_cpp
print_boxed_message cyan "----------------------------------"

# Compile and run Java code
print_boxed_message yellow "Compiling Prime.java..."
javac Prime.java
print_boxed_message green "Running Prime.java..."
time java Prime
print_boxed_message cyan "----------------------------------"

# Run JavaScript code using Node.js
print_boxed_message yellow "Running Prime.js..."
time node Prime.js
print_boxed_message cyan "----------------------------------"

# Run Python code
print_boxed_message yellow "Running Prime.py..."
time python3 Prime.py
print_boxed_message cyan "----------------------------------"

# Clean up generated files
print_boxed_message yellow "Cleaning up..."
rm -f Prime_c Prime_cpp Prime.class Prime.class Prime_js

# Print a thank you message
print_boxed_message green "All scripts executed successfully!"
