#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

void sumario(FILE *csv) {
        if (!csv) {
                perror("[-] sumario(): Arquivo não existe");

                return;
        }
        
        char *linha1 = (char *)malloc(SIZE_LINE_BUFFER * sizeof(char));
        char *linha2 = (char *)malloc(SIZE_LINE_BUFFER * sizeof(char));

        if (!linha1) {
                perror("[-] sumario(): Erro na alocação da linha 1");

                return;
        }

        char **vetor_dados = (char **)malloc(SIZE_LINE_BUFFER * sizeof(char *));
        char **vetor_pessoas = (char **)malloc(SIZE_LINE_BUFFER * sizeof(char *));
        rewind(csv);
        int i = 0;
        linha1 = fgets(linha1, SIZE_LINE_BUFFER, csv);

        if (linha1) {
                char *token = strtok(linha1, ",");
                vetor_dados[i] = token;

                while (token) {
                        i++;
                        token = strtok(NULL, ",");
                        vetor_dados[i] = token;
                }
        }

        linha2 = fgets(linha2, SIZE_LINE_BUFFER, csv);
        i = 0;

        if (linha2) {
                char *token = strtok(linha2, ",");
                vetor_pessoas[i] = token;

                while (token) {
                        i++;
                        token = strtok(NULL, ",");
                        vetor_pessoas[i] = token;
                }
        } else {
                perror("[-] sumario(): Erro na leitura da linha 2");
                free(linha1);
                linha1 = NULL;
                free(vetor_dados);
                vetor_dados = NULL;
                free(vetor_pessoas);
                vetor_pessoas = NULL;

                return;
        }

        for (int j = 0; j < i; j++) {
                if (atof(vetor_pessoas[j]) == 0)
                        printf("%s [S]\n", vetor_dados[j]);
                else
                        printf("%s [N]\n", vetor_dados[j]);
        }

        printf("\n%d variaveis encontradas\n", i);
        free(linha1);
        linha1 = NULL;
        free(linha2);
        linha2 = NULL;
        free(vetor_dados);
        vetor_dados = NULL;
        free(vetor_pessoas);
        vetor_pessoas = NULL;
}

unsigned int conta_lin(FILE *csv) {
        if (!csv) {
                perror("[-] conta_lin(): Arquivo não existe");

                return 0;
        }
        
        rewind(csv);
        char *linha = (char *)malloc(SIZE_LINE_BUFFER * sizeof(char));

        if (!linha) {
                perror("[-] conta_lin(): Erro na alocação da linha auxiliar");

                return 0;
        }

        unsigned int i = 0;

        while (fgets(linha, SIZE_LINE_BUFFER, csv) != NULL)
                i++;

        free(linha);
        linha = NULL;

        return i;
}

unsigned int conta_col(FILE *csv) {
        if (!csv) {
                perror("[-] conta_col(): Arquivo não existe");

                return 0;
        }
        
        rewind(csv);
        char *linha = (char *)malloc(SIZE_LINE_BUFFER * sizeof(char));

        if (!linha) {
                perror("[-] conta_col(): Erro na alocação da linha auxiliar");

                return 0;
        }

        unsigned int i = 0;

        if (fgets(linha, SIZE_LINE_BUFFER, csv) != NULL) {
                char *token = strtok(linha, ",");

                while (token) {
                        i++;
                        token = strtok(NULL, ",");
                }
        }

        free(linha);
        linha = NULL;

        return i;
}

void mostrar(FILE *csv) {
        if (!csv) {
                perror("[-] mostrar(): Arquivo não existe");

                return;
        }

        rewind(csv);
        char *linha = (char *)malloc(SIZE_LINE_BUFFER * sizeof(char));

        if (!linha) {
                perror("[-] linha(): Erro na alocação da linha do cabeçalho");

                return;
        }

        unsigned int i = 0;

        if (fgets(linha, SIZE_LINE_BUFFER, csv)) {
                char *token = strtok(linha, ",");

                while (token) {
                        printf("\t%-30s", token);
                        token = strtok(NULL, ",");
                }
        }

        printf("\n");

        while (i < 5 && fgets(linha, SIZE_LINE_BUFFER, csv) != NULL) {
                printf("%u", i);
                char *token = strtok(linha, ",");

                while (token) {
                        printf("\t%-30s", token);
                        token = strtok(NULL, ",");
                }
                
                printf("\n");

                i++;
        }

        for (unsigned int j = 0; j < i + 1; j++)
                printf("\t%-30s", "...");
        
        printf("\n");

        unsigned int lin = conta_lin(csv);
        unsigned int col = conta_col(csv);

        while (i < lin && fgets(linha, SIZE_LINE_BUFFER, csv) != NULL) {
                if (i >= lin - 5) {
                        printf("%u", i);
                        char *token = strtok(linha, ",");

                        while (token) {
                                printf("\t%-30s", token);
                                token = strtok(NULL, ",");
                        }

                        printf("\n");
                }

                i++;
        }

        printf("[%u rows x %u columns]\n", lin, col);
        free(linha);
        linha = NULL;
}