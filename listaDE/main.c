#include <stdlib.h>
#include <stdio.h>
#include "listaDupla.h"

int main() {
	struct listaDE *lista = inicializaLDE();
	int valRm = -1001;
	insereCauda(lista, 5);
	insereCauda(lista, 10);
	insereCabeca(lista, 2);
	insereCabeca(lista, 4);
	removeCabeca(lista, &valRm);
	removeCauda(lista, &valRm);
	imprimeLDE(lista);
	imprimeCabeca(lista);
	imprimeCauda(lista);
	printf("tam. da LDE: %d\n", tamanhoLDE(lista));
	printf("último valor removido da lista: %d\n", valRm);
	destroiLDE(lista);

	return 0;
}
