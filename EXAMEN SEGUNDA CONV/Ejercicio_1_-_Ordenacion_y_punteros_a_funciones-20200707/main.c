#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


struct nomina* reservarVector(int nEle);
int imprimirVector(int nEle, struct nomina* Vector);
void rellenarVector(int nEle, struct nomina * Vector);
int comprobarOrdenacion(int nEle, struct nomina* Vector, int* ordenCodigos, char* ordenNombres[]);

int main()
{
   struct nomina * Vector;
   int nEle = 6;
   char opcion;   
   int orden=0;  
   float pesoExamen=0.3;
   int valorExamen=10;
   float acumulada = 0;
   float puntosOrdenacionA=1.25;
   float puntosOrdenacionD=1.25;
   float puntosPteroFuncion=2; 
   float totalEjercicio = puntosOrdenacionA+puntosOrdenacionD+puntosPteroFuncion;
  
   Vector  = reservarVector(nEle); 
   rellenarVector(nEle, Vector);   
   
   printf("\n\n-----------------------------");
   printf("\nPUNTUACION DEL EJERCICIO 1: ORDENACION Y PUNTEROS A FUNCIONES");
   printf("\n\t\tordenacion ascendente %.3f puntos\n\t\tordenacion descendente: %.3f puntos\n\t\tpunteros a funciones: %.3f puntos", puntosOrdenacionA, puntosOrdenacionD, puntosPteroFuncion);
   printf("\n\tTOTAL EJERCICIO (sobre 10): %.3f puntos", totalEjercicio);
   printf("\n\tTOTAL NOTA FINAL(sobre 3) : %.3f puntos", pesoExamen*totalEjercicio);   
   printf("\n\nSi el programa funciona correctamente te dara \nla puntuacion obtenida al terminar la ejecucion");   
   printf("\n-----------------------------");
   
   printf("\nEl ejercicio se esta evaluando...");    
   printf("\n\nVector relleno SIN ORDENAR: ");
   imprimirVector(nEle, Vector);
   ejercicio1(nEle, Vector, 0);  
   printf("\n\nVector ORDENADO ascendentemente por SALARIO NETO: ");
   imprimirVector(nEle, Vector);   
   int ordenCodigosA[]={4,9,3,8,1,7};
   char* ordenNombresA[]={"persona1", "persona7", "persona8", "persona3", "persona9", "persona4"};
   if(comprobarOrdenacion(nEle, Vector, ordenCodigosA, ordenNombresA)==0)
   {
       printf("\n\n\tINCORRECTO: puntuacion obtenida en ordenacion ascendente: %.3f puntos", 0.0);
   }
   else
   {
       acumulada+=puntosOrdenacionA;
       orden=1;
       printf("\n\n\tCORRECTO: puntuacion obtenida en ordenacion ascendente: %.3f puntos", puntosOrdenacionA);
   }
   printf("\n\tACUMULADA: %.3f/%d", acumulada, valorExamen);  

   ejercicio1(nEle, Vector, 1);  
   printf("\n\nVector ORDENADO descendentemente por NOMBRE: ");
   imprimirVector(nEle, Vector);  
   int ordenCodigosD[]={9,8,7,4,3,1};
   char* ordenNombresD[]={"persona9", "persona8", "persona7", "persona4", "persona3", "persona1"};    
   if(comprobarOrdenacion(nEle, Vector, ordenCodigosD, ordenNombresD)==0)
   {
       printf("\n\n\tINCORRECTO: puntuacion obtenida en ordenacion descendente: %.3f puntos", 0.0);
   }
   else
   {
       acumulada+=puntosOrdenacionD;
       orden=1;
       printf("\n\n\tCORRECTO: puntuacion obtenida en ordenacion descendente: %.3f puntos", puntosOrdenacionD);
   }       
   printf("\n\tACUMULADA: %.3f/%d", acumulada, valorExamen);    
 
   if(orden)
   {       
       printf("\n\nPREGUNTA: Tu funcion de ordenacion acepta como parametro un puntero a una funcion de comparacion?");
       printf("\nO has utilizado el quicksort de C?");
       printf("\n\tRESPUESTA (S|N): ");
       scanf("%c", &opcion);
       getchar();
       if((opcion=='S')||(opcion=='s')) 
       {         
          acumulada+=puntosPteroFuncion;
          printf("\n\tCORRECTO: Puntuacion obtenida en punteros a funciones: %.3f puntos", puntosPteroFuncion);
       }
       else
       {
          printf("\n\tINCORRECTO: Puntuacion obtenida en punteros a funciones: %.3f puntos", 0.0); 
       }           
   }
   else
   {
      printf("\n\tINCORRECTO: Puntuacion obtenida en punteros a funciones: %.3f puntos", 0.0); 
   }
   
   printf("\n\tACUMULADA: %.3f/%d", acumulada, valorExamen);    
  
   printf("\n\n-----------------------------");
   printf("\nEJERCICIO 1: NOTA OBTENIDA");
   printf("\n\tEVALUACION EJERCICIO (sobre 10): %.3f puntos", acumulada);
   printf("\n\tTOTAL NOTA FINAL (sobre 3) : %.3f puntos", pesoExamen*acumulada);   
   printf("\n\tLa calificacion es PROVISIONAL y deber ser validada por la profesora");   
   printf("\n-----------------------------");   
   
   return 0;    
}


