#include <stdio.h>
#include "funciont2.h"
int main()
{
    int *v=NULL;
    int tam;
    int res,max,min,n;
    printf("Introduzca el numero de elementos \n");
    scanf("%d",&tam);
    
    v= reservaMemoria(tam);
    
    rellenaVector(v, tam);
    
    mostrarVector(v, tam);
    
    printf("Introduzca el dato a buscar \n");
    scanf("%d",&n);
    res= buscarDato(v,tam,n);
    
    if(res==1)
    {
        printf("Se ha encontrado el dato \n");
    }
    if(res!=1)
    {
        printf("Dato no encontrado \n");
    }

    buscarMayorMenor(v,tam,&max,&min);
    printf("%d ---> es maximo \n",max);
    printf("%d ---> es minimo \n",min);

    liberarMemoria(&v);
    return 0;
    

}