#include <stdio.h>
#include <stdlib.h>
#include "lista_de.h"

node_t *new_node() {
	node_t *aux = (node_t *)malloc(sizeof(node_t));

	if (!aux) {
		fprintf(stderr, "[-] Allocation error\n");

		return NULL;
	}

	aux->next = NULL;
	aux->prev = NULL;
	aux->data = 0;

	return aux;
}

dl_list *new_list() {
	dl_list *aux = (dl_list *)malloc(sizeof(dl_list));

	if (!aux) {
		fprintf(stderr, "[-] Allocation error\n");

		return NULL;
	}

	aux->head = NULL;
	aux->tail = NULL;
	aux->size = 0;

	return aux;
}

int size_list(dl_list *dll) { return dll->size; }

int empty_list(dl_list *dll) { return size_list(dll) == 0; }

void insert_head(dl_list *dll, node_t *n) {
	if (empty_list(dll)) {
		dll->head = n;
		dll->tail = n;
		(dll->size)++;

		return;
	}

	n->next = dll->head;
	dll->head->prev = n;
	dll->head = n;
	(dll->size)++;
}

void insert_tail(dl_list *dll, node_t *n) {
	if (empty_list(dll)) {
		dll->head = n;
		dll->tail = n;
		(dll->size)++;

		return;
	}

	n->prev = dll->tail;
	dll->tail->next = n;
	dll->tail = n;
	(dll->size)++;
}

void insert_sorted(dl_list *dll, node_t *n) {
	insert_tail(dll, n);
	insertion_sort(dll, size_list(dll));
}

int remove_node(dl_list *dll, int value) {
	if (empty_list(dll)) {
		fprintf(stderr, "[-] Empty list\n");

		return -1;
	}

	node_t *aux = dll->head;

	if (dll->head->data == value)
		return remove_head(dll);
	else if (dll->tail->data == value)
		return remove_tail(dll);

	for (int i = 0; i < size_list(dll); i++) {
		if (aux->data == value) {
			int return_data = aux->data;
			aux->prev->next = aux->next;
			aux->next->prev = aux->prev;
			free(aux);
			aux = NULL;
			(dll->size)--;

			return return_data;
		}

		aux = aux->next;
	}
	
	fprintf(stderr, "[-] %d was not found in the list.\n", value);

	return -1;
}

int remove_head(dl_list *dll) {
	if (empty_list(dll)) {
		fprintf(stderr, "[-] Empty list\n");

		return -1;
	}
	
	node_t *aux = dll->head;
	int return_data = aux->data;

	if (size_list(dll) == 1) {
		free(aux);
		aux = NULL;
		(dll->size)--;

		return return_data;
	}
	
	dll->head = dll->head->next;
	free(aux);
	aux = NULL;
	(dll->size)--;

	return return_data;
}

int remove_tail(dl_list *dll) {
	if (empty_list(dll)) {
		fprintf(stderr, "[-] Empty list\n");

		return -1;
	}

	node_t *aux = dll->tail;
	int return_data = aux->data;

	if (size_list(dll) == 1) {
		free(aux);
		aux = NULL;
		(dll->size)--;

		return return_data;
	}

	dll->tail = dll->tail->prev;
	free(aux);
	aux = NULL;
	(dll->size)--;

	return return_data;
}

void swap_values(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

void insertion_sort(dl_list *dll, int size) {
	if (size == 1)
		return;

	int *list_values = (int *)malloc(size * sizeof(int));

	if (!list_values) {
		fprintf(stderr, "[-] Allocation error\n");

		return;
	}

	node_t *aux = dll->head;

	for (int i = 0; i < size; i++) {
		list_values[i] = aux->data;
		aux = aux->next;
	}

	for (int j = 0; j < size; j++) {
		int k = j;

		while (k > 0 && list_values[k] < list_values[k - 1]) {
			swap_values(&list_values[k], &list_values[k - 1]);
			k--;
		}
	}

	aux = dll->head;

	for (int p = 0; p < size; p++) {
		aux->data = list_values[p];
		aux = aux->next;
	}

	free(list_values);
	list_values = NULL;
}

void free_list(dl_list *dll) {
	while (!empty_list(dll))
		remove_head(dll);

	free(dll);
	dll = NULL;
}

void print_list(dl_list *dll) {
	if (empty_list(dll)) {
		fprintf(stderr, "[-] Empty list.\n");

		return;
	}

	node_t *aux = dll->head;

	for (int i = 0; i < size_list(dll); i++) {
		printf("%d ", aux->data);
		aux = aux->next;
	}

	printf("\n");
}

void print_head(dl_list *dll) {
	if (empty_list(dll)) {
		fprintf(stderr, "[-] Empty list.\n");

		return;
	}

	printf("%d\n", dll->head->data);
}

void print_tail(dl_list *dll) {
	if (empty_list(dll)) {
		fprintf(stderr, "[-] Empty list.\n");

		return;
	}

	printf("%d\n", dll->tail->data);
}
