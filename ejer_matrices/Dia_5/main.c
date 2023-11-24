/**
	@file main.c
	@brief Aqui se invoca la funcion
	@author Angel
*/
#include "funciones.h"
#include "leeEscribe.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

    int ** m = NULL;
    int nfil, ncol, ndiv, suma;

    printf("->Introduce el número de filas: ");
    scanf("%d",&nfil);
    printf("->Introduce el número de columnas: ");
    scanf("%d",&ncol);
    
    m = reservaMemoria(nfil,ncol);

    rellenarMatriz(m,nfil,ncol);
    mostrarMatriz(m,nfil,ncol);

    calculosVarios(m,nfil,ncol,&suma,&ndiv);
    printf("\n ->Hay %d elementos divisibles por 3 en la matriz\n",ndiv);
    printf("\n ->La suma de los elementos divisibles por 3 es: %d\n",suma);

    liberaMemoria(&m,nfil);

    return 0;
}