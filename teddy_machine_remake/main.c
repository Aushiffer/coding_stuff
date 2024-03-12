#include <stdio.h>
#include <stdlib.h>
#include "teddy_machine.h"

int main() {
	int n_machines, rounds, seed;
	scanf("%d %d %d", &n_machines, &rounds, &seed);
	srand((unsigned int)seed);

	if (n_machines < 0) {
		fprintf(stderr, "[-] main(): Invalid n_machines input\n");

		return EXIT_FAILURE;
	}

	teddy_machine *list = create_machine_list((unsigned int)n_machines);
	unsigned int machine_place, machine_attempt;

	for (int r = 0; r < rounds; r++) {
		printf("\n============================ ROUND %u ============================\n", r + 1);
		machine_place = get_place(n_machines);
		machine_attempt = get_attempt();
		teddy_machine *aux = select_machine(list, machine_place);
		print_attempt(aux, machine_attempt);

		if (machine_attempt <= aux->probability)
			remove_machine(list, aux);
		else
			aux->probability = aux->probability + 2;
		
		print_remaining_machines(list);
		printf("==================================================================\n");
	}
	
	destroy_machine_list(list);

	return EXIT_SUCCESS;
}
