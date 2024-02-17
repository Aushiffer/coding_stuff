#include <stdio.h>
#include <stdlib.h>
#include "marriage.h"

int main() {
	node_t *n1 = new_node();
	node_t *n2 = new_node();
	node_t *n3 = new_node();
	dl_list *list = new_dl_list();
	insert_node(list, n1);
	insert_node(list, n2);
	insert_node(list, n3);
	free_list(list);

	return 0;
}
