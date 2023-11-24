#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

//Mostramos fichero
void mostrarFichero(char *nF)
{
    FILE *fich=fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    struct producto a;
    while (fgets(a.nombre, 200, fich))
    {
        a.nombre[strlen(a.nombre)-1]='\0';

        fscanf(fich, "%s %f", a.codigo, &a.precio);
        fscanf(fich, "%d\n", &a.unidades);

        printf("%s \n", a.nombre);
        printf("%s %f \n", a.codigo, a.precio);
        printf("%d \n", a.unidades);
    }
    fclose(fich);
}

//Busca el codigo
int buscarCodigo(char *nF, char *codigo)
{
    FILE *fich=fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    int busqueda=0;
    struct producto a;
    while (fgets(a.nombre, 200, fich))
    {
        a.nombre[strlen(a.nombre)-1]='\0';
        fscanf(fich, "%s %f", a.codigo, &a.precio);
        fscanf(fich, "%d \n", &a.unidades);

        if (strcmp(codigo, a.codigo)==0)
        {
            fclose(fich);
            return 1;
        } 
    }
    fclose(fich);
    return 0;
}

//Vende unidades
void vender(char *nF, char *codigo, int unidades)
{
    FILE *fich1=fopen(nF, "r");
    if (fich1==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    FILE *fich2=fopen("aux.txt", "w");
    if (fich2==NULL)
    {
        printf("Error \n");
        fclose(fich1);
        exit(-1);
    }
    struct producto a;
    while (fgets(a.nombre, 200, fich1))
    {
        a.nombre[strlen(a.nombre)-1]='\0';
        fscanf(fich1, "%s %f", a.codigo, &a.precio);
        fscanf(fich1, "%d \n", &a.unidades);
        
        if (strcmp(codigo, a.codigo)==0)
        {
           if (unidades > a.unidades)
            {
                printf("Unidades no disponibles \n");
                fclose(fich1);
                exit(-1);
            }
            else
            {
                a.unidades= a.unidades-unidades;
            }
        }        
        fprintf(fich2, "%s\n%s %f\n%d\n", a.nombre, a.codigo, a.precio, a.unidades);
    }
    fclose(fich1);
    fclose(fich2);
    remove(nF);
    rename("aux.txt", nF);
}

//Añade productos
void addp(char *nF, struct producto add)
{
    FILE *fich=fopen(nF, "a");
    if (fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    fprintf(fich, "%s\n%s %f\n%d\n", add.nombre, add.codigo, add.precio, add.unidades);
    fclose(fich);
}

//Borrar alumno
int borrarp(char *nF, char *codigo)
{
    FILE *fich1=fopen(nF, "r");
    if (fich1==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    FILE *fich2=fopen("aux.txt", "w");
    if (fich2==NULL)
    {
        printf("Error \n");
        exit(-1);
    }

    struct producto a;
    int borrados=0; //Si devuelve 1 lo elimina
    
    while (fgets(a.nombre, 200, fich1))
    {
        a.nombre[strlen(a.nombre)-1]='\0';
        fscanf(fich1, "%s %f", a.codigo, &a.precio);
        fscanf(fich1, "%d\n", &a.unidades);

        if (strcmp(codigo, a.codigo)!=0)
        {
            fprintf(fich2, "%s\n%s %f\n%d\n", a.nombre, a.codigo, a.precio, a.unidades);
        }
        else
        {
            borrados=1;
        }
        
    }
    fclose(fich1);
    fclose(fich2);
    remove(nF);
    rename("aux.txt", nF);
    
    return borrados;
}

//Contar productos
int contarProductos(char *nF)
{
    FILE *fich=fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    struct producto a;
    int cont=0;
    while (fgets(a.nombre, 200, fich))
    {
        a.nombre[strlen(a.nombre)-1]='\0';
        fscanf(fich, "%s %f", a.codigo, &a.precio);
        fscanf(fich, "%d\n", &a.unidades);
        cont++;
    }
    fclose(fich);
    return cont;
}

//Reserva memoria
struct producto *reservaMem(int pr)
{
    struct producto *v=NULL;
    v=(struct producto*)malloc(sizeof(struct producto)*pr);
    if (v==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    return v;
}

//Libera memoria
void liberaMem(struct producto **v)
{
    free(*v);
    (*v)=NULL;
}

//De fichero a vector
void fichero_a_vector(char *nF, struct producto *v)
{
    FILE *fich=fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    int i=0;
    struct producto a;
    while (fgets(a.nombre, 200, fich))
    {
        a.nombre[strlen(a.nombre)-1]='\0';
        fscanf(fich, "%s %f", a.codigo, &a.precio);
        fscanf(fich, "%d\n", &a.unidades);

        v[i]=a;
        i++;
    }
    fclose(fich);
}

//De vector a fichero
void vector_a_fichero(char *nF, struct producto *v, int pr)
{
     FILE *fich=fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    for (int i = 0; i < pr; i++)
    {
        fprintf(fich, "%s\n%s %f\n%d\n", v[i].nombre, v[i].codigo, v[i].precio, v[i].unidades);
    }
    fclose(fich);
}