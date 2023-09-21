#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

void push(struct pilha *p, int x) {
	if (p -> top == p -> cap) {
		printf("[-] Overflow detectado, abortando a execução...\n");
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

void pop(struct pilha *p) {
	if (emptyStack(*) == 1) {
		printf("[-] Underflow detectado, abortando a execução...\n");
		return;
	}
	p -> itens[p -> top] = -1;
	p -> top = p -> top - 1;
}
