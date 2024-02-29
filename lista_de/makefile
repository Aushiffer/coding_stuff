CCFLAGS = -Wall -Wextra -pedantic
PROGRAM = run_list

all: $(PROGRAM)

$(PROGRAM): main.o lista_de.o
	gcc -o $(PROGRAM) main.o lista_de.o $(CCFLAGS)

main.o: main.c
	gcc -c main.c $(CCFLAGS)

lista_de.o: lista_de.c lista_de.h
	gcc -c lista_de.c $(CCFLAGS)

clean:
	rm -rf *.gch *.o $(PROGRAM)
