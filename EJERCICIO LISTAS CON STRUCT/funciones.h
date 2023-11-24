#ifndef FUNCIONES_H
#define FUNCIONES_H

struct alumno
{
    char nombre[100];
    int edad;
    float nota;
};

struct nodo
{
    struct alumno dato;
    struct nodo * sig;
};

struct nodo * nuevoElemento();
void insertarDelante(struct nodo **cabeza,struct alumno dato);
void insertarDetras(struct nodo **cabeza,struct alumno dato);
void mostrarLista(struct nodo * cabeza);
int contarElementos(struct nodo * cabeza);
int buscarAlumno(struct nodo *cabeza, char * nombre);
void borrarLista(struct nodo **cabeza);


#endif