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

        unsigned int *vetor, tamVetor;
	unsigned long numComps = 0;
	printf("Tamanho do vetor a ser ordenado: ");
	scanf("%d", &tamVetor);
	printf("\n");
        if (!(vetor = (unsigned int *)malloc(tamVetor * sizeof(unsigned int)))) {
		printf("[-] Erro na alocação do vetor.\n");
		return -1;
	}
	aleatorizarVetor((int *)vetor, tamVetor);
	for (int i = 0; i < tamVetor; i++)
		printf("%d ", vetor[i]);
	printf("\n");
	countingSort(vetor, tamVetor, RNG_CAP);
	for (int j = 0; j < tamVetor; j++)
		printf("%d ", vetor[j]);
	printf("\n");
	printf("comps: %ld\n\n", numComps);
	free(vetor);
	vetor = NULL;

	return 0;
}