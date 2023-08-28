#include <stdio.h>
#include <stdbool.h>
#include "Set.h"

bool isEmpty(struct set s) {
        if (s.size == 0)
                return true;
        return false;
}

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

bool isIn(struct set s, int x) {
        for (int i = 0; i < s.size; i++)
                if (s.elements[i] == x)
                        return true;
        return false;
}

void printSet(struct set s) {
        if (isEmpty(s)) {
                printf("conjunto vazio\n");
        } else {
                printf("imprimindo conjunto...\n");
                for (int i = 0; i < s.size; i++)
                        printf("%d ", s.elements[i]);
                printf("\n");
        }
}

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
        printSet(isec);
}

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
