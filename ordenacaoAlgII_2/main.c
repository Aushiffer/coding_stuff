#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "complementar.h"

int main() {
	srand(time(NULL)); // Semente do RNG
        char nome[MAX_CHAR];
        char nomeAlg[MAX_CHAR];
	clock_t start, end;
	float total;
	int *vetor, tamVetor;
	unsigned long numComps;
	printf("\nTamanho do vetor a ser ordenado: ");
	scanf("%d", &tamVetor);
        if (!(vetor = (int *)malloc(tamVetor * sizeof(int)))) {
		printf("[-] Erro na alocação do vetor.\n");
		return -1;
	}
        getNome(nome);
	getNomeAlgoritmoExtra(nomeAlg);
        printf("\nAluno: %s\n", nome);
        printf("GRR: %u\n", getGRR());
	printf("Algoritmo extra: %s\n", nomeAlg);
	aleatorizarVetor(vetor, tamVetor);
	printVetor(vetor, tamVetor);
	start = clock();
	numComps = heapSort(vetor, tamVetor);
	end = clock();
	total = ((float)end - start) / CLOCKS_PER_SEC;
	printVetor(vetor, tamVetor);
	printf("Comparações: %ld\n", numComps);
	printf("Tempo de execução: %fs\n\n", total);
	free(vetor);
	vetor = NULL;

	return 0;
}