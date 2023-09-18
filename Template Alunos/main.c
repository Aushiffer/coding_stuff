#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main(){
	char nome[MAX_CHAR_NOME];
	int valSearch, *vetorTeste;
	long size;
	getNome(nome);
	printf("Nome: %s\n", nome);
	printf("GRR: %u\n", getGRR());
	scanf("%ld", &size);
	vetorTeste = malloc(size * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		vetorTeste[i] = rand() % 50;
	for (int i = 0; i < size; i++)
		printf("%d ", vetorTeste[i]);
	printf("\n");
	insertionSort(vetorTeste, size);
	for (int i = 0; i < size; i++)
		printf("%d ", vetorTeste[i]);
	printf("\n");

	free(vetorTeste);
	vetorTeste = NULL;

	return 0;
}
