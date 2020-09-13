#!/bin/bash
count=0
S=0
while [ -n "$1" ]
do
count=$[ $count + 1 ]
S=$[ $S + $1 ]
shift
done
A=$[ $S / $count ]
echo "Количество = $count; Среднее = $A"