#include "conjunto.h"
#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

// Cria um conjunto novo
struct conjunto *criaConj() {
	struct conjunto *temp;
	if (!(temp = malloc(sizeof(struct conjunto))))
		return NULL;
	temp -> tam = 0;
	temp -> maxTam = 10000;
	if (!(temp -> elementos = malloc(temp -> maxTam * sizeof(int))))
		return NULL;
	
	return temp;
}

// Destroi o conjunto, liberando toda a memória alocada para ele
void destroiConj(struct conjunto *c) {
	free(c -> elementos);
	c -> elementos = NULL;
	free(c);
	c = NULL;
}

// Retorna o tamanho do conjunto
int tamConj(struct conjunto *c) {
	return c -> tam;
}

bool conjVazio(struct conjunto *c) {
	if (tamConj(c) == 0)
		return true;
	
	return false;
}

// Verifica se o elemento x pertence ao conjunto C
bool pertenceConj(struct conjunto *c, int x) {
	if (!(conjVazio(c))) {
		for (int i = 0; i < tamConj(c); i++)
			if (c -> elementos[i] == x)
				return true;
	}

	return false;
}

// Ordena C com merge sort
void ordenaConj(struct conjunto *c) {
	mergeSort(c -> elementos, 0, tamConj(c) - 1);
}

// Insere o elemento x ao conjunto C, caso x não exista em C
void insereConj(struct conjunto *c, int x) {
	if (pertenceConj(c, x))
		return;
	if (c -> tam == c -> maxTam)
		return;
	c -> elementos[tamConj(c)] = x;
	(c -> tam)++;
}

// Se x pertencer ao conjunto, o remove
void removeConj(struct conjunto *c, int x) {
	if (pertenceConj(c, x))
		return;
	int posElemento = buscaSequencial(c -> elementos, 0, tamConj(c), x);
	swap(c -> elementos, posElemento, tamConj(c) - 1);
	c -> elementos[tamConj(c) - 1] = -42069;
	(c -> tam)--;
}

// Retorna conjunto de tamanho alocado máximo tamConj(c1) + tamConj(c2)
struct conjunto *uniao(struct conjunto *c1, struct conjunto *c2) {
	struct conjunto *conjUniao = criaConj();
	conjUniao -> maxTam = tamConj(c1) + tamConj(c2);

	return conjUniao;
}

// Retorna a interseção de C1 com C2
struct conjunto *intersecao(struct conjunto *c1, struct conjunto *c2) {
	struct conjunto *conjInter = criaConj();

	return conjInter;
}

void imprimeConj(struct conjunto *c) {
	for (int i = 0; i < tamConj(c); i++)
		printf("%d ", c -> elementos[i]);
	printf("\n");
}
