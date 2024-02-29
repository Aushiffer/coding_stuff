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
	insert_node(dll, n1);
	insert_node(dll, n2);
	insert_node(dll, n3);
	remove_node(dll, 2000);
	print_list(dll);
	free_list(dll);

	return 0;
}
