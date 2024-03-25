#ifndef IO_H
#define IO_H

#define SIZE_LINE_BUFFER 1025

#include <stdio.h>

void sumario(FILE *csv);

void mostrar(FILE *csv);

unsigned int conta_col(FILE *csv);

unsigned int conta_lin(FILE *csv);

#endif // IO_H