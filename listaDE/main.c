#include <stdlib.h>
#include <stdio.h>
#include "listaDupla.h"

int main() {
	struct listaDE *lista = inicializaLDE();
	insereCauda(lista, 5);
	insereCauda(lista, 10);
	imprimeCabeca(lista);
	imprimeCauda(lista);
	printf("tam. da LDE: %d\n", tamanhoLDE(lista));
	destroiLDE(lista);

	return 0;
}
