// Nodo com valor real
typedef struct nodo {
        float valor;
        struct nodo *prox;
} nodo;

// Bucket de nodos (lista simplesmente encadeada)
typedef struct bucket {
        int tam;
        nodo *topo;
} bucket;

// Cria um novo item
nodo *criaNodo();

// Cria um novo bucket
bucket *criaBucket();

// Se o bucket estiver vazio, retorna 1
int bucketVazio(bucket *b);

// Insere um nodo em um bucket
void push(bucket *b, nodo *n);

// Remove um nodo do bucket
void pop(bucket *b);

// Libera os nodos do bucket, assim como o próprio bucket
void destroiBucket(bucket *b);