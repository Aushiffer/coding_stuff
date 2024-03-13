#define SIZE_WORD 257

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

int main() {
	char data[SIZE_WORD];
	fgets(data, sizeof(data), stdin);
	data[strcspn(data, "\n")] = '\0';
	
	if (is_palindrome(data))
		puts("Palindrome: true");
	else
		puts("Palindrome: false");
	
	return 0;
}
