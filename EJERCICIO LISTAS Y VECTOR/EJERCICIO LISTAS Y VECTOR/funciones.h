#ifndef FUNCIONES_H
#define FUNCIONES_H

struct dato
{
    int codigo;
    float peso;
};

struct lista
{
    struct dato elemento;
    struct lista * siguiente;
};

int ejercicio(struct dato * VECTOR, int NUMELEMENTOS, struct lista ** LISTA, float limite);

//COMPLETA AQUÍ CON EL PROTOTIPO DE LAS FUNCIONES QUE HAYAS CREADO
void insertarDelante(struct lista **LISTA, struct dato elemento);
int contarElementos(struct lista *LISTA);
void vector_a_lista(struct lista ** LISTA,struct dato *VECTOR,int NUMELEMENTOS,float limite);
struct lista *nuevoElemento();
#endif