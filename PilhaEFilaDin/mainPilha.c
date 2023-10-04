#include "pilha.h"
#include <stdio.h>

int main() {
	struct pilha *p = inicializaPilha();
	int valPop;
	push(p, 5);
	push(p, 10);
	push(p, 15);
	push(p, 20);
	pop(p, &valPop);
	pop(p, &valPop);
	imprimeTopo(p);
	printf("tam. da pilha: %d\n", tamanhoPilha(p));
	destroiPilha(p);

	return 0;
}
