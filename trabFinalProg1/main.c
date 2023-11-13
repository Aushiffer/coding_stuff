#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "marriage.h"

int main() {
	srand(time(NULL));
	int match = 0;
	int mismatch = 0;
	int noPair = 0;
	struct pessoa *c1 = criaPessoa('A', 1, 0, 0, 1, 0, 0);
	struct pessoa *c2 = criaPessoa('B', 1, 1, 1, 0, 0, 0);
	struct pessoa *c3 = criaPessoa('C', 0, 0, 1, 1, 1, 1);
	struct pessoa *p1 = criaPessoa('@', 1, 1, 1, 1, 1, 1);
	struct pessoa *p2 = criaPessoa('!', 0, 1, 0, 1, 0, 1);
	struct pessoa *p3 = criaPessoa('?', 0, 1, 0, 1, 1, 1);
	struct pilha *pilhaCandidatos = criaPilha();
	struct listaCirc *listaPretendentes = criaListaCircular();
	push(pilhaCandidatos, c3);
	push(pilhaCandidatos, c2);
	push(pilhaCandidatos, c1);
	enlist(listaPretendentes, p1);
	enlist(listaPretendentes, p2);
	enlist(listaPretendentes, p3);
	printf("tamPilha: %d\n", tamPilha(pilhaCandidatos));
	printf("tamLista: %d\n", tamLista(listaPretendentes));
	destroiPilha(pilhaCandidatos);
	destroiLista(listaPretendentes, &noPair);
	printf("Pessoas sem par: %d\n", noPair);
	printf("Matches: %d\n", match);
	printf("Mismatches: %d\n", mismatch);

	return 0;
}
