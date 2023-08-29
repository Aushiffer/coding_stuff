#include <stdio.h>
#include <stdbool.h>
#include "Set.h"

bool isEmpty(struct set s) {
        if (s.size == 0)
                return true;
        return false;
}
/* Retorna true se o tamanho utilizável de s.elements[] for 0 e 
 * false caso o contrário ocorra */

int size(struct set s) {
        int count, i;
        i = 0;
        count = 0;
        while (s.elements[i] != -1) {
                count++;
                i++;
        }

        return count;
}
/* Count é incrementado até que se ache um s.elements[i] tal que
 * ele seja -1. A função funciona partindo do pressuposto de que
 * s.elements[] sempre está em ordem decrescente e que foi
 * inicializado com -1 em todas as suas posições */

bool isIn(struct set s, int x) {
        for (int i = 0; i < s.size; i++)
                if (s.elements[i] == x)
                        return true;
        return false;
}
/* Busca linear que ocorre até que s.elements[i] seja igual a x.
 * Se isso ocorrer, true é retornado. Caso contrário, false é
 * retornado */

void printSet(struct set s) {
        if (isEmpty(s)) {
                printf("conjunto vazio\n");
        } else {
                for (int i = 0; i < s.size; i++)
                        printf("%d ", s.elements[i]);
                printf("\n");
        }
}
/* Imprime os elementos de s.elements[] através de um for loop */

void sortSet(struct set s) {
        int aux;
        for (int i = 0; i < s.size; i++)
                for (int j = i + 1; j < s.size; j++)
                        if (s.elements[i] > s.elements[j]) {
                                aux = s.elements[i];
                                s.elements[i] = s.elements[j];
                                s.elements[j] = aux;
                        }
        printSet(s);
}
/* Ordena os elementos de s.elements[] em ordem crescente. 
 * O algoritmo é similar a um selection sort */

void printIntersection(struct set s1, struct set s2) {
        struct set isec;
        int aux;
        isec.size = MAX_SIZE;
        for (int i = 0; i < MAX_SIZE; i++)
                isec.elements[i] = -1;
        for (int i = 0; i < s1.size; i++)
                for (int j = 0; j < s2.size; j++)
                        if (s1.elements[i] == s2.elements[j])
                                isec.elements[i] = s1.elements[i];
        for (int i = 0; i < isec.size; i++)
                for (int j = i + 1; j < isec.size; j++)
                        if (isec.elements[i] == isec.elements[j])
                                isec.elements[j] = -1;
        for (int i = 0; i < isec.size; i++)
                for (int j = i + 1; j < isec.size; j++)
                        if (isec.elements[i] < isec.elements[j]) {
                                aux = isec.elements[i];
                                isec.elements[i] = isec.elements[j];
                                isec.elements[j] = aux;
                        }
        isec.size = size(isec);
        printf("imprimindo intersecção...\n");
        printSet(isec);
}
/* Coloca os valores coincidentes entre s1 e s2 em um vetor isec.elements[]
 * de uma struct set chamada isec. Após isso, -1 é colocado em todos
 * os valores coincidentes em isec.elements[]. Esse vetor é ordenado
 * em ordem decrescente e isec.size é definido a partir disso com size(isec).
 * Finalmente, printSet(isec) é chamada, imprimindo a intersecção, guardada
 * em isec.elements[] */

void printUnion(struct set s1, struct set s2) {
	struct setUni {
                int size;
                int elements[s1.size + s2.size];
        };

	if (s1.size == 0) {
		printSet(s1);
	} else {
		struct setUni uni;
		int k, aux;
		k = 0;
		uni.size = s1.size + s2.size;
		for (int i = 0; i < uni.size; i++)
			uni.elements[i] = -1;
                uni.elements[uni.size] = -1;
		for (int i = 0; i < s1.size; i++)
			uni.elements[i] = s1.elements[i];
		for (int i = s1.size; i < uni.size; i++) {
			uni.elements[i] = s2.elements[k];
			k++;
		}
		for (int i = 0; i < uni.size; i++)
			for (int j = i + 1; j < uni.size; j++)
				if (uni.elements[i] == uni.elements[j])
					uni.elements[j] = -1;
		for (int i = 0; i < uni.size; i++)
			for (int j = i + 1; j < uni.size; j++)
				if (uni.elements[i] < uni.elements[j]) {
					aux = uni.elements[i];
					uni.elements[i] = uni.elements[j];
					uni.elements[j] = aux;
				}
                k = 0;
		printf("imprimindo união...\n");
		while (uni.elements[k] != -1) {
			printf("%d ", uni.elements[k]);
			k++;
		}
		printf("\n");
	}
} 
/* Os elementos de s1 e s2 são colocados numa struct setUni
 * de nome uni e uni.size = s1.size + s2.size. Note que
 * o elemento após o último elemento de uni.elements[] é -1.
 * Isso ocorre para que lixo de memória não seja impresso no 
 * final da função (isso acontece quando nenhum elemento de s1
 * é igual a algum elemento de s2). A união é feita eliminando
 * todos os elementos coincidentes em uni, uma vez que esta
 * possui todos os elementos de s1 e s2. Essa eliminação ocorre
 * de uma forma similar a printIntersection(struct set s1, struct set s2)
 * porém com a impressão acontecendo sem uma função própria
 * (a struct de uni é diferente para que não se tenha o risco de 
 * extrapolar o valor de MAX_SIZE, definido em Set.h) */
