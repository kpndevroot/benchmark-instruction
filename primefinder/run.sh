#!/bin/sh
date=$(date +"%Y%m%d_%H%M%S")
result="results_${date}.txt"

exec > >(tee -a "$result") 2>&1


echo "SingleCore test running...."

cd SingleCore

source ./SingleCore.sh

cd ..

echo "MultiCore test running.... "

cd Multicore

source ./Multicore.sh

cd ..

echo "Execution successfull!"
