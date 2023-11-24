parametrosCompilacao=-Wall -lm #-Wshadow
nomePrograma=trab

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o complementar.o
	gcc -o $(nomePrograma) main.o ordenacao.o complementar.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

complementar.o: complementar.h complementar.c
	gcc -c complementar.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)