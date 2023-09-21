#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila createQueue() {
	struct fila temp;
	temp.cap = MAX;
	temp.first = 0;
	temp.last = 0;
	temp.itens[0] = -1;

	return temp;
}

int queueEmpty(struct fila f) {
	if (f.first == 0)
		return 1;
	
	return 0;
}

void enqueue(struct fila *f, int x) {
	if (queueEmpty(*f) == 1) {
		f -> first = f -> first + 1;
		f -> last = f -> last + 1;
		f -> itens[f -> first] = x;
	}
	if (f -> last == f -> cap) {
		printf("[-] Overflow detectado, abortando enqueue...\n");
		return;
	}
	f -> last = f -> last + 1;
	f -> itens[f -> last] = x;
}

int dequeue(struct fila *f) {
	if (f -> first == f -> last) {
		printf("[-] Underflow detectado, abortando dequeue...\n");
		return -1;
	}
	int dequeueItem = f -> itens[f -> first];
	f -> itens[f -> first] = -1;
	f -> first = f -> first + 1;

	return dequeueItem;
}

int countItensQueue(struct fila f) {
	int count = 0;
	if (queueEmpty(f) == 1)
		return count;
	for (int i = f.first; i <= f.last; i++)
		count++;

	return count;
}
