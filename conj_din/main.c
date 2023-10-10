#include <stdio.h>
#include "conjunto.h"

int main() {
	struct conjunto *c = criaConj();
	insereConj(c, 900);
	insereConj(c, 10);
	insereConj(c, 1);
	imprimeConj(c);
	printf("%d\n", tamConj(c));
	destroiConj(c);

	return 0;
}
