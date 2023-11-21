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

// Retorna a posição do nodo à esquerda do nodo em i na heap
int nodoEsq(int idxNodo);

// Retorna a posição do nodo à direita do nodo em i na heap
int nodoDir(int idxNodo);

// Ambas as funções para determinar posições dos filhos de heap[idxNodo] usaram SLL

// Max-heapify em uma heap cuja raiz é representada por idxNodo
void maxHeapify(int *heap, int idxNodo, int tam, unsigned long *comps);

// Constroi uma max-heap a partir de um vetor qualquer
void constroiMaxHeap(int *vetor, int n, unsigned long *comps);

// Heap sort, usa maxHeapify e constroiMaxHeap
void hpSort(int *vetor, int n, unsigned long *comps);

// Particionamento para o quicksort
int particaoQS(int *vetor, int a, int b, unsigned long *comps);

// Quicksort, usa particaoQS
void qkSort(int *vetor, int a, int b, unsigned long *comps);