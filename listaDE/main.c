// .c para teste da biblioteca de LDE
#include <stdlib.h>
#include <stdio.h>
#include "listaDupla.h"

int main() {
	struct listaDE *lista = inicializaLDE();
	int valRm = -1001; // valor inicial qualquer p/ inicializar valRm
	insereCabeca(lista, 5);
	insereOrdenado(lista, 10);
	insereOrdenado(lista, 0);
	insereOrdenado(lista, 20);
	removeCabeca(lista, &valRm);
	removeCauda(lista, &valRm);
	insereOrdenado(lista, 15);
	insereOrdenado(lista, 13);
	insereOrdenado(lista, 0);
	removeItem(lista, 13);
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
	printf("último valor removido da lista (por remoção/inserção na cauda/cabeça): %d\n", valRm);
	destroiLDE(lista);

	return 0;
}
