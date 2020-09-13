#!/bin/bash
make -f makefile clean
make

#chmod ugo+x start.sh
#./start.sh

#./tcpserver --port 20001 --bufsize 10 &
#./tcpclient --port 20001 --bufsize 10 --ip 127.0.0.1
#kill $(pgrep tcpserver)

#./udpserver --port 20001 --bufsize 5 &
#sleep 1
#./udpclient --port 20001 --bufsize 5 --ip 127.0.0.1
#11111222223333344444555556666677777
#kill $(pgrep udpserver)