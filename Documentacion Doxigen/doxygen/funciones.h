/**
	@file funciones.h
	@brief Fichero donde se encuentra los prototipos de las funciones y estructuras
	@author Academia Main()
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H

/** Definición de la estructura alumno*/
struct alumno
{
	char nombre[100]; /**< Nombre del alumno */
	float nota; /**< Nota del alumno */
};

typedef struct alumno Alumno;

Alumno * reservaMemoria(int tam);

void rellenarVector(Alumno * v,int tam);

void mostrarAlumno(Alumno * v,int tam);

void liberarMemoria(Alumno * * v);

/**
	@fn	void mediaNotas(Alumno * v,int tam,float * media);
	@brief	Función que calcula la media de las notas de un vector de alumnos por referencia.
	@param	Parámetro 1: Vector de alumnos
	@param 	Parámetro 2: Tamaño del vector de alumnos
	@param	Parámetro 3: Variable recibida por referencia donde guardaré la media.
	@return	Esta función no retorna nada por valor.
	@warning	El tamaño del vector debe ser mayor o igual cero
	@attention	Esto es un aviso
*/
void mediaNotas(Alumno * v,int tam,float * media);

#endif
