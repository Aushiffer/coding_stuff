#include <stdlib.h>
#include <stdio.h>
#include "nodos.h"

struct node *criaNodo(int val) {
	struct nodo *temp;
	if (!(temp = malloc(sizeof(struct nodo)))) {
		printf("[-] Impossível alocar nodo. Abortando...\n");
		return NULL;
	}	
	temp -> data = val;
	temp -> next = NULL;

	return temp;
}

void destroiNodo(struct nodo *n) {
	free(n);
}
