#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "marriage.h"

int main() {
	srand(time(NULL)); // inicializando a semente para a geração de números aleatórios
	int match = 0, mismatch = 0, noPair = 0;
	struct pessoa *c1 = criaPessoa('A', 0, 0, 0, 0, 0, 0);
	struct pessoa *c2 = criaPessoa('B', 1, 1, 1, 0, 0, 0);
	struct pessoa *c3 = criaPessoa('C', 0, 0, 1, 1, 1, 1);
	struct pessoa *p1 = criaPessoa('<', 1, 1, 1, 1, 1, 1);
	struct pessoa *p2 = criaPessoa('^', 0, 0, 1, 1, 1, 0);
	struct pessoa *p3 = criaPessoa('?', 1, 0, 1, 1, 0, 0);
	struct pilha *pilhaCandidatos = criaPilha();
	struct listaCirc *listaPretendentes = criaListaCircular();
	struct listaCirc *listaConcorrentes = criaListaCircular();
	push(pilhaCandidatos, c3);
	push(pilhaCandidatos, c2);
	push(pilhaCandidatos, c1);
	enlist(listaPretendentes, p1);
	enlist(listaPretendentes, p2);
	enlist(listaPretendentes, p3);
	while (!pilhaVazia(pilhaCandidatos)) {
		int numAtrCommon = 0, atrCand[6], k = 0;
		pop(pilhaCandidatos, atrCand);
		struct pessoa *aux = listaPretendentes -> cbc;
		while (k < tamLista(listaPretendentes)) {
			for (int i = 0; i < 6; i++) {
				if (atrCand[i] == 1)
					numAtrCommon++;
			}
			aux -> atrCommon = numAtrCommon;
			if (numAtrCommon >= 1) {
				struct pessoa *conc = criaPessoa(aux -> id, aux -> atr[0], aux -> atr[1], aux -> atr[2], aux -> atr[3], aux -> atr[4], aux -> atr[5]);
				aux = aux -> prox;
				delist(listaPretendentes, numAtrCommon);
				enlist(listaConcorrentes, conc);
			} else {
				aux = aux -> prox;
			}
			k++;
		}
	}
	printf("Lista de candidatos remanescentes: ");
	printLista(listaPretendentes);
	printf("Lista de concorrentes: ");
	printLista(listaConcorrentes);
	destroiPilha(pilhaCandidatos);
	destroiLista(listaPretendentes, &noPair);
	printf("Pessoas sem par: %d\n", noPair);
	printf("Matches: %d\n", match);
	printf("Mismatches: %d\n", mismatch);

	return 0;
}
