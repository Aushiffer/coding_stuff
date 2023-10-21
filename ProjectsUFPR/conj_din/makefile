parametrosCompilacao=-Wall -Wextra -pedantic #-Wshadow
nomePrograma=testa_conjunto

all: $(nomePrograma)

$(nomePrograma): main.o conjunto.o ordenacao.o
	gcc -o $(nomePrograma) main.o conjunto.o ordenacao.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

conjunto.o: conjunto.h conjunto.c
	gcc -c conjunto.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
