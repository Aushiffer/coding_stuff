#include <stdio.h>
#include <stdlib.h>
#include "marriage.h"

int main() {
	node_t *n = new_node();
	node_t *n1 = new_node();
	stack_t *st = new_stack();
	push_stack(st, n);
	push_stack(st, n1);
	free_stack(st);

	return 0;
}
