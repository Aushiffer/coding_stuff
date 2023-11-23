#include <stdlib.h>
#include <stdio.h>
#include "manipularBuckets.h"

nodo *criaNodo(float valor) {
        nodo *tmp;
        if(!(tmp = (nodo *)malloc(sizeof(nodo)))) {
                printf("[-] Impossível alocar nodo.\n");
                return NULL;
        }
        tmp->prox = NULL;
        tmp->valor = valor;

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

void trocarValoresNodos(nodo *n1, nodo *n2) {
        float aux = n1->valor;
        n1->valor = n2->valor;
        n2->valor = aux;
}

int bucketVazio(bucket *b) { return !b->topo; }

int tamBucket(bucket *b) { return b->tam; }

void insereNodo(bucket *b, float valor) {
        nodo *n = criaNodo(valor);
        if (bucketVazio(b)) {
                b->topo = n;
                (b->tam)++;
                return;
        }
        n->prox = b->topo;
        b->topo = n;
        (b->tam)++;
}

void removeNodo(bucket *b) {
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
                removeNodo(b);
        free(b);
        b = NULL;
}