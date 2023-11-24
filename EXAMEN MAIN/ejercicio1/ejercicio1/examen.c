/*------------------------------------------------------------------*/
/* NOMBRE Y APELLIDOS:    se compila gcc main.c examen.c funciones.o                                          */
/* DNI:                                                             */
/*------------------------------------------------------------------*/
#include "funciones.h"
#include "examen.h"

/*------------------------------------------------------------------*/
//HAZ AQUI LOS INCLUDE QUE CONSIDERES NECESARIOS
/*------------------------------------------------------------------*/


/*------------------------------------------------------------------*/
/*Apartado1:
	nEle: número de elementos del vector. Devuelto POR REFERENCIA, hay que calcular su valor.
	nombreFichAlumnos: Nombre del fichero de alumnos.
	nombreFichNotas: Nombre del fichero de notas.
	VALOR DEVUELTO: Vector de struct alumno que debes reservar y rellenar con los datos de los ficheros.
*/
/*------------------------------------------------------------------*/
struct alumno* apartado1(int* nEle, char* nombreFichAlumnos, char* nombreFichNotas)
{

  //INCLUYE AQUI EL CODIGO NECESARIO PARA RESOLVER EL EJERCICIO
	struct alumno *v=NULL;
	(*nEle)=tam(nombreFichNotas);
	printf("tam = %d\n",*nEle);
	v=reservaMem(*nEle);
	ficheros_a_vector(nombreFichAlumnos, nombreFichNotas, v, nEle);
	
  //NO TE OLVIDES DE HACER EL RETURN
  //NI DE DEVOLVER POR REFERENCIA EL NUMERO DE ELEMENTOS DEL VECTOR
  	return v;
}

/*------------------------------------------------------------------*/
/*Apartado2:
	nEle: número de elementos del vector.
	Vector: Vector ya creado y relleno con los datos de alumnos.
	nombreFichResultado: Nombre del fichero resultado.

*/
/*------------------------------------------------------------------*/
void apartado2(int nEle, struct alumno* Vector, char* nombreFichResultado)
{
     //INCLUYE AQUI EL CODIGO NECESARIO PARA RESOLVER EL EJERCICIO
	vector_a_fichero(nombreFichResultado, Vector, nEle);
}

/*------------------------------------------------------------------*/
//ESCRIBE AQUI TODAS LAS FUNCIONES QUE CONSIDERES NECESARIAS
struct alumno *reservaMem(int tam)
{
	struct alumno *v=NULL;
	v=(struct alumno *)malloc(sizeof(struct alumno)*tam);
	if (v==NULL)
	{
		printf("Error en reserva memoria\n");
		exit(-1);
	}
	return v;
}
void ficheros_a_vector(char *nf1, char *nf2, struct alumno *v, int *nEle)
{
	FILE *fich1=fopen(nf1, "r");
	if (fich1==NULL)
	{
		printf("fichero1 vacio\n");
		exit(-1);
	}
	FILE *fich2=fopen(nf2, "r");
	if (fich2==NULL)
	{
		printf("fichero2 vacio\n");
		exit(-1);
		fclose(fich1);
	}
	struct alumno a;
	int i=0;
	float nota1, nota2, nota3;

	while (fgets(a.nombre, sizeof(struct alumno), fich1))
	{
		a.nombre[strlen(a.nombre)-1]='\0';
		fscanf(fich1, "%ld\n", &a.dni);

		fscanf(fich2, "%ld %f %f %f", &a.dni, &nota1, &nota2, &nota3);
		a.media=(nota1+nota2+nota3)/3;//hacemos la media de las notas
		v[i]=a;//pasamos la informacion al vector
		i++;
	}
	fclose(fich1);
	fclose(fich2);
}
void vector_a_fichero(char *nf, struct alumno *v, int tam)
{
	FILE *fich=fopen(nf, "w");
	if (fich==NULL)
	{
		printf("mal el vector a fich\n");
		exit(-1);
	}
	
	for (int i = 0; i < tam; i++)
	{
		fprintf(fich, "%s %ld %f\n", v[i].nombre, v[i].dni, v[i].media);
	}
	fclose(fich);
}
int tam(char *nf)
{
	FILE *fich=fopen(nf, "r");
	if (fich==NULL)
	{
		printf("Error al tamano\n");
		exit(-1);
	}
	struct alumno a;
	float n1, n2, n3;
	int cont=0;
	while (fscanf(fich, "%ld %f %f %f\n", &a.dni, &n1, &n2, &n3)==4)
	{
		cont++;
	}
	fclose(fich);
	return cont;
}
/*------------------------------------------------------------------*/
