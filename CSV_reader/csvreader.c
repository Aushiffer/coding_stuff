#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <bits/getopt_core.h>
#include "io.h"

int main(int argc, char **argv) {
        if (argc != 2) {
                perror("[-] Uso: ./csvreader <arquivo.csv>; Use 1 CSV por vez");

                return 1;
        }
        
        int input_main;
        FILE *csv = fopen(argv[1], "r");

        if (!csv) {
                perror("[-] main(): Arquivo não existe");

                return 2;
        }

        do {
                printf("1) Sumário do Arquivo\n");
                printf("2) Mostrar\n");
                printf("3) Fim\n");
                scanf("%17d", &input_main);
                printf("\n");
                if (input_main == 1)
                        sumario(csv);
                else if (input_main == 2)
                        mostrar(csv);
                else if (input_main > 3 || input_main < 1)
                        perror("[-] main(): Opção inválida");
                
                printf("\n");
        } while (input_main != 3);

        fclose(csv);

        return 0;
}