#include "conjunto.h"
#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

// Cria um conjunto novo
struct conjunto *criaConj() {
	struct conjunto *temp;
	if (!(temp = malloc(sizeof(struct conjunto))))
		return NULL; // aloca o conjunto
	temp -> tam = 0;
	temp -> maxTam = 1; // o tamanho máximo do conjunto mudará conforme a necessidade.
			    // em um conjunto novo, comporta 1 elemento
	if (!(temp -> elementos = malloc(temp -> maxTam * sizeof(int))))
		return NULL; // aloca os elementos do conjunto
	
	return temp; // retorna o conjunto criado
}

// Destroi o conjunto, liberando toda a memória alocada para ele
void destroiConj(struct conjunto *c) {
	free(c -> elementos); // libera os elementos
	c -> elementos = NULL;
	free(c); // libera o conjunto
	c = NULL;
}

// Retorna o tamanho do conjunto
int tamConj(struct conjunto *c) {
	return c -> tam;
}

// Se C for vazio, retorna true
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
	} // se C n for vazio, retorna um valor booleano para a pertinênica de x à C

	return false;
}

// Insere o elemento x ao conjunto C, caso x não exista em C
void insereConj(struct conjunto *c, int x) {
	if (pertenceConj(c, x))
		return; // preservação da unicidade do conjunto
	c -> elementos[tamConj(c)] = x; // x vai p/ última pos. do conjunto
	(c -> tam)++;
	(c -> maxTam)++; // incr. os tamanhos
	if (!(c -> elementos = realloc(c -> elementos, c -> maxTam * sizeof(int))))
		return; // realocação do tamanho max. do conjunto;
}

// Se x pertencer ao conjunto, o remove
void removeConj(struct conjunto *c, int x) {
	if (!(pertenceConj(c, x)))
		return;
	int posElemento = buscaSequencial(c -> elementos, 0, tamConj(c), x); // adquire a pos. de x
	swap(c -> elementos, posElemento, tamConj(c) - 1); // troca x com o último elemento do vetor
	(c -> tam)--;
	(c -> maxTam)--; // decr. os tamanhos
	if (!(c -> elementos = realloc(c -> elementos, c -> maxTam * sizeof(int))))
		return; // realocação do tamanho max. do conjunto
}

// Retorna conjunto de tamanho alocado máximo tamConj(c1) + tamConj(c2)
struct conjunto *uniao(struct conjunto *c1, struct conjunto *c2) {
	struct conjunto *conjUniao = criaConj();
	for (int i = 0; i < tamConj(c1); i++)
		insereConj(conjUniao, c1 -> elementos[i]);
	for (int j = 0; j < tamConj(c2); j++)
		insereConj(conjUniao, c2 -> elementos[j]);
	// os loops inserem os elementos na união, preservando a unicidade
	mergeSort(conjUniao -> elementos, 0, tamConj(conjUniao) - 1); // ordena a união

	return conjUniao; // retorna a união
}

// Retorna a interseção de C1 com C2
struct conjunto *intersecao(struct conjunto *c1, struct conjunto *c2) {
	struct conjunto *conjInter = criaConj();
	for (int i = 0; i < tamConj(c1); i++)
		for (int j = 0; j < tamConj(c2); j++)
			if (c1 -> elementos[i] == c2 -> elementos[j])
				insereConj(conjInter, c1 -> elementos[i]);
	// os loops inserem os elementos na interseção, preservando a unicidade
	mergeSort(conjInter -> elementos, 0, tamConj(conjInter) - 1); // ordena a interseção

	return conjInter; // retorna a interseção
}

// Imprime C com um for loop
void imprimeConj(struct conjunto *c) {
	for (int i = 0; i < tamConj(c); i++)
		printf("%d ", c -> elementos[i]);
	printf("\n");
}