struct nomina* reservarVector(int nEle)
{   
    struct nomina * Vector = (struct nomina*) malloc (nEle*sizeof(struct nomina));
    return Vector;  
}
int imprimirVector(int nEle, struct nomina * Vector)
{
  
  int i;
  for(i=0; i<nEle; i++)
  {
   printf("\n\t----Vector[%d]----", i);
   printf("\tNombre: <%s>",  Vector[i].nombre);
   printf("\tCodigo: %3d",  Vector[i].codigo);             
   printf("\tRetenciones: %3.2f",  Vector[i].retenciones);  
   printf("\tS. bruto: %3.2f", Vector[i].salarioBruto);
   printf("\tS. neto: %3.2f", Vector[i].salarioBruto - Vector[i].salarioBruto*(Vector[i].retenciones/100.0));   
 }  
  
 return 1;
   
}
void rellenarVector(int nEle, struct nomina * Vector)
{
    Vector[0].codigo = 8;
    Vector[1].codigo = 3;      
    Vector[2].codigo = 7;
    Vector[3].codigo = 9;      
    Vector[4].codigo = 1;
    Vector[5].codigo = 4;
          
    Vector[0].salarioBruto = 2142.85;
    Vector[1].salarioBruto = 1835.9;      
    Vector[2].salarioBruto = 2548.5;
    Vector[3].salarioBruto = 1624.3;      
    Vector[4].salarioBruto = 2698.35;
    Vector[5].salarioBruto = 1398.4;
    
    Vector[0].retenciones = 14.92;
    Vector[1].retenciones = 13.98;      
    Vector[2].retenciones = 15.13;
    Vector[3].retenciones = 12.11;      
    Vector[4].retenciones = 19.97;
    Vector[5].retenciones = 11.86;     

    strcpy(Vector[0].nombre, "empleado8");
    strcpy(Vector[1].nombre, "empleado3");
    strcpy(Vector[2].nombre, "empleado7");
    strcpy(Vector[3].nombre, "empleado9");
    strcpy(Vector[4].nombre, "empleado1");
    strcpy(Vector[5].nombre, "empleado4");
}

int comprobarOrdenacion(int nEle, struct nomina* Vector, int* ordenCodigos, char* ordenNombres[])
{
    int correcto=1;
    
    if((Vector[0].codigo !=ordenCodigos[0] )&& strcmp(Vector[0].nombre, ordenNombres[0]))
      correcto=0;        
    if((Vector[1].codigo !=ordenCodigos[1] )&& strcmp(Vector[1].nombre, ordenNombres[1]))
      correcto=0;   
    if((Vector[2].codigo !=ordenCodigos[2] )&& strcmp(Vector[2].nombre, ordenNombres[2]))
      correcto=0;         
    if((Vector[3].codigo !=ordenCodigos[3] )&& strcmp(Vector[3].nombre, ordenNombres[3]))
      correcto=0;
    if((Vector[4].codigo !=ordenCodigos[4] )&& strcmp(Vector[4].nombre, ordenNombres[4]))
      correcto=0;   
    if((Vector[5].codigo !=ordenCodigos[5] )&& strcmp(Vector[5].nombre, ordenNombres[5]))
      correcto=0;   
     
    return correcto;                      
}


