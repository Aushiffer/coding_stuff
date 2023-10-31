// .c para teste da biblioteca de LDE
#include <stdlib.h>
#include <stdio.h>
#include "listaDupla.h"

int main() {
	struct listaDE *lista = inicializaLDE();
	int valRm = -1001; // valor inicial qualquer p/ inicializar valRm
	insereCabeca(lista, 0);
	insereCauda(lista, 10);
	insereCauda(lista, 100);
	insereCabeca(lista, 1);
	insereOrdenado(lista, 11);
	insereOrdenado(lista, 12);
	removeItem(lista, 10);
	insereCabeca(lista, 10);
	insereCauda(lista, 11);
	insereOrdenado(lista, 1000);
	removeCabeca(lista, &valRm);
	removeCauda(lista, &valRm);
	removeItem(lista, 0);
	printf("lista: ");
	imprimeLDE(lista);
	printf("\n");
	printf("cabeça da lista: ");
	imprimeCabeca(lista);
	printf("\n");
	printf("cauda da lista: ");
	imprimeCauda(lista);
	printf("\n");
	printf("tam. da LDE: %d\n", tamanhoLDE(lista));
	printf("\n");
	printf("último valor removido da lista (por remoção na cauda/cabeça): %d\n", valRm);
	destroiLDE(lista);

	return 0;
}
