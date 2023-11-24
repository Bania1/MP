#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

//ABRIR FICHERO
void mostrarFichero( char *nombreFichero)
{
    FILE *fich= fopen(nombreFichero, "r");
    if (fich==NULL)
    {
        printf("Error al abrir el fichero \n");
        exit(-1);
    }
//PROCESAR
    int num, den;
    while (fscanf(fich, "%d / %d ", &num, &den)==2)
    {
        printf("%d / %d \n", num, den);
    }
//CERRAR
    fclose(fich);
}
int contarRegistros(char *nombreFichero)
{
    FILE *fich= fopen(nombreFichero, "r");
    if(fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    int num, den, cont=0;
    while(fscanf(fich, "%d / %d ", &num, &den)==2)
    {
        cont++;
    }
    fclose(fich);
    return cont;
}
//Con struct
int contarRegistros(char *nombreFichero, struct fraccion f1)
{
    FILE *fich= fopen(nombreFichero, "r");
    if(fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    struct fraccion f2;

    while(fscanf(fich, "%d / %d ", &num, &den)==2)
    {
        if((f1.num/f1.den)==(f2.num/f2.den))
        {

        }
    }
    fclose(fich);
    return cont;
}

int addFraccion(char *nombreFichero, struct fraccion f1)
{
    FILE *fich= fopen(nombreFichero, "a");
    if(fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    fprintf(fich, "%d / %d \n", f.num, f.den);

    fclose(fich);
}
//Buscar fraccion
int buscarFraccion(char *nombreFichero, struct fraccion f1)
{
    FILE *fich= fopen(nombreFichero, "r");
    if (fich==NULL)
    {
        printf("Error");
        exit(-1);
    }
    struct fraccion f2;
    
    while (fscanf(fich, "%d / %d ",&f2.num, &f2.den)==2)
    {
        if((f1.num/f1.den)==(f2.num/f2.den))
        {
            fclose(fich);
            return 1;
        }
    }
    fclose(fich);
    return 0;    
}
//Modificar


/* 
1) abro el fichero original en modo lectura
2) abro el fichero auxiliar en modo escritura
3) recorro el fichero original
4) escribo cada dato leido (modificado si hay que modificarlo) en el fichero
   auxiliar
5) cierro ambos ficheros
6) borro el fichero original
7) renombro el fichero auxiliar
*/

void modificarFichero(char* nombreFichero, struct fraccion f)
{
    FILE *fich1= fopen(nombreFichero, "r");
    if(fich1==NULL)
    {
        printf("Error");
        exit(-1);
    }
    FILE *fich2= fopen("auxiliar.txt", "w");
    if(fich2==NULL)
    {
        printf("Error");
        fclose(fich1);
        exit(-1);
    }
    struct fraccion f;
    while(fscanf(fich1, "%d / %d ", &num, &den)==2)
    {
        if(f,num%2==0)
        {
            f.num++;
        }
        fprintf(fich2, "%d / %d ", f.num, f,den);
    }
    fclose(fich1);
    fclose(fich2);
    remove(nombreFichero);
    rename("auxiliar,txt", nombreFichero);
}
//Para borrar la fraccion es como la funcion de modificar
void borrarFraccion(char* nombreFichero, struct fraccion f2)
{
    FILE *fich1= fopen(nombreFichero, "r");
    if(fich1==NULL)
    {
        printf("Error");
        exit(-1);
    }
    FILE *fich2= fopen("auxiliar.txt", "w");
    if(fich2==NULL)
    {
        printf("Error");
        fclose(fich1);
        exit(-1);
    }
    //Empezamos a modificar
    struct fraccion f1;
    while(fscanf(fich1, "%d / %d ", &num, &den)==2)
    {
        if(f1.num!=f2.num || f1.den!=f2.den)
        {
            fprintf(fich2, " %d / %d ", f1.num, f1.den);
        }
    }
    fclose(fich1);
    fclose(fich2);
    remove(nombreFichero);
    rename("auxiliar,txt", nombreFichero);
}

//version 1 de fichero a vector
void fichero_A_vector(char *nombreFichero, struct fraccion *v)
{
    FILE *fich=fopen(nombreFichero, "r");
    if(fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    int i=0;
    struct fraccion f;
    while(fscanf(fich, "%d / %d ", &f.num, &f.den)==2)
    {
        v[i]=f;
        i++;
    }
    fclose(fich);
}

//version pro xD
void fichero_A_vector(char *nombreFichero, struct fraccion *v)
{
    FILE *fich=fopen(nombreFichero, "r");
    if(fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }

    int i=0;

    while(fscanf(fich, "%d / %d ", &v[i].num, &v[i].den)==2)
    {
        i++;
    }
    fclose(fich);
}

void vector_A_fichero(char *nombreFichero, struct fraccion *v, int tam)
{
    FILE *fich= fopen(nombreFichero, "r");
    if(fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    
    }
    for(int i=0; i < tam; i++)
    {
        fprintf(fich, "%d / %d \n", v[i].num, v[i].den);
    }
    fclose(fich);    
}