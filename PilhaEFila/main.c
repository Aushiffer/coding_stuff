#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

int main() {
	struct pilha p = createStack();
	struct fila f = createQueue();
	push(&p, 10);
	push(&p, 20);
	pop(&p);
	pop(&p);
	printf("item (topo) e topo da pilha: %d %d\n", p.itens[p.top], p.top);

	return 0;	
}
