#include <stdio.h>
#include <stdlib.h>
#include "funcionMicro.h"

 int main(int argc, char const *argv[])
{
    if (argc!=3)
    {
        printf("Error introduzca el numero de filas y columnas para el apartado 4 \n");
        exit (-1);
    }
    int fil= atoi(argv[1]);
    int col= atoi(argv[2]);
    
    float **m=NULL;
    float a,b;
    float media, mediaDiagMat;
    int *v=NULL, tam;
    int numc, codigo, busqueda;
    struct conejo *c=NULL;
    
//Apartado 1
    printf("Introduce un valor para a y b \n");
    scanf("%f",&a);
    scanf("%f",&b);

    cambiaValor(&a, &b);
    printf("a --->  %f \n",a);
    printf("b --->  %f \n",b);
    printf("\n");
    printf("\n");

//Apartado 2
    printf("Introduzca el numero de elementos del vector \n");
    scanf("%d",&tam);
    printf("\n");

    v=reservaMemoriaV(tam);
    
    leeV(v, tam);
    printf("\n");
    
    imprimeV(v,tam);
    printf("\n");

    mediaV(v,tam,&media);
    printf("La media de los valores del vector es de --> %f \n", media);
    printf("\n");

    liberaMemoriaV(&v);

//Apartado 3
    printf("Introduzca el numero de conejos \n");
    scanf("%d",&numc);
    printf("\n");

    c=reservaMemoriaS(numc);

    rellenarVector(c, numc);
    printf("\n");

    mostrarVector(c, numc);
    printf("\n");

    printf("Introduzca el codigo del conejo \n");
    scanf("%d", &codigo);
    printf("\n");

    busqueda= buscarConejo(c, numc, codigo);
    if(busqueda==1)
    {
        printf("Conejo encontrado! \n");
    }
    if (busqueda!=1)
    {
        printf("Conejo  NO encontrado \n");
    }
    printf("\n");

    liberaMemoriaS(&c);

//Apartado 4
    m= reservaMemoriaM(fil, col);

    rellenaMatriz(m, fil, col);

    muestraMatriz(m, fil, col);

    mediaDiagonalPrin_Matriz(m, fil, col, &mediaDiagMat);
    
    printf("La media de la diagonal principal es de --> %f \n", mediaDiagMat);

    liberaMemoriaM(&m, fil);
    return 0;
}