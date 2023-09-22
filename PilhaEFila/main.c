#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

int main() {
	struct pilha p = createStack();
	struct fila f = createQueue();
	push(&p, 10);
	enqueue(&f, 100);
	enqueue(&f, 2000);
	dequeue(&f);
	dequeue(&f);
	dequeue(&f);
	printf("item (topo) e topo da pilha: %d %d\n", p.itens[p.top], p.top);
	printf("primeiro e último da fila: %d %d (índices %d e %d)\n", f.itens[f.first], f.itens[f.last], f.first, f.last);

	return 0;	
}
