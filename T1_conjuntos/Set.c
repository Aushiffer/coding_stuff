#include <stdio.h>
#include <stdbool.h>
#include "Set.h"

bool isEmpty(struct set s) {
        if (s.size == 0)
                return true;
        return false;
} // retorna true se S for vazio

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

bool isIn(struct set s, int x) {
        for (int i = 0; i < s.size; i++)
                if (s.elements[i] == x)
                        return true;
        return false;
} // busca linear que ocorre até que se ache x (ou não)

void printSet(struct set s) {
        if (isEmpty(s)) { // verifica se S é vazio
                printf("conjunto vazio\n");
        } else {
                int aux;
                for (int i = 0; i < s.size; i++)
                        for (int j = i + 1; j < s.size; j++) {
                                if (s.elements[i] == s.elements[j])
                                        s.elements[j] = -1;
                                if (s.elements[i] < s.elements[j]) {
                                        aux = s.elements[i];
                                        s.elements[i] = s.elements[j];
                                        s.elements[j] = aux;
                                }
                        }
                s.size = size(s);
                for (int i = 0; i < s.size; i++)
                        printf("%d ", s.elements[i]);
                printf("\n");
        } // for loop que imprime todos os elementos de S
}

void sortSet(struct set s) {
        int aux; // variável auxiliar para a troca
        if (isEmpty(s)) { // verifica se S é vazio
                printf("conjunto vazio\n");
        } else {
                s.elements[s.size] = -1;
                for (int i = 0; i < s.size; i++)
                        for (int j = i + 1; j < s.size; j++) {
                                if (s.elements[i] == s.elements[j])
                                        s.elements[j] = -1;
                                if (s.elements[i] < s.elements[j]) {
                                        aux = s.elements[i];
                                        s.elements[i] = s.elements[j];
                                        s.elements[j] = aux;
                                }
                        } // -1 em duplicatas
                s.size = size(s); // remoção de duplicatas
                for (int i = 0; i < s.size; i++)
                        for (int j = i + 1; j < s.size; j++)
                                if (s.elements[i] > s.elements[j]) {
                                        aux = s.elements[i];
                                        s.elements[i] = s.elements[j];
                                        s.elements[j] = aux;
                                } // fim da ordenação 
                for (int i = 0; i < s.size; i++)
                        printf("%d ", s.elements[i]);
                printf("\n");
        }
}

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

void printUnion(struct set s1, struct set s2) {
	struct setUni {
                int size;
                int elements[s1.size + s2.size];
        }; // struct da união, para evitar que MAX_SIZE seja ultrapassado

        int aux; // var. auxiliar para a troca
	if (s1.size == 0) {
                printf("imprimindo união...\n");
                s2.elements[s2.size] = -1; // evitando a impressão de lixo de memória
                for (int i = 0; i < s2.size; i++)
                        for (int j = i + 1; j < s2.size; j++) {
                                if (s2.elements[i] == s2.elements[j])
                                        s1.elements[j] = -1;
                                if (s2.elements[i] < s2.elements[j]) {
                                        aux = s2.elements[i];
                                        s2.elements[i] = s2.elements[j];
                                        s2.elements[j] = aux;
                                } // ordenação decrescente e -1 em duplicatas
                        }
                s2.size = size(s2); // remoção de duplicatas
		printSet(s2); // se s1 for vazio, s2 é impresso
	} else if (s2.size == 0) {
                printf("imprimindo união...\n");
                s1.elements[s1.size] = -1; // evitando a impressão de lixo de memória
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
                s1.size = size(s1); // remoção de duplicatas
                printSet(s1); // se s2 for vazio, s1 é impresso
        } else {
		struct setUni uni;
		int k;
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

void printDifference(struct set s1, struct set s2) {
        int aux; // var. auxiliar para a troca
        s1.elements[s1.size] = -1; // evitando a impressão de lixo de memória em um caso especial
        for (int i = 0; i < s2.size; i++)
                for (int j = 0; j < s1.size; j++)
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

bool isSubset(struct set s1, struct set s2) {
        int aux; // var. auxiliar para a troca
        s1.elements[s1.size] = -1; // evitando a impressão de lixo de memória em um caso especial
        for (int i = 0; i < s2.size; i++)
                for (int j = 0; j < s1.size; j++)
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
        s1.size = size(s1); // definição de s1.size usando size
        if (isEmpty(s1)) // verifica se s1 - s2 é vazia (se for, s1 é subconjunto de s2)
                return true;
        return false;
}
