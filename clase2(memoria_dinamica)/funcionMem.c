#include "funcionMem.h"
#include <stdio.h>
#include <stdlib.h>
int *reservaMemoria(int tam)
{
    int *v=NULL;
    v=(int *)malloc(sizeof(int)*tam);
    if(v==NULL)
    {
        printf("Error en reservar memoria \n");
        exit -1;
    }
    return v;
}
void liberarMemoria(int **v)
{
    free(*v);
    (*v)=NULL;
}
void rellenaVector(int *v,int tam)
{
    int i,val;
    for(i=0;i<tam;i++)
    {
        printf("Introduce el valor \n");
        scanf("%d",&val);
        v[i]=val;
    }
}
void mostrarVector(int *v,int tam)
{
    int i,val;
    for(i=0;i<tam;i++)
    {
        val=v[i];
        printf("--> %d \n",val);
    }
}