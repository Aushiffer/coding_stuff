#include <stdlib.h>
#include "listaDupla.h"

int main() {
	struct listaDE *lista = inicializaLDE();
	insereCauda(lista, 5);
	insereCauda(lista, 10);
	free(lista);
	lista = NULL;

	return 0;
}
