FLAGS=-Wall -Wextra -pedantic
PROGRAM=main

all: $(PROGRAM)

$(PROGRAM): main.o listaDupla.o
	gcc -o $(PROGRAM) main.o listaDupla.o $(FLAGS)
main.o: main.c
	gcc -c main.c $(FLAGS)
listaDupla.o: listaDupla.c
	gcc -c listaDupla.c $(FLAGS)
clean:
	rm -f *.o $(PROGRAM)
