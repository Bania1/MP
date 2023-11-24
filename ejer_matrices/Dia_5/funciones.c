/**
	@file funciones.c
	@brief Aqui se fundamentan las funciones
	@author Angel
*/
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

/**
    @fn 	    int ** reservaMemoria(int nfil, int ncol)
	@brief      Esta funcion sirve para reservar la memoria de la matriz	
 	@param      nfil indica el numero de filas de la matriz
 	
 	@param      ncol indica el numero de columnas de la matriz
*/
int ** reservaMemoria(int nfil, int ncol)
{

    int ** m = NULL;

    m = (int **)malloc(sizeof(int **) * nfil);

    for (int i = 0; i < nfil; i++)
    {
        m[i] = (int *)malloc(sizeof(int) * ncol);
    }

    return m;
}

void liberaMemoria(int *** m, int nfil)
{
    for (int i = 0; i < nfil; i++)
    {
        free((*m)[i]);
    }

    free(*m);
}


void calculosVarios(int ** m, int nfil, int ncol,int * suma, int * ndiv)
{
    (*suma) = 0;
    (*ndiv) = 0;
    for (int i = 0; i < nfil; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            if (m[i][j]%3 == 0)
            {
                (*ndiv) += 1;
                (*suma) = (*suma) + m[i][j];
            }
        }
    }
}