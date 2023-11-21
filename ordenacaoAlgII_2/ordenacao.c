#include <string.h>
#include "ordenacao.h"
#include "complementar.h"

void getNome(char nome[]) {
    	// substitua por seu nome
   	strncpy(nome, "Caio Eduardo Ferreira de Miranda", MAX_CHAR);
   	// adicionada terminação manual para caso de overflow
    	nome[MAX_CHAR - 1] = '\0';
}

void getNomeAlgoritmoExtra(char nomeAlg[]) {
   	// substitua pelo nome do algoritmo que você escolheu
    	strncpy(nomeAlg, "Bucket sort", MAX_CHAR);
    	nomeAlg[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR() { return 20232359; }

unsigned long mergeSort(int vetor[], int tam) {
    	vetor[0] = 99;
    	return -1;
}

unsigned long quickSort(int vetor[], int tam) {
    	unsigned long comps = 0;
	qkSort(vetor, 0, tam - 1, &comps);
	
	return comps;
}

unsigned long heapSort(int vetor[], int tam) {
    	unsigned long comps = 0;
	hpSort(vetor, tam - 1, &comps);
    	
	return comps;
}

void countingSort(unsigned int vetor[], int tam, int maxVal) {
    	vetor[0] = 99;
   	return;
}

unsigned long algoritmoExtra(int vetor[], int tam) {
    	vetor[0] = 99;
    	return -1;
}