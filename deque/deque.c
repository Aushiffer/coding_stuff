#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

node_t *new_node(char letter) {
	node_t *tmp = (node_t *)malloc(sizeof(node_t));

	if (!tmp) {
		fprintf(stderr, "[-] Allocation error in new_node().\n");

		return NULL;
	}

	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->letter = letter;

	return tmp;
}

deque_t *new_deque() {
	deque_t *tmp = (deque_t *)malloc(sizeof(deque_t));

	if (!tmp) {
		fprintf(stderr, "[-] Allocation error in new_deque().\n");

		return NULL;
	}

	tmp->head = NULL;
	tmp->tail = NULL;
	tmp->size = 0;

	return tmp;
}

unsigned int size_deque(deque_t *d) { return d->size; }

bool empty_deque(deque_t *d) { return d->size == 0; }

void insert_head(deque_t *d, char letter) {
	node_t *n = new_node(letter);

	if (!n) {
		fprintf(stderr, "[-] Returned node was NULL in insert_head().\n");

		return;
	}

	if (size_deque(d) == 1) {
		d->head = n;
		d->tail = n;
		(d->size)++;

		return;
	}

	n->next = d->head;
	d->head->prev = n;
	d->head = n;
	(d->size)++;
}

void insert_tail(deque_t *d, char letter) {
	node_t *n = new_node(letter);

	if (!n) {
		fprintf(stderr, "[-] Returned node was NULL in insert_tail().\n");

		return;
	}

	if (size_deque(d) == 1) {
		d->head = n;
		d->tail = n;
		(d->size)++;

		return;
	}

	n->prev = d->tail;
	d->tail->next = n;
	d->tail = n;
	(d->size)++;
}

char remove_head(deque_t *d) {
	if (empty_deque(d)) {
		fprintf(stderr, "[-] The deque is empty.\n");

		return '\0';
	}

	node_t *aux = d->head;
	char node_data = aux->letter;
	
	if (size_deque(d) == 1) {
		free(aux);
		aux = NULL;
		(d->size)--;

		return node_data; 
	}

	d->head = d->head->next;
	free(aux);
	aux = NULL;
	(d->size)--;

	return node_data;
}

char remove_tail(deque_t *d) {
	if (empty_deque(d)) {
		fprintf(stderr, "[-] The deque is empty.\n");

		return '\0';
	}

	node_t *aux = d->tail;
	char node_data = aux->letter;
	
	if (size_deque(d) == 1) {
		free(aux);
		aux = NULL;
		(d->size)--;

		return node_data; 
	}

	d->tail = d->tail->prev;
	free(aux);
	aux = NULL;
	(d->size)--;

	return node_data;
}

bool is_palindrome(deque_t *d);
