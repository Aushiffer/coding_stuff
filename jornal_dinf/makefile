CFLAGS = -g -Wall -Wextra -pedantic
PROGRAM = jornal_dinf

all: $(PROGRAM)

$(PROGRAM): main.o jornal.o
	gcc -o $(PROGRAM) main.o jornal.o $(CFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

jornal.o: jornal.c jornal.h
	gcc -c jornal.c $(CFLAGS)

clean:
	rm -rf *.gch *.o $(PROGRAM)
