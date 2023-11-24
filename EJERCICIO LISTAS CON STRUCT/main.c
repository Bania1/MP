#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{

    struct alumno a1 = {"alumno1", 20,6.8};
    struct alumno a2 = {"alumno2", 25,10};
    struct alumno a3 = {"alumno3", 34,8};
    struct alumno a4 = {"alumno4", 10,4};

    struct nodo * cabeza = NULL;

    insertarDelante(&cabeza,a1);
    insertarDelante(&cabeza,a2);
    insertarDetras(&cabeza,a3);
    insertarDetras(&cabeza,a4);

    printf("MOSTRAR LISTA:\n");
    mostrarLista(cabeza);

    int tam = contarElementos(cabeza);
    printf("En la lista hay %d elementos.\n",tam);

    printf("BUSCAR DATO EN LA LISTA:\n");
    int encontrado = buscarAlumno(cabeza,"alumno1");
    if(encontrado==1)
    {
        printf("El alumno1 se encuentra en la lista.\n");
    }
    else{
        printf("El alumno1 no se encuentra en la lista.\n");
    }

    encontrado = buscarAlumno(cabeza,"alumno6");
    if(encontrado==1)
    {
        printf("El alumno6 se encuentra en la lista.\n");
    }
    else{
        printf("El alumno6 no se encuentra en la lista.\n");
    }

    printf("BORRAR LISTA\n");
    borrarLista(&cabeza);
}