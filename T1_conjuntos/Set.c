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
        } // até que o elemento em s.elements[i] seja -1, count++ e i++

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
        if (isEmpty(s)) { // verifica se S é vazio
                printf("conjunto vazio\n");
        } else {
                for (int i = 0; i < s.size; i++)
                        printf("%d ", s.elements[i]);
                printf("\n");
        }
	/* Se S não for vazio, os elementos de s.elements[]
	 * são impressos com um for loop */
}
/* Imprime os elementos de s.elements[] através de um loop */

void sortSet(struct set s) {
        int aux; // variável auxiliar para a troca
        for (int i = 0; i < s.size; i++)
                for (int j = i + 1; j < s.size; j++)
                        if (s.elements[i] > s.elements[j]) {
                                aux = s.elements[i];
                                s.elements[i] = s.elements[j];
                                s.elements[j] = aux;
                        } // fim da ordenação
        printSet(s); // impressão de S (usando printSet), agora ordenado
}
/* Ordena os elementos de s.elements[] em ordem crescente. 
 * O algoritmo é similar a um selection sort */

void printIntersection(struct set s1, struct set s2) {
        struct set isec;
        int aux; // var. auxiliar para a troca (ordenação decrescente)
        isec.size = MAX_SIZE;
        for (int i = 0; i < MAX_SIZE; i++)
                isec.elements[i] = -1; // inicialização de isec.elements[] com -1
        for (int i = 0; i < s1.size; i++)
                for (int j = 0; j < s2.size; j++)
                        if (s1.elements[i] == s2.elements[j])
                                isec.elements[i] = s1.elements[i]; // coloca elementos coincidentes em isec.elements[]
        for (int i = 0; i < isec.size; i++)
                for (int j = i + 1; j < isec.size; j++) {
                        if (isec.elements[i] == isec.elements[j])
                                isec.elements[j] = -1;
                        if (isec.elements[i] < isec.elements[j]) {
                                aux = isec.elements[i];
                                isec.elements[i] = isec.elements[j];
                                isec.elements[j] = aux;
                        }
                } // ordenação decrescente e -1 em duplicatas
        isec.size = size(isec); // definição do tamanho de isec usando a função size (consequentemente remove as duplicatas)
        printf("imprimindo intersecção...\n");
        printSet(isec); // impressão da intersecção usando printSet
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
        }; // struct da união, para evitar que MAX_SIZE seja ultrapassado

	if (s1.size == 0) {
		printSet(s1); // se s1 é vazio, s2 também é
	} else {
		struct setUni uni;
		int k, aux;
		k = 0;
		uni.size = s1.size + s2.size;
                uni.elements[uni.size] = -1; // evitando a impressão de lixo de memória em um caso especial
		for (int i = 0; i < s1.size; i++)
			uni.elements[i] = s1.elements[i];
		for (int i = s1.size; i < uni.size; i++) {
			uni.elements[i] = s2.elements[k];
			k++;
		} // inserção dos elementos de ambos os conjuntos em uni.elements[]
		for (int i = 0; i < uni.size; i++)
			for (int j = i + 1; j < uni.size; j++) {
				if (uni.elements[i] == uni.elements[j])
                                        uni.elements[j] = -1;
                                if (uni.elements[i] < uni.elements[j]) {
					aux = uni.elements[i];
					uni.elements[i] = uni.elements[j];
					uni.elements[j] = aux;
				}
                        } // ordenação decrescente e -1 em duplicatas
                k = 0;
		printf("imprimindo união...\n");
		while (uni.elements[k] != -1) {
			printf("%d ", uni.elements[k]);
			k++;
		} /* até que uni.elements[k] seja -1, uni.elements[k] é impresso e k++
		   * impressão sem usar printSet, uma vez que size e printSet aceitam
		   * apenas struct set */
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
 * de forma similar a como acontece em printIntersection(struct set s1, struct set s2)
 * porém com a impressão acontecendo sem uma função própria
 * (a struct de uni é diferente para que não se tenha o risco de 
 * extrapolar o valor de MAX_SIZE, definido em Set.h) */

void printDifference(struct set s1, struct set s2) {
        int aux; // var. auxiliar para troca (ordenação decrescente)
        s1.elements[s1.size] = -1; // evitando a impressão de lixo de memória em um caso especial
        for (int i = 0; i < s2.size; i++)
                for (int j = 0; j < s2.size; j++)
                        if (s2.elements[i] == s1.elements[j])
                                s1.elements[j] = -1; // -1 em elementos de s2 que coincidem com elementos de s1
        for (int i = 0; i < s1.size; i++)
                for (int j = i + 1; j < s1.size; j++) {
                        if (s1.elements[i] == s1.elements[j])
                                s1.elements[j] = -1;
                        if (s1.elements[i] < s1.elements[j]) {
                                aux = s1.elements[i];
                                s1.elements[i] = s1.elements[j];
                                s1.elements[j] = aux;
                        }
                } // ordenação decrescente e -1 em duplicatas
        s1.size = size(s1); // definição de s1.size usando size (consequentemente remove as duplicatas)
        printf("imprimindo diferença...\n");
        printSet(s1); // impressão da diferença usando printSet
}
/* Os elementos de s1 que coincidem com s2 são removidos através de atribuições
 * e ordenação decrescente */
