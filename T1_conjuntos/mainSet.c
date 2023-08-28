// Nome: Caio Eduardo Ferreira de Miranda; GRR: 20232359

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Set.h"

int main() {
        struct set conj1, conj2;
        int n;
        scanf("%d", &n);
        if (n > MAX_SIZE || n < 0) {
                printf("erro: tamanho inválido de conjunto\n");
        } else {
                conj1.size = n;
                conj2.size = n;
                srand(time(NULL));
                for (int i = 0; i < conj1.size; i++)
                        conj1.elements[i] = rand() % 10;
                for (int i = 0; i < conj2.size; i++)
                        conj2.elements[i] = rand() % 10;
                printSet(conj1);
                printSet(conj2);
		printUnion(conj1, conj2);
        }

        return 0;
}
