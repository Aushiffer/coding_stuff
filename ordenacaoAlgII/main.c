#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "complementares.h"

int main() {
        char nome[MAX_CHAR_NOME];
	int *vetorTeste, valSearch, posValSearch;
	long size, *numComps;
	clock_t start, end;
	double total;

	getNome(nome);
	printf("Nome: %s\n", nome);
	printf("GRR: %u\n", getGRR());
	printf("Entre com o tamanho do vetor a ser ordenado e o valor a ser buscado: ");
	scanf("%ld %d", &size, &valSearch);
	if (!(numComps = malloc(sizeof(long)))) {
		printf("[-] Erro fatal: problema com aloc. dinâmica de memória\n");
		return 1;
	}
	if (!(vetorTeste = malloc(size * sizeof(int)))) {
		free(numComps);
		printf("[-] Erro fatal: problema com aloc. dinâmica de memória\n");
		return 1;
	}
	*numComps = 0;
	putRandomNumbersOnArray(vetorTeste, size);
	printf("O vetor foi criado e será ordenado. Coloque printArray(vetorTeste, size) aqui para visualizar.\n");
	start = clock();
	*numComps = quickSort(vetorTeste, size);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("\nTempo de exec. do quicksort: %fs\n", total);
	printf("Comparações feitas: %ld\n\n", *numComps);
	*numComps = 0;
	putRandomNumbersOnArray(vetorTeste, size);
	start = clock();
	*numComps = insertionSort(vetorTeste, size);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo de exec. do insertion sort: %fs\n", total);
	printf("Comparações feitas: %ld\n\n", *numComps);
	*numComps = 0;
	putRandomNumbersOnArray(vetorTeste, size);
	start = clock();
	*numComps = selectionSort(vetorTeste, size);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC; 
	printf("Tempo de exec. do selection sort: %fs\n", total);
	printf("Comparações feitas: %ld\n\n", *numComps);
	*numComps = 0;
	putRandomNumbersOnArray(vetorTeste, size);
	start = clock();
	*numComps = mergeSort(vetorTeste, size);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo de exec. do merge sort: %fs\n", total);
	printf("Comparações feitas: %ld\n\n", *numComps);
	*numComps = 0;
	start = clock();
	posValSearch = buscaSequencial(vetorTeste, size, valSearch, numComps);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo de exec. da busca sequencial: %fs\n", total);
	printf("Comparações feitas: %ld\n", *numComps);
	if (posValSearch == -1)
		printf("%d n está no vetor\n\n", valSearch);
	else
		printf("%d está no vetor, pos: %d\n\n", valSearch, posValSearch);
	*numComps = 0;
	start = clock();
	posValSearch = buscaBinaria(vetorTeste, size, valSearch, numComps);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo de exec. da busca binária: %fs\n", total);
	printf("Comparações feitas: %ld\n", *numComps);
	if (posValSearch == -1)
		printf("%d n está no vetor\n\n", valSearch);
	else
		printf("%d está no vetor, pos: %d\n\n", valSearch, posValSearch);
	printf("O vetor foi ordenado. Coloque printArray(vetorTeste, size) aqui para visualizar.\n");
	free(vetorTeste);
	free(numComps);
	vetorTeste = NULL;
	numComps = NULL;

	return 0;
}
