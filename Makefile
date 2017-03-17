CFLAGS=-O3 -ansi -Wall
LDFLAGS=-lm
CC=gcc

all: asa1

asa1: main.o graph.o list.o 
	$(CC) $(CFLAGS) -o asa1 main.o graph.o list.o $(LDFLAGS)

main.o: main.c list.h graph.h
	$(CC) $(CFLAGS) -c main.c $(LDFLAGS)

list.o: list.c list.h graph.h
	$(CC) $(CFLAGS) -c list.c $(LDFLAGS)

graph.o: graph.c graph.h list.h 
	$(CC) $(CFLAGS) -c graph.c $(LDFLAGS)

clean:
	rm -f *.o asa1
