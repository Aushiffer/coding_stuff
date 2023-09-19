#include "ordenacao.h"

#include <string.h>
#include <stdio.h>

void getNome(char nome[]){
	//substitua por seu nome
	strncpy(nome, "Caio Eduardo Ferreira de Miranda", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR(){
	return 20232359;
}

int buscaSequencial(int vetor[], int tam, int valor, long* numComparacoes){	
	if (tam < 0)
		return -1; // caso base
	*numComparacoes = *numComparacoes + 1; // +1 comparação
	if (valor == vetor[tam])
		return tam; // achou o valor especificado

	return buscaSequencial(vetor, tam - 1, valor, numComparacoes); // chamada recursiva
}

int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes){
	int ini = (tam - 1) + 1 - tam; // inicio do vetor
	if (ini > tam)
		return -1; // caso base
	int meio = (ini + tam) / 2;
	*numComparacoes = *numComparacoes + 1; // +1 comparação abaixo
	if (vetor[meio] > valor)
		return buscaBinaria(vetor, meio - 1, valor, numComparacoes);
		// chamada recursiva para um vetor de tamanho = meio - 1

	return buscaBinaria(vetor, tam, valor, numComparacoes);
}

void swap(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux; 
}

void printArray(int vetor[], int tam) {
	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
	printf("\n");
}

long insertionSort(int vetor[], int tam){
	if (tam <= 1)
		return 0;
	long comps = insertionSort(vetor, tam - 1);
	int i = tam - 1;
	while (i > 0 && vetor[i] < vetor[i - 1]) {
		comps++;
		swap(&vetor[i - 1], &vetor[i]);
		i--;
	}

	return comps;
}

long selectionSort(int vetor[], int tam){
	if (tam <= 0)
		return 0;
	int posMax = tam - 1;
	long comps = 0;
	for (int i = 0; i < tam; i++) {
		comps++;
		if (vetor[i] > vetor[posMax])
			posMax = i;
	}
	swap(&vetor[posMax], &vetor[tam - 1]);

	return comps + selectionSort(vetor, tam - 1);
}

long mergeSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

long quickSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

long heapSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}
