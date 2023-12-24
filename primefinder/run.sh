#!/bin/bash

# Run Python program
echo "Running Python program..."
python3 prime.py

# Run C++ program
echo -e "\nRunning C++ program..."
g++ prime.cpp -o prime_cpp
./prime_cpp

# Run JavaScript program
echo -e "\nRunning JavaScript program..."
node prime.js

# Run Java program
echo -e "\nRunning Java program..."
javac Prime.java
java Prime

# Clean up
rm -f prime_cpp Prime.class
