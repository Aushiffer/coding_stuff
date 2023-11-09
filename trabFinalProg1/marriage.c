#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "marriage.h"

struct pessoa *criaPessoa(char *nome, int atr1, int atr2, int atr3, int atr4, int atr5, int atr6) {
	struct pessoa *tmpPessoa;
	if (!(tmpPessoa  = malloc(sizeof(struct pessoa)))) {
		printf("[-] ERRO NA ALOC. DA PESSOA: %s\n", nome);
		return NULL;
	}
	tmpPessoa -> nome = nome;
	tmpPessoa -> atr[0] = atr1;
	tmpPessoa -> atr[1] = atr2;
	tmpPessoa -> atr[2] = atr3;
	tmpPessoa -> atr[3] = atr4;
	tmpPessoa -> atr[4] = atr5;
	tmpPessoa -> atr[5] = atr6;
	tmpPessoa -> prox = NULL;

	return tmpPessoa;
}

struct listaCirc *criaLista() {
	struct listaCirc *tmp;
	if (!(tmp = malloc(sizeof(struct listaCirc)))) {
		printf("[-] ERRO NA ALOC. DA FILA DE PRETENDENTES\n");
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

void push(struct pilha *p, struct pessoa *pers, char *nome, int atr1, int atr2, int atr3, int atr4, int atr5, int atr6) {
	struct pessoa *novaPessoa = criaPessoa(nome, atr1, atr2, atr3, atr4, atr5, atr6);
	if (p -> topo == NULL) {
		p -> topo = novaPessoa;
		(p -> tam)++;
		return;
	}
	novaPessoa -> prox = p -> topo;
	p -> topo = novaPessoa;
	(p -> tam)++;
}

void pop(struct pilha *p, int *atrReturn) {
	if (p -> topo == NULL) {
		printf("[-] PILHA VAZIA! IMPOSSÍVEL REALIZAR POP\n");
		return;
	}
	atrReturn = p -> topo -> atr;
	struct pessoa *tmp = p -> topo;
	p -> topo = p -> topo -> prox;
	free(tmp);
	tmp = NULL;
	(p -> tam)--;
}
