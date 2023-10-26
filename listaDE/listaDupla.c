#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

struct item *criaItem(int valor) {
	struct item *tmp;
	if (!(tmp = malloc(sizeof(struct item))))
		return NULL;
	tmp -> valor = valor;
	tmp -> anterior = NULL;
	tmp -> proximo = NULL;

	return tmp;
}

struct listaDE *inicializaLDE() {
	struct listaDE *tmp;
	if (!(tmp = malloc(sizeof(struct listaDE))))
		return NULL;
	tmp -> cabeca = NULL;
	tmp -> cauda = NULL;
	tmp -> tamanho = 0;

	return tmp;
}

bool listaVazia(struct listaDE *l) {
	if (l -> cabeca == NULL || l -> cauda == NULL)
		return true; // verifica se a lista está vazia, checando se a cabeça ou a cauda são nulos

	return false;
}

int tamanhoLDE(struct listaDE *l) {
	return l -> tamanho;
}

void imprimeCabeca(struct listaDE *l) {
	if (listaVazia(l))
		return;
	printf("%d ", l -> cabeca -> valor);
	printf("\n");
}

void imprimeCauda(struct listaDE *l) {
	if (listaVazia(l))
		return;
	printf("%d ", l -> cauda -> valor);
	printf("\n");
}

void imprimeLDE(struct listaDE *l) {
	if (listaVazia(l))
		return;
	struct item *aux;
	aux = l -> cauda;
	while (aux -> proximo != NULL) {
		printf("%d ", aux -> valor);
		aux = aux -> proximo;
	}
	printf("\n");
}

int insereCabeca(struct listaDE *l, int x) {
	struct item *novoItem = criaItem(x);
	if (novoItem == NULL)
		return 0;
	if (listaVazia(l)) {
		l -> cabeca = novoItem;
		l -> cauda = novoItem;
		(l -> tamanho)++;
		return 1;
	}
	novoItem -> anterior = l -> cabeca;
	l -> cabeca -> proximo = novoItem;
	l -> cabeca = novoItem;
	(l -> tamanho)++;

	return 1;
}

int removeCabeca(struct listaDE *l, int *dado) {
	if (listaVazia(l))
		return 0;
	*dado = l -> cabeca -> valor;
	struct item *tmp = l -> cabeca;
	l -> cabeca = l -> cabeca -> anterior;
	free(tmp);
	tmp = NULL;
	(l -> tamanho)--;

	return 1;
}

int insereCauda(struct listaDE *l, int x) {
	struct item *novoItem = criaItem(x);
	if (novoItem == NULL)
		return 0;
	if (listaVazia(l)) {
		l -> cabeca = novoItem;
		l -> cauda = l -> cabeca;
		(l -> tamanho)++;
		return 1;
	}
	novoItem -> proximo = l -> cauda;
	l -> cauda -> anterior = novoItem;
	l -> cauda = novoItem;
	(l -> tamanho)++;

	return 1;
}

int removeCauda(struct listaDE *l, int *dado) {
	if (listaVazia(l))
		return 0;
	*dado = l -> cauda -> valor;
	struct item *tmp = l -> cauda;
	l -> cauda = l -> cauda -> proximo;
	free(tmp);
	tmp = NULL;
	(l -> tamanho)--;

	return 1;
}

void destroiLDE(struct listaDE *l) {
	int aux;
	while (l -> cauda -> proximo != NULL)
		removeCauda(l, &aux);
	free(l);
	l = NULL;
}
