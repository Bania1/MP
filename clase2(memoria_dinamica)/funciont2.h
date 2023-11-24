#ifndef FUNCIONMEM_H
#define FUNCIONMEM_H

int *reservaMemoria(int tam);
void rellenaVector(int *v, int tam);
void mostrarVector(int *v, int tam);
int buscarDato(int *v, int tam, int n);
void buscarMayorMenor(int *v, int tam, int *max, int *min);
void liberarMemoria(int **v);

#endif