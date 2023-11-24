#ifndef FUNCIONES_H
#define FUNCIONES_H

struct alumno
{
    char dni[10];
    int curso;
    float nota;
};
void mostrarFichero(char *nF);
void addAlumno(char *nF, struct alumno a);
int buscarAlumno(char *nF, char *dni);
void mediaNotas(char *nF, float *media);
struct alumno *reservaMem(int tam);
void liberaMem(struct alumno **m);
int contarRegistros(char *nF);
void modificarNota(char *nF, char *dni, float nota);
int borrarAlumno(char *nF, char *dni);
void alumnoMaximaNota(char *nF, struct alumno *a);
void fichero_A_vector(char *nF, struct alumno *v);
void vector_A_fichero(char *nF, struct alumno *v, int tam);
void minMaxNota(struct alumno *v, int tam, float *min, float *max);
void aprobadosSuspensos(char *nF, int *aprobados, int *suspensos);


#endif