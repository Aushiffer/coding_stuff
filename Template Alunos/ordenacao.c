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

int maxValue(int vetor[], int tam) {
	int max = vetor[0]; // assumindo vetor[0] como max
	for (int i = 1; i < tam; i++)
		if (vetor[i] > max)
			max = vetor[i]; // for loop que atualiza o valor de max conforme o if

	return max; // maior elemento no vetor
}

long insertionSort(int vetor[], int tam){
	if (tam <= 1)
		return 0; // caso base, 0 comparações
	long comps = insertionSort(vetor, tam - 1); // recursão, guarda as comparações das demais chamadas
		for (int i = tam - 1; i > 0; i--) {
		if (vetor[i] < vetor[i - 1])
			swap(&vetor[i], &vetor[i - 1]);
		comps++;
	}

	return comps;
}

long selectionSort(int vetor[], int tam){
	if (tam <= 1)
		return 0; // caso base, 0 comparações
	int posMax = maxValue(vetor, tam);
	swap(&vetor[tam - 1], &vetor[posMax]); // troca o último elemento com o maior
	int comps = tam;

	return comps + selectionSort(vetor, tam - 1); // retorna o total de comparações
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
