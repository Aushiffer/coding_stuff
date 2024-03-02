#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jornal.h"

noticia *cria_noticia() {
	noticia *tmp = (noticia *)malloc(sizeof(noticia));

	if (!tmp) {
		fprintf(stderr, "[-] Falha na alocação em cria_noticia()\n");

		return NULL;
	}

	tmp->prox = NULL;
	tmp->dias = 0;

	return tmp;
}

short dias_noticia(noticia *n) { return n->dias; }

short noticia_valida(noticia *n) { return dias_noticia(n) < 3; }

void requisita(char *titulo, char *texto) {
	getchar();
	printf("\nDigite o título: ");
	fgets(titulo, TAM_TITULO, stdin);
	printf("Digite o texto: ");
	fgets(texto, TAM_TEXTO, stdin);
}

void cadastra_noticia(fila *f) {
	noticia *n = cria_noticia();
	requisita(n->titulo, n->texto);
        insere_fila(f, n);
}

void fechar_edicao(fila *f_breaking, fila *f_informe) {
	int n_breaking = 0, count = 0;

	if (!fila_vazia(f_breaking)) {
		noticia *aux_breaking = f_breaking->cbc;

		while (n_breaking < 2 && count < tam_fila(f_breaking)) {
			if (noticia_valida(aux_breaking)) {
				printf("\n%s", aux_breaking->titulo);
				printf("%s", aux_breaking->texto);
				n_breaking++;

				if (aux_breaking->prox != NULL)
					aux_breaking = aux_breaking->prox;
			} else if (!noticia_valida(aux_breaking)) {
				if (aux_breaking->prox != NULL)
					aux_breaking = aux_breaking->prox;
				
				remove_fila(f_breaking);
			}

			count++;
		}

		aux_breaking = f_breaking->cbc;

		for (int i = 0; i < tam_fila(f_breaking); i++) {
			(aux_breaking->dias)++;
			
			if (aux_breaking->prox != NULL)
				aux_breaking = aux_breaking->prox;
		}
	}

	count = 0;

	if (!fila_vazia(f_informe)) {
		noticia *aux_informe = f_informe->cbc;

		while (n_breaking < 2 && count < tam_fila(f_informe)) {
			if (noticia_valida(aux_informe)) {
				printf("\n%s", aux_informe->titulo);
				printf("%s", aux_informe->texto);
				n_breaking++;

				if (aux_informe->prox != NULL)
					aux_informe = aux_informe->prox;
			} else if (!noticia_valida(aux_informe)) {
				if (aux_informe->prox != NULL)
					aux_informe = aux_informe->prox;

				remove_fila(f_informe);
			}

			count++;
		}

		aux_informe = f_informe->cbc;

		for (int j = 0; j < tam_fila(f_informe); j++) {
			(aux_informe->dias)++;

			if (aux_informe->prox != NULL)
				aux_informe = aux_informe->prox;
		}
	}

	if (n_breaking == 0)
		printf("\nEsta edição foi pulada por falta de notícias!\n");
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

int tam_fila(fila *f) { return f->tam; }

short fila_vazia(fila *f) { return tam_fila(f) == 0; }

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
	if (fila_vazia(f)) {
		fprintf(stderr, "[-] Fila vazia. Impossível realizar remoção.\n");
	}

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
