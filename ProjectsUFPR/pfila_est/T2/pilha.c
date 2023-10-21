#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct pilha createStack() {
	struct pilha temp;
	temp.top = 0; // a pilha começa a partir de 1
	temp.itens[0] = -1; // watchdog da pilha
	temp.cap = MAX; // capacidade máxima da pilha

	return temp; // retorna uma pilha inicializada
}

void push(struct pilha *p, int x) {
	if (p -> top == p -> cap) {
		printf("[-] Overflow detectado, abortando o push...\n");
		return;
	} // o if é satisfeito se o topo for igual à capacidade máxima, indicando overflow
	p -> top = p -> top + 1; // atualização do topo
	p -> itens[p -> top] = x; // inserção de x no novo topo
}

int emptyStack(struct pilha p) {
	if (p.top == 0)
		return 1;
	// a pilha começa em 1, então se o topo for 0, não há elementos

	return 0;
}

int pop(struct pilha *p) {
	if (emptyStack(*p) == 1) {
		printf("[-] Underflow detectado, abortando o pop...\n");
		return -1;
	} // if satisfeito se a pilha estiver vazia
	int valPop = p -> itens[p -> top]; // guarda o valor a ser retornado
	p -> itens[p -> top] = -1; // coloca um valor watchdog no topo atual (remove)
	p -> top = p -> top - 1; // atualiza o topo

	return valPop; // retorna o valor que foi removido anteriormente
}

int searchStack(struct pilha p, int x) {
	if (emptyStack(p) == 1) {
		printf("[-] A pilha está vazia. Abortando busca...\n");
		return -1;
	} // if satisfeito se a pilha estiver vazia
	for (int i = 1; i <= p.top; i++)
		if (p.itens[i] == x)
			return i; // retorna o índice do elemento, se este for encontrado
	
	return -1; // se o elemento não for encontrado, retorna -1
}
