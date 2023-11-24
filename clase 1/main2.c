#include "funciones.h"
#include <stdio.h>
int main()
{
saluda();
int a,b;
printf("introduce a:");
scanf("%d", &a);
printf("introduce b:");
scanf("%d", &b);

float res;
media(a, b, &res);
printf("la media es %f.\n", res);
    return 0;
}