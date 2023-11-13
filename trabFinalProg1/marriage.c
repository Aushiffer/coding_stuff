#include <stdio.h>
#include <stdlib.h>
#include "marriage.h"

struct pessoa *criaPessoa(char id, int atr1, int atr2, int atr3, int atr4, int atr5, int atr6) {
	struct pessoa *tmpPessoa;
	if (!(tmpPessoa  = malloc(sizeof(struct pessoa)))) {
		printf("[-] ERRO NA ALOC. DA PESSOA!\n");
		return NULL;
	}
	tmpPessoa -> id = id;
	tmpPessoa -> atr[0] = atr1;
	tmpPessoa -> atr[1] = atr2;
	tmpPessoa -> atr[2] = atr3;
	tmpPessoa -> atr[3] = atr4;
	tmpPessoa -> atr[4] = atr5;
	tmpPessoa -> atr[5] = atr6;
	tmpPessoa -> tag = -1;
	tmpPessoa -> ant = NULL;
	tmpPessoa -> prox = NULL;

	return tmpPessoa;
}

struct listaCirc *criaListaCircular() {
	struct listaCirc *tmp;
	if (!(tmp = malloc(sizeof(struct listaCirc)))) {
		printf("[-] ERRO NA ALOC. DA LISTA DE PRETENDENTES\n");
		return NULL;
	}
	tmp -> cbc = NULL;
	tmp -> cauda = NULL;
	tmp -> tam = 0;

	return tmp;
}

struct pilha *criaPilha() {
	struct pilha *tmp;
	if (!(tmp = malloc(sizeof(struct pilha)))) {
		printf("[-] ERRO NA ALOC. DA PILHA DE CANDIDATOS\n");
		return NULL;
	}
	tmp -> topo = NULL;
	tmp -> tam = 0;

	return tmp;
}

int tamPilha(struct pilha *p) {
	return p -> tam;
}

int tamLista(struct listaCirc *l) {
	return l -> tam;
}

int pilhaVazia(struct pilha *p) {
	return p -> topo == NULL;
}

int listaVazia(struct listaCirc *l) {
	return l -> cbc == NULL || l -> cauda == NULL;
}

void push(struct pilha *p, struct pessoa *pers) {
	if (pilhaVazia(p) == 1) {
		p -> topo = pers;
		(p -> tam)++;
		return;
	}
	pers -> prox = p -> topo;
	p -> topo = pers;
	(p -> tam)++;
}

void pop(struct pilha *p, int atrReturn[]) {
	if (pilhaVazia(p) == 1) {
		printf("[-] PILHA VAZIA! IMPOSSÍVEL REALIZAR POP\n\n");
		return;
	}
	for (int i = 0; i < 6; i++)
		atrReturn[i] = p -> topo -> atr[i];
	struct pessoa *tmp = p -> topo;
	p -> topo = p -> topo -> prox;
	free(tmp);
	tmp = NULL;
	(p -> tam)--;
}

void enlist(struct listaCirc *l, struct pessoa *pers) {
	if (listaVazia(l) == 1) {
		l -> cbc = pers;
		l -> cauda = pers;
		pers -> prox = pers;
		pers -> ant = pers;
		(l -> tam)++;
		return;
	}
	pers -> ant = l -> cauda;
	pers -> prox = l -> cbc;
	l -> cauda -> prox = pers;
	l -> cbc -> ant = pers;
	l -> cauda = pers;
	(l -> tam)++;
}

void delistCbc(struct listaCirc *l) {
	if (listaVazia(l)) {
		printf("[-] LISTA VAZIA! IMPOSSÍVEL REALIZAR DELIST\n\n");
		return;
	}
	struct pessoa *tmp = l -> cbc;
	if (l -> cbc == l -> cauda) {
		free(l -> cbc);
		l -> cbc = NULL;
		(l -> tam)--;
		return;
	}
	l -> cbc = l -> cbc -> prox;
	l -> cauda -> prox = l -> cbc;
	l -> cbc -> ant = l -> cauda;
	free(tmp);
	tmp = NULL;
	(l -> tam)--;
}

void delistCauda(struct listaCirc *l) {
	if (listaVazia(l)) {
		printf("[-] LISTA VAZIA! IMPOSSÍVEL REALIZAR DELIST\n\n");
		return;
	}
	struct pessoa *tmp = l -> cauda;
	if (l -> cauda == l -> cbc) {
		free(l -> cauda);
		l -> cauda = NULL;
		(l -> tam)--;
		return;
	}
	l -> cauda = l -> cauda -> ant;
	l -> cbc -> ant = l -> cauda;
	l -> cauda -> prox = l -> cbc;
	free(tmp);
	tmp = NULL;
	(l -> tam)--;
}

struct pessoa *delist(struct listaCirc *l, int tag) {
	if (listaVazia(l)) {
		printf("[-] LISTA VAZIA! IMPOSSÍVEL REALIZAR DELIST\n\n");
		return NULL;
	}
	struct pessoa *aux = l -> cbc;
	struct pessoa *persReturn = NULL;
	do {
		if (aux -> tag == tag) {
			persReturn = aux;
			if (aux == l -> cbc) {
				delistCbc(l);
				break;
			}
			if (aux == l -> cauda) {
				delistCauda(l);
				break;
			}
			aux -> prox -> ant = aux -> ant;
			aux -> ant -> prox = aux -> prox;
			free(aux);
			aux = NULL;
			(l -> tam)--;
			break;
		}
		aux = aux -> prox;
	} while (aux != l -> cbc);
	if (!persReturn)
		printf("[-] DELIST NÃO REALIZADO! A PESSOA COM A TAG '%d' NÃO FOI ENCONTRADA NA LISTA\n\n", tag);
	else
		printf("[+] PESSOA '%c', TAG '%d' REMOVIDA COM SUCESSO!\n\n", persReturn -> id, persReturn -> tag);

	return persReturn;
}

void destroiPilha(struct pilha *p) {
	int aux[6];
	while (!pilhaVazia(p))
		pop(p, aux);
	free(p);
	p = NULL;
}

void destroiLista(struct listaCirc *l, int *count) {
	while (!listaVazia(l)) {
		(*count)++;
		delistCbc(l);
	}
	free(l);
	l = NULL;
}

int rolar1d20(int nDados) {
	int sum = 0;
	for (int i = 0; i < nDados; i++)
		sum += ((rand() % 20) + 1);

	return sum;
}
