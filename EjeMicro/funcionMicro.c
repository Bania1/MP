#include <stdio.h>
#include <stdlib.h>
#include "funcionMicro.h"

//Apartado 1
void cambiaValor(float *a, float *b)
{
    float aux;
    aux= (*a);
    (*a)=(*b);
    (*b)=aux;
}
//Apartado 2
int *reservaMemoriaV(int tam)
{
    int *v=NULL;
    v= (int*)malloc(sizeof(int)*tam);
    if (v==NULL)
    {
        printf("Error al reservar memoria");
        exit(-1);
    }
    return v;
}
void leeV(int *v, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("Introduzca el valor del vector \n");
        scanf("%d",&v[i]);
    }
}
void imprimeV(int *v, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("Valor del vector --> %d \n",v[i]);
        
    }
}
void mediaV(int *v, int tam, float *media)
{
    float suma=0;
    for (int i = 0; i < tam; i++)
    {
        suma+=v[i];
    }
    (*media)=suma/tam;
}
void liberaMemoriaV(int **v)
{
    free(*v);
    (*v)=NULL;
}
//Apartado 3
struct conejo *reservaMemoriaS(int numc)
{
    struct conejo *c=NULL;
    c=(struct conejo*)malloc(sizeof(struct conejo)*numc);
    if (c==NULL)
    {
        printf("Error al reservar memoria");
        exit(-1);
    }
    return c;
}
void rellenarVector(struct conejo *c, int numc)
{
    for (int i = 0; i < numc; i++)
    {
        printf("Introduzca el codigo del conejo %d \n", i);
        scanf("%d",&c[i].codigo);

        printf("Introduzca el peso del conejo %d \n", i);
        scanf("%f",&c[i].peso);

        printf("Introduzca la edad del conejo %d \n", i);
        scanf("%d",&c[i].edad);
        printf("\n");
    
    }
}
void mostrarVector(struct conejo *c, int numc)
{
    for(int i=0; i<numc; i++)
    {
    printf("Nombre del conejo %d ---> %d \n", i, c[i].codigo);
    printf("Peso del conejo %d ---> %f \n", i, c[i].peso);
    printf("Edad del conejo %d ---> %d \n", i, c[i].edad);
    printf("\n");
    }
}
int buscarConejo(struct conejo *c, int numc, int codigo)
{
    for (int i = 0; i < numc; i++)
    {
        if(c[i].codigo==codigo);
        return 1;
    }
    return 0;
}
struct conejo liberaMemoriaS(struct conejo **c)
{
    free(*c);
    (*c)==NULL;
}

//Apartado 4
float **reservaMemoriaM(int fil, int col)
{
    float **m=NULL;
    m= (float**)malloc(sizeof(float*)*fil);
    if (m==NULL)
    {
        printf("Error al reservar memoria \n");
        exit(-1);
    }
    for (int i = 0; i < fil; i++)
    {
        m[i]=NULL;
        m[i]=(float*)malloc(sizeof(float)*col);
        if (m[i]==NULL)
        {
            printf("Error al reservar memoria \n");
            exit (-1);
        }  
    }
    return m;    
}
void rellenaMatriz(float **m, int fil, int col)
{   
    int cont=0;
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cont=i+1;
            printf("Introduzca el valor %d para la matriz \n", cont);
            scanf("%f", &m[i][j]);
            printf("\n");
        }
        
    }  
}
void muestraMatriz(float **m, int fil, int col)
{   
    int cont=0;
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cont=i+1;
            printf("Valor %d ---> %f \n", cont, m[i][j]);
            printf("\n");
        }   
    }
}
void mediaDiagonalPrin_Matriz(float **m, int fil, int col, float *mediaDiagMat)
{  
    float suma=0; 
    for (int i = 0; i < fil; i++)
    {
        suma+=m[i][i];    
    }
    (*mediaDiagMat)=suma/fil;
}
void liberaMemoriaM(float ***m, int fil)
{
    for (int i = 0; i < fil; i++)
    {
        free((*m)[i]);
    }
    free(*m);
    (*m)=NULL;
}       