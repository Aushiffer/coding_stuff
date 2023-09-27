#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila createQueue() {
	struct fila temp;
	temp.cap = MAX; // cap. máxima da fila
	temp.first = 0; // o índice do começo e do início da fila é o mesmo
	temp.last = 0;
	temp.itens[0] = -1; // watchdog da fila

	return temp; // retorna a fila inicializada
}

int queueEmpty(struct fila f) {
	if (f.first == 0)
		return 1;
	// se o primeiro for 0 consequentemente o último também é
	// logo, a fila está vazia

	return 0;
}

void enqueue(struct fila *f, int x) {
	if (queueEmpty(*f) == 1) {
		f -> first = f -> first + 1;
		f -> last = f -> last + 1;
		f -> itens[f -> first] = x;
		return;
	}
	// se for vazia, a fila é redefinida para ter um elemento
	// logo, início = final
	if (f -> last == f -> cap) {
		printf("[-] Overflow detectado, abortando enqueue...\n");
		return; 
	} // se o último for igual à cap. máxima, a atualização do final resulta em overflow
	f -> last = f -> last + 1; // atualização do final da fila
	f -> itens[f -> last] = x; // coloca x no final da fila
}

int dequeue(struct fila *f) {	
	int dequeueItem;
	if (queueEmpty(*f) == 1) {
		printf("[-] Underflow detectado, abortando dequeue...\n");
		return -1;
	} // se a fila estiver vazia, ocorre underflow
	if (f -> first == f -> last) {	
		dequeueItem = f -> itens[f -> first];
		f -> itens[f -> first] = -1;
		f -> first = f -> first - 1;
		f -> last = f -> last - 1;
		return dequeueItem;
	} // quando a fila tem 1 elemento, ambos last e first são atualizados
	dequeueItem = f -> itens[f -> first];
	f -> itens[f -> first] = -1;
	f -> first = f -> first + 1; // atualização de first e remoção do elemento no first anterior

	return dequeueItem; // retorna o item removido
}

int countItensQueue(struct fila f) {
	int count = 0;
	if (queueEmpty(f) == 1)
		return count; // se a fila estiver vazia, retorna 0
	for (int i = f.first; i <= f.last; i++)
		count++; // conta os elementos da fila, sequencialmente

	return count; // retorna o no. de elementos na fila
}

int searchQueue(struct fila f, int x) {
	if (queueEmpty(f) == 1) {
		printf("[-] Fila vazia, abortando busca...\n");
		return -1;
	} // aborta a busca em caso de fila vazia
	for (int i = 1; i <= f.last; i++)
		if (f.itens[i] == x)
			return i; // retorna a posição de x, se encontrado na fila
	
	return -1; // retorna -1 se x não for encontrado na fila
}
