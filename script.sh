#!/bin/bash
cat /proc/cpuinfo | grep flag | head -1
cd /home/grid/testbed/tb055/lab3/vec_samples/src 
ml icc
array=( "-xSSE2" "-xSSE3" "-xAVX"  )
for a in "${array[@]}"; do
  for b in {1..3}; do
    const1=$(date +%M)
    const2=$(date +%S)
    echo icpc -std=c++17 -O$b $a lab.cpp -o file-$const1-$const2
    icpc -std=c++17 -O$b $a lab.cpp -o file-$const1-$const2
    echo "$a $b:"
    time ./file-$const1-$const2
  done 
done