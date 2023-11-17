#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "marriage.h"

int main() {
	srand(time(NULL)); // inicializando a semente para a geração de números aleatórios
	printf("-== Bem-vindo ao 90 IFs para casar! ==-\n\n");
	int match = 0, mismatch = 0, noPair = 0;
	struct pessoa *c1 = criaPessoa('A', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pessoa *c2 = criaPessoa('B', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pessoa *c3 = criaPessoa('C', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pessoa *p1 = criaPessoa('<', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pessoa *p2 = criaPessoa('^', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pessoa *p3 = criaPessoa('?', rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2);
	struct pilha *pilhaCandidatos = criaPilha();
	struct listaCirc *listaPretendentes = criaListaCircular();
	struct listaCirc *listaConcorrentes = criaListaCircular();
	push(pilhaCandidatos, c3);
	push(pilhaCandidatos, c2);
	push(pilhaCandidatos, c1);
	enlist(listaPretendentes, p1);
	enlist(listaPretendentes, p2);
	enlist(listaPretendentes, p3);
	printf("Lista de candidatos: ");
	printPilha(pilhaCandidatos);
	printf("Lista inicial de pretendentes: ");
	printLista(listaPretendentes);
	printf("\n");
	printf("O que os candidatos querem (1) e não querem (0):\n\n");
	printf("%c: ", c1 -> id);
	for (int i = 0; i < 6; i++)
		printf("%d ", c1 -> atr[i]);
	printf("\n");
	printf("%c: ", c2 -> id);
	for (int i = 0; i < 6; i++)
		printf("%d ", c2 -> atr[i]);
	printf("\n");
	printf("%c: ", c3 -> id);
	for (int i = 0; i < 6; i++)
		printf("%d ", c3 -> atr[i]);
	printf("\n\n");
	printf("Os atributos que os pretendentes possuem (1) e não possuem (0):\n\n");
	printf("%c: ", p1 -> id);
	for (int i = 0; i < 6; i++)
		printf("%d ", p1 -> atr[i]);
	printf("\n");
	printf("%c: ", p2 -> id);
	for (int i = 0; i < 6; i++)
		printf("%d ", p2 -> atr[i]);
	printf("\n");
	printf("%c: ", p3 -> id);
	for (int i = 0; i < 6; i++)
		printf("%d ", p3 -> atr[i]);
	printf("\n\n");
	while (!pilhaVazia(pilhaCandidatos)) {
		int atrCandidato[6], k = 0;
		char idCand = pilhaCandidatos -> topo -> id;
		pop(pilhaCandidatos, atrCandidato);
		struct pessoa *aux = listaPretendentes -> cbc;
		int j = tamLista(listaPretendentes);
		while (k < j) {
			for (int i = 0; i < 6; i++)
				if (aux -> atr[i] == 1 && atrCandidato[i] == 1)
					(aux -> relevancia)++;
			int relevanciaPretendente = aux -> relevancia;
			if (aux -> relevancia > 1) {
				printf("[+] O PRETENDENTE '%c' TEM ALGUNS ATRIBUTOS EM COMUM COM '%c'! ELE VAI CONCORRER AO MATCH!\n\n", aux -> id, idCand);
				struct pessoa *conc = criaPessoa(aux -> id, aux -> atr[0], aux -> atr[1], aux -> atr[2], 
								aux -> atr[3], aux -> atr[4], aux -> atr[5]);
				aux = aux -> prox;
        			delist(listaPretendentes, relevanciaPretendente);
				enlist(listaConcorrentes, conc);
			} else {
				printf("[-] O PRETENDENTE '%c' NÃO COMBINOU COM '%c'! CONTINUA NA LISTA DE PRETENDENTES...\n\n", aux -> id, idCand);
				aux = aux -> prox;
			}
			k++;
		}
		if (tamLista(listaConcorrentes) > 1) {
			// duelo entre concorrentes, quem perder volta para a lista de pretendentes
			// duelo: 1d20 por relevância
			// quem ganhar é delistado (só 1 deles) e vai duelar com o candidato
		} else if (tamLista(listaConcorrentes) == 1) {
			// delistagem do pretendente, ele vai duelar com o candidato
		} else {
			// SE O TAMANHO DA LISTA É MENOR QUE 1:
			// o candidato não é compatível com ninguém da lista de pretendentes
			// ele vai embora e o contador de noPair é incrementado
		}
		for (int i = 0; i < 90; i++) {
			// duelo entre candidato e pretendente
			// ambos rolam 1d20 por atributo por 90 iterações
			// a cada atributo, um deles acumula vitórias
			// se candidato tem mais vitórias que o pretendente, match++
			// senão, mismatch-- e o pretendentes volta para a lista
		}
	}
	printf("Lista de candidatos remanescentes: ");
	printLista(listaPretendentes);
	printf("Lista de concorrentes: ");
	printLista(listaConcorrentes);
	destroiPilha(pilhaCandidatos);
	noPair += tamLista(listaPretendentes);
	match += tamLista(listaConcorrentes);
	destroiLista(listaPretendentes);
	destroiLista(listaConcorrentes);
	printf("Pessoas sem par: %d\n", noPair);
	printf("Matches: %d\n", match);
	printf("Mismatches: %d\n", mismatch);

	return 0;
}
