parametrosCompilacao=-Wall #-Wshadow
nomePrograma=trab

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o complementar.o manipularBuckets.o
	gcc -o $(nomePrograma) main.o ordenacao.o complementar.o manipularBuckets.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

complementar.o: complementar.h complementar.c
	gcc -c complementar.c $(parametrosCompilacao)

manipularBuckets.o: manipularBuckets.h manipularBuckets.c
	gcc -c manipularBuckets.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)