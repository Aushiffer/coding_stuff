#ifndef IO_H
#define IO_H

#define SIZE_LINE_BUFFER 1025

#include <stdio.h>

void sumario(FILE *csv);

unsigned int conta_lin(FILE *csv);

unsigned int conta_col(FILE *csv);

void mostrar(FILE *csv);

#endif // IO_H