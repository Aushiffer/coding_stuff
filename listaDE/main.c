#include <stdlib.h>
#include <stdio.h>
#include "listaDupla.h"

int main() {
	struct listaDE *lista = inicializaLDE();
	int valRm = -1001;
	insereCabeca(lista, 5);
	insereCauda(lista, 10);
	insereCauda(lista, 20);
	insereCauda(lista, 100);
	insereCabeca(lista, 1);
	insereCabeca(lista, 2);
	removeCabeca(lista, &valRm);
	removeCauda(lista, &valRm);
	printf("lista: ");
	imprimeLDE(lista);
	printf("cabeça da lista: ");
	imprimeCabeca(lista);
	printf("cauda da lista: ");
	imprimeCauda(lista);
	printf("tam. da LDE: %d\n", tamanhoLDE(lista));
	printf("último valor removido da lista: %d\n", valRm);
	destroiLDE(lista);

	return 0;
}
