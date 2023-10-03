// Header de funções complementares adicionadas pelo aluno

// Troca o conteúdo em vetor[a] pelo conteúdo em vetor[b]
void swap(int vetor[], int a, int b);

// Imprime um vetor de tamanho tam
void printArray(int vetor[], int tam);

// Coloca números aleatórios num vetor de tamanho tam
void putRandomNumbersOnArray(int vetor[], int tam);

// Busca binária possível. Será passada por uma função wrapper
int buscaBinariaPossivel(int vetor[], int a, int b, int valor, long* numComparacoes);

// Busca sequencial ingênua (possível). Será usada em um wrapper
int buscaSequencialIngenua(int vetor[], int tam, int valor, long* numComparacoes);

// Junta dois sub-vetores ordenados, de forma que o resultado seja um vetor ordenado
long merge(int vetor[], int a, int b, int m);

// Merge sort, será usada em um wrapper
long mergeSortPart(int vetor[], int a, int b);

// Particiona o vetor, de maneira que um certo pivô tenha valores menores
// que ele à esquerda e valores maiores que ele à direita.
int part(int vetor[], int a, int b);

// Quick sort possível, será passada por um wrapper
long quickSortPossivel(int vetor[], int a, int b);
