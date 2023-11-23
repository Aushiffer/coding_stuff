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

        unsigned int *vetorUnsigned, tamVetor;

	unsigned long numComps = 0;
	printf("Tamanho do vetor a ser ordenado: ");
	scanf("%d", &tamVetor);
	printf("\n");
        if (!(vetorUnsigned = (unsigned int *)malloc(tamVetor * sizeof(unsigned int)))) {
		printf("[-] Erro na alocação do vetor.\n");
		return -1;
	}
	aleatorizarVetor((int *)vetorUnsigned, tamVetor);
	printVetor((int *)vetorUnsigned, tamVetor);
	countingSort(vetorUnsigned, tamVetor, RNG_CAP); // RNG_CAP define o tamanho do vetor de contagem
	printVetor((int *)vetorUnsigned, tamVetor);
	printf("comps: %ld\n\n", numComps);
	free(vetorUnsigned);
	vetorUnsigned = NULL;

	return 0;
}