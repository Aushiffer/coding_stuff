#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <bits/getopt_core.h>
#include "io.h"

int main(int argc, char **argv) {
        int opt;
        char *entrada = NULL;

        while ((opt = getopt(argc, argv, "r:")) != -1) {
                switch (opt) {
                        case 'r':
                                entrada = strdup(optarg);

                                break;
                        default:
                                perror("[-] Uso: ./csvreader -r <arquivo.csv>");

                                return 1;
                }
        }

        FILE *csv = fopen(entrada, "r");

        if (!csv) {
                perror("[-] main(): Arquivo não existe");
                free(entrada);
                entrada = NULL;

                return 2;
        }

        sumario(csv);
        free(entrada);
        entrada = NULL;
        fclose(csv);

        return 0;
}