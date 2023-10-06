#include "pilha.h"
#include <stdio.h>

int main() {
	struct pilha *p = inicializaPilha();
	int valPop = -1;
	push(p, 5);
	push(p, 10);
	push(p, 15);
	push(p, 20);
	pop(p, &valPop);
	pop(p, &valPop);
	imprimeTopo(p);
	printf("tam. da pilha: %d\n", tamanhoPilha(p));
	printf("ultimo valor removido: %d\n", valPop);
	destroiPilha(p);

	return 0;
}
