#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "nodos.h"

struct pilha *criaPilha() {
	struct pilha *temp;
	if (!(temp = malloc(sizeof(struct pilha)))) {
		printf("[-] Impossível alocar pilha. Abortando...\n");
		return NULL;
	}
	temp -> size = 0;
	temp -> cap = sizeof(struct pilha);
	temp -> top = criaNodo();
	
	return temp;
}

int pilhaVazia(struct pilha *p) {
	if (p -> size == 0)
		return 1;

	return 0;
}

int pop(struct pilha *p) {
	if (pilhaVazia(p)) {
		printf("[-] Pop abortado por conta de underflow\n");
		return -1; // sinaliza underflow se a pilha estiver vazia
	}
	int returnVal = p -> top -> data;
	destroiNodo(p -> top);

	return returnVal;
}

void push(struct pilha *p, int x) {
	if (p -> size == p -> cap) {
		printf("[-] Push abortado por conta de overflow\n");
		return -1; // sinaliza overflow se a pilha estiver cheia
	}
	p -> top -> next = criaNodo(x);
	p -> top = p -> top -> next;
	(p -> size)++;
}

void destroiPilha(struct pilha *p) {
	for (int i = 0; i < p -> size; i++)
		pop(p);
	free(p);
}

int retornaTop(struct pilha *p) {
	return p -> top -> data;
}
