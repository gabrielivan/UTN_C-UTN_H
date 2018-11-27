//#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"
#include "informes.h"
#include "utn.h"


/**
*\brief informa la cantidad de unidades vendidas totales
*\param listaVentas Es el puntero  a la lista
*\return Retorna 0 en caso de error sino,retorna la cantidad de unidades vendidas totales.
*/

int informe_cantidadTotal(LinkedList* listaVentas)
{
    int retorno = 0;
    int resultadoCount;

    if(listaVentas != NULL)
    {
        resultadoCount = ll_count(listaVentas,Venta_cantidadUnidadesTotal);
        retorno = resultadoCount;
    }

    return retorno;
}

/**
*\brief informa la cantidad de ventas que el precio unitario es mayor a 10000
*\param listaVentas Es el puntero  a la lista
*\return Retorna 0 en caso de error sino,retorna la cantidad de ventas que el precio unitario es mayor a 10000.
*/

int informe_cantidadMontoMayor(LinkedList* listaVentas)
{
    int retorno = 0;
    int resultadoCount;

    if(listaVentas != NULL)
    {
        resultadoCount = ll_count(listaVentas,Venta_Mayor);
        retorno = resultadoCount;
    }

    return retorno;
}

/**
*\brief informa la cantidad de ventas que el precio unitario es mayor a 20000
*\param listaVentas Es el puntero  a la lista
*\return Retorna 0 en caso de error sino,retorna la cantidad de ventas que el precio unitario es mayor a 20000.
*/


int informe_cantidadMontoMayorMas(LinkedList* listaVentas)
{
    int retorno = 0;
    int resultadoCount;

    if(listaVentas != NULL)
    {
        resultadoCount = ll_count(listaVentas,Venta_MayorMas);
        retorno = resultadoCount;
    }

    return retorno;
}

/**
*\brief informa la cantidad de unidades de tipo LCD_TV vendidas
*\param listaVentas Es el puntero  a la lista
*\return Retorna 0 en caso de error sino,retorna la cantidad de unidades de tipo LCD_TV vendidas
*/

int informe_cantidadLcdTV(LinkedList* listaVentas)
{
    int retorno = 0;
    int resultadoCount;

    if(listaVentas != NULL)
    {
        resultadoCount = ll_count(listaVentas,Venta_cantidadTvLcd);
        retorno = resultadoCount;
    }

    return retorno;
}
