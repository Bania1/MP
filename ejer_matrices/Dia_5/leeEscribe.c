#include "leeEscribe.h"
#include <stdlib.h>
#include <stdio.h>

void rellenarMatriz(int ** m, int nfil, int ncol)
{
    for (int i = 0; i < nfil; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            printf("-Introduce un número: ");
            scanf("%d",&m[i][j]);
        }
    }
}


void mostrarMatriz(int **m, int nfil, int ncol)
{
    for (int i = 0; i < nfil; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            printf("-m[%d][%d] = %d\n",i,j,m[i][j]);
        }
    }
}