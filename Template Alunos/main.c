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
	if (vetorTeste == NULL) {
		printf("[-] Erro fatal: erro de alocação dinâmica\n");
		return 1;
	}
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		vetorTeste[i] = rand() % 50;
	printArray(vetorTeste, size);
	insertionSort(vetorTeste, size);
	printArray(vetorTeste, size);
	printf("comps ins. sort: %ld\n", insertionSort(vetorTeste, size));

	free(vetorTeste);
	vetorTeste = NULL;

	return 0;
}
