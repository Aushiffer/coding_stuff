#include "ordenacao.h"

#include <string.h>

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
		return -1;
	*numComparacoes = *numComparacoes + 1;
	if (valor == vetor[tam])
		return tam;

	return buscaSequencial(vetor, tam - 1, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes){
	return -1;
}

void swap(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux; 
}

int minValue(int vetor[], int tam) {
	int min = vetor[0];
	for (int i = 1; i < tam; i++)
		if (vetor[i] < min)
			min = vetor[i];

	return min;
}

long insertionSort(int vetor[], int tam){
	if (tam <= 1)
		return 0;
	long comps = insertionSort(vetor, tam - 1);
	int i = tam;
	while (i > 0 && vetor[i] < vetor[i - 1]) {
		comps++;
		swap(&vetor[i], &vetor[i - 1]);
		i--;
	}
			
	return comps;
}

long selectionSort(int vetor[], int tam){
	if (tam <= 1)
		return 0;
	
	int comps = selectionSort(vetor, tam - 1);

	return comps;
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
