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
		return true; // verifica se a lista está vazia, checando se a cabeça e a cauda são nulos

	return false;
}

int tamanhoLDE(struct listaDE *l) {
	return l -> tamanho;
}

void imprimeLDE(struct listaDE *l) {
	struct item *aux;
	aux = l -> cabeca;
	while (aux != NULL) {
		printf("%d ", aux -> valor);
		aux = aux -> proximo;
	}
}

void imprimeCabeca(struct listaDE *l) {
	printf("%d ", l -> cabeca -> valor);
}

void imprimeCauda(struct listaDE *l) {
	printf("%d ", l -> cauda -> valor);
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

	return 1;
}
