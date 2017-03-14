# Makefile, versao 1
# Sistemas Operativos, DEI/IST/ULisboa 2016-17

CFLAGS=-g -Wall -pedantic -pthread
CC=gcc

all: asa1

asa1: main.o graph.o list.o 
	$(CC) $(CFLAGS) -o asa1 main.o graph.o list.o 

main.o: main.c list.h graph.h
	$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h graph.h
	$(CC) $(CFLAGS) -c list.c

graph.o: graph.c graph.h list.h
	$(CC) $(CFLAGS) -c graph.c

clean:
	rm -f *.o asa1
