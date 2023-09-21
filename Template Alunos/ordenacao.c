#include "ordenacao.h"
#include "complementares.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
	if (tam <= 0)
		return -1; // caso base
	(*numComparacoes)++; // +1 comparação
	if (valor == vetor[tam - 1])
		return tam; // achou o valor especificado

	return buscaSequencial(vetor, tam - 1, valor, numComparacoes); // chamada recursiva
}

int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes){
	return -1;
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

void putRandomNumbersOnArray(int vetor[], int tam) {
	srand(time(NULL));
	for (int i = 0; i < tam; i++)
		vetor[i] = rand() % 11;
}

long insertionSort(int vetor[], int tam){
	if (tam <= 0)
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
