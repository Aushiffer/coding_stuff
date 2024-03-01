#define TAM_TITULO 33
#define TAM_TEXTO 513

typedef struct Noticia {
	struct Noticia *prox;
	char *titulo;
	char *texto;
	short tipo;
	short dias;
	short valida;
} noticia;

typedef struct Fila {
	noticia *cbc;
	noticia *cauda;
	int tam;
} fila;

noticia *cria_noticia();

fila *cria_fila();

short noticia_valida(noticia *n);

short dias_noticia(noticia *n);

void requisita(char *titulo, char *texto);

int tam_fila(fila *f);

short fila_vazia(fila *f);

void insere_fila(fila *f, noticia *n);

void remove_fila(fila *f);

void libera_fila(fila *f);
