#include "ordenacao.h"
#include "complementares.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void getNome(char nome[]) {
	//substitua por seu nome
	strncpy(nome, "Caio Eduardo Ferreira de Miranda", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR() {
	return 20232359;
}

int buscaSequencial(int vetor[], int tam, int valor, long* numComparacoes) {
	if (tam <= 0)
		return -1; // caso base
	(*numComparacoes)++; // +1 comparação
	if (valor == vetor[tam - 1])
		return tam - 1; // achou o valor especificado

	return buscaSequencial(vetor, tam - 1, valor, numComparacoes); // chamada recursiva
}

int buscaBinariaPossivel(int vetor[], int a, int b, int valor, long* numComparacoes) {
	if (a > b)
		return a - 1;
	int m = (a + b) / 2;
	(*numComparacoes)++;
	if (vetor[m] > valor)
		return buscaBinariaPossivel(vetor, a, m - 1, valor, numComparacoes);

	return buscaBinariaPossivel(vetor, m + 1, b, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes) {
	if (vetor[buscaBinariaPossivel(vetor, 0, tam - 1, valor, numComparacoes)] != valor)
		return -1;

	return buscaBinariaPossivel(vetor, 0, tam - 1, valor, numComparacoes);
}

void swap(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux; 
} // troca o valor de a com o valor de b

void printArray(int vetor[], int tam) {
	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
	printf("\n"); // faz um loop para imprimir o vetor
}

void putRandomNumbersOnArray(int vetor[], int tam) {
	srand(time(NULL));
	for (int i = 0; i < tam; i++)
		vetor[i] = rand() % 11;
} // coloca números aleatórios no vetor

long insert(int vetor[], int tam) {
	int i = tam - 1;
	long comps = 0;
	while (i > 0 && vetor[i] < vetor[i - 1]) {
		comps++;
		swap(&vetor[i], &vetor[i - 1]);
		i--;
	}

	return comps;
}

long insertionSort(int vetor[], int tam) {
	if (tam <= 1)
		return 0; // caso base
	long comps = insertionSort(vetor, tam - 1); // cham. recursiva

	return comps + insert(vetor, tam); // acumula comps. p/ função seguinte
}

long selectionSort(int vetor[], int tam){
	if (tam <= 1)
		return 0; // caso base
	int posMax = tam - 1;
	long comps = 0;
	for (int i = 0; i < tam; i++) {
		comps++;
		if (vetor[i] > vetor[posMax])
			posMax = i;
	} // acha o maior valor do vetor e incrementa comps
	swap(&vetor[posMax], &vetor[tam - 1]); // coloca o maior na última posição da cham. recursiva

	return comps + selectionSort(vetor, tam - 1); // soma as comparações
}

long mergeSort(int vetor[], int tam) {
	vetor[0] = 99;
	return -1;
}

long quickSort(int vetor[], int tam) {
	vetor[0] = 99;
	return -1;
}

long heapSort(int vetor[], int tam) {
	vetor[0] = 99;
	return -1;
}
