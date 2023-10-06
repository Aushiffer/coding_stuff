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
	if (tam <= 1)
		return -1; // caso base, vetor vazio ou de tamanho 1
	(*numComparacoes)++;
	if (valor >= vetor[tam - 1])
		return tam - 1; // achou o valor especificado

	return buscaSequencial(vetor, tam - 1, valor, numComparacoes); // chamada recursiva
}

int buscaSequencialIngenua(int vetor[], int tam, int valor, long* numComparacoes) {
	int pos = buscaSequencial(vetor, tam, valor, numComparacoes);
	if (vetor[pos] != valor)
		return -1; // retorna -1 caso o valor não esteja no vetor

	return pos;
	// caso contrário, retorna o índice do valor
}

int buscaBinariaPossivel(int vetor[], int a, int b, int valor, long* numComparacoes) {
	if (a > b)
		return a - 1; // caso base, início > final
	int m = (a + b) / 2; // calcula o meio do vetor
	(*numComparacoes)++;
	if (vetor[m] > valor)
		return buscaBinariaPossivel(vetor, a, m - 1, valor, numComparacoes);

	return buscaBinariaPossivel(vetor, m + 1, b, valor, numComparacoes);
	// returns para os cenários possíveis em uma busca binária (sem contar o caso base)
}

int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes) {
	int pos = buscaBinariaPossivel(vetor, 0, tam, valor, numComparacoes);
	if (vetor[pos] != valor)
		return -1;

	return pos; // retorna o índice do vetor (se o valor n foi encontrado, retorna -1)
}

void swap(int vetor[], int a, int b) {
	int aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux; 
} // troca o valor de vetor[a] com o valor de vetor[b]

void printArray(int vetor[], int tam) {
	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
	printf("\n");
} // impressão do vetor com for loop

void putRandomNumbersOnArray(int vetor[], int tam) {
	srand(time(NULL));
	for (int i = 0; i < tam; i++)
		vetor[i] = rand() % 10000;
} // coloca números aleatórios no vetor

void insertionSortContagem(int vetor[], int a, int b, long* comps) {
	if (a >= b)
		return;
	insertionSortContagem(vetor, a, b - 1, comps);
	int i = b - 1;
	while (i > a && vetor[i] < vetor[i - 1]) {
		(*comps)++;
		swap(vetor, i, i - 1);
		i--;
	}
}

long insertionSort(int vetor[], int tam) {
	long comps = 0;
	insertionSortContagem(vetor, 0, tam, &comps);
	
	return comps;
}

void selectionSortContagem(int vetor[], int a, int b, long* comps) {
	if (a >= b)
		return;
	int posMin = a;
	for (int i = a + 1; i < b; i++) {
		(*comps)++;
		if (vetor[i] < vetor[posMin])
			posMin = i;
	}
	swap(vetor, posMin, a);
	selectionSortContagem(vetor, a + 1, b, comps);
}

long selectionSort(int vetor[], int tam) {
	long comps = 0;
	selectionSortContagem(vetor, 0, tam, &comps);

	return comps;
}

void merge(int vetor[], int a, int b, int meio, long* comps) {
	if (a >= b)
		return;
	int i, j, k, vetorAux[b];
	i = a;
	j = meio + 1;
	k = a;
	while (i <= meio && j <= b) {
		(*comps)++;
		if (vetor[i] <= vetor[j]) {
			vetorAux[k] = vetor[i];
			i++;
			k++;
		} else {
			vetorAux[k] = vetor[j];
			j++;
			k++;
		}
	}
	while (i <= meio) {
		vetorAux[k] = vetor[i];
		i++;
		k++;
	}
	while (j <= b) {
		vetorAux[k] = vetor[j];
		j++;
		k++;
	}
	for (int p = a; p <= b; p++)
		vetor[p] = vetorAux[p];
}

void mergeSortContagem(int vetor[], int a, int b, long* comps) {
	if (a >= b)
		return;
	int meio = (a + b) / 2;
	mergeSortContagem(vetor, a, meio, comps);
	mergeSortContagem(vetor, meio + 1, b, comps);
	merge(vetor, a, b, meio, comps);
}

long mergeSort(int vetor[], int tam) {
	long comps = 0;
	mergeSortContagem(vetor, 0, tam - 1, &comps);

	return comps;
}

int part(int vetor[], int a, int b, long* comps) {
	if (a >= b)
		return 0;
	int pivo = vetor[b - 1]; // o pivô é o último elemento do vetor
	int futuroPivo = a; // esta variável será a posição do pivô ao final do loop
	for (int i = a; i < b - 1; i++) {
		if (vetor[i] <= pivo) {
			(*comps)++;
			swap(vetor, futuroPivo, i);
			futuroPivo++;
		}
	}
	swap(vetor, futuroPivo, b - 1);
	/* o loop e a função de troca após o loop
	 * rearranjam o vetor de forma que o pivô tenha
	 * elementos menores que ele à esquerda e elementos maiores
	 * que ele à direita */

	return futuroPivo; // retorna a posição do pivô selecionado no vetor
}

void quickSortPossivel(int vetor[], int a, int b, long* comps) {
	if (a >= b)
		return;
	int indPivo = part(vetor, a, b, comps); // adquire o índice do pivô (na atual cham. recursiva)
	quickSortPossivel(vetor, a, indPivo, comps); // chama o quick sort de a até indPart no vetor
	quickSortPossivel(vetor, indPivo + 1, b, comps); // chama o quick sort para o resto do vetor
}

long quickSort(int vetor[], int tam) {
	long comps = 0;
	quickSortPossivel(vetor, 0, tam, &comps); // wrapper as comparações feitas no quick sort
	
	return comps;
}
