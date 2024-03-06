CFLAGS = -g -Wall -Wextra -pedantic
PROGRAM = deque
CC = gcc

all: $(PROGRAM)

$(PROGRAM): main.o deque.o
	$(CC) -o $(PROGRAM) main.o deque.o $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

deque.o: deque.c deque.h
	$(CC) -c deque.c $(CFLAGS)

clean:
	rm -rf *.gch *.o $(PROGRAM)
