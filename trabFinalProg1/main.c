#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "marriage.h"

int main() {
	srand(time(NULL)); // inicializando a semente para a geração de números aleatórios
	printf("\n-= 90 IFs Para Casar! =-\n\n");
	int match = 0, mismatch = 0, noPair = 0;
	struct pessoa *c1 = criaPessoa('A', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pessoa *c2 = criaPessoa('B', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pessoa *c3 = criaPessoa('C', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pessoa *p1 = criaPessoa('<', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pessoa *p2 = criaPessoa('^', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pessoa *p3 = criaPessoa('?', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pessoa *p4 = criaPessoa('/', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pilha *pilhaCandidatos = criaPilha();
	struct listaCirc *listaPretendentes = criaListaCircular();
	struct listaCirc *listaConcorrentes = criaListaCircular();
	push(pilhaCandidatos, c3);
	push(pilhaCandidatos, c2);
	push(pilhaCandidatos, c1);
	enlist(listaPretendentes, p1);
	enlist(listaPretendentes, p2);
	enlist(listaPretendentes, p3);
	enlist(listaPretendentes, p4);
	printf("Lista de candidatos: ");
	printPilha(pilhaCandidatos);
	printf("Lista inicial de pretendentes: ");
	printLista(listaPretendentes);
	printf("\n");
	printf("Os atributos que os candidatos querem (1) e não querem (0):\n\n");
	struct pessoa *aux = pilhaCandidatos -> topo;
	for (int i = 0; i < tamPilha(pilhaCandidatos); i++) {
		printf("'%c': ", aux -> id);
		for (int j = 0; j < MAX_ATR; j++)
			printf("%d ", aux -> atr[j]);
		printf("\n");
		aux = aux -> prox;
	}
	printf("\n");
	printf("Os atributos que os pretendentes possuem (1) e não possuem (0):\n\n");
	struct pessoa *aux2 = listaPretendentes -> cbc;
	for (int i = 0; i < tamLista(listaPretendentes); i++) {
		printf("'%c': ", aux2 -> id);
		for (int j = 0; j < MAX_ATR; j++)
			printf("%d ", aux2 -> atr[j]);
		printf("\n");
		aux2 = aux2 -> prox;
	}
	printf("\n");
	iniciarPareamento(pilhaCandidatos, listaPretendentes, listaConcorrentes, &match, &mismatch, &noPair);
	printf("-= Fim do pareamento =-\n\n");
	printf("Lista de candidatos remanescentes: ");
	printLista(listaPretendentes);
	printf("Lista de concorrentes: ");
	printLista(listaConcorrentes);
	destroiPilha(pilhaCandidatos);
	noPair += tamLista(listaPretendentes);
	destroiLista(listaPretendentes);
	destroiLista(listaConcorrentes);
	printf("\n");
	printf("Matches: %d\n", match);
	printf("Mismatches: %d\n", mismatch);
	printf("Pessoas sem par/infelizes: %d\n\n", noPair);

	return 0;
}
