#!/bin/bash
make -f makefile clean
make
LD_LIBRARY_PATH=$(pwd)
./server --port 20001 --tnum 2 &
./server --port 20002 --tnum 3 &
./client --k 20 --mod 58 --servers ./servers.txt
#chmod ugo+x 
#./start.sh
#kill $(pgrep server)