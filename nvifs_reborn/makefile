CCFLAGS = -Wall -Wextra -pedantic
PROGRAM = nvifs_reborn

all: $(PROGRAM)

$(PROGRAM): main.o marriage.o
	gcc -o $(PROGRAM) main.o marriage.o $(CCFLAGS)

main.o: main.c
	gcc -c main.c $(CCFLAGS)

marriage.o: marriage.c marriage.h
	gcc -c marriage.c $(CCFLAGS)

clear:
	rm -rf *.gch *.o $(PROGRAM) 
