//#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Venta.h"
#include "Parser.h"
#include "utn.h"



/** \brief Carga los datos de las ventas desde el archivo data.csv (modo texto).
 * \param path char* ruta del archivo
 * \param listaVenta LinkedList* lista donde se va a guardar el archivo
 * \return [0] Exito y [-1] Error
 */

int controller_loadFromText(char* path , LinkedList* listaVenta)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo,listaVenta))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de las ventas en el archivo data.csv (modo texto).
 * \param path char* ruta del archivo
 * \param listaVenta LinkedList* lista que se va a guardar
 * \return [0] Exito y [-1] Error
 */

int controller_saveAsText(char* path , LinkedList* listaVenta)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,listaVenta))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Lista las Ventas
 * \param listaVentas Es la LinkedList del cual se desea listar las Ventas
 * \return retorna 0 si la LinkedList es diferente a NULL sino retorna -1
 *
 */
int controller_ListarEmpleados(LinkedList* listaVentas)
{
    int retorno = -1;
    int i;
    int auxIdVenta;
    int auxCantidad;
    float auxPrecioUnitario;
    char auxCodigoProducto[128];
    char auxCuit[128];
    char auxFecha[128];
    Venta* auxPunteroVenta;

    if(listaVentas != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(listaVentas);i++)
        {
            auxPunteroVenta = ll_get(listaVentas,i);

            Venta_getCodigoProducto(auxPunteroVenta,auxCodigoProducto);
            Venta_getCantidad(auxPunteroVenta,&auxCantidad);
            Venta_getPrecioUnitario(auxPunteroVenta,&auxPrecioUnitario);
            Venta_getId(auxPunteroVenta,&auxIdVenta);
            Venta_getFecha(auxPunteroVenta,auxFecha);
            Venta_getCuitCliente(auxPunteroVenta,auxCuit);

            printf("\n ID: %d\n ",auxIdVenta);
            printf("Codigo Producto: %s\n ",auxCodigoProducto);
            printf("Precio Unitario: %f\n ",auxPrecioUnitario);
            printf("Cantidad: %d\n ",auxCantidad);
            printf("CUIT : %s\n ",auxCuit);
            printf("FECHA: %s\n  ",auxFecha);
            printf("\n");
        }
    }
    return retorno;
}
