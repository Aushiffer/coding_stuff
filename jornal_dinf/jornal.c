#include <stdio.h>
#include <stdlib.h>
#include "jornal.h"

noticia *cria_noticia() {
	noticia *tmp = (noticia *)malloc(sizeof(noticia));

	if (!tmp) {
		fprintf(stderr, "[-] Falha na alocação em cria_noticia()\n");

		return NULL;
	}

	tmp->titulo = (char *)malloc(TAM_TITULO * sizeof(char));

	if (!tmp->titulo) {
		free(tmp);
		tmp = NULL;

		return NULL;
	}

	tmp->texto = (char *)malloc(TAM_TEXTO * sizeof(char));

	if (!tmp->texto) {
		free(tmp->titulo);
		tmp->titulo = NULL;
		free(tmp);
		tmp = NULL;

		return NULL;
	}

	tmp->prox = NULL;
	tmp->tipo = 0;
	tmp->dias = 0;
	tmp->valida = 0;

	return tmp;
}

fila *cria_fila() {
	fila *tmp = (fila *)malloc(sizeof(fila));

	if (!tmp) {
		fprintf(stderr, "[-] Falha na alocação da fila de notícias em cria_fila()\n");

		return NULL;
	}	

	tmp->cbc = NULL;
	tmp->cauda = NULL;
	tmp->tam = 0;

	return tmp;
}

short noticia_valida(noticia *n) { return n->valida == 0; }

short dias_noticia(noticia *n) { return n->dias; }

void requisita(char *titulo, char *texto) {
	getchar();
	printf("\nDigite o título: ");
	fgets(titulo, TAM_TITULO, stdin);
	printf("Digite o texto: ");
	fgets(texto, TAM_TEXTO, stdin);
}

int tam_fila(fila *f) { return f->tam; }

short fila_vazia(fila *f) { return tam_fila(f); }

void insere_fila(fila *f, noticia *n) {
	if (fila_vazia(f)) {
		f->cbc = n;
		f->cauda = n;
		(f->tam)++;

		return;
	}

	f->cauda->prox = n;
	f->cauda = n;
	(f->tam)++;
}

void remove_fila(fila *f) {
	if (tam_fila(f) == 1) {
		free(f->cbc);
		f->cbc = NULL;
		(f->tam)--;

		return;
	}

	noticia *aux = f->cbc;
	f->cbc = f->cbc->prox;
	free(aux);
	aux = NULL;
	(f->tam)--;
}

void libera_fila(fila *f) {
	while (!fila_vazia(f))
		remove_fila(f);

	free(f);
	f = NULL;
}
