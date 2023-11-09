//   pessoa
struct pessoa {
	int atr[6];
	char *nome;
	struct pessoa *prox;
};

// pilha
struct pilha {
	struct pessoa *topo;
	int tam;
};

// fila circular
struct circFila {
	struct pessoa *inicio;
	struct pessoa *fim;
	int tam;
};

// cria uma pessoa
struct pessoa *criaPessoa(int atr1, int atr2, int atr3, int atr4, int atr5, int atr6);

// cria uma fila de pretendentes
struct filaCirc *criaFila();

// cria uma pilha de candidatos
struct pilha *criaPilha();

// coloca uma pessoa na pilha de candidatos
void push(struct pilha *p, struct pessoa *pers);

// remove uma pessoa da pilha de candidatos e a retorna
struct pilha *pop(struct pilha *p);

// enfileira uma pessoa na fila de pretendentes
void *enqueue(struct filaCirc *f, struct pessoa *pers);

// desenfileira uma pessoa da fila de pretendentes e a retorna
struct filaCirc *dequeue(struct filaCirc *f);
