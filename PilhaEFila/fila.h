#define MAX 100

struct fila {
	int cap;
	int itens[MAX];
	int first;
	int last;
	int size;
};

struct fila createQueue();

void enqueue(struct fila *f, int x);

int dequeue(struct fila *f);

int countItensQueue(struct fila f);
