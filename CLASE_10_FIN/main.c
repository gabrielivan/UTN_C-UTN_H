#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"
#include "contrataciones.h"

#define PANTALLAS 5
#define CONTRATACIONES 5


int main()
{
    Pantalla arrayPantallas[PANTALLAS];
    Contratacion arrayContrataciones[CONTRATACIONES];
    char cuitIngresado[14];

   //ABM DE PANTALLA
    pantalla_alta(arrayPantallas,PANTALLAS);

    //pantalla_modificar(arrayPantallas,PANTALLAS);

    //pantalla_baja(arrayPantallas,PANTALLAS);

   //TERMINA EL ABM DE PANTALLA

   //ABM DE CONTRATACIONES

    contratacion_alta(arrayContrataciones,arrayPantallas,CONTRATACIONES,PANTALLAS);

    //contratacion_modificar(arrayContrataciones,CONTRATACIONES,cuitIngresado,arrayPantallas,PANTALLAS);//tiene un error.

    //contratacion_baja(arrayContrataciones,CONTRATACIONES,cuitIngresado,arrayPantallas,PANTALLAS);//tiene un error.

    return 0;
}






