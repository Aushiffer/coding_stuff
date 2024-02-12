#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "marriage.h"

node_t *new_node() {
	srand(time(NULL));
	node_t *tmp = (node_t *)malloc(sizeof(node_t));
	
	if (!tmp) {
		printf("[-] Bad node_t malloc! Code: NULL_0\n");

		return NULL;
	}

	tmp->next = NULL;
	tmp->prev = NULL;

	for (int i = 0; i < ATR_NUM; i++)
		tmp->atr[i] = rand() % 2;

	tmp->name = (char *)malloc(CHAR_PTR_CAP * sizeof(char));
	
	if (!tmp->name) {
		printf("[-] Bad node name malloc! Code: NULL_1\n");
		free(tmp);
		tmp = NULL;

		return NULL;
	}

	strcpy(tmp->name, "undefined");
	tmp->relevance = 0;

	return tmp;
}

stack_t *new_stack() {
	stack_t *tmp = (stack_t *)malloc(sizeof(stack_t));

	if (!tmp) {
		printf("[-] Bad stack malloc! Code: NULL_2\n");

		return NULL;
	}

	tmp->top = NULL;
	tmp->size = 0;

	return tmp;
}

dl_list *new_dl_list() {
	dl_list *tmp = (dl_list *)malloc(sizeof(dl_list));

	if (!tmp) {
		printf("[-] Bad dl_list malloc! Code: NULL_3\n");

		return NULL;
	}

	tmp->tail = NULL;
	tmp->head = NULL;
	tmp->size = 0;

	return tmp;
}

int size_list(dl_list *l) { return l->size; }

bool empty_list(dl_list *l) { return l->size <= 0; } 

void give_name(node_t *n) { 
	if (!fgets(n->name, CHAR_PTR_CAP, stdin))
		printf("[-] Invalid name. NULL returned by fgets(). Code: INVALID_NAME\n");
}

bool empty_stack(stack_t *s) { return s->size <= 0; }

void push_stack(stack_t *s, node_t *n) {
	if (empty_stack(s)) {
		s->top = n;
		(s->size)++;

		return;
	}
	
	n->prev = s->top;
	s->top = n;
	(s->size)++;
}

void pop_stack(stack_t *s) {
	if (empty_stack(s)) {
		printf("[-] Stack is empty! Code: EMPTY_STACK\n");

		return;
	}

	node_t *aux = s->top;
	s->top = s->top->prev;
	free(aux->name);
	aux->name = NULL;
	free(aux);
	aux = NULL;
	(s->size)--;
}

void free_stack(stack_t *s) {
	while (!empty_stack(s))
		pop_stack(s);

	free(s);
	s = NULL;
}

void insert_node(dl_list *l, node_t *n) {
	if (empty_list(l)) {
		n->prev = n;
		n->next = n;
		l->head = n;
		l->tail = n;
		(l->size)++; // tudo aponta para o novo nodo

		return;
	}

	n->prev = l->tail;
	n->next = l->head;
	l->head->prev = n;
	l->tail->next = n;
	l->tail = n;
	(l->size)++; // redef. de ponteiros, mantendo a circularidade
}

void remove_head(dl_list *l) {
	if (l->head == l->tail) {
		free(l->head->name);
		l->head->name = NULL;
		free(l->head);
		l->head = NULL;
		(l->size)--;

		return;
	}
	
	node_t *aux = l->head;
	l->head = l->head->next;
	l->head->prev = l->tail;
	l->tail->next = l->head;
	free(aux->name);
	aux->name = NULL;
	free(aux);
	aux = NULL;
	(l->size)--;
}

void remove_tail(dl_list *l) {
	if (l->tail == l->head) {
		free(l->tail->name);
		l->tail->name = NULL;
		free(l->tail);
		l->tail = NULL;
		(l->size)--;

		return;
	}

	node_t *aux = l->tail;
	l->tail = l->tail->prev;
	l->tail->next = l->head;
	l->head->prev = l->tail;
	free(aux->name);
	aux->name = NULL;
	free(aux);
	aux = NULL;
	(l->size)--;
}

void remove_node(dl_list *l, int relevance_del) {
	if (empty_list(l)) {
		printf("[-] Empty list! Code: EMPTY_LIST\n");

		return;
	}

	if (l->head->relevance == relevance_del) {
		remove_head(l);

		return;
	} else if (l->tail->relevance == relevance_del) {
		remove_tail(l);

		return;
	}

	node_t *aux = l->head;
	int k = 0;
	
	while (k < size_list(l)) {
		if (aux->relevance == relevance_del) {
			aux->prev->next = aux->next;
			aux->next->prev = aux->prev;
			free(aux->name);
			aux->name = NULL;
			free(aux);
			aux = NULL;
			(l->size)--;

			return;
		}

		aux = aux->next;
		k++;
	}

}

void free_list(dl_list *l) {
	while (!empty_list(l))
		remove_head(l);

	free(l);
	l = NULL;
}

int roll_1d20(short n_dices) {
	srand(time(NULL));
	int sum = 0;

	for (int i = 0; i < n_dices; i++)
		sum += ((rand() % 20) + 1);

	return sum;
}
