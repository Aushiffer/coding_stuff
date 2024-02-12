CCFLAGS = -Wall -Wextra -pedantic
PROGRAM = nvIfsREBORN

$(PROGRAM): main.o marriage.o
	gcc -o $(PROGRAM) main.o marriage.o $(CCFLAGS)

main.o: main.c
	gcc -c main.c $(CCFLAGS)

marriage.o: marriage.h marriage.c
	gcc -c marriage.c $(CCFLAGS)

clear:
	rm -f *.gch *.o $(PROGRAM) 
