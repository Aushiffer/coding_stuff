#include <stdio.h>
#include <stdlib.h>
#include "teddy_machine.h"

int main() {
	int n_machines, rounds, seed;
	scanf("%d %d %d", &n_machines, &rounds, &seed);

	if (n_machines < 0) {
		fprintf(stderr, "[-] main(): Invalid n_machines input\n");

		return EXIT_FAILURE;
	}

	teddy_machine *list = create_machine_list((unsigned int)n_machines);
	teddy_machine *aux = list;

	for (unsigned int i = 0; i < (unsigned int)n_machines; i++) {
		printf("%u\n", aux->id);
		aux = aux->next;
	}

	teddy_machine *select = select_machine(list, 5);

	if (!select) {
		fprintf(stderr, "main(): [-] Impossible to execute machine selection\n");

		return EXIT_FAILURE;
	}

	printf("\n%u\n", select->id);
	printf("We got here!\n");
	destroy_machine_list(list);

	return EXIT_SUCCESS;
}
