#define MAX_ATR 6

// pessoa
struct pessoa {
	int atr[MAX_ATR];
	int relevancia;
	char id;
	struct pessoa *ant;
	struct pessoa *prox;
};

// pilha
struct pilha {
	struct pessoa *topo;
	int tam;
};

// lista circular duplamente encadeada (cauda aponta p/ cbc)
struct listaCirc {
	struct pessoa *cbc;
	struct pessoa *cauda;
	int tam;
};

// cria uma pessoa
struct pessoa *criaPessoa(char id, int atr1, int atr2, int atr3, int atr4, int atr5, int atr6);

// cria uma lista de pretendentes
struct listaCirc *criaListaCircular();

// cria uma pilha de candidatos
struct pilha *criaPilha();

// retorna o tam. da pilha de candidatos
int tamPilha(struct pilha *p);

// retorna o tam. da lista circular de pretendentes
int tamLista(struct listaCirc *l);

// coloca uma pessoa na pilha de candidatos
void push(struct pilha *p, struct pessoa *pers);

// remove uma pessoa da pilha de candidatos e a retorna
void pop(struct pilha *p, int atrReturn[]);

// coloca uma pessoa na lista de pretendentes pela cauda
void enlist(struct listaCirc *l, struct pessoa *pers);

// desenfileira uma pessoa específica da fila de pretendentes e a retorna
void delist(struct listaCirc *l, int relevancia);

// remove uma pessoa pela cabeça da lista
void delistCbc(struct listaCirc *l);

// remove uma pessoa pela cauda da lista
void delistCauda(struct listaCirc *l);

// imprime a lista circular
void printLista(struct listaCirc *l);

// imprime a pilha
void printPilha(struct pilha *p);

// imprime os atributos das pessoas na pilha
void printAtrsPilha(struct pilha *p);

// imprime os atributos das pessoas na lista
void printAtrsLista(struct listaCirc *l);

// verifica se a pilha está vazia
int pilhaVazia(struct pilha *p);

// verifica se a lista está vazia
int listaVazia(struct listaCirc *l);

// libera a pilha e seus elementos
void destroiPilha(struct pilha *p);

// libera a lista e seus elementos
void destroiLista(struct listaCirc *l);

// rola "nDados" dados de 20 lados e retorna o valor da soma entre eles
int rolar1d20(int nDados);

// executa o pareamento de um candidato com um pretendente
void iniciarPareamento(struct pilha *pilhaCandidatos, struct listaCirc *listaPretendentes, struct listaCirc *listaConcorrentes, int *match, int *mismatch, int *noPair);