#ifndef JORNAL_H
#define JORNAL_H

#define TAM_TITULO 33
#define TAM_TEXTO 513

typedef struct Noticia {
	struct Noticia *prox;
	char titulo[TAM_TITULO];
	char texto[TAM_TEXTO];
	short dias;
} noticia;

typedef struct Fila {
	noticia *cbc;
	noticia *cauda;
	int tam;
} fila;

noticia *cria_noticia();

fila *cria_fila();

short dias_noticia(noticia *n);

short noticia_valida(noticia *n);

void requisita(char *titulo, char *texto);

void cadastra_noticia(fila *f);

void fechar_edicao(fila *f_breaking, fila *f_informe);

int tam_fila(fila *f);

short fila_vazia(fila *f);

void insere_fila(fila *f, noticia *n);

void remove_fila(fila *f);

void libera_fila(fila *f);

#endif // JORNAL_H
