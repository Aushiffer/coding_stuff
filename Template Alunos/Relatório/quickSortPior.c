#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "complementares.h"

int main() {
	char nome[MAX_CHAR_NOME];
	int *vetorTeste;
	long size, *numComps;
	clock_t start, end;
	double total;

	getNome(nome);
	printf("Nome: %s\n", nome);
	printf("GRR: %u\n", getGRR());
	printf("Entre com o tamanho do vetor a ser ordenado (quick sort): ");
	scanf("%ld", &size);
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
	for (int i = 0; i < size; i++)
		vetorTeste[i] = i;
	printArray(vetorTeste, size);
	start = clock();
	*numComps = quickSort(vetorTeste, size);
	end = clock();
	printArray(vetorTeste, size);
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo de exec. do quick sort: %fs\n", total);
	printf("Comparações feitas: %ld\n", *numComps);
	free(vetorTeste);
	free(numComps);
	vetorTeste = NULL;
	numComps = NULL;

	return 0;
}
