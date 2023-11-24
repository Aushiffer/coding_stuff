#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complementar.h"

void trocar(int *vetor, int a, int b) {
        int aux = vetor[a];
        vetor[a] = vetor[b];
        vetor[b] = aux;
}

void printVetor(int *vetor, int tam) {
	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
	printf("\n");
}

void aleatorizarVetor(int *vetor, int tam) {
	for (int i = 0; i < tam; i++)
		vetor[i] = rand() % RNG_CAP;
} // Para aumentar ou diminuir a variedade dos elementos, mude o valor de RNG_CAP em 'complementar.h'

int nodoEsq(int idxNodo) { return (idxNodo << 1) + 1; }

int nodoDir(int idxNodo) { return (idxNodo << 1) + 2; }

void maxHeapify(int *heap, int idxNodo, int tam, unsigned long *comps) {
        int esq = nodoEsq(idxNodo);
        int dir = nodoDir(idxNodo);
        int max;
        if (esq <= tam && heap[esq] > heap[idxNodo])
                max = esq;
        else
                max = idxNodo;
        if (dir <= tam && heap[dir] > heap[max])
                max = dir;
	*comps = *comps + 2;
        if (max != idxNodo) {
                trocar(heap, idxNodo, max);
                maxHeapify(heap, max, tam, comps);
        }
}

void constroiMaxHeap(int *vetor, int tam, unsigned long *comps) {
	for (int i = (tam / 2); i >= 0; i--)
		maxHeapify(vetor, i, tam, comps);
} // Executa max-heapify até que o vetor se torne uma max-heap

void hpSort(int *vetor, int tam, unsigned long *comps) {
	constroiMaxHeap(vetor, tam, comps);
	for (int i = tam; i >= 1; i--) {
		trocar(vetor, 0, i);
		maxHeapify(vetor, 0, i - 1, comps);
	}
} // ^ Constroi uma max-heap e executa max-heapify 'de trás para frente' na heap até
// se tenha um vetor ordenado

int particaoQS(int *vetor, int a, int b, unsigned long *comps) {
        if (a >= b)
                return 0;
        int pivo = vetor[b - 1]; // Último elemento é o pivô
        int novoPivo = a;
        for (int i = a; i < b - 1; i++) {
                (*comps)++;
		if (vetor[i] <= pivo) {
                        trocar(vetor, novoPivo, i);
                        novoPivo++;
                }
	}
        trocar(vetor, novoPivo, b - 1);
	/* ^ O loop e a função de troca após ele particionam o vetor
	 * de maneira que o pivô selecionado fique com elementos maiores que
	 * ele à direita e menores que ele à esquerda */ 

        return novoPivo; // Retona a pos. do novo pivô
}

void qkSort(int *vetor, int a, int b, unsigned long *comps) {
	if (a >= b)
		return;
	int idxPivo = particaoQS(vetor, a, b, comps);
	qkSort(vetor, a, idxPivo, comps);
	qkSort(vetor, idxPivo + 1, b, comps);
} // ^ Particionamento ocorre até que o vetor esteja ordenado

void merge(int *vetor, int a, int b, int meio, unsigned long *comps) {
	if (a >= b)
		return; // Uma partição de 1 elemento está ordenada
	int i, j, k, *vetorAux;
	vetorAux = (int *)malloc(b * sizeof(int));
        i = a;
	j = meio + 1;
	k = a;
	while (i < meio && j < b) {
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
	} // ^ Colocando valores no vetor auxiliar, de maneira ordenada
	while (i <= meio) {
		vetorAux[k] = vetor[i];
		i++;
		k++;
	}
	while (j < b) {
		vetorAux[k] = vetor[j];
		j++;
		k++;
	}
	// ^ Ambos os whiles colocam, no vetor auxiliar, valores que podem ter ficado para trás
	for (int p = a; p < b; p++)
		vetor[p] = vetorAux[p]; // Copiando os valores para o vetor original
        free(vetorAux);
        vetorAux = NULL;
}

void mrgSort(int *vetor, int a, int b, unsigned long *comps) {
        if (a >= b)
                return;
        int meio = (a + b) / 2;
        mrgSort(vetor, a, meio, comps);
        mrgSort(vetor, meio + 1, b, comps);
        merge(vetor, a, b, meio, comps);
} // ^ Particiona o vetor e executa merge em suas partições até que o vetor esteja ordenado

void insertionSort(int *vetor, int tam, unsigned long *comps) {
	for (int i = 0; i < tam - 1; i++) {
		int k = i + 1;
		while (k > 0 && vetor[k] < vetor[k - 1]) {
			(*comps)++;
			trocar(vetor, k, k - 1);
			k--;
		}
	}
}

void qkSortForIntro(int *vetor, int a, int b, int limite, unsigned long *comps) {
	if (a >= b)
		return;
	if (limite == 0) {
		insertionSort(vetor, b, comps);
		return;
	}
	int idxPivo = particaoQS(vetor, a, b, comps);
	qkSortForIntro(vetor, a, idxPivo, limite - 1, comps);
	qkSortForIntro(vetor, idxPivo + 1, b, limite - 1, comps);
}

void introSort(int *vetor, int a, int b, unsigned long *comps) {
	int limite = log2(b - a + 1);
	qkSortForIntro(vetor, 0, b, limite, comps);
	hpSort(vetor, b - 1, comps);
}