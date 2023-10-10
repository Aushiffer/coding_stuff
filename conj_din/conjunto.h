#include <stdbool.h>

// Estrutura do conjunto
struct conjunto {
	int tam;
	int maxTam;
	int *elementos;
};

// Cria um conjunto
struct conjunto *criaConj();

// Destroi um conjunto, liberando a memória alocado a ele
void destroiConj(struct conjunto *c);

// Retorna o tamanho do conjunto
int tamConj(struct conjunto *c);

// Verifica se o elemento x pertence ao conjunto C
bool pertenceConj(struct conjunto *c, int x);

// Insere o elemento x ao conjunto C, caso x não exista em C
void insereConj(struct conjunto *c, int x);

// Remove o elemento x do conjunto C, caso ele exista em C
void removeConj(struct conjunto *c, int x);

// Retorna conjunto de tamanho alocado máximo tamConj(c1) + tamConj(c2)
struct conjunto *uniao(struct conjunto *c1, struct conjunto *c2);

// Retorna a interseção de C1 com C2
struct conjunto *intersecao(struct conjunto *c1, struct conjunto *c2);

// Imprime os elementos do conjunto C
void imprimeConj(struct conjunto *c);

// Verifica se C é vazio
bool conjVazio(struct conjunto *c);
