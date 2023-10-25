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
	if (l -> cabeca == NULL && l -> cauda == NULL)
		return true;

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
