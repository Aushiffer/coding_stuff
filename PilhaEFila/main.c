#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
	struct pilha p;
	p.top = 0;
	p.itens[p.top] = -1;
	p.cap = MAX;
	push(&p, 10);
	pop(&p);
	pop(&p);
	printf("%d %d\n", p.itens[p.top], p.top);

	return 0;	
}
