#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conjunto.h"

int main() {
	struct conjunto *c1 = criaConj();
	struct conjunto *c2 = criaConj();
	int size, elemRemove;
	printf("defina o tam. dos conjuntos (pode variar se algum número se repetir no processo):\n");
	scanf("%d", &size);
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		insereConj(c1, rand() % 11);
	for (int j = 0; j < size; j++)
		insereConj(c2, rand() % 11); // mude os valores após os rands para alterar a variedade de elementos
	printf("remova algum elemento de ambos os conjuntos (garantidamente não estará tanto em c1 quanto em c2):\n");
	scanf("%d", &elemRemove);
	removeConj(c1, elemRemove);
	removeConj(c2, elemRemove);
	printf("c1:\n");
	imprimeConj(c1);
	printf("c2:\n");
	imprimeConj(c2);
	struct conjunto *c3 = uniao(c1, c2);
	struct conjunto *c4 = intersecao(c1, c2);
	printf("união:\n");
	imprimeConj(c3);
	printf("interseção:\n");
	imprimeConj(c4);
	printf("tam. do conjunto c1: %d\n", tamConj(c1));
	printf("tam. do conjunto c2: %d\n", tamConj(c2));
	printf("tam. da união: %d\n", tamConj(c3));
	printf("tam. da interseção: %d\n", tamConj(c4));
	destroiConj(c1);
	destroiConj(c2);
	destroiConj(c3);
	destroiConj(c4);

	return 0;
}
