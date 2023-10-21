#define MAX 100

struct pilha {
	int cap;
	int itens[MAX];
	int top;
};
// estrutura da pilha

void push(struct pilha *p, int x);
// atualiza o topo e coloca x nele

int pop(struct pilha *p);
// remove o elemento do topo da pilha

int emptyStack(struct pilha p);
// verifica se a pilha está vazia

int searchStack(struct pilha p, int x);
// procura x dentro da pilha e retorna seu índice

struct pilha createStack();
// cria uma pilha
