#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"
#include "complementares.h"

int main() {
	char nome[MAX_CHAR_NOME];
	int *vetorTeste, valSearch;
	long size, *numComps, *numComps2;
	getNome(nome);
	printf("Nome: %s\n", nome);
	printf("GRR: %u\n", getGRR());
	scanf("%ld %d", &size, &valSearch);
	numComps = malloc(sizeof(long));
	numComps2 = malloc(sizeof(long));
	*numComps = 0;
	*numComps2 = 0;
	vetorTeste = malloc(size * sizeof(int));
	putRandomNumbersOnArray(vetorTeste, size);
	printArray(vetorTeste, size);
	insertionSort(vetorTeste, size);
	printArray(vetorTeste, size);
	int posValSearch = buscaSequencial(vetorTeste, size, valSearch, numComps);
	int posValSearch2 = buscaBinaria(vetorTeste, size, valSearch, numComps2);
	printf("comps ins. sort: %ld\n", insertionSort(vetorTeste, size));
	printf("comps sel. sort: %ld\n", selectionSort(vetorTeste, size));
	printf("searching for %d (seq. search): %d\n", valSearch, posValSearch);
	printf("searching for %d (bin. search); %d\n", valSearch, posValSearch2);
	if (posValSearch == -1)
		printf("%d isn't on the array (seq)\n", valSearch);
	if(posValSearch2 == -1)
		printf("%d isn't on the array (bin)\n", valSearch);
	printf("numComps for seq. search: %ld\n", *numComps);
	printf("numComps for bin. search: %ld\n", *numComps2);
	free(vetorTeste);
	free(numComps);
	free(numComps2);
	vetorTeste = NULL;
	numComps = NULL;
	numComps2 = NULL;

	return 0;
}
