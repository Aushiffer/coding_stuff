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

int buscaSequencialIngenua(int vetor[], int tam, int valor, long* numComparacoes) {
	if (tam <= 1)
		return -1; // caso base, vetor vazio ou de tamanho 1
	(*numComparacoes)++; // incrementa comparações
	if (valor >= vetor[tam - 1])
		return tam - 1; // retorna o índice do valor (ou onde ele deveria estar)

	return buscaSequencialIngenua(vetor, tam - 1, valor, numComparacoes); // chamada recursiva
}

int buscaSequencial(int vetor[], int tam, int valor, long* numComparacoes) {
	int pos = buscaSequencialIngenua(vetor, tam, valor, numComparacoes);
	if (vetor[pos] != valor) // se o valor estiver na posição dada pelo algoritmo de busca, retorna pos
		return -1;	// senão, retorna -1

	return pos;
}

int buscaBinariaContagem(int vetor[], int a, int b, int valor, long* numComparacoes) {
	if (a > b)
		return a - 1; // caso base, início > final
	int m = (a + b) / 2; // calcula o meio do vetor
	(*numComparacoes)++; // incrementa comparações
	if (vetor[m] > valor)
		return buscaBinariaContagem(vetor, a, m - 1, valor, numComparacoes);

	return buscaBinariaContagem(vetor, m + 1, b, valor, numComparacoes);
	// returns para os cenários possíveis em uma busca binária (sem contar o caso base)
}

int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes) {
	int pos = buscaBinariaContagem(vetor, 0, tam - 1, valor, numComparacoes);
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
		vetor[i] = rand() % 21;
} // coloca números aleatórios no vetor (aleatoriedade depende do número após %)

void insertionSortContagem(int vetor[], int a, int b, long* comps) {
	if (a >= b)
		return;
	insertionSortContagem(vetor, a, b - 1, comps); // cham. recursiva
	int i = b - 1;
	while (i > a && vetor[i] < vetor[i - 1]) {
		(*comps)++;
		swap(vetor, i, i - 1);
		i--;
	} // loop que insere o valor na posição correta e incrementa comparações
}

long insertionSort(int vetor[], int tam) {
	long comps = 0;
	insertionSortContagem(vetor, 0, tam, &comps);
	
	return comps; // retorna as comps. do insertion sort
}

void selectionSortContagem(int vetor[], int a, int b, long* comps) {
	if (a >= b)
		return;
	int posMin = a;
	for (int i = a + 1; i < b; i++) {
		(*comps)++;
		if (vetor[i] < vetor[posMin])
			posMin = i;
	} // acha o menor valor
	swap(vetor, posMin, a); // troca o menor valor com o elemento em vetor[a]
	selectionSortContagem(vetor, a + 1, b, comps); // cham. recursiva
}

long selectionSort(int vetor[], int tam) {
	long comps = 0;
	selectionSortContagem(vetor, 0, tam, &comps);

	return comps; // retorna as comps. do selection sort
}

void merge(int vetor[], int a, int b, int meio, long* comps) {
	if (a >= b)
		return;
	int i, j, k, vetorAux[b]; // criação dos índices e do vetor auxiliar
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
	} // loop que coloca os valores das partições do vetor ordenadamente em um vetor auxiliar
	// enquanto incrementa as comparações
	while (i <= meio) {
		vetorAux[k] = vetor[i];
		i++;
		k++;
	}
	while (j <= b) {
		vetorAux[k] = vetor[j];
		j++;
		k++;
	} // loops que colocam valores restantes no vetor auxiliar
	for (int p = a; p <= b; p++)
		vetor[p] = vetorAux[p]; // loop que copia os valores do vetor auxiliar para o vetor original
}

void mergeSortContagem(int vetor[], int a, int b, long* comps) {
	if (a >= b)
		return;
	int meio = (a + b) / 2; // calcula o meio do vetor
	mergeSortContagem(vetor, a, meio, comps); // merge sort para a primeira metade do vetor
	mergeSortContagem(vetor, meio + 1, b, comps); // merge sort para a segunda metade do vetor
	merge(vetor, a, b, meio, comps); // função de junção (merge)
}

long mergeSort(int vetor[], int tam) {
	long comps = 0;
	mergeSortContagem(vetor, 0, tam - 1, &comps);

	return comps; // retorna as comps. do merge sort
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

	return futuroPivo; // retorna a posição atual do pivô selecionado no vetor
}

void quickSortContagem(int vetor[], int a, int b, long* comps) {
	if (a >= b)
		return; // caso base
	int indPivo = part(vetor, a, b, comps); // adquire o índice do pivô (na atual cham. recursiva)
	quickSortContagem(vetor, a, indPivo, comps); // chama o quicksort de a até indPivo no vetor
	quickSortContagem(vetor, indPivo + 1, b, comps); // chama o quicksort para o resto do vetor
}

long quickSort(int vetor[], int tam) {
	long comps = 0;
	quickSortContagem(vetor, 0, tam, &comps);
	
	return comps; // retorna as comps. do quicksort
}
