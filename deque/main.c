#define SIZE_WORD 257

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

int main() {
	deque_t *d = new_deque();
	char data[SIZE_WORD];
	fgets(data, sizeof(data), stdin);
	data[strcspn(data, "\n")] = '\0';
	printf("%d\n", is_palindrome(data, d));
	free_deque(d);
	
	return 0;
}
