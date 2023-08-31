/* Nome: Caio Eduardo Ferreira de Miranda; GRR: 20232359
 * Arquivo para teste da biblioteca Set.h */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Set.h"

int main() {
        struct set conj1, conj2;
        int n, m;
        scanf("%d %d", &n, &m);
        printf("\n");
        if ((n > MAX_SIZE || n < 0) || (m > MAX_SIZE || m < 0)) {
                printf("erro: tamanho inválido de conjunto\n");
        } else {
                conj1.size = n;
                conj2.size = m;
                srand(time(NULL));
                for (int i = 0; i < conj1.size; i++)
                        conj1.elements[i] = rand() % 11;
                for (int i = 0; i < conj2.size; i++)
                        conj2.elements[i] = rand() % 11;
                printf("imprimindo s1...\n");
                printSet(conj1);
                printf("imprimindo s2...\n");
                printSet(conj2);
                printDifference(conj1, conj2);
                printUnion(conj1, conj2);
                printIntersection(conj1, conj2);
                if (isIn(conj1, n)) {
                        printf("\n%d pertence a s1\n", n);
                } else {
                        printf("\n%d não pertence a s1\n", n);
                }
                if (isIn(conj2, m)) {
                        printf("%d pertence a s2\n", m);
                } else {
                        printf("%d não pertence a s2\n", m);
                }
                if (isSubset(conj1, conj2)) {
                        printf("s1 é subconjunto de s2\n\n");
                } else {
                        printf("s1 não é subconjunto de s2\n\n");
                }
                printf("imprimindo conj1 em ordem crescente...\n");
                sortSet(conj1);
                printf("imprimindo conj2 em ordem crescente...\n");
                sortSet(conj2);
                printf("\no tamanho de s1 é: %d\n", size(conj1));
                printf("o tamanho de s2 é: %d\n\n", size(conj2));
        }
        
        return 0;
}
