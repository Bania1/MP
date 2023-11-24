#include <stdio.h>
#include <stdlib.h>
#include "funciont2.h"

int *reservaMemoria(int tam)
{
    int * v=NULL;
    v= (int*)malloc(sizeof(int)*tam);
    if(v==NULL)
    {
        printf("Error en reservar memoria");
        exit -1;
    }
    return v;
}

void rellenaVector(int *v, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("Introduzca el valor del vector \n");
        scanf("%d",&v[i]);
    }
}
void mostrarVector(int *v, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("--> %d \n",v[i]);
    }
}
int buscarDato(int *v, int tam, int n)
{
    for(int i=0; i<tam; i++)
    {
        if(v[i]==n)
        {
            return 1;
        }    
    }
    return 0;
}
void buscarMayorMenor(int *v, int tam,int *max, int *min)
{ 
    (*max)=v[0];
    (*min)=v[0];
    for(int i=0; i<tam; i++)
    {
        if(v[i]>(*max))
        {
            (*max)=v[i];
        }
        if(v[i]<(*min))
        {
            (*min)=v[i];
        }
    }

}

void liberarMemoria(int **v)
{
    free(*v);
    (*v)=NULL;
}