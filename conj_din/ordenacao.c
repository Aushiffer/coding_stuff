#include "ordenacao.h"
#include "conjunto.h"

int buscaSequencial(int vetor[], int a, int b, int x) {
	if (a >= b)
		return -1;
	if (vetor[a] == x)
		return a;
	return buscaSequencial(vetor, a + 1, b, x);
}

void swap(int vetor[], int a, int b) {
	int aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux; 
} // troca o valor de vetor[a] com o valor de vetor[b]

void merge(int vetor[], int a, int b, int m) {
	if (a >= b)
		return;
	int i, j, k, vetorAux[b]; // criação dos índices e do vetor auxiliar
	i = a;
	j = m + 1;
	k = a;
	while (i <= m && j <= b) {
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
	while (i <= m) {
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

void mergeSort(int vetor[], int a, int b) {
	if (a >= b)
		return;
	int m = (a + b) / 2;
	mergeSort(vetor, a, m);
	mergeSort(vetor, m + 1, b);
	merge(vetor, a, b, m);
}
