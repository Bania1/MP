#ifndef FUNCION_H
#define FUNCION_H

struct fraccion
{
    int num;
    int den;
};
void mostrarFichero( char *nombreFichero);
int contarRegistros(char *nombreFichero);
int addFraccion(char *nombreFichero, struct fraccion f1);
int buscarFraccion(char *nombreFichero, struct fraccion f1);
void modificarFichero(char* nombreFichero, struct fraccion f);
void borrarFraccion(char* nombreFichero, struct fraccion f2);
void fichero_A_vector(char *nombreFichero, struct fraccion *v);
void vector_A_fichero(char *nombreFichero, struct fraccion *v, int tam);
/*
-r "No lo crea" osea lee
-w y -a --> "Si lo crea" escriben
*/
#endif