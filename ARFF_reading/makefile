CFLAGS = -g -Wall -Wextra -pedantic
CC = gcc
PROGRAM = arff

all: $(PROGRAM)

$(PROGRAM): main.o
	$(CC) $(CFLAGS) -o $(PROGRAM) main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -rf *.gch *.o $(PROGRAM)
