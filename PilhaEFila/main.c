#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
	struct pilha p;
	createStack(&p);
	push(&p, 10);
	push(&p, 20);
	pop(&p);
	printf("item (topo) e topo da pilha: %d %d\n", p.itens[p.top], p.top);

	return 0;	
}
