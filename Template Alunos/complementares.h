// Header de funções complementares adicionadas pelo aluno

// Troca o conteúdo de um inteiro a pelo conteúdo de um inteiro b
void swap(int *a, int *b);

// Imprime um vetor de tamanho tam
void printArray(int vetor[], int tam);

// Coloca números aleatórios num vetor de tamanho tam
void putRandomNumbersOnArray(int vetor[], int tam);

// Busca binária possível. Será passada por uma função wrapper
int buscaBinariaPossivel(int vetor[], int a, int b, int valor, long* numComparacoes);

// Wrapper da busca sequencial
int buscaSequencialWrapper(int vetor[], int tam, int valor, long* numComparacoes);

// Junta dois vetores ordenados, de forma que o resultado seja um vetor ordenado
long merge(int vetor[], int m, int b);
