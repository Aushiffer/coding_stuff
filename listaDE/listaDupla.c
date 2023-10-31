#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

struct item *criaItem(int valor) {
	struct item *tmp;
	if (!(tmp = malloc(sizeof(struct item))))
		return NULL; // aloca espaço p/ um item (nodo) da LDE
	tmp -> valor = valor; // o valor do item é o passado por parâmetro
	tmp -> anterior = NULL; 
	tmp -> proximo = NULL; // um item n/ encadeado não possui próximo e anterior

	return tmp;
}

struct listaDE *inicializaLDE() {
	struct listaDE *tmp;
	if (!(tmp = malloc(sizeof(struct listaDE))))
		return NULL; // aloca espaço p/ a LDE
	tmp -> cabeca = NULL;
	tmp -> cauda = NULL; // lista inicializada, os ptrs. de cabeça/cauda são nulos
	tmp -> tamanho = 0;

	return tmp; // retorna a lista criada
}

bool listaVazia(struct listaDE *l) {
	if (l -> cabeca == NULL || l -> cauda == NULL)
		return true; // verifica se a lista está vazia, checando se a cabeça ou a cauda são nulos

	return false;
}

int tamanhoLDE(struct listaDE *l) {
	return l -> tamanho; // tamanho da LDE
}

void imprimeCabeca(struct listaDE *l) {
	if (listaVazia(l))
		return;
	printf("%d ", l -> cabeca -> valor); // impressão da cabeça da LDE, se esta não estiver vazia
	printf("\n");
}

void imprimeCauda(struct listaDE *l) {
	if (listaVazia(l))
		return;
	printf("%d ", l -> cauda -> valor); // impressão da cauda da LDE, se esta não estiver vazia
	printf("\n");
}

void imprimeLDE(struct listaDE *l) {
	if (listaVazia(l))
		return;
	int k, j;
	k = 0;
	j = tamanhoLDE(l);
	struct item *aux = l -> cabeca;
	while (k < j) {
		printf("%d ", aux -> valor);
		aux = aux -> proximo;
		k++;
	} // impressão da LDE usando um contador, se esta não estiver vazia
	printf("\n");
}

int insereCabeca(struct listaDE *l, int x) {
	struct item *novoItem = criaItem(x);
	if (novoItem == NULL)
		return 0; // retorna 0 se o novo item for nulo
	if (listaVazia(l)) {
		l -> cabeca = novoItem;
		l -> cauda = l -> cabeca;
		(l -> tamanho)++;
		return 1;
	} // se a LDE estiver vazia, a cabeça e a cauda apontam p/ o mesmo lugar
	novoItem -> proximo = l -> cabeca; // proximo do novo item é a atual cabeça
	l -> cabeca -> anterior = novoItem; // anterior da atual cabeça é o novo item
	l -> cabeca = novoItem; // a cabecça agora é o novo item
	(l -> tamanho)++; 

	return 1;
}

int removeCabeca(struct listaDE *l, int *dado) {
	if (listaVazia(l))
		return 0; // se a LDE for vazia, não há nada para remover
	*dado = l -> cabeca -> valor; // "salvando" o dado removido
	struct item *tmp = l -> cabeca; // auxiliar recebe a atual cabeça
	l -> cabeca = l -> cabeca -> proximo; // cabeça agora é seu próximo
	free(tmp);
	tmp = NULL; // antiga cabeça é liberada
	(l -> tamanho)--;

	return 1;
}

int insereCauda(struct listaDE *l, int x) {
	struct item *novoItem = criaItem(x);
	if (novoItem == NULL)
		return 0;
	if (listaVazia(l)) {
		l -> cauda = novoItem;
		l -> cabeca = l -> cauda;
		(l -> tamanho)++;
		return 1;
	} // se a LDE estiver vazia, a cabeça e a cauda apontam p/ o mesmo lugar
	novoItem -> anterior = l -> cauda; // anterior do novo item é a atual cauda
	l -> cauda -> proximo = novoItem; // próximo da cauda recebe o novo item
	l -> cauda = novoItem; // a cauda agora é o novo item
	(l -> tamanho)++;

	return 1;
}

int removeCauda(struct listaDE *l, int *dado) {
	if (listaVazia(l))
		return 0;
	*dado = l -> cauda -> valor; // "salvando" o valor removido
	struct item *tmp = l -> cauda; // auxiliar recebe a atual cauda
	l -> cauda = l -> cauda -> anterior; // cauda agora é seu anterior
	free(tmp);
	tmp = NULL; // antiga cauda é liberada
	(l -> tamanho)--;

	return 1;
}

int removeItem(struct listaDE *l, int valor) {
	if (listaVazia(l))
		return 0;
	struct item *ptrl = l -> cabeca; // ponteiro aux. que começa na cabeça
	int aux;
	if (l -> cabeca -> valor == valor) {
		removeCabeca(l, &aux);
		return 1;
	} else if (l -> cauda -> valor == valor) {
		removeCauda(l, &aux);
		return 1;
	} // verificando se o item a ser removido está na cauda ou na cabeça
	while (ptrl -> proximo != NULL) {	
		if (ptrl -> valor == valor) {
			ptrl -> anterior -> proximo = ptrl -> proximo; // próximo do anterior do ptr. aux. aponta p/ o próximo do ptr. aux.
			ptrl -> proximo -> anterior = ptrl -> anterior; // anterior do próximo do ptr. aux. aponta p/ o anterior do ptr. aux.
			// ^ com isso, agora o ptr. aux. não está mais encadeado
			free(ptrl);
			ptrl = NULL; // liberação do ponteiro aux.
			(l -> tamanho)--;
			return 1;
		}
		ptrl = ptrl -> proximo; // atualização do ponteiro aux. (vai 1 casa p/ direita)
	}

	return 0;
}

void destroiLDE(struct listaDE *l) {
	int aux, k, j;
	j = tamanhoLDE(l);
	k = 0;
	while (k < j) {
		removeCabeca(l, &aux);
		k++;
	} // liberação de cada nodo da lista com um contador
	free(l);
	l = NULL; // liberação da lista
}
