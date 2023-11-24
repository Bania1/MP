/* Ficheros especiales:

--> 1 fichero:

EJEMPLO:
Fichero de personas el cual en su campo tiene peso, edad y nombre

Pepe Macias
19 72.3400

--> Las 2 lineas son una persona

Dentro de un while para cagarse la linea se usa fgets

struct persona
{
    char nombre[200];
    int edad;
    float peso;
};

struct persona p;
while(fgets(p.nombre, 200, fich))
{
    *
    fscanf(fich, "%d %f \n", &p.edad, &p.peso);

}
fclose(fich);     

--> 2 ficheros:

EJEMPLO:
Fichero de personas y otro de grupos de asignaturas

-- alumnos.txt

Pablo Castillo
Paco Arroyo
Nacho Sanchez
Jose De Dios

-- grupos.txt

Metodologia de la programacion
Programacion y administracion de sistemas
Estructuras de datos
Estructuras de datos

void unirFicheros(char *nF1, char *nF2, char *nF3)
{
    //ABRIR

    FILE *fich1=fopen(nF1, "r"); // alumnos.txt
    if(fich1==NULL)
    {
        printf("Error \n");
        exit(-1);
    }
    FILE *fich2=fopen(nF2, "r"); // grupos.txt
    if(fich2==NULL)
    {
        printf("Error \n");
        fclose(fich1);
        exit(-1);
    }
    FILE *fich3=fopen(nF3, "w"); // Donde se une
    if(fich3==NULL)
    {
        printf("Error \n");
        fclose(fich1);
        fclose(fich2);
        exit(-1);
    }

    //PROCESAR
    
    char nombre[200];
    char grupo[400];

    while(fgets(nombre, 200, fich1))
    {
        nombre[strlen(nombre)-1]= '\0';

        fgets(grupo, 400, fich2);

        grupo[strlen(grupo)-1]= '\0';

        fprintf(fich3, "%s\n %s\n", nombre, grupo);
    }

    //CERRAR

    fclose(fich1);
    fclose(fich2);
    fclose(fich3);
}
*/

Para 1 fichero:

Siempre que tengamos un fgets y despues fscanf, en el ultimo fscanf hay que poner:
un (\n) que sino peta

linea 20 de arriba

(Funcion que muestra el fichero)
-----------------
struct persona p;
while(fgets(p.nombre, 200, fich))
{
    (*) En los printfs, para las cadenas se usa \0 para el fin de cadena
    con una funcion strcmp no se va a poder comparar
    se pone: 
    -->  p.nombre[strlen(p.nombre)-1]= '\0'

    fscanf(fich, "%d %f \n", &p.edad, &p.peso);

    printf("Nombre: %s \n", p.nombre);
    printf("Edad : %d \n", p.edad);
}
fclose(fich);