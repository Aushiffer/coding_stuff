#include <stdio.h>
#include "lista_de.h"

int main() {
	node_t *n1 = new_node();
	node_t *n2 = new_node();
	node_t *n3 = new_node();
	n1->data = 10;
	n2->data = 100;
	n3->data = 1000;
	dl_list *dll = new_list();
	insert_tail(dll, n1);
	insert_head(dll, n2);
	insert_tail(dll, n3);
	remove_head(dll);
	print_head(dll);
	print_tail(dll);
	print_list(dll);
	free_list(dll);

	return 0;
}
