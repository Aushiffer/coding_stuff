#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "marriage.h"

int main() {
	srand(time(NULL)); // inicializando a semente para a geração de números aleatórios
	int match = 0, mismatch = 0, noPair = 0;
	struct pessoa *c1 = criaPessoa('A', 0, 0, 1, 1, 0, 0);
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
		int relevanciaPretendente = 0, atrCandidato[6], k = 0, vitorias = 0;
		pop(pilhaCandidatos, atrCandidato);
		struct pessoa *aux = listaPretendentes -> cbc;
		while (k < tamLista(listaPretendentes)) {
			for (int i = 0; i < 6; i++) {
				if (atrCandidato[i] == 1 && aux -> atr[i] == 1)
					relevanciaPretendente++;
			}
			aux -> relevancia = relevanciaPretendente;
			if (relevanciaPretendente >= 1) {
				struct pessoa *conc = criaPessoa(aux -> id, aux -> atr[0], aux -> atr[1], aux -> atr[2], 
								aux -> atr[3], aux -> atr[4], aux -> atr[5]);
				aux = aux -> prox;
				delist(listaPretendentes, relevanciaPretendente);
				enlist(listaConcorrentes, conc);
			} else {
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
	destroiLista(listaPretendentes, &noPair);
	printf("Pessoas sem par: %d\n", noPair);
	printf("Matches: %d\n", match);
	printf("Mismatches: %d\n", mismatch);

	return 0;
}
