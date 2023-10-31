#include <stdlib.h>
#include <stdio.h>
#include "listaDupla.h"

int main() {
	struct listaDE *lista = inicializaLDE();
	int valRm = -1001; // valor inicial qualquer p/ inicializar valRm
	insereCabeca(lista, 1);
	insereCabeca(lista, 10);
	insereCabeca(lista, 100);
	insereCauda(lista, 5);
	insereCauda(lista, 2);
	insereCauda(lista, 9);
	removeCauda(lista, &valRm);
	removeCabeca(lista, &valRm);
	removeItem(lista, 1);
	removeItem(lista, 5);
	printf("lista: ");
	imprimeLDE(lista);
	printf("cabeça da lista: ");
	imprimeCabeca(lista);
	printf("cauda da lista: ");
	imprimeCauda(lista);
	printf("tam. da LDE: %d\n", tamanhoLDE(lista));
	printf("último valor removido da lista (por remoção/inserção na cauda/cabeça): %d\n", valRm);
	destroiLDE(lista);

	return 0;
}
