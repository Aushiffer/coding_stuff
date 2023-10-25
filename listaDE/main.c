#include <stdlib.h>
#include "listaDupla.h"

int main() {
	struct listaDE *lista = inicializaLDE();
	free(lista);
	lista = NULL;

	return 0;
}
