#include <stdio.h>
#include <stdlib.h>
#include "teddy_machine.h"

int main() {
	unsigned int n_machines, rounds, seed;
	scanf("%u %u %u", &n_machines, &rounds, &seed);
	srand(seed);
	teddy_machine *list = create_machine_list(n_machines);
	teddy_machine *aux;
	unsigned int machine_place, machine_attempt;

	for (unsigned int r = 0; r < rounds; r++) {
		machine_place = get_place(n_machines);
		machine_attempt = get_attempt();
		aux = select_machine(list, machine_place);

		if (!aux)
			break;
		
		printf("\n============================ ROUND %u ============================\n", r + 1);
		print_attempt(aux, machine_attempt);

		if (machine_attempt <= aux->probability)
			list = remove_machine(list, aux);
		else
			aux->probability = aux->probability + 2;
	
		print_remaining_machines(list);
		printf("==================================================================\n");
	}
	
	destroy_machine_list(list);

	return EXIT_SUCCESS;
}
