#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

struct item *criaItem(int valor) {
	struct item *temp;
	if (!(temp = malloc(sizeof(struct item))))
		return NULL; // verifica se o item foi alocado corretamente
	temp -> valor = valor; // o valor do item criado eh o valor passado por quem chamou a funcao
	temp -> proximo = NULL; // o proximo item nao aponta para nenhum endereco

	return temp; // retorna o item criado
}

struct fila *inicializaFila() {
	struct fila *fTemp;
	if (!(fTemp = malloc(sizeof(struct fila))))
		return NULL; // verifica se a fila foi alocada corretamente
	fTemp -> inicio = NULL;
	fTemp -> fim = NULL; // ambos fim e inicio da fila sao nulos, pois nao existem itens na fila
	fTemp -> tamanho = 0;

	return fTemp; // retorna uma fila inicializada
}

bool filaVazia(struct fila *f) {
	if(f -> tamanho == 0)
		return true;
	
	return false; // verifica se uma fila eh vazia, checando seu tamanho
}

int enfileira(struct fila *f, int x) {
	struct item *itemNovo = criaItem(x);
	if (itemNovo == NULL) // se por algum motivo o item criado for nulo, interrompe a operacao
		return 0;
	if (filaVazia(f)) {
		f -> inicio = itemNovo;
		f -> fim = f -> inicio; // se a fila for vazia, aponta o inicio e o fim para o item novo
		(f -> tamanho)++;
		return 1;
	}
	f -> fim -> proximo = itemNovo; // o proximo do fim atual aponta para o item novo 
	f -> fim = itemNovo; // atualiza o fim da fila com o item novo
	(f -> tamanho)++; // incrementa o tamanho da fila

	return 1;
}

int desenfileira(struct fila *f, int *dado) {
	if (filaVazia(f))
		return 0; // verifica se a fila esta vazia para que nao ocorra underflow
	*dado = f -> inicio -> valor; // "devolve" o valor removido para quem chamou a funcao
	struct item *temp = f -> inicio;
	f -> inicio = f -> inicio -> proximo; // atualiza o inicio da fila, agora ele passa a ser o proximo
	free(temp); // libera o inicio desatualizado
	temp = NULL;
	(f -> tamanho)--; // decrementa o tamanho

	return 1;
}

void imprimeInicioDaFila(struct fila *f) {
	if (filaVazia(f))
		return; // se a fila estiver vazia, nao imprime nada
	printf("%d\n", f -> inicio -> valor);
}

void imprimeFimDaFila(struct fila *f) {
	if(filaVazia(f))
		return; // se a fila estiver vazia, nao imprime nada
	printf("%d\n", f -> fim -> valor);
}

int tamanhoFila(struct fila *f) {
	return f -> tamanho;
}

void destroiFila(struct fila *f) {
	int aux;
	while (!(filaVazia(f)))
		desenfileira(f, &aux); // ate que a fila esteja vazia, realiza dequeue
	free(f); // libera o espaco alocado para a fila
	f = NULL;
}
