/* Leitor de atributos em arquivos ARFF */
/* @author: Caio E. F. de Miranda */
/* @date: 24/03/2024 */

/* Tamanho da linha auxiliar, usada para conseguir informações do arquivo ARFF. */
#define SIZE_CHARBUF 1025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <bits/getopt_core.h>

typedef struct Atributo {
	char *rotulo;
	char *tipo;
	char *categorias;
} atributo;

void exibe_atributos(atributo *infos, int tamanho) {
    	if (!infos) {
		printf("O arquivo ARFF fornecido é inválido!\n");
    		exit(0);
    	}

    	printf("==== ATRIBUTOS DO ARQUIVO ====\n");
    
    	for (int i = 0; i < tamanho; i++) {
		printf("-> Atributo #%d\n", i + 1);
        	printf("Rótulo: %s\n", infos[i].rotulo);
        	printf("Tipo: %s\n", infos[i].tipo);

        if (infos[i].categorias) 
		printf("Categorias: %s\n", infos[i].categorias);

        if (i < tamanho - 1) 
		printf("------------------------------\n");
    	}

    	printf("===============================\n");
}

int conta_atributos(FILE *arff) {
	if (!arff) {
		perror("[-] conta_atributos: Arquivo ARFF recebido não existe");

		return -1;
	}

	rewind(arff);
	int n_atr = 0;
	char *linha_aux = (char *)malloc(SIZE_CHARBUF * sizeof(char));

	if (!linha_aux) {
		perror("[-] conta_atributos(): Impossível alocar substring auxiliar de linha_aux");

		return -1;
	}

	while (fgets(linha_aux, SIZE_CHARBUF, arff) != NULL) {
		if (strncmp(linha_aux, "@attribute", strlen("@attribute")) == 0) {
			n_atr++;
		} else if (strncmp(linha_aux, "@data", strlen("@data")) == 0) {
			free(linha_aux);
			linha_aux = NULL;
			rewind(arff);

			return n_atr;
		}
	}

	perror("[-] conta_atributos(): Formato de atributo inválido");
	free(linha_aux);
	linha_aux = NULL;

	return -1;
}

atributo *processa_atributos(FILE *arff) {
	if (!arff) {
		perror("[-] processa_atributos: Arquivo ARFF recebido não existe");

		return NULL;
	}

	char *linha_aux = (char *)malloc(SIZE_CHARBUF * sizeof(char));

	if (!linha_aux) {
		perror("[-] processa_atributos(): Impossível alocar substring auxiliar de linha_aux");

		return NULL;
	}

	int n_atr = conta_atributos(arff);

	if (n_atr < 0) {
		perror("[-] processa_atributos(): Impossível criar um vetor de atributos com tamanho negativo");
		free(linha_aux);
		linha_aux = NULL;

		return NULL;
	}

	atributo *atr = (atributo *)malloc(n_atr * sizeof(atributo));

	if (!atr) {
		perror("[-] processa_atributos(): Impossível alocar atributos de retorno");
		free(linha_aux);
		linha_aux = NULL;

		return NULL;
	}

	int i = 0;
	
	while (fgets(linha_aux, SIZE_CHARBUF, arff) != NULL) {
		if (strncmp(linha_aux, "@attribute", strlen("@attribute")) == 0) {
			char *token = strtok(linha_aux, " ");
			token = strtok(NULL, " ");
			atr[i].rotulo = strdup(token);
			token = strtok(NULL, " ");

			if (strchr(token, '{')) {
				atr[i].tipo = strdup("categoric");
				atr[i].categorias = strdup(token);
			} else {
				atr[i].tipo = strdup(token);
				atr[i].categorias = NULL;
			}

			i++;
		} else if (strncmp(linha_aux, "@data", strlen("@data")) == 0) {
			free(linha_aux);
			linha_aux = NULL;

			return atr;
		}
	}

	perror("[-] processa_atributos(): O formato de arquivo ARFF é inválido");
	free(linha_aux);
	linha_aux = NULL;
	free(atr);
	atr = NULL;

	return NULL;
}

void libera_atrs(atributo *vetor, int n_atr) {
	if (vetor) {
		for (int i = 0; i < n_atr; i++) {
			free(vetor[i].rotulo);
			free(vetor[i].tipo);
			free(vetor[i].categorias);
		}

		free(vetor);
		vetor = NULL;
	}
}

int main(int argc, char **argv) {
	int opt;
  	char exibicao = 0;
  	char *entrada = 0;

	while ((opt = getopt(argc, argv, "pi:")) != -1) {
		switch (opt) {
		case 'i':
			entrada = strdup(optarg);
			
			break;
		case 'p':
			exibicao = 1;

			break;
		default:
			fprintf(stderr, "Forma de uso: ./arff -i <arq_in> [-p]\n");
			exit(1);
		}
	}

	if (!entrada) {
		fprintf(stderr, "Forma de uso: ./arff -i <arq_in> [-p]\n");
		exit(2);
	}

	FILE *arff = fopen(entrada, "r");

	if (!arff) {
		perror("[-] main(): Ponteiro para arquivo ARFF não existe");

		return EXIT_FAILURE;
	}

	int n_atr = conta_atributos(arff);

	if (n_atr < 0) {
		perror("[-] main(): Não foi possível contar os atributos do arquivo ARFF");
		free(entrada);
		entrada = NULL;
		fclose(arff);

		return EXIT_FAILURE;
	}

	atributo *atr = processa_atributos(arff);

	if (exibicao)
		exibe_atributos(atr, n_atr);

	libera_atrs(atr, n_atr);
	free(entrada);
	entrada = NULL;
	fclose(arff);

	return EXIT_SUCCESS;
}
