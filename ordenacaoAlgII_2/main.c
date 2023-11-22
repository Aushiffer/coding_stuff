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
        printf("Aluno: %s\n", nome);
        printf("GRR: %u\n", getGRR());
	printf("%s\n", nomeAlg);

        unsigned int *vetor, tamVetor;
	unsigned long numComps = 0;
	printf("Tamanho do vetor a ser ordenado: ");
	scanf("%d", &tamVetor);
        if (!(vetor = (unsigned int *)malloc(tamVetor * sizeof(unsigned int)))) {
		printf("[-] Erro na alocação do vetor.\n");
		return -1;
	}
	aleatorizarVetor((int *)vetor, tamVetor);
	for (int i = 0; i < tamVetor; i++)
		printf("%d ", vetor[i]);
	printf("\n");
	countingSort(vetor, tamVetor, 10);
	for (int j = 0; j < tamVetor; j++)
		printf("%d ", vetor[j]);
	printf("\n");
	printf("comps: %ld\n", numComps);
	free(vetor);
	vetor = NULL;

	return 0;
}