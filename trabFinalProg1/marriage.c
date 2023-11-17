#include <stdio.h>
#include <stdlib.h>
#include "marriage.h"

struct pessoa *criaPessoa(char id, int atr1, int atr2, int atr3, int atr4, int atr5, int atr6) {
	struct pessoa *tmpPessoa;
	if (!(tmpPessoa  = malloc(sizeof(struct pessoa)))) {
		printf("[-] ERRO NA ALOC. DA PESSOA!\n");
		return NULL; // aloc. dinâmica da pessoa
	}
	tmpPessoa -> id = id; // identificador da pessoa
	tmpPessoa -> atr[0] = atr1;
	tmpPessoa -> atr[1] = atr2;
	tmpPessoa -> atr[2] = atr3;
	tmpPessoa -> atr[3] = atr4;
	tmpPessoa -> atr[4] = atr5; 
	tmpPessoa -> atr[5] = atr6; 
	tmpPessoa -> relevancia = 0;
	tmpPessoa -> ant = NULL;
	tmpPessoa -> prox = NULL;

	return tmpPessoa; // retorna uma pessoa inicializada
}

struct listaCirc *criaListaCircular() {
	struct listaCirc *tmp;
	if (!(tmp = malloc(sizeof(struct listaCirc)))) {
		printf("[-] ERRO NA ALOC. DA LISTA DE PRETENDENTES\n");
		return NULL; // aloc. da lista circular duplamente encadeada
	}
	tmp -> cbc = NULL;
	tmp -> cauda = NULL;
	tmp -> tam = 0;

	return tmp; // retorna uma lista inicializada
}

struct pilha *criaPilha() {
	struct pilha *tmp;
	if (!(tmp = malloc(sizeof(struct pilha)))) {
		printf("[-] ERRO NA ALOC. DA PILHA DE CANDIDATOS\n");
		return NULL; // aloc. da pilha
	}
	tmp -> topo = NULL;
	tmp -> tam = 0;

	return tmp; // retorna uma pilha inicializada
}

int tamPilha(struct pilha *p) {
	return p -> tam;
}

int tamLista(struct listaCirc *l) {
	return l -> tam;
}

int pilhaVazia(struct pilha *p) {
	return tamPilha(p) == 0; // checa se a pilha está vazia pelo tamanho
}

int listaVazia(struct listaCirc *l) {
	return tamLista(l) == 0; // checa se a lista está vazia pelo tamanho
}

void push(struct pilha *p, struct pessoa *pers) {
	if (pilhaVazia(p)) {
		p -> topo = pers;
		(p -> tam)++;
		return; // se a pilha está vazia, define o topo como sendo a nova pessoa
	}
	pers -> prox = p -> topo;
	p -> topo = pers; // redefinição do topo, caso a pilha não esteja vazia
	(p -> tam)++;
}

void pop(struct pilha *p, int atrReturn[]) {
	if (pilhaVazia(p)) {
		printf("[-] PILHA VAZIA! IMPOSSÍVEL REALIZAR POP\n\n");
		return;
	}
	for (int i = 0; i < MAX_ATR; i++)
		atrReturn[i] = p -> topo -> atr[i]; // cópia dos atributos da pessoa
	struct pessoa *tmp = p -> topo;
	p -> topo = p -> topo -> prox;
	free(tmp);
	tmp = NULL; // redefinição de ponteiros e liberação da pessoa removida
	(p -> tam)--;
}

void enlist(struct listaCirc *l, struct pessoa *pers) {
	if (listaVazia(l)) {
		l -> cbc = pers;
		l -> cauda = pers;
		pers -> prox = pers;
		pers -> ant = pers;
		(l -> tam)++;
		return; // se a lista for vazia, todos os ponteiros apontam para a pessoa
	}
	pers -> ant = l -> cauda;
	pers -> prox = l -> cbc;
	l -> cauda -> prox = pers;
	l -> cbc -> ant = pers;
	l -> cauda = pers; // redefinição de ponteiros, mantendo a circularidade
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
		return; // caso a lista tenha um único ponteiro, ele é apenas liberado, sem redefinição
	}
	l -> cbc = l -> cbc -> prox;
	l -> cauda -> prox = l -> cbc;
	l -> cbc -> ant = l -> cauda;
	free(tmp);
	tmp = NULL; // redefinição de ponteiros e liberação da antiga cabeça da lista
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
		return; // caso a lista tenha um único ponteiro, ele é apenas liberado, sem redefinição
	}
	l -> cauda = l -> cauda -> ant;
	l -> cbc -> ant = l -> cauda;
	l -> cauda -> prox = l -> cbc;
	free(tmp);
	tmp = NULL; // redefinição de ponteiros e liberação da antiga cauda da lista
	(l -> tam)--;
}

void delist(struct listaCirc *l, int relevancia) {
	if (listaVazia(l)) {
		printf("[-] LISTA VAZIA! IMPOSSÍVEL REALIZAR DELIST\n\n");
		return;
	}
	struct pessoa *aux = l -> cbc; // ponteiro auxiliar que se move pela lista
	int k = 0;
	while (k < tamLista(l)) {
		if (aux -> relevancia == relevancia) {
			if (aux == l -> cbc) {
				delistCbc(l);
				return; // caso especial: a pessoa está na cabeça
			}
			if (aux == l -> cauda) {
				delistCauda(l);
				return; // caso especial: a pessoa está na cauda
			}
			aux -> prox -> ant = aux -> ant;
			aux -> ant -> prox = aux -> prox; // "ignorando" a pessoa a ser removida
			free(aux);
			aux = NULL; // liberação da pessoa
			(l -> tam)--;
			return;
		}
		aux = aux -> prox; // o ponteiro anda 1 casa para a direita na lista
		k++;
	}
	printf("[-] A PESSOA NÃO EXISTE!\n");
}

void printLista(struct listaCirc *l) {
	if (listaVazia(l)) {
		printf("[-] LISTA VAZIA! IMPOSSÍVEL IMPRIMIR A LISTA\n");
		return;
	}
	struct pessoa *aux = l -> cbc;
	do {
		printf("%c ", aux -> id);
		aux = aux -> prox;
	} while (aux != l -> cbc); // impressão das pessoa da lista
	printf("\n");
}

void printPilha(struct pilha *p) {
	if (pilhaVazia(p)) {
		printf("[-] PILHA VAZIA! IMPOSSÍVEL IMPRIMIR A PILHA\n");
		return;
	}
	struct pessoa *aux = p -> topo;
	while (aux != NULL) {
		printf("%c ", aux -> id);
		aux = aux -> prox;
	} // impressão das pessoas da pilha 
	printf("\n");
}

void destroiPilha(struct pilha *p) {
	int aux[MAX_ATR];
	while (!pilhaVazia(p))
		pop(p, aux);
	free(p);
	p = NULL; // liberação das pessoas da pilha, assim como o espaço reservado a elas
}

void destroiLista(struct listaCirc *l) {
	while (!listaVazia(l))
		delistCbc(l);
	free(l);
	l = NULL; // liberação das pessoas da lista, assim como o espaço reservado a elas
}

int rolar1d20(int nDados) {
	int sum = 0;
	for (int i = 0; i < nDados; i++)
		sum += ((rand() % 20) + 1); // soma e definição do intervalo [1, 20] para o dado

	return sum; // retorna a soma dos valores dos dados
}
