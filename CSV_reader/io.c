#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

void sumario(FILE *csv) {
        char *linha = (char *)malloc(SIZE_LINE_BUFFER * sizeof(char));

        if (!linha) {
                perror("[-] sumario(): Erro na alocação da linha auxiliar");

                return;
        }

        unsigned int i = 0;
        char **vetor_dados = (char **)malloc(SIZE_LINE_BUFFER * sizeof(char *));
        char **vetor_pessoas = (char **)malloc(SIZE_LINE_BUFFER * sizeof(char *));

        if (fgets(linha, SIZE_LINE_BUFFER, csv) != NULL) {
                char *token = strtok(linha, ",");
                vetor_dados[i] = token;

        } else {
                perror("[-] sumario(): Erro na leitura do cabeçalho");
                free(linha);
                linha = NULL;

                return;
        }

        printf("%u variaveis encontradas\n", i);
}