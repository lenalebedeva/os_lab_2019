CC=gcc
CFLAGS=-I.

all : mult.c server.c client.c
	gcc -c mult.c -o mult.o
	gcc -shared mult.o -o libmult.so
	gcc server.c -L. -lmult -lpthread -o server
	gcc client.c -L. -lmult -lpthread -o client

clean :
	rm mult.o libmult.so server client