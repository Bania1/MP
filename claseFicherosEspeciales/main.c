#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char **argv)
{
    if (argc=!2)
    {
        printf("Error al ejecutar, introduzca todos los txt \n");
        exit(-1);
    }
    char *nF=argv[1];
    printf("\n");
//Mostramos el fichero
    mostrarFichero(nF);
    printf("\n");
    printf("\n");

//Buscamos el producto por su codigo
    char codigo[10];
    printf("Introduzca el codigo para encontrar el producto \n");
    scanf("%s", codigo);

    int busqueda=buscarCodigo(nF, codigo);

    if (busqueda!=1)
    {
        printf("Producto no encontrado \n");
        printf("\n");
    }
    else
    {
        printf("Producto encontrado \n");
        printf("\n");
    }
    printf("\n");
    
//Buscamos el producto y ponemos cantidades a vender
    printf("Introduzca el codigo del producto a vender \n");
    scanf("%s", codigo);

    int unidades;
    printf("Numero de unidades a vender: \n");
    scanf("%d", &unidades);

    vender(nF, codigo, unidades); //Vendemos
    printf("\n");
    printf("\n");
    
    mostrarFichero(nF); //Mostramos fichero
    printf("\n");    
    printf("\n");

//Añadimos producto
    int np; //numero de productos
    struct producto add; //struct del producto
    printf("Introduzca el numero de productos que desea agregar \n");
    scanf("%d", &np);

    for (int i = 0; i < np; i++)
    {
        printf("Introduzca el nombre del producto \n");
        scanf("%s", add.nombre);

        printf("Introduzca el codigo del producto \n");
        scanf("%s", add.codigo);

        printf("Introduzca el precio del producto \n");
        scanf("%f", &add.precio);

        printf("Introduzca las unidades del producto \n");
        scanf("%d", &add.unidades);

        addp(nF, add); 
    }
    printf("\n");
    mostrarFichero(nF);
    printf("\n");
    printf("\n");
    
//Borramos producto
    printf("Introduzca el codigo del producto que desea borrar: \n");
    scanf("%s", codigo);

    int borrados=borrarp(nF, codigo);
    if (borrados==1)
    {
        mostrarFichero(nF);
    }
    else
    {
        printf("Producto no encontrado \n");
    }
    printf("\n");

//Contamos cuantos productos hay
    int pr=contarProductos(nF);
    printf("La cantidad de productos es de %d \n", pr);    
    printf("\n");

//Reserva memoria
    struct producto *v=NULL;
    v=reservaMem(pr);

//Fichero a vector
    fichero_a_vector(nF, v);

//Vector a fichero
    vector_a_fichero(nF, v, pr);

//Libera memoria
    liberaMem(&v);

    return 0;
}
