#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int main(int argc, char **argv)
{
    if (argc!=2)
    {
        printf("Error, introduzca en linea de argumentos el nombre del fichero \n");
        exit(-1);
    }
    char *nF=argv[1];
    struct alumno *a=NULL; //Creamos vector
    
//Mostramos el fichero
    mostrarFichero(nF);
    printf("\n");

//Añadimos alumnos y lo mostramos por pantalla
    int na; //numero de alumnos que quiera añadir el usuario
    printf("Introduzca el numero de alumnos que desea agregar \n");
    scanf("%d", &na);

    struct alumno add; //variable referencia a los datos del alumno

    for (int i = 0; i < na; i++)
    {   
        printf("Ponga el DNI del alumno \n");
        scanf("%s", add.dni);

        printf("Ponga el curso del alumno \n");
        scanf("%d", &add.curso);

        printf("Ponga la nota del alumno \n");
        scanf("%f", &add.nota);

        addAlumno(nF, add);
    }
    mostrarFichero(nF);
    printf("\n");

//Buscamos el alumno por su DNI
    char dni[10]; //DNI de referencia
    printf("Introduzca el DNI del alumno para buscarlo \n");
    scanf("%s", dni);
    int busqueda;
    busqueda= buscarAlumno(nF, dni);

    if (busqueda==1)
    {
        printf("Alumno encontrado \n");
    }
    else
    {
        printf("Alumno no encontrado \n");
    }
    printf("\n");

//Funcion que muestra cuantos alumnos hay
    int tam=contarRegistros(nF);
    printf("El numero de alumnos es de: %d \n", tam);
    printf("\n");
 
//Hacemos la media de las notas (la he hecho sin usar la variable tam)
    float media;
    mediaNotas(nF, &media); //invoca la funcion
    printf("La media de las notas de los alumnos es de: %f \n", media);
    printf("\n");

//Modifica el fichero
    printf("DNI para modificar la nota del alumno que desee \n");
    scanf("%s", dni);
        
    float nota; //Nota referencia
    printf("Introduzca la nueva nota: \n");
    scanf("%f", &nota);
    printf("\n");
    
    modificarNota(nF, dni, nota);    
    
    mostrarFichero(nF);
    printf("\n");

//Borramos el alumno
    printf("DNI del alumno que desea eliminar: \n");
    scanf("%s", dni);
    printf("\n");

    int borrados;
    borrados=borrarAlumno(nF, dni);
    if (borrados==1)
    {
        mostrarFichero(nF);
    }
    else
    {
        printf("No hay alumnos para eliminar \n");
    }
    printf("\n");

//Reservamos memoria del vector
    struct alumno m;
    //m=reservaMem(1);

//Alumno de maxima nota
    alumnoMaximaNota(nF, &m);
    printf("El alumno con maxima nota es --> %s ; del curso --> %d ; con nota --> %f \n", m.dni, m.curso, m.nota);
    printf("\n");

//Libera memoria
    //liberaMem(&m);

//Fichero a vector
    a=reservaMem(tam);
    fichero_A_vector(nF, a);

//Vector a fichero
    vector_A_fichero(nF, a, tam);     
    
//Minima y maxima nota
    float min, max;
    minMaxNota(a, tam, &min, &max);
    printf("La maxima nota es de %f , la menor nota es de %f \n", max, min);
    printf("\n");

//Aprobados y suspensos
    int aprobados, suspensos;
    aprobadosSuspensos(nF, &aprobados, &suspensos);
    printf("Hay -->  %d alumnos aprobados y hay %d alumnos suspensos \n", aprobados, suspensos);
    
//Libera memoria    
    liberaMem(&a);
    
    return 0;
}
