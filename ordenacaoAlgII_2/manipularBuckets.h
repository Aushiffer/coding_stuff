// Nodo com valor real
typedef struct nodo {
        float valor;
        struct nodo *prox;
} nodo;

// Bucket de nodos (lista duplamente encadeada)
typedef struct bucket {
        int tam;
        nodo *topo;
} bucket;

// Cria um novo item
nodo *criaNodo(float valor);

// Cria um novo bucket
bucket *criaBucket();

// Troca valores de dois nodos
void trocarValoresNodos(nodo *n1, nodo *n2);

// Insertion Sort para buckets
void insertionSortBucket(bucket *b, unsigned long *comps);

// Se o bucket estiver vazio, retorna 1
int bucketVazio(bucket *b);

// Retorna o tamanho do bucket
int tamBucket(bucket *b);

// Insere um nodo em um bucket pela cabeça
void insereNodo(bucket *b, float valor);

// Remove um nodo do bucket pela cabeça
void removeNodo(bucket *b);

// Libera os nodos do bucket, assim como o próprio bucket
void destroiBucket(bucket *b);