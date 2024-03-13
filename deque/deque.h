#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

// Node
typedef struct Node {
	struct Node *next;
	struct Node *prev;
	char letter;
} node_t;

// Deque
typedef struct Deque {
	node_t *head;
	node_t *tail;
	unsigned int size;
} deque_t;

// Creates a new node
node_t *new_node(char letter);

// Creates a new deque
deque_t *new_deque();

// Returns the size of the deque
unsigned int size_deque(deque_t *d);

// Returns 'true' if the deque is empty
bool empty_deque(deque_t *d);

// Inserts a node in the head of the deque
void insert_head(deque_t *d, char letter);

// Inserts a node in the tail of the deque
void insert_tail(deque_t *d, char letter);

// Removes a node from the head of the deque
char remove_head(deque_t *d);

// Removes a node from the tail of the deque
char remove_tail(deque_t *d);

// Prints the deque
void print_deque(deque_t *d);

// Frees the deque structure
void free_deque(deque_t *d);

// Verifies if a word, stored in a deque, is a palindrome
bool is_palindrome(char *word);

#endif // DEQUE_H
