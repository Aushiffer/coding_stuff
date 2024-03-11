#ifndef TEDDY_MACHINE_H
#define TEDDY_MACHINE_H

typedef struct teddy_machine {
	unsigned int id;
	unsigned int probability;
	struct teddy_machine *next;
	struct teddy_machine *prev;
} teddy_machine;

// Cria uma lista de máquinas
teddy_machine *create_machine_list(unsigned int n_machines);

// Seleciona uma máquina da lista de máquinas
teddy_machine *select_machine(teddy_machine *list, unsigned int machine_place);

// Remove uma máquina da lista de máquinas
void remove_machine(teddy_machine *list, unsigned int machine_place);

// Libera a lista de máquinas e seus elementos
void destroy_machine_list(teddy_machine *list);

unsigned int get_attempt(unsigned int n_attempts);

unsigned int get_machine_place(unsigned int machine_place);

// Imprime a tentativa de conseguir um urso em determinada máquina
void print_attempt(teddy_machine *list, unsigned int attempt);

// Imprime as máquinas remanescentes
void print_remaining_machines(teddy_machine *list);

#endif // TEDDY_MACHINE_H
