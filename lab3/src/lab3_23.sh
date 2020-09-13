#!/bin/bash
gcc find_min_max.c utils.c parallel_min_max.c -o parallel_min_max.o
./parallel_min_max --seed 10 --array_size 10 --pnum 4 --by_files 0

#chmod ugo+x lab3_23.sh
#./lab3_23.sh