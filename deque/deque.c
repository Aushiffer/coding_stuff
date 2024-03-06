#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

	if (empty_deque(d)) {
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

	if (empty_deque(d)) {
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

void free_deque(deque_t *d) {
	while(!empty_deque(d))
		remove_head(d);

	free(d);
	d = NULL;
}

void print_deque(deque_t *d) {
	node_t *aux = d->head;

	for (unsigned int i = 0; i < size_deque(d); i++) {
		printf("%c ", aux->letter);
		aux = aux->next;
	}

	printf("\n");
}

bool is_palindrome(char *word, deque_t *d) {
	bool return_var = true;	

	for (unsigned int i = 0; i < strlen(word); i++)
		insert_tail(d, word[i]);

	for (unsigned int j = 0; j < (strlen(word) / 2); j++) {
		if (remove_head(d) != remove_tail(d))
			return !return_var;
	}

	return return_var;
}
