#include "funcionMem.h"
#include <stdio.h>
int main()
{
    int *v=NULL;
    int tam;
    
    printf("Introduce el tamaño: \n");
    scanf("%d", &tam);
    v= reservaMemoria(tam);
    rellenaVector(v, tam);
    mostrarVector(v, tam);
    liberarMemoria(&v);
   
}