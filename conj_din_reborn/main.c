#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "set.h"

int main() {
	srand(time(NULL));
	set_t *s1 = new_set();
	set_t *s2 = new_set();
	int range_sets;
	printf("Max value of the sets: ");
	scanf("%d", &range_sets);
	printf("\n");
	
	for (int i = 0; i < range_sets; i++)
		insert_in_set(s1, (rand() % range_sets) + 1);

	for (int j = 0; j < range_sets; j++)
		insert_in_set(s2, (rand() % range_sets) + 1);

	set_t *u1 = unite(s1, s2);
	set_t *i1 = intersect(s1, s2);
	printf("Set 1: ");
	print_set(s1);
	printf("\n");
	printf("Set 2: ");
	print_set(s2);
	printf("\n");
	printf("Union: ");
	print_set(u1);
	printf("\n");
	printf("Intersection: ");
	print_set(i1);
	free_set(s1);
	free_set(s2);
	free_set(u1);
	free_set(i1);

	return 0;
}
