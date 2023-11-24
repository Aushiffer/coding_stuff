#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "complementar.h"

int main() {
	srand(time(NULL));
        char nome[MAX_CHAR];
        char nomeAlg[MAX_CHAR];
        getNome(nome);
	getNomeAlgoritmoExtra(nomeAlg);
        printf("\nAluno: %s\n", nome);
        printf("GRR: %u\n", getGRR());
	printf("Algoritmo extra: %s\n\n", nomeAlg);

        int *vetor, tamVetor;

	unsigned long numComps;
	printf("Tamanho do vetor a ser ordenado: ");
	scanf("%d", &tamVetor);
	printf("\n");
        if (!(vetor = (int *)malloc(tamVetor * sizeof(int)))) {
		printf("[-] Erro na alocação do vetor.\n");
		return -1;
	}
	aleatorizarVetor(vetor, tamVetor);
	printVetor(vetor, tamVetor);
	numComps = mergeSort(vetor, tamVetor); // RNG_CAP define o tamanho do vetor de contagem
	printVetor(vetor, tamVetor);
	printf("comps: %ld\n\n", numComps);
	free(vetor);
	vetor = NULL;

	return 0;
}