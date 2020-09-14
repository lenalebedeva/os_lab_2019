#!/bin/bash
max=150
count=0
rand=$(od -A n -td -N 2 /dev/random |tr -d ' ') 
num=$((rand % 10)) 
while [ $count -lt $max ]; 
do 
count=$[ $count + 1 ]
rand=$(od -A n -td -N 1 /dev/random |tr -d ' ') 
num="${num}$((rand % 10)) "
done 
echo $num > nambers.txt