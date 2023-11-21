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
	vetor[0] = 5;
	vetor[1] = 2;
	vetor[2] = 10;
	vetor[3] = 1;
	vetor[4] = 3;
	printVetor(vetor, tamVetor);
	numComps = heapSort(vetor, tamVetor);
	printVetor(vetor, tamVetor);
	printf("comps: %ld\n", numComps);
	free(vetor);
	vetor = NULL;

	return 0;
}