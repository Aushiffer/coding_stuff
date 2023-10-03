#include "fila.h"
#include <stdio.h>

int main() {
	struct fila *f = inicializaFila();
	int valDequeue;
	enfileira(f, 10);
	enfileira(f, 100);
	enfileira(f, 1000);
	enfileira(f, 10000);
	desenfileira(f, &valDequeue);
	imprimeInicioDaFila(f);
	imprimeFimDaFila(f);
	printf("tam. da fila: %d\n", tamanhoFila(f));
	printf("valor retornado pelo último dequeue: %d\n", valDequeue);

	return 0;
}
