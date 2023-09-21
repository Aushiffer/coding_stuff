#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

void createStack(struct pilha *p) {
	p -> top = 0;
	p -> cap = MAX;
	p -> itens[0] = -1;
}

void push(struct pilha *p, int x) {
	if (p -> top == p -> cap) {
		printf("[-] Overflow detectado, abortando o push...\n");
		return;
	}
	p -> top = p -> top + 1;
	p -> itens[p -> top] = x;
}

int emptyStack(struct pilha p) {
	if (p.top == 0)
		return 1;
	
	return 0;
}

int pop(struct pilha *p) {
	if (emptyStack(*p) == 1) {
		printf("[-] Underflow detectado, abortando o pop...\n");
		return -1;
	}
	int valPop = p -> itens[p -> top];
	p -> itens[p -> top] = -1;
	p -> top = p -> top - 1;

	return valPop;
}

int searchStack(struct pilha p, int x) {
	if (emptyStack(p) == 1) {
		printf("[-] A pilha está vazia. Abortando busca...\n");
		return -1;
	}
	for (int i = 1; i <= p.top; i++)
		if (p.itens[i] == x)
			return i;
	
	return -1;
}
