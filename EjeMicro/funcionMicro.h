#ifndef FUNCIONMICRO_H
#define FUNCIONMICRO_H

//Apartado 1
void cambiaValor(float *a, float *b);
//Apartado 2
int *reservaMemoriaV(int tam);
void leeV(int *v, int tam);
void imprimeV(int *v, int tam);
void mediaV(int *v, int tam, float *media);
void liberaMemoriaV(int **v);
//Apartado 3
struct conejo
{
    int codigo;
    float peso;
    int edad;
};
struct conejo *reservaMemoriaS(int numc);
void rellenarVector(struct conejo *c, int numc);
void mostrarVector(struct conejo *c, int numc);
int buscarConejo(struct conejo *c, int numc, int codigo);
struct conejo liberaMemoriaS(struct conejo **c);

//Apartado 4
float **reservaMemoriaM(int fil, int col);
void rellenaMatriz(float **m, int fil, int col);
void muestraMatriz(float **m, int fil, int col);
void mediaDiagonalPrin_Matriz(float **m, int fil, int col, float *mediaDiagMat);
void liberaMemoriaM(float ***m, int fil);
#endif