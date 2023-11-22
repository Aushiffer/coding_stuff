#include <stdlib.h>
#include <stdio.h>
#include "manipularBuckets.h"

nodo *criaNodo() {
        nodo *tmp;
        if(!(tmp = (nodo *)malloc(sizeof(nodo)))) {
                printf("[-] Impossível alocar nodo.\n");
                return NULL;
        }
        tmp->prox = NULL;
        tmp->valor = -1.0;

        return tmp;
}

bucket *criaBucket() {
        bucket *tmp;
        if (!(tmp = (bucket *)malloc(sizeof(bucket)))) {
                printf("[-] Impossível alocar bucket.\n");
                return NULL;
        }
        tmp->tam = 0;
        tmp->topo = NULL;

        return tmp;
}

int bucketVazio(bucket *b) {
        if (!b->topo)
                return 1;

        return 0;
}

void push(bucket *b, nodo *n) {
        if (bucketVazio(b)) {
                b->topo = n;
                (b->tam)++;
                return;
        }
        n->prox = b->topo;
        b->topo = n;
        (b->tam)++;
}

void pop(bucket *b) {
        if (bucketVazio(b)) {
                printf("[-] Impossível remover nodos de um bucket vazio.\n");
                return;
        }
        if (!b->topo->prox) {
                free(b->topo);
                b->topo = NULL;
                (b->tam)--;
                return;
        }
        nodo *tmp = b->topo;
        b->topo = b->topo->prox;
        free(tmp);
        tmp = NULL;
        (b->tam)--;
}

void destroiBucket(bucket *b) {
        while (!bucketVazio(b))
                pop(b);
        free(b);
        b = NULL;
}