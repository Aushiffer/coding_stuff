#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "complementares.h"

int main() {
	char nome[MAX_CHAR_NOME];
	int *vetorTeste, valSearch;
	long size, *numComps;
	clock_t start, end;
	double total;

	getNome(nome);
	printf("Nome: %s\n", nome);
	printf("GRR: %u\n", getGRR());
	scanf("%ld %d", &size, &valSearch);

	if (!(numComps = malloc(sizeof(long)))) {
		free(numComps);
		printf("[-] Erro fatal: problema com aloc. dinâmica de memória\n");
		return 1;
	}

	if (!(vetorTeste = malloc(size * sizeof(int)))) {
		free(numComps);
		printf("[-] Erro fatal: problema com aloc. dinâmica de memória\n");
		return 1;
	}
	
	for (int i = 0; i < size; i++)
		vetorTeste[i] = i;

	*numComps = 0;
	start = clock();
	int posValSearch = buscaBinaria(vetorTeste, size, valSearch, numComps);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo de exec. da busca binária: %fs\n", total);
	printf("Comparações feitas: %ld\n", *numComps);
	printf("%d está na posição %d\n", valSearch, posValSearch);
	if (posValSearch == -1)
		printf("%d não está no vetor\n", valSearch);

	free(vetorTeste);
	free(numComps);
	vetorTeste = NULL;
	numComps = NULL;

	return 0;
}
