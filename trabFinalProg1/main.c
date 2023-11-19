// Programa feito por Caio E. F. de Miranda - caio.miranda@ufpr.br

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "marriage.h"

int main() {
	srand(time(NULL)); // inicializando a semente para a geração de números aleatórios
	int match = 0, mismatch = 0, noPair = 0, tamPilhaCandidatos, tamListaPretendentes;
	struct pilha *pilhaCandidatos = criaPilha();
	struct listaCirc *listaPretendentes = criaListaCircular();
	struct listaCirc *listaConcorrentes = criaListaCircular();
	printf("\n-> Entre com o número de candidatos: ");
	scanf("%d", &tamPilhaCandidatos);
	printf("-> Entre com o número de pretendentes: ");
	scanf("%d", &tamListaPretendentes);
	printf("\n");
	for (int i = 0; i < tamPilhaCandidatos; i++) {
		char id;
		printf("* ID (caracter) do candidato %d: ", i + 1);
		scanf(" %c", &id);
		printf("\n");
		struct pessoa *novoCandidato = criaPessoa(id, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
		push(pilhaCandidatos, novoCandidato);
	}
	for (int j = 0; j < tamListaPretendentes; j++) {
		char id;
		printf("* ID (caracter) do pretendente %d: ", j + 1);
		scanf(" %c", &id);
		printf("\n");
		struct pessoa *novoPretendente = criaPessoa(id, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
		enlist(listaPretendentes, novoPretendente);
	}
	printf("\n-= 90 IFs Para Casar! =-\n\n");
	printf("Lista de candidatos: ");
	printPilha(pilhaCandidatos);
	printf("Lista inicial de pretendentes: ");
	printLista(listaPretendentes);
	printf("\n");
	printf("Os atributos que os candidatos querem (1) e não querem (0):\n\n");
	printAtrsPilha(pilhaCandidatos);
	printf("\n");
	printf("Os atributos que os pretendentes possuem (1) e não possuem (0):\n\n");
	printAtrsLista(listaPretendentes);
	printf("\n");
	iniciarPareamento(pilhaCandidatos, listaPretendentes, listaConcorrentes, &match, &mismatch, &noPair);
	printf("Lista de pretendentes remanescentes: ");
	printLista(listaPretendentes);
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
