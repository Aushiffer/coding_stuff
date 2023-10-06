#define MAX 100

struct fila {
	int cap;
	int itens[MAX];
	int first;
	int last;
	int size;
};
// estrutura da fila

struct fila createQueue();
// cria uma fila

int queueEmpty(struct fila f);
// verifica se a fila está vazia

void enqueue(struct fila *f, int x);
// atualiza o final da fila e coloca um elemento x nele

int dequeue(struct fila *f);
// remove o elemento no começo da fila e atualiza esse começo

int countItensQueue(struct fila f);
// conta quantos elementos existem na fila

int searchQueue(struct fila f, int x);
// busca um valor dentro da fila, e retorna o índice se encontrado
