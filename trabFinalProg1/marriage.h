// pessoa
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

// lista circular
struct listaCirc {
	struct pessoa *cbc;
	struct pessoa *cauda;
	int tam;
};

// cria uma pessoa
struct pessoa *criaPessoa(char *nome, int atr1, int atr2, int atr3, int atr4, int atr5, int atr6);

// cria uma lista de pretendentes
struct listaCirc *criaLista();

// cria uma pilha de candidatos
struct pilha *criaPilha();

// coloca uma pessoa na pilha de candidatos
void push(struct pilha *p, struct pessoa *pers, char *nome, int atr1, int atr2, int atr3, int atr4, int atr5, int atr6);

// remove uma pessoa da pilha de candidatos e retorna um ptr. para seus atributos
void pop(struct pilha *p, int *atrReturn);

// coloca uma pessoa na lista de pretendentes
void enlist(struct listaCirc *l, struct pessoa *pers);

// desenfileira uma pessoa específica da fila de pretendentes e a retorna
void delist(struct listaCirc *l);

// rola "nDados" dados de 20 lados e retorna o valor
int roll1d20(int nDados);
