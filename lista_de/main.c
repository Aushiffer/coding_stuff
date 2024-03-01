#include <stdio.h>
#include "lista_de.h"

int main() {
	node_t *n1 = new_node();
	node_t *n2 = new_node();
	node_t *n3 = new_node();
	n1->data = 1000;
	n2->data = -1;
	n3->data = 0;
	dl_list *dll = new_list();
	insert_tail(dll, n1);
	insert_tail(dll, n2);
	insert_tail(dll, n3);
	print_list(dll);
	print_head(dll);
	print_tail(dll);
	insertion_sort(dll, size_list(dll));
	print_list(dll);
	free_list(dll);

	return 0;
}
