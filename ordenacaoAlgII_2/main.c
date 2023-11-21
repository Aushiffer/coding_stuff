#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "complementar.h"

int main() {
        char nome[MAX_CHAR];
        char nomeAlg[MAX_CHAR];
        getNome(nome);
	getNomeAlgoritmoExtra(nomeAlg);
        printf("Aluno: %s\n", nome);
        printf("GRR: %u\n", getGRR());
	printf("%s\n", nomeAlg);

        int tamVetor, *vetor;
	unsigned long numComps;
	printf("Tamanho do vetor a ser ordenado: ");
	scanf("%d", &tamVetor);
        if (!(vetor = (int *)malloc(tamVetor * sizeof(int)))) {
		printf("[-] Erro na alocação do vetor.\n");
		return -1;
	}
	vetor[0] = 10;
	vetor[1] = 13;
	vetor[2] = 15;
	vetor[3] = 11;
	vetor[4] = 12;
	printVetor(vetor, tamVetor);
	numComps = mergeSort(vetor, tamVetor);
	printVetor(vetor, tamVetor);
	// printf("comps: %ld\n", numComps);
	free(vetor);
	vetor = NULL;

	return 0;
}