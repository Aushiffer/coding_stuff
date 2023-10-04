#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct item *criaItem(int valor) {
	struct item *temp;
	if (!(temp = malloc(sizeof(struct item))))
		return NULL; // verifica se o item foi alocado corretamente
	temp -> proximo = NULL;
	temp -> valor = valor; // insere valor passado por parametro no item criado

	return temp; // retorna um item criado
}

struct pilha *inicializaPilha() {
	struct pilha *temp;
	if (!(temp = malloc(sizeof(struct pilha))))
		return NULL; // verifica se a pilha foi alocada corretamente
	temp -> topo = NULL; // uma pilha inicializada nao tem nada em seu topo
	temp -> tamanho = 0;

	return temp; // retorna uma pilha inicializada
}

bool pilhaVazia(struct pilha *p) {
	if (p -> tamanho == 0)
		return true;

	return false; // verifica se a pilha eh vazia, checando seu tamanho
}

int push(struct pilha *p, int x) {
	struct item *itemNovo = criaItem(x);
	if (itemNovo == NULL) // se por algum motivo o item a ser inserido for nulo, interrompe a operacao
		return 0;
	if (pilhaVazia(p)) {
		p -> topo = itemNovo;
		(p -> tamanho)++;
		return 1; // item novo nao aponta para o proximo (anterior) se a pilha for vazia, pois nao existe proximo
	}
	itemNovo -> proximo = p -> topo; // o proximo do item novo eh o topo atual (que vem antes dele na pilha)
	p -> topo = itemNovo; // atualiza o topo com o item novo
	(p -> tamanho)++; // incrementa o tamanho da pilha

	return 1;
}

int pop(struct pilha *p, int *dado) {
	if (pilhaVazia(p))
		return 0; // verifica se a pilha eh vazia, para nao ocorrer underflow
	*dado = p -> topo -> valor; // "devolve" o valor removido a quem chamou a funcao
	struct item *temp = p -> topo;
	p -> topo = p -> topo -> proximo; // topo atualizado, agora ele eh o proximo item da pilha (seu anterior)
	free(temp); // libera o topo desatualizado
	temp = NULL;
	(p -> tamanho)--; // decrementa o tamanho da pilha

	return 1;
}

void imprimeTopo(struct pilha *p) {
	if (pilhaVazia(p))
		return; // se a pilha for vazia, nao imprime nada
	printf("%d\n", p -> topo -> valor);
}

int tamanhoPilha(struct pilha *p) {
	return p -> tamanho;
}

void destroiPilha(struct pilha *p) {
	int aux;
	while (!(pilhaVazia(p)))
		pop(p, &aux); // realiza pop ate que a pilha esteja vazia
	free(p); // libera o espaco alocado para a pilha
	p = NULL;
}
