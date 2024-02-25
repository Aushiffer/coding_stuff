#include <stdio.h>
#include <stdlib.h>
#include "set.h"

set_t *new_set() {
	set_t *aux = (set_t *)malloc(sizeof(set_t));

	if (!aux)
		return NULL;
	
	aux->abs_size = 0;
	aux->max_size = aux->abs_size + 1;
	aux->elements = (int *)malloc(aux->max_size * sizeof(int));

	if (!aux->elements) {
		fprintf(stderr, "[-] Unfortunately, we got here.\n");
		free(aux);
		aux = NULL;

		return NULL;
	}

	return aux;
}

int size_set(set_t *s) { return s->abs_size; }

int is_set_empty(set_t *s) { return size_set(s) == 0; }

int exists_in_set(set_t *s, int a) {
	for (int i = 0; i < s->abs_size; i++)
		if (s->elements[i] == a)
			return 1;

	return 0;
}

void insertion_sort(int *set_array, int b) {
	for (int i = 0; i < b; i++) {
		int j = i;

		while (j > 0 && set_array[j] < set_array[j - 1]) {
			int aux = set_array[j];
			set_array[j] = set_array[j - 1];
			set_array[j - 1] = aux;
			j--;
		}
	}
}

void insert_in_set(set_t *s, int a) {
	if (exists_in_set(s, a))
		return;

	s->elements = realloc(s->elements, (s->max_size + 1) * sizeof(int));

	if (!s->elements) {
		fprintf(stderr, "[-] Unfortunately, we got here.\n");

		return;
	}

	(s->abs_size)++;
	(s->max_size)++;
	s->elements[size_set(s) - 1] = a;
	insertion_sort(s->elements, size_set(s));
}

void remove_from_set(set_t *s, int a) {
	if (is_set_empty(s)) {
		fprintf(stderr, "[-] Empty set.\n");

		return;
	}

	for (int i = 0; i < s->abs_size; i++) {
		if (s->elements[i] == a) {
			int aux = s->elements[i];
			s->elements[i] = s->elements[size_set(s) - 1];
			s->elements[size_set(s) - 1] = aux;
			(s->abs_size)--;
			(s->max_size)--;
			s->elements = realloc(s->elements, s->max_size * sizeof(int));

			if (!s->elements) {
				fprintf(stderr, "[-] Unfortunately, we got here.\n");

				return;
			}

			break;
		}
	}
}

void free_set(set_t *s) {
	if (!s) {
		fprintf(stderr, "[-] This set was already freed.\n");

		return;
	}

	free(s->elements);
	s->elements = NULL;
	free(s);
	s = NULL;
}

void print_set(set_t *s) {
	for (int i = 0; i < s->abs_size; i++)
		printf("%d ", s->elements[i]);

	printf("\n");
}

set_t *unite(set_t *s1, set_t *s2) {
	set_t *united_set = new_set();

	for (int i = 0; i < s1->abs_size; i++)
		insert_in_set(united_set, s1->elements[i]);

	for (int j = 0; j < s2->abs_size; j++)
		insert_in_set(united_set, s2->elements[j]);

	return united_set;
}

set_t *intersect(set_t *s1, set_t *s2) {
	set_t *intersected_set = new_set();

	for (int i = 0; i < s1->abs_size; i++) {
		for (int j = 0; j < s2->abs_size; j++) {
			if (s1->elements[i] == s2->elements[j])
				insert_in_set(intersected_set, s1->elements[i]);
		}
	}

	return intersected_set;
}