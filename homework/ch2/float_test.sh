#!/bin/bash
# compile
gcc -pthread -o $(dirname $0)/2.92.out $(dirname $0)/2.92.c
gcc -pthread -o $(dirname $0)/2.93.out $(dirname $0)/2.93.c
gcc -pthread -o $(dirname $0)/2.94.out $(dirname $0)/2.94.c
gcc -pthread -o $(dirname $0)/2.95.out $(dirname $0)/2.95.c
gcc -pthread -o $(dirname $0)/2.96.out $(dirname $0)/2.96.c
gcc -pthread -o $(dirname $0)/2.97.out $(dirname $0)/2.97.c

# test
echo "2.92"
./$(dirname $0)/2.92.out
echo "2.93"
./$(dirname $0)/2.93.out
echo "2.94"
./$(dirname $0)/2.94.out
echo "2.95"
./$(dirname $0)/2.95.out
echo "2.96"
./$(dirname $0)/2.96.out
echo "2.97"
./$(dirname $0)/2.97.out

echo "test finished"
