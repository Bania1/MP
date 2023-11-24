#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

//Mostramos el fichero
void mostrarFichero(char *nF)
{
    FILE *fich=fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error, no se puede abrir el fichero \n");
        exit(-1);
    }
    struct alumno A;

    while (fscanf(fich, "%s %d %f \n", A.dni, &A.curso, &A.nota)==3)
    {
        printf("%s %d %f \n", A.dni, A.curso, A.nota);
    }
    fclose(fich);
    printf("\n");
}
//Añadimos alumnos
void addAlumno(char *nF, struct alumno add)
{
    FILE *fich=fopen(nF, "a");
    if (fich==NULL)
    {
        printf("Error, no se puede abrir el fichero \n");
        exit(-1);
    }
    fprintf(fich,"%s %d %f \n", add.dni, add.curso, add.nota);
    fclose(fich);
}
//Buscamos el alumno en el fichero
int buscarAlumno(char *nF, char *dni)
{
    FILE *fich=fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error, no se puede abrir el fichero \n");
        exit(-1);
    }
    struct alumno a;
    while (fscanf(fich, "%s %d %f \n", a.dni, &a.curso, &a.nota)==3)
    {
        if (strcmp(dni, a.dni)==0)
        {
            fclose(fich);
            return 1;
            
        }        
    }
    fclose(fich);
    return 0;
}
//Reserva memoria del struct
int contarRegistros(char *nF)
{
    struct alumno a;
    FILE *fich=fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    int cont=0;
    while (fscanf(fich, "%s %d %f \n", a.dni, &a.curso, &a.nota)==3)
    {
       cont++; 
    }
    fclose(fich);
    return cont;
}
struct alumno *reservaMem(int tam)
{
    struct alumno *a=NULL;
    a=(struct alumno*)malloc(sizeof(struct alumno)*tam);
    if (a==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    return a;
}
void mediaNotas(char *nF, float *media)
{
    FILE *fich=fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    struct alumno a;
    float suma=0;
    float cont=0;
    while (fscanf(fich, "%s %d %f \n", a.dni, &a.curso, &a.nota)==3)
    {
        suma=suma+a.nota;     
        cont++;
    }
    (*media)=suma/cont; //cont es el numero de alumnos
    fclose(fich);
}
void modificarNota(char *nF, char *dni, float nota)
{
    FILE *fich1= fopen(nF, "r");
    if (fich1==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    FILE *fich2= fopen("aux.txt", "w");   
    if (fich2==NULL)
    {
        printf("Error \n");
        fclose(fich1);
        exit(-1);
    }
    struct alumno a;
    while (fscanf(fich1,"%s %d %f \n", a.dni, &a.curso, &a.nota)==3)
    {
        if (strcmp(dni, a.dni)==0)
        {
            a.nota=nota;
        }
        fprintf(fich2, "%s %d %f \n", a.dni, a.curso, a.nota);
    }
    fclose(fich1);
    fclose(fich2);
    remove(nF);
    rename("aux.txt", nF);
}
void liberaMem(struct alumno **m)
{
    free(*m);
    (*m)=NULL;
}
int borrarAlumno(char *nF, char *dni)
{
    FILE *fich1= fopen(nF, "r");
    if (fich1==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    FILE *fich2= fopen("aux.txt", "w");   
    if (fich2==NULL)
    {
        printf("Error \n");
        fclose(fich1);
        exit(-1);
    }
    struct alumno a;
    int borrados=0; //Si encuentra 1 es que lo elimina
    while (fscanf(fich1,"%s %d %f", a.dni, &a.curso, &a.nota)==3)
    {
        if (strcmp(dni, a.dni)!=0)
        {
            fprintf(fich2, "%s %d %f \n", a.dni, a.curso, a.nota);
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
void alumnoMaximaNota(char *nF, struct alumno *a)
{
    FILE *fich=fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    struct alumno b;
    fscanf(fich, "%s %d %f \n", b.dni, &b.curso, &b.nota);
    (*a) =b;
    while (fscanf(fich, "%s %d %f \n", b.dni, &b.curso, &b.nota)==3)
    {
        if (b.nota>a->nota)
        {
            (*a)=b;
        }
    }
    fclose(fich);
}
void fichero_A_vector(char *nF, struct alumno *v)
{
    FILE *fich= fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error");
        exit(-1);
    }
    int i=0;
    while (fscanf(fich, "%s %d %f \n", v[i].dni, &v[i].curso, &v[i].nota)==3)
    {
        i++;
    }
    fclose(fich);  
}
void vector_A_fichero(char *nF, struct alumno *v, int tam)
{
    FILE *fich= fopen(nF, "w");
    if (fich==NULL)
    {
        printf("Error\n");
        exit(-1);
    }
    for (int i = 0; i < tam; i++)
    {
        fprintf(fich, "%s %d %f \n", v[i].dni, v[i].curso, v[i].nota);
    }
    fclose(fich);
}
void minMaxNota(struct alumno *v, int tam, float *min, float *max)
{
    (*min)=v[0].nota;
    (*max)=v[0].nota;
    for (int i = 0; i < tam; i++)
    {
        if ((*max)<v[i].nota)
        {
            (*max)=v[i].nota;
        }
        if ((*min)>v[i].nota)
        {
            (*min)=v[i].nota;
        }  
    }
}
void aprobadosSuspensos(char *nF, int *aprobados, int *suspensos)
{
    FILE *fich= fopen(nF, "r");
    if (fich==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    struct alumno a;
    (*aprobados)=0;
    (*suspensos)=0;
    while (fscanf(fich, "%s %d %f \n", a.dni, &a.curso, &a.nota)==3)
    {
        if (a.nota>=5)
        {
            (*aprobados)++;
        }
        else
        {
            (*suspensos)++;
        }
    }
    fclose(fich);
}