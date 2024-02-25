CCFLAGS = -Wall -Wextra -pedantic
PROGRAM = set_program

all: $(PROGRAM)

$(PROGRAM): main.o set.o
	gcc -o $(PROGRAM) main.o set.o $(CCFLAGS)

main.o: main.c
	gcc -c main.c $(CCFLAGS)

set.o: set.c 
	gcc -c set.c $(CCFLAGS)

clean:
	rm -rf *.gch *.o $(PROGRAM)