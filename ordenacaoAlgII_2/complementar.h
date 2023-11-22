#define RNG_CAP 20

// Header da biblioteca complementar

// Lista encadeada (bucket)
typedef struct bucket {
        float valor;
        struct bucket *prox;
} bucket;

// Troca vetor[a] com vetor[b]
void trocar(int *vetor, int a, int b);

// Imprime um vetor de tamanho 'b'
void printVetor(int *vetor, int b);

// Aleatoriza um vetor de tamanho 'b'
void aleatorizarVetor(int *vetor, int b);

// Retorna a posição do nodo à esquerda do nodo em idxNodo na heap
int nodoEsq(int idxNodo);

// Retorna a posição do nodo à direita do nodo em idxNodo na heap
int nodoDir(int idxNodo);

// Max-heapify em uma heap cuja raiz é representada por idxNodo
void maxHeapify(int *heap, int idxNodo, int b, unsigned long *comps);

// Constroi uma max-heap a partir de um vetor qualquer
void constroiMaxHeap(int *vetor, int b, unsigned long *comps);

// Heapsort, usa maxHeapify e constroiMaxHeap (conta comps.)
void hpSort(int *vetor, int b, unsigned long *comps);

// Particionamento para o quicksort
int particaoQS(int *vetor, int a, int b, unsigned long *comps);

// Quicksort, usa particaoQS (conta comps.)
void qkSort(int *vetor, int a, int b, unsigned long *comps);

// Junta dois vetores ordenados em um vetor só, também ordenado
void merge(int *vetor, int a, int b, int meio, unsigned long *comps);

// Merge sort, usa merge (conta comps.)
void mrgSort(int *vetor, int a, int b, unsigned long *comps);