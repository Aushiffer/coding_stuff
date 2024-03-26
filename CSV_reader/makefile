CFLAGS = -g -Wall -Wextra -pedantic
CC = gcc
PROGRAM = csvreader

all: $(PROGRAM)

$(PROGRAM): csvreader.o io.o
	$(CC) -o $(PROGRAM) $(CFLAGS) csvreader.o io.o

csvreader.o: csvreader.c
	$(CC) -c csvreader.c $(CFLAGS)

io.o: io.c io.h
	$(CC) -c io.c $(CFLAGS)

clear:
	rm -rf *.gch *.o $(PROGRAM)