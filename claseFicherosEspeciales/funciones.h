#ifndef FUNCIONES_H
#define FUNCIONES_H

struct producto
{
char nombre[200];
char codigo[10];
float precio;
int unidades;
};

void mostrarFichero(char *nF); 
int buscarCodigo(char *nF, char *producto);
void vender(char *nF, char *codigo, int unidades);
void addp(char *nF, struct producto add);
int borrarp(char *nF, char *codigo);
int contarProductos(char *nF);
struct producto *reservaMem(int pr);
void fichero_a_vector(char *nF, struct producto *v);
void vector_a_fichero(char *nF, struct producto *v, int pr);
void liberaMem(struct producto **v);

#endif