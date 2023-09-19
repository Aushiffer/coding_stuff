#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "complementares.h"

int main() {
	char nome[MAX_CHAR_NOME];
	int *vetorTeste, valSearch;
	long size, *numComps;
	*numComps = 0;
	getNome(nome);
	printf("Nome: %s\n", nome);
	printf("GRR: %u\n", getGRR());
	scanf("%ld %d", &size, &valSearch);
	if (!(vetorTeste = malloc(size * sizeof(int)))) {
		printf("[-] ERRO FATAL: problema com alocação dinâmica de memória\n");
		return 1;
	}
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		vetorTeste[i] = rand() % 11;
	printArray(vetorTeste, size);
	selectionSort(vetorTeste, size);
	printArray(vetorTeste, size);
	int posValSearch = buscaSequencial(vetorTeste, size, valSearch, numComps); 
	printf("comps ins. sort: %ld\n", insertionSort(vetorTeste, size));
	printf("comps sel. sort: %ld\n", selectionSort(vetorTeste, size));
	printf("searching for %d: %d\n", valSearch, posValSearch);
	if (posValSearch == -1)
		printf("%d isn't on the array\n", valSearch);
	printf("numComps for seq. search: %ld\n", *numComps);
	free(vetorTeste);
	vetorTeste = NULL;

	return 0;
}
