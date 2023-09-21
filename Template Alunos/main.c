#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"
#include "complementares.h"

int main() {
	char nome[MAX_CHAR_NOME];
	int *vetorTeste, valSearch;
	long size, *numComps;
	if (!(numComps = malloc(sizeof(int)))) {
		printf("[-] ERRO FATAL: problema com alocação dinâmica de memória\n");
		return 1;
	}
	getNome(nome);
	printf("Nome: %s\n", nome);
	printf("GRR: %u\n", getGRR());
	scanf("%ld %d", &size, &valSearch);
	if (!(vetorTeste = malloc(size * sizeof(int)))) {
		printf("[-] ERRO FATAL: problema com alocação dinâmica de memória\n");
		return 1;
	}
	putRandomNumbersOnArray(vetorTeste, size);
	printArray(vetorTeste, size);
	insertionSort(vetorTeste, size);
	printArray(vetorTeste, size);
	int posValSearch = buscaSequencial(vetorTeste, size, valSearch, numComps); 
	printf("comps ins. sort: %ld\n", insertionSort(vetorTeste, size));
	printf("comps sel. sort: %ld\n", selectionSort(vetorTeste, size));
	printf("searching for %d: %d\n", valSearch, posValSearch);
	if (posValSearch == -1)
		printf("%d isn't on the array\n", valSearch);
	printf("numComps for seq. search: %ld\n", *numComps);
	free(vetorTeste);
	free(numComps);
	vetorTeste = NULL;
	numComps = NULL;

	return 0;
}
