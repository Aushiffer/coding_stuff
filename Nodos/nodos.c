#include <stdlib.h>
#include <stdio.h>
#include "nodos.h"

struct node {
	int data;
	struct node *next;
};

struct stack {
	struct node *top;
	int size;
};

struct stack *criaStack() {
	struct stack *temp;
	if (!(temp = malloc(sizeof(struct stack))))
		return -1;
	temp -> top -> next = NULL;
	temp -> top -> data = -1;
	temp -> size = 0;

	return temp;
}

int stackVazia(struct pilha *p) {
	if (p -> top -> next == NULL && p -> size == 0)
		return 1;
	
	return 0;
}

struct node *criaNode() {
	struct nodo *temp;
	if (!(temp = malloc(sizeof(struct nodo))))
		return -1;
	temp -> next = NULL;
	temp -> data = -1;

	return temp;
}
