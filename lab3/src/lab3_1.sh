#!/bin/bash
gcc find_min_max.c utils.c sequential_min_max.c -o sequential_min_max.o && ./sequential_min_max 2 10

#chmod ugo+x lab3_1.sh
#./lab3_1.sh