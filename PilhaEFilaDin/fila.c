#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

struct item *criaItem(int valor) {
	struct item *temp;
	if (!(temp = malloc(sizeof(struct item)))) {
		printf("[-] Erro de alocação dinâmica de memória\n");
		return NULL;
	}
	temp -> valor = valor;
	temp -> proximo = NULL;

	return temp;
}

struct fila *inicializaFila() {
	struct fila *fTemp;
	if (!(fTemp = malloc(sizeof(struct fila)))) {
		printf("[-] Impossível inicializar a fila. Interrompendo inicialização...\n");
		return NULL;
	}
	fTemp -> inicio = NULL;
	fTemp -> fim = NULL;
	fTemp -> tamanho = 0;

	return fTemp;
}

bool filaVazia(struct fila *f) {
	if(f -> inicio == NULL && f -> fim == NULL)
		return true;
	
	return false;
}

int enfileira(struct fila *f, int x) {
	if (filaVazia(f)) {
		f -> inicio = criaItem(x);
		if (f -> inicio == NULL) {
			printf("[-] Algo de errado ocorreu ao enfileirar na fila vazia. Interrompendo enfileiramento...\n");
			return 0;
		}
		f -> fim = f -> inicio;
		(f -> tamanho)++;
	}
	f -> fim = criaItem(x);
	if (f -> fim == NULL) {
		printf("[-] Algo de errado ocorreu na enfileiração deste item. Interrompendo enfileiramento...\n");	
		return 0;
	}
	(f -> tamanho)++;

	return 1;
}

int desenfileira(struct fila *f, int *dado) {
	if (filaVazia(f)) {
		printf("[-] Fila vazia. Interrompendo desenfileiramento...\n");
		return 0;
	}
	*dado = f -> inicio -> valor;
	struct item *aux = f -> inicio;
	f -> inicio = f -> inicio -> proximo;
	free(aux);
	aux = NULL;
	(f -> tamanho)--;

	return 1;
}

void imprimeInicioDaFila(struct fila *f) {
	printf("%d\n", f -> inicio -> valor);
}

void imprimeFimDaFila(struct fila *f) {
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
