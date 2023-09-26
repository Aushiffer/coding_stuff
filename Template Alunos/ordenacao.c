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
	(*numComparacoes)++;
	if (valor >= vetor[tam - 1])
		return tam - 1; // achou o valor especificado

	return buscaSequencial(vetor, tam - 1, valor, numComparacoes); // chamada recursiva
}

int buscaSequencialWrapper(int vetor[], int tam, int valor, long* numComparacoes) {
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

void swap(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux; 
} // troca o valor de a com o valor de b

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

long insert(int vetor[], int tam) {
	int i = tam - 1;
	long comps = 0;
	while (i > 0 && vetor[i] < vetor[i - 1]) {
		comps++;
		swap(&vetor[i], &vetor[i - 1]);
		i--;
	} // incrementa as comparações e insere o valor em vetor[tam - 1] na pos. correta

	return comps; // retorna o no. de comparações feitas na inserção
}

long insertionSort(int vetor[], int tam) {
	if (tam <= 1)
		return 0; // caso base
	long comps = insertionSort(vetor, tam - 1); // cham. recursiva

	return comps + insert(vetor, tam); 
	/* acumula comparações feitas nessa chamada
	 * soma com as comparações de insert e retorna
	 * para a última função */
}

long selectionSort(int vetor[], int tam){
	if (tam <= 0)
		return 0; // caso base
	int posMax = tam - 1; // assume que o último elemento do vetor é o maior
	long comps = 0;
	for (int i = 0; i < tam; i++) {
		comps++;
		if (vetor[i] > vetor[posMax])
			posMax = i;
	} // acha o ind. do maior valor do vetor e incrementa comparações
	swap(&vetor[posMax], &vetor[tam - 1]); // coloca o maior elemento na última posição da cham. recursiva

	return comps + selectionSort(vetor, tam - 1); // soma as comparações e faz uma cham. recursiva
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
