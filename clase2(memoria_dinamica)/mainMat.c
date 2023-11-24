#include <stdio.h>
#include <stdlib.h>
#include "funcionMat.h"

int main()
{
//Primero declaro las variables
    float **m=NULL;
    int *v=NULL;
    int fila,col;
    int res;
    int mayor, menores;
    int dato;
    float mediaa;

//Pido por teclado numero de filas y columnas
    printf("Introduzca el numero de filas \n");
    scanf("%d", &fila);
    printf("Introduzca el numero de columnas\n");
    scanf("%d", &col);
    printf("\n");

//RESERVA MEMORIA
    m= reservaMemoria(fila, col);
    
//Rellena la matriz
    rellenarMatriz(m, fila, col);

//Muestra la matriz
    mostrarMatriz(m, fila, col);
    printf("\n");

//Hace la media de la matriz
    mediaa= mediaMatriz(m, fila, col);
    printf("La media de la matriz es de --> %f \n", mediaa);
    printf("\n");

//Buscar el dato
    printf("Introduzca el dato que desea encontrar \n");
    scanf("%d", &dato);
    printf("\n");

    res= buscarDato(m, fila, col, dato);
    if(res==1)
    {
        printf("Se ha encontrado el dato \n");
    }
    if(res!=1)
    {
        printf("Dato no encontrado \n");
    }
    printf("\n");

//Busca el valor mas grande
    buscarMayorElem(m, fila, col, &mayor);
    printf("El mayor elemento de la matriz es --> %d \n", mayor);
    printf("\n");

//Buscamos el menor elemento de la fila y RESERVAMOS MEMORIA
    v=reservaMemoriaV(fila);

    menoresFilas(m, fila, col, &menores);
    printf("El menor elemento de la fila es --> %d \n", menores);
    
//LIBERAMOS MEMORIA
    liberaMemoria(&m, fila);
    liberaMemoriaV(&v);
    return 0;

}
