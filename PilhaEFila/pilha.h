#define MAX 100

struct pilha {
	int cap;
	int itens[MAX];
	int top;
};

void push(struct pilha *p, int x);

void pop(struct pilha *p);

int emptyStack(struct pilha p);

int searchStack(struct pilha p, int x);

void createStack(struct pilha *p);
