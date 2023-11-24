//En este fichero indicaremos la funcion main y los include de los ficheros.h
// los ficheros.h ademas de las librerias que utilicen
#include "funciones.h"
#include <stdio.h>
int main()
{
saluda();
int a,b;
printf("introduce a:");
scanf("%d", &a);
printf("introduce b:");
scanf("%d", &b);

float res= media(a, b);
printf("la media es %f.\n", res);
    return 0;
}