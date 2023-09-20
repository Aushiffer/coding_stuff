#include <stdlib.h>
#include "pilha.h"

void push(struct pilha *p, int x) {
	p -> top = p -> top + 1;
	p -> itens[p -> top] = x;
}

void pop(struct pilha *p) {
	p -> itens[p -> top] = -1;
	p -> top = p -> top - 1;
}

int emptyStack(struct pilha *p) {
	if (p -> top = -1)
		return 1;
	
	return 0;
}
