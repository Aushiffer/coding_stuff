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
	int *vetor, tamVetor, selectAlg;
	unsigned int *vetorUnsigned;
	unsigned long numComps = 0;
	getNome(nome);
	getNomeAlgoritmoExtra(nomeAlg);
        printf("\nAluno: %s\n", nome);
        printf("GRR: %u\n", getGRR());
	printf("Algoritmo extra: %s\n", nomeAlg);
	printf("\nTamanho do vetor a ser ordenado: ");
	scanf("%d", &tamVetor);
	if (!(vetor = (int *)malloc(tamVetor * sizeof(int)))) {
		printf("[-] Erro na alocação do vetor.\n");
		return -1;
	}
	if (!(vetorUnsigned = (unsigned int *)malloc(tamVetor * sizeof(unsigned int)))) {
		printf("[-] Erro na alocação do vetor.\n");
		return -1;
	}
	printf("1: Heapsort; 2: Quicksort; 3: Merge Sort; 4: Counting Sort; 5: %s\n", nomeAlg);
	printf("Selecione qual algoritmo deve ser usado para ordenar o vetor: ");
	scanf("%d", &selectAlg);
	printf("\n");
	if (selectAlg == 1) {
		aleatorizarVetor(vetor, tamVetor);
		// printVetor(vetor, tamVetor);
		start = clock();
		numComps = heapSort(vetor, tamVetor);
		end = clock();
		total = ((float)end - start) / CLOCKS_PER_SEC;
		// printVetor(vetor, tamVetor);
		printf("Comparações: %ld\n", numComps);
		printf("Tempo de execução: %fs\n\n", total);
	} else if (selectAlg == 2) {
		aleatorizarVetor(vetor, tamVetor);
		// printVetor(vetor, tamVetor);
		start = clock();
		numComps = quickSort(vetor, tamVetor);
		end = clock();
		total = ((float)end - start) / CLOCKS_PER_SEC;
		// printVetor(vetor, tamVetor);
		printf("Comparações: %ld\n", numComps);
		printf("Tempo de execução: %fs\n\n", total);
	} else if (selectAlg == 3) {
		aleatorizarVetor(vetor, tamVetor);
		// printVetor(vetor, tamVetor);
		start = clock();
		numComps = mergeSort(vetor, tamVetor);
		end = clock();
		total = ((float)end - start) / CLOCKS_PER_SEC;
		// printVetor(vetor, tamVetor);
		printf("Comparações: %ld\n", numComps);
		printf("Tempo de execução: %fs\n\n", total);
	} else if (selectAlg == 4) {
		aleatorizarVetorUnsigned(vetorUnsigned, tamVetor);
		// printVetorUnsigned(vetorUnsigned, tamVetor);
		int maxVal = vetorUnsigned[0];
		for (int i = 1; i < tamVetor; i++)
			if (vetorUnsigned[i] > maxVal)
				maxVal = vetorUnsigned[i]; // Definindo 'k'
		start = clock();
		countingSort(vetorUnsigned, tamVetor, maxVal);
		end = clock();
		total = ((float)end - start) / CLOCKS_PER_SEC;
		// printVetorUnsigned(vetorUnsigned, tamVetor);
		printf("Comparações: %ld\n", numComps);
		printf("Tempo de execução: %fs\n\n", total);
	} else {
		aleatorizarVetor(vetor, tamVetor);
		// printVetor(vetor, tamVetor);
		start = clock();
		numComps = algoritmoExtra(vetor, tamVetor);
		end = clock();
		total = ((float)end - start) / CLOCKS_PER_SEC;
		// printVetor(vetor, tamVetor);
		printf("Comparações: %ld\n", numComps);
		printf("Tempo de execução: %fs\n\n", total);
	}
	free(vetor);
	vetor = NULL;
	free(vetorUnsigned);
	vetorUnsigned = NULL;

	return 0;
}
