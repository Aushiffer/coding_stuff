#define MAX 100

struct pilha {
	int cap = MAX;
	int itens[cap];
	int top = 0;
};

void push(struct pilha p, int x);

void pop(struct pilha p);

int emptyStack(struct pilha p);

int searchStack(struct pilha p, int x);
