#include <stdbool.h>

/* Item da lista */
struct item {
	int valor;
	struct item *anterior;
	struct item *proximo;
};

/* Lista Duplamente Encadeada */
struct listaDE {
	struct item *cabeca;
	struct item *cauda;
	int tamanho;
};

// Cria um item que pode ser inserido numa lista
struct item *criaItem(int valor);

// Inicializa uma lista duplamente encadeada
struct listaDE *inicializaLDE();

// Verifica se a lista é vazia
bool listaVazia(struct listaDE *l);

// Insere elemento na cabeça da lista
int insereCabeca(struct listaDE *l, int x);

// Insere elemento na cauda da lista
int insereCauda(struct listaDE *l, int x);

// Insere um elemento de maneira ordenada na lista
int insereOrdenado(struct listaDE *l, int x);

// Remove o item na cabeça da lista
int removeCabeca(struct listaDE *l, int *dado);

// Remove o item na cauda da lista
int removeCauda(struct listaDE *l, int *dado);

// Remove um item qualquer da lista
int removeItem(struct listaDE *l, int valor);

// Imprime o item na cabeça da lista
void imprimeCabeca(struct listaDE *l);

// Imprime o item na cauda da lista
void imprimeCauda(struct listaDE *l);

// Imprime a lista duplamente encadeada
void imprimeLDE(struct listaDE *l);

// Retorna o tamanho da lista
int tamanhoLDE(struct listaDE *l);

// Destroi a lista
void destroiLDE(struct listaDE *l);
