#ifndef FUNCIONMEM_H
#define FUNCIONMEM_H

int *reservaMemoria(int tam);
void rellenaVector(int *v, int tam);
void mostrarVector(int *v, int tam);
void liberarMemoria(int **v);

/*
Ejercicio en casa --paso de argumento por referencia y estructura
Mirar estructura de IP

implementar un programa que cree un vector dinamico, el programa debe:
-pedira por teclado el tamaño del vector
-reservara memoria para dicho tamaño
-rellenara el vector por teclado
-mostrara el vector por pantalla
-buscara un numero introducido por teclado (int buscarDato(int *v, int tam, int n))
-funcion que calcula por referencia tanto el mayor como el menor elemento del vector
-liberar memoria
*/
#endif


