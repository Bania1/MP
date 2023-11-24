/**
	@file main.c
	@brief Programa principal del ejercicio de alumnos
	@author Academia Main()
*/

#include <stdio.h>
#include "funciones.h"

int main()
{
	/*
	struct alumno a;
	Alumno b;

	printf("Introduce un nombre: ");
	scanf("%s",b.nombre); //cuando es una cadena no se pone &
	printf("Introduce la nota: ");
	scanf("%f",&b.nota);


	printf("El alumno b se llama %s y tiene una nota de %.3f\n",b.nombre,b.nota);
	*/

	Alumno * v = NULL;
	int tam;

	printf("Introduzca el numero de alumnos: ");
	scanf("%d",&tam);

	v = reservaMemoria(tam);

	printf("Procedemos a rellenar el vector...\n");
	rellenarVector(v,tam);

	printf("Procedemos a mostrar el vector...\n");
	mostrarAlumno(v,tam);

	printf("Procedemos a calcular la media de las notas por referencia...\n");
	float media;
	mediaNotas(v,tam,&media);
	printf("La media de las notas de los alumnos es %f\n",media);

	liberarMemoria(&v);

	return 0;
}