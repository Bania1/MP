#include <stdlib.h>
#include <stdio.h>
#include "funcionMat.h"

//RESERVA MEMORIA
int **reservaMemoria(int fila, int col)
{
    int **m=NULL;
    m= ((int**)malloc(sizeof(int *)*fila));
    if(m==NULL)
    {
        printf("Error \n");
        exit (-1);
    }
    for(int i=0; i<fila; i++)
    {
        m[i]=NULL;
        m[i]=(int *)malloc(sizeof(int)*col);
        if(m[i]==NULL)
        {
            printf("Error \n");
            exit (-1);
        }
    }
    return m;
}

int *reservaMemoriaV(int fila)
{
    int *v=NULL;
    v=(int *)malloc(sizeof(int)*fila);
    if(v==NULL)
    {
        printf("Error en reservar memoria \n");
        exit -1;
    }
    return v;
}

//Funcion que pide que rellenes la matriz con valores
void rellenarMatriz(int **m, int fila, int col)
{
    for(int i=0; i<fila; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("Introduzca el valor del elemento \n");
            scanf("%d",&m[i][j]);
        }
    }
}

//Funcion que muestra la matriz
void mostrarMatriz(int **m, int fila, int col)
{
    for(int i=0; i<fila; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("\n");
            printf("----> %d \n",m[i][j]);
        }
    }
}

//Funcion que calcula la media de la matriz
float mediaMatriz(int **m, int fila, int col)
{
    float suma=0;
    for(int i=0; i<fila; i++)
    {
        for(int j=0; j<col; j++)
        {
            suma+=suma+m[i][j];
        }
    }
    return suma/(fila*col);
}

//Funcion que busca un dato dentro de la matriz que te piden por teclado
int buscarDato(int **m, int fila, int col, int dato)
{
    for(int i=0; i<fila; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(m[i][j]==dato)
            {
                return 1;
            }
        }
    }
    return 0;  

}

// Funcion que busca el mayor elemento por referencia
void buscarMayorElem(int **m, int fila, int col, int *mayor)
{
    (*mayor)= m[0][0];
    for(int i=0; i<fila; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(m[i][j]>(*mayor))
            {
                (*mayor)= m[i][j];
            }
        }
    }
}

//Funcion que busca el menor elemento de una fila
void menoresFilas(int **m, int fila, int col, int *menores)
{
    for(int i=0; i<fila; i++)
    {
        menores[i]= m[i][0];
        for(int j=0; j<col; j++)
        {
            if(m[i][j]<menores[i])
            {
                (*menores)=m[i][j];
            }
        }
    }
}

//LIBERA MEMORIA
void liberaMemoria(int ***m, int fil)
{
    for(int i=0; i<fil; i++)
    {
        free((*m)[i]);
    }
    free(*m);
    (*m)=NULL;
}

void liberaMemoriaV(int **v)
{
    free(*v);
    (*v)=NULL;
}