#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR 50

// a função getNome deve colocar o seu nome no vetor
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função getNomeAlgoritmoExtra deve colocar o nome do algoritmo
// extra implementado no trabalho
void getNomeAlgoritmoExtra(char nomeAlg[]);

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

// Cada uma das funções deve ordenar o vetor passado como parâmetro

// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

// Chama a função de merge sort e retorna quantas comps. foram feitas
unsigned long mergeSort(int vetor[], int tam);

// Chama a função de quicksort e retorna quantas comps. foram feitas
unsigned long quickSort(int vetor[], int tam);

// Chama a função de heap sort e retorna quantas comps. foram feitas
unsigned long heapSort(int vetor[], int tam);

// Ordena diretamente o vetor com counting sort (maxVal é k)
void countingSort(unsigned int vetor[], int tam, int maxVal);

// Ordena diretamente o vetor com bucket sort. Retorna -1 pois não são feitas comparações
unsigned long algoritmoExtra(int vetor[], int tam);

#endif  // ORDENACAO_H_