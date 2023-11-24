#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
int main(int argc, char **argv)
{
    if (argc!=2)
    {
        printf("Error linea de argumentos \n");
        exit(-1);
    }
    
    char *nombreFichero=argv[1];

    struct fraccion*v=NULL;
    int tam= contarRegistro(nombreFichero);
    v= reservaMemoria(tam);
    
    fichero_A_vector(nombreFichero, v);
    
    mostrarVector(v, tam);
    vector_A_fichero("fracciones2.txt", v, tam); //vector a fichero
    mostrarFichero(nombreFichero);

    liberaMemoria(&v);
    

    return 0;
}

/*

TAREA PARA SEMANA SANTA

struct alumno
{
    char dni[10];
    int curso;
    float nota;
};

EL TXT:

1234A 1 7.5
7680F 1 4.75
6912W 2 10
7793D 2 2.15

ENUNCIADOS:

1) void mostrarFichero(char *nF);
2) void addAlumno(char *nF, struct alumno a);
3) int buscarAlumno(char *nF, char *dni);
4) void mediaNotas(char *nF, float *media)
5) void contarRegistros(char *nF);
6) void modificarNota(char *nF, char *dni, float nota);
7) int borrarAlumno(char *nF, char *dni);
8) void alumnoMaximaNota(char *nF, struct alumno *a);
9) void fichero_A_vector(char *nF, struct alumno *v);
10) void vector_A_fichero(char *nF, struct alumno *v, int tam);
11) void minMaxNota(struct alumno *v, int tam, float *min, float *max);
12) void aprobadosSuspensos(char *nF, int *aprobados, int *suspensos);

*/