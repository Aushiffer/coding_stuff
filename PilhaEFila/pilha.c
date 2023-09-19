#include <stdlib.h>

int emptyStack(struct pilha *p) {
	if (p -> itens[0] == -1)
		return 1;

	return 0;
}

int searchStack(struct pilha *p, int x) {
	if (emptyStack(p) == 1) {
		printf("[-] Pilha vazia\n");
		return -1;
	} else {
		for (int i = 0; i < top; i++)
			if (p -> itens[i] == x)
				return i;
	}
	printf("[-] Elemento não encontrado\n");
	
	return -2;
}

void push(struct pilha *p, int x) {
	if (p -> top == cap) {
		printf("[-] Overflow\n");
		return;
	} else {
		p -> top = p -> top + 1;
		p -> itens[p -> top] = x;
	}
}
