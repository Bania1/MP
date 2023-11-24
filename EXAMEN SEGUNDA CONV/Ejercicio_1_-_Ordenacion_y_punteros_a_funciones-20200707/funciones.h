#ifndef EXAMEN
#define EXAMEN

#define LENGTH 100
struct nomina
{
   int codigo; //Identificador unico para cada empleado
   char nombre[LENGTH];
   float retenciones; //ej. 15.13    
   float salarioBruto; //ej. 2548.5
};

void ejercicio1(int nEle, struct nomina* Vector, int criterio);

//INCLUYE AQUI LOS PROTOTIPOS DE TUS FUNCIONES


#endif
