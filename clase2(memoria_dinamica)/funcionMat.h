#ifndef FUNCIONMAT_H
#define FUNCIONMAT_H

/*
Programa que pida por teclado el numero de filas 
y columnas

funciones:
-void rellenarMatriz(int **m, int fila, int col);
-void mostrarMatriz(int **m, int fila, int col);
-float mediaMatriz(int **m, int fila, int col);
-int buscarDato(int **m, int fila, int col, int dato);
-int buscarMayorElem(int **m, int fila, int col, int *mayor);
(por referencia)
-void menoresFilas(int **m, int fila, int col, int *menores);
*/

int **reservaMemoria(int fila, int col);
int *reservaMemoriaV(int fila);

void rellenarMatriz(int **m, int fila, int col);
void mostrarMatriz(int **m, int fila, int col);
float mediaMatriz(int **m, int fila, int col);
int buscarDato(int **m, int fila, int col, int dato);
void buscarMayorElem(int **m, int fila, int col, int *mayor);

//El menor es un vector
void menoresFilas(int **m, int fila, int col, int *menores);

void liberaMemoria(int ***m, int fil);
void liberaMemoriaV(int **v);

/*





*/

#endif