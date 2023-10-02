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
		return -1; // caso base, vetor vazio
	(*numComparacoes)++;
	if (valor >= vetor[tam - 1])
		return tam - 1; // achou o valor especificado

	return buscaSequencial(vetor, tam - 1, valor, numComparacoes); // chamada recursiva
}

int buscaSequencialPossivel(int vetor[], int tam, int valor, long* numComparacoes) {
	int pos = buscaSequencial(vetor, tam, valor, numComparacoes);
	if (vetor[pos] != valor)
		return -1; // retorna -1 caso o valor não esteja no vetor

	return pos;
	// caso contrário, retorna o índice do valor
}

int buscaBinariaPossivel(int vetor[], int a, int b, int valor, long* numComparacoes) {
	if (a > b)
		return a - 1; // caso base
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
		vetor[i] = rand() % 11;
} // coloca números aleatórios no vetor

long insertionSort(int vetor[], int tam) {
	if (tam <= 1)
		return 0; // caso base
	long comps = insertionSort(vetor, tam - 1);
	int i = tam - 1;
	comps++;
	while (i > 0 && vetor[i] < vetor[i - 1]) {
		comps++;
		swap(vetor, i, i - 1);
		i--;
	}
	/* o loop incrementa as comparações enquanto 
	 * insere o elemento de vetor[tam - 1] no seu devido lugar
	 * dentro do sub-vetor ordenado */

	return comps;
}

long selectionSort(int vetor[], int tam) {
	if (tam <= 1)
		return 0; // caso base
	int posMax = tam - 1; // assume que o último elemento do vetor é o maior
	long comps = 0;
	for (int i = 0; i < tam; i++) {
		comps++;
		if (vetor[i] > vetor[posMax])
			posMax = i;
	} // acha o ind. do maior valor do vetor e incrementa as comparações
	swap(vetor, posMax, tam - 1); // coloca o maior elemento na última posição da cham. recursiva

	return comps + selectionSort(vetor, tam - 1); // soma as comparações e faz uma cham. recursiva
}

long merge(int vetor[], int a, int b, int m) {
	if (a >= b)
		return 0;
	int vetorAux[b - a + 1], i, j, p, compsMerge;
	compsMerge = 0;
	i = a;
	j = m + 1;
	for (int k = 0; k < b - a; k++) {
		compsMerge++;
		if (j >= b || (i <= m && vetor[i] <= vetor[j])) {
			p = i;
			i++;
		} else {
			p = j;
			j++;
		}
		vetorAux[k] = vetor[p];
	}
	for (int u = 0; u < b; u++)
		vetor[u] = vetorAux[u];

	return compsMerge;
}

long mergeSortPart(int vetor[], int a, int b) {
	if (a >= b)
		return 0;
	int meio = (a + b) / 2;
	mergeSortPart(vetor, a, meio);
	merge(vetor, a, b, meio);

	return 0;
}

long mergeSort(int vetor[], int tam) {
	return mergeSortPart(vetor, 0, tam);
}

int part(int vetor[], int a, int b) {
	if (a >= b)
		return 0;
	int pivo = vetor[b - 1]; // o pivô é o último elemento do vetor
	int futuroPivo = a; // esta variável será a posição do pivô ao final do loop
	for (int i = a; i < b - 1; i++) {
		if (vetor[i] <= pivo) {
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

long quickSortPossivel(int vetor[], int a, int b) {
	if (a >= b)
		return 0;
	int indPart = part(vetor, a, b);
	quickSortPossivel(vetor, a, indPart);
	quickSortPossivel(vetor, indPart + 1, b);

	return 0;
}

long quickSort(int vetor[], int tam) {
	return quickSortPossivel(vetor, 0, tam);
}
