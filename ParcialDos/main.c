//#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Venta.h"
#include "utn.h"
#include "Parser.h"
#include "informes.h"

/****************************************************
    Menu:
    01. Cargar archivo.
    02. Guardar archivo.
    03. Listar ventas.
    04. mostrar informes.
    05. Salir.
*****************************************************/

int main()
{
    LinkedList* listaVenta = ll_newLinkedList();
    int option;
    int CantidadUnidadesVendidasTotales;
    int CantidadDeVentasPorUnMontoMayorDiez;
    int CantidadDeVentasPorUnMontoMayorVeinte;
    int CantidadDeTvLcdVendidas;

    do
    {
        utn_getNumero(&option, "\n 01-Cargar archivo(data.csv)\n 02-Generar informe(Informe.txt)\n 03-Listar Ventas\n 04-Mostrar informes\n 05-Salir\n","Ingrese un numero valido\n",1,5,1);
        switch(option)
        {
        case 1:
            if(!controller_loadFromText("data.csv",listaVenta))
            {
                printf("\nDatos cargados correctamente\n");
            }
            else
            {
                printf("No se puedo cargar el archivo!\n");
            }
            getchar();
            limpiarPantalla();
            break;
        case 2:
            if(!controller_saveAsText("informes.txt",listaVenta))
            {
                printf("\nArchivo generado correctamente.");
            }
            else
            {
                printf("\nNo se pudo generar el archivo\n");
            }
            getchar();
            limpiarPantalla();
            break;
        case 3:
            if(ll_isEmpty(listaVenta))
            {
                printf("No se puede listar el vacio!");
            }
            else if(ll_isEmpty(listaVenta)== 0)
            {
                controller_ListarEmpleados(listaVenta);
            }
            else
            {
                printf("Error al listar!");
            }
            getchar();
            limpiarPantalla();
            break;
        case 4:
            if(ll_isEmpty(listaVenta))
            {
                printf("No se puede listar el vacio!");
            }
            else if(ll_isEmpty(listaVenta)== 0)
            {
                CantidadDeTvLcdVendidas = informe_cantidadLcdTV(listaVenta);
                CantidadDeVentasPorUnMontoMayorDiez = informe_cantidadMontoMayor(listaVenta);
                CantidadDeVentasPorUnMontoMayorVeinte = informe_cantidadMontoMayorMas(listaVenta);
                CantidadUnidadesVendidasTotales = informe_cantidadTotal(listaVenta);

                printf("**************INFORMES*********************\n");
                printf("\n CantidadDeTvLcdVendidas: %d\n ",CantidadDeTvLcdVendidas);
                printf("CantidadDeVentasPorUnMontoMayorDiez %d\n ",CantidadDeVentasPorUnMontoMayorDiez);
                printf("CantidadDeVentasPorUnMontoMayorVeinte %d\n ",CantidadDeVentasPorUnMontoMayorVeinte);
                printf("CantidadUnidadesVendidasTotales %d\n ",CantidadUnidadesVendidasTotales);
                printf("\n\n*********************************************\n");
            }
            else
            {
                printf("Error al listar!");
            }
            getchar();
            limpiarPantalla();
            break;
        }
    }
    while(option != 5);

    return 0;
}
