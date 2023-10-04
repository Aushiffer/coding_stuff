#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

struct item *criaItem(int valor) {
	struct item *temp;
	if (!(temp = malloc(sizeof(struct item))))
		return NULL;
	temp -> valor = valor;
	temp -> proximo = NULL;

	return temp;
}

struct fila *inicializaFila() {
	struct fila *fTemp;
	if (!(fTemp = malloc(sizeof(struct fila))))
		return NULL;
	fTemp -> inicio = NULL;
	fTemp -> fim = NULL;
	fTemp -> tamanho = 0;

	return fTemp;
}

bool filaVazia(struct fila *f) {
	if(f -> tamanho == 0)
		return true;
	
	return false;
}

int enfileira(struct fila *f, int x) {
	struct item *itemNovo = criaItem(x);
	if (itemNovo == NULL)
		return 0;
	if (filaVazia(f)) {
		f -> inicio = itemNovo;
		f -> fim = f -> inicio;
	}
	f -> fim -> proximo = itemNovo;
	f -> fim = itemNovo;
	(f -> tamanho)++;

	return 1;
}

int desenfileira(struct fila *f, int *dado) {
	if (filaVazia(f))
		return 0;
	*dado = f -> inicio -> valor;
	struct item *temp = f -> inicio;
	f -> inicio = f -> inicio -> proximo;
	free(temp);
	temp = NULL;
	(f -> tamanho)--;

	return 1;
}

void imprimeInicioDaFila(struct fila *f) {
	if (filaVazia(f))
		return;
	printf("%d\n", f -> inicio -> valor);
}

void imprimeFimDaFila(struct fila *f) {
	if(filaVazia(f))
		return;
	printf("%d\n", f -> fim -> valor);
}

int tamanhoFila(struct fila *f) {
	return f -> tamanho;
}

void destroiFila(struct fila *f) {
	int aux;
	while (!(filaVazia(f)))
		desenfileira(f, &aux);
	free(f);
	f = NULL;
}
