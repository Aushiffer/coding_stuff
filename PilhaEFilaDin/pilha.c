#include <stdlib.h>

struct item *criaItem(int valor) {
	struct item *temp;
	if (!(temp = malloc(sizeof(struct item))))
		return NULL;
	temp -> proximo = NULL;
	temp -> valor = valor;

	return temp;
}

struct pilha *inicializaPilha() {
	struct pilha *temp;
	temp -> topo = NULL;
	temp -> tamanho = 0;

	return temp;
}
