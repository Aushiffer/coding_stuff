#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"
#include "complementar.h"
#include "manipularBuckets.h"

void getNome(char nome[]) {
    	// substitua por seu nome
   	strncpy(nome, "Caio Eduardo Ferreira de Miranda", MAX_CHAR);
   	// adicionada terminação manual para caso de overflow
    	nome[MAX_CHAR - 1] = '\0';
}

void getNomeAlgoritmoExtra(char nomeAlg[]) {
   	// substitua pelo nome do algoritmo que você escolheu
    	strncpy(nomeAlg, "Bucket Sort", MAX_CHAR);
    	nomeAlg[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR() { return 20232359; }

unsigned long mergeSort(int vetor[], int tam) {
    	unsigned long comps = 0;
	mrgSort(vetor, 0, tam, &comps);

    	return comps;
}

unsigned long quickSort(int vetor[], int tam) {
    	unsigned long comps = 0;
	qkSort(vetor, 0, tam, &comps);
	
	return comps;
}

unsigned long heapSort(int vetor[], int tam) {
    	unsigned long comps = 0;
	hpSort(vetor, tam - 1, &comps);
    	
	return comps;
}

void countingSort(unsigned int vetor[], int tam, int maxVal) {
	unsigned int *vetorOrdenado, *vetorContagem;
	if (!(vetorOrdenado = (unsigned int *)malloc(tam * sizeof(unsigned int)))) {
		printf("[-] Impossível alocar o vetor ordenado.\n");
		return;
	}
	if (!(vetorContagem = (unsigned int *)malloc((maxVal + 1) * sizeof(unsigned int)))) {
		printf("[-] Impossível alocar o vetor de contagem.\n");
		return;
	} // Vai contar desde 0, então precisa de maxVal + 1 elementos
	for (int i = 0; i <= maxVal; i++)
		vetorContagem[i] = 0;
	for (int k = 0; k < tam; k++)
		vetorContagem[vetor[k]] = vetorContagem[vetor[k]] + 1;
	for (int i = 1; i <= maxVal; i++)
		vetorContagem[i] = vetorContagem[i] + vetorContagem[i - 1];
	for (int k = tam - 1; k >= 0; k--) {
		vetorOrdenado[vetorContagem[vetor[k]] - 1] = vetor[k];
		vetorContagem[vetor[k]] = vetorContagem[vetor[k]] - 1;
	}
	for (int j = 0; j < tam; j++)
		vetor[j] = vetorOrdenado[j];
	free(vetorContagem);
	free(vetorOrdenado);
	vetorContagem = NULL;
	vetorOrdenado = NULL;
}

// O algoritmo escolhido foi o Bucket Sort
unsigned long algoritmoExtra(int vetor[], int tam) {
	unsigned long comps = 0;
	bucket *vetorBuckets;
	if (!(vetorBuckets = (bucket *)malloc(tam * sizeof(bucket)))) {
		printf("[-] Impossível alocar o vetor de buckets.\n");
		return -1;
	}

	return comps;
}