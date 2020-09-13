CC=gcc
CFLAGS=-I.

#цель: зависимости
#[tab] команда
all : parallel_sum.c sum.c utils.c
	gcc -c sum.c -o sum.o
	gcc -shared sum.o -o libsum.so
	gcc parallel_sum.c utils.c -L. -lsum -lpthread -o sum
	#gcc parallel_sum.c utils.c -L. -lsum -lpthread -o sum_
	#LD_LIBRARY_PATH=$(pwd)
	#./sum_ --seed 1 --array_size 100 --threads_num 10

clean :
	rm sum.o sum libsum.so sum_
	#make -f makefile clean
