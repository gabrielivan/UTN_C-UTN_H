#include "Venta.h"
#include "LinkedList.h"
//#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
*\brief Reserva espacio en memoria para un elemento
*\param void
*\return Retorna el elemento si reserva memoria sino NULL
*/
Venta* Venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    if(this!=NULL)
    {
        return this;
    }
    else
    {
        return NULL;
    }

}

/**
*\brief Libera espacio en memoria ocupado por elemento
*\param this Es el elemento a liberar
*\return Retorna 0 si logra liberar sino retorna -1
*/

int Venta_delete(Venta* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/**
 * \brief Asigna el espacio de memoria para la creacion de un venta con todos sus atributos cargados,
 *        y verifica que sean correctos antes de crear la nueva venta.
 * \return Venta* En caso de exito retorna el puntero a la venta, si no NULL
 *
 */

Venta* Venta_newConParametros(char* idVenta,char* fecha,char* codigoProducto,char* cantidad,char* precioUnitario,char* cuitCliente)//lee desde el archivo
{
    Venta* this;
    this = Venta_new();
    int idVentaInt;
    int cantidadInt;
    float precioUnitarioInt;
    char codigoProductoAux[1024];
    char cuitClienteAux[1024];
    char fechaAux[1024];

    if(EsEntero(idVenta,1024)&& EsEntero(cantidad,1024) && EsFloat(precioUnitario,1024) && EsCuit(cuitCliente,1024) && EsAlfaNumerico(codigoProducto,1024) && EsFecha(fecha))
    {
        idVentaInt = atoi(idVenta);
        cantidadInt = atoi(cantidad);
        precioUnitarioInt = atof(precioUnitario);
        strcpy(codigoProductoAux,codigoProducto);
        strcpy(cuitClienteAux,cuitCliente);
        strcpy(fechaAux,fecha);

        if(
        !Venta_setId(this,idVentaInt)&&
        !Venta_setCodigoProducto(this,codigoProductoAux)&&
        !Venta_setCantidad(this,cantidadInt)&&
        !Venta_setPrecioUnitario(this,precioUnitarioInt)&&
        !Venta_setCuitCliente(this,cuitClienteAux)&&
        !Venta_setFecha(this,fechaAux))
            return this;
    }
    else
    {
        printf(" \nVENTA NO VALIDA: \n");
        printf("\n ID: %s\n ",idVenta);
        printf("CANTIDAD: %s\n ",cantidad);
        printf("PRECIO: %s\n ",precioUnitario);
        printf("CODIGO PRODUCTO: %s\n ",codigoProducto);
        printf("CUIT DEL CLIENTE: %s\n ",cuitCliente);
        printf("FECHA: %s\n ",fecha);
        printf("\n\n");

    }

    Venta_delete(this);
    return NULL;
}

/**
*\brief Se setea el ID del elemento
*\param this Es el elemento
*\param id Es el ID para setear
*\return Retorna 0 si setea sino -1
*/

int Venta_setId(Venta* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->idVenta=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->idVenta=proximoId;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el ID del elemento
*\param this Es el elemento
*\param id Es el ID que se obtiene
*\return Retorna 0 si obtiene sino retorna -1
*/

int Venta_getId(Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}

/**
*\brief setea el codigo producto del elemento
*\param this Es el elemento
*\param codigo producto Es el codigo producto para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Venta_setCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=0;
    }
    return retorno;
}

/**
*\brief obtiene el codigo producto del elemento
*\param this Es el elemento
*\param codigo producto Es el codigo producto a obtener
*\return Retorna 0 si se obtiene el elemento, sino retorna -1
*/

int Venta_getCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(codigoProducto,this->codigoProducto);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea la cantidad del elemento
*\param this Es el elemento
*\param cantidad Es la cantidad de horas para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Venta_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtienen la cantidad del elemento
*\param this Es el elemento
*\param cantidad Es la cantidad que se obtiene
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea el precio unitario del elemento
*\param this Es el elemento
*\param precio unitario Es el precio unitario para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

float Venta_setPrecioUnitario(Venta* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el precio unitario del elemento
*\param this Es el elemento
*\param precio unitario Es el precio unitario que se obtiene
*\return Retorna 0 si setea elemento sino retorna -1
*/

float Venta_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se muestran los datos de todos los campos del elemento
*\param pVenta Es el puntero al elemento
*\return Retorna 0 si el elemento es diferente a NULL sino retorna -1
*/

int Venta_mostrar(void* pVenta)
{
    int retorno = -1;
    int auxIdVenta;
    int auxCantidad;
    float auxPrecioUnitario;
    char auxCodigoProducto[128];
    char auxCuit[128];
    char auxFecha[128];

    if(pVenta != NULL)
    {
        Venta_getId(pVenta,&auxIdVenta);
        if(auxIdVenta != -1)
        {
            Venta_getCodigoProducto(pVenta,auxCodigoProducto);
            Venta_getCantidad(pVenta,&auxCantidad);
            Venta_getPrecioUnitario(pVenta,&auxPrecioUnitario);
            Venta_getId(pVenta,&auxIdVenta);
            Venta_getFecha(pVenta,auxFecha);
            Venta_getCuitCliente(pVenta,auxCuit);

            printf("\n ID: %d\n ",auxIdVenta);
            printf("Codigo Producto: %s\n ",auxCodigoProducto);
            printf("Precio Unitario: %f\n ",auxPrecioUnitario);
            printf("Cantidad: %d\n ",auxCantidad);
            printf("CUIT : %s\n ",auxCuit);
            printf("FECHA: %s\n  ",auxFecha);
            retorno = 0;
        }
    }
    return retorno;
}

/**
*\brief Se obtienen todos los campos del elemento
*\param this Venta* Es el elemento
*\return Retorna 0 si obtienen todos los elementos sino retorna -1
*/

int Venta_getAll(Venta* this,char* codigoProducto,char* cuitCliente,char* fecha,int* cantidad,float* precioUnitario,int* idVenta)
{
    int retorno = -1;

    if(this != NULL)
    {
        Venta_getCodigoProducto(this,codigoProducto);
        Venta_getCuitCliente(this,cuitCliente);
        Venta_getCantidad(this,cantidad);
        Venta_getPrecioUnitario(this,precioUnitario);
        Venta_getId(this,idVenta);
        Venta_getFecha(this,fecha);
        retorno = 0;
    }
    return retorno;
}

/**
*\brief Se setea el cuit del cliente del elemento
*\param this Es el elemento
*\param cuitCliente Es el cuit del cliente a setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Venta_setCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(this->cuitCliente,cuitCliente);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el cuit del cliente del elemento
*\param this Es el elemento
*\param cuitCliente Es el cuit del cliente a obtener
*\return Retorna 0 si obtiene el elemento sino retorna -1
*/

int Venta_getCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(cuitCliente,this->cuitCliente);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea la fecha del elemento
*\param this Es el elemento
*\param fecha es la fecha a setear
*\return Retorna 0 si setea el elemento sino retorna -1
*/

int Venta_setFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene la fecha del elemento
*\param this Es el elemento
*\param fecha es la fecha a obtener
*\return Retorna 0 si obtiene el elemento sino retorna -1
*/

int Venta_getFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=0;
    }
    return retorno;
}

///********************************FUNCIONES CRITERIO*************************************************


/**
 * \brief Filtra la cantidad de ventas que el precio unitario es mayor a 10000
 * \param this void* Es la venta que se le calcula el precio unitario mayor a 10000
 * \return 0 En caso de que no filtro,sino retorna la cantidad de ventas que el precio unitario es mayor a 10000
 *
 */

int Venta_Mayor(void* this)
{
    int retorno = 0;
    float auxPrecio;
    int auxCantidad;
    int contadorCantidad = 0;

    Venta_getPrecioUnitario(this,&auxPrecio);
    Venta_getCantidad(this,&auxCantidad);

    if(this != NULL)
    {
        if(auxPrecio*auxCantidad > 10000)
        {
            contadorCantidad = contadorCantidad + 1;
            retorno = contadorCantidad;
        }
    }
    return retorno;
}

/**
 * \brief Filtra la cantidad de ventas que el precio unitario es mayor a 20000
 * \param this void* Es la venta que se le calcula el precio unitario mayor a 20000
 * \return 0 En caso de que no filtro,sino retorna la cantidad de ventas que el precio unitario es mayor a 20000
 *
 */

int Venta_MayorMas(void* this)
{
    int retorno = 0;
    float auxPrecio;
    int auxCantidad;
    int contadorCantidad = 0;

    Venta_getPrecioUnitario(this,&auxPrecio);
    Venta_getCantidad(this,&auxCantidad);

    if(this != NULL)
    {
        if(auxPrecio*auxCantidad > 20000)
        {
            contadorCantidad = contadorCantidad + 1;
            retorno = contadorCantidad;
        }
    }
    return retorno;
}

/**
 * \brief cuenta la cantidad de unidades total por venta
 * \param this void* Es la venta que se le cuenta la cantidad de unidades total
 * \return 0 En caso de que no conto nada,sino retorna la cantidad de unidades total
 *
 */

int Venta_cantidadUnidadesTotal(void* this)
{
    int retorno = 0;
    int auxCantidad;
    int contadorCantidad = 0;

    Venta_getCantidad(this,&auxCantidad);

    if(this != NULL)
    {
        contadorCantidad = contadorCantidad + auxCantidad;
        retorno = contadorCantidad;
    }
    return retorno;
}

/**
 * \brief cuenta la cantidad de unidades por venta que su codigo producto es de tipo LCD_TV
 * \param this void* Es la venta que se le cuenta la cantidad de unidades que su codigo producto es de tipo LCD_TV
 * \return 0 En caso de que no conto nada,sino retorna la cantidad
 *
 */

int Venta_cantidadTvLcd(void* this)
{
    int retorno = 0;
    char auxTvLcd[1024];
    int auxCantidad;
    int contadorTvLcd = 0;

    Venta_getCodigoProducto(this,auxTvLcd);
    Venta_getCantidad(this,&auxCantidad);

    if(this != NULL)
    {
        if(strcmp(auxTvLcd,"LCD_TV")== 0)
        {
            contadorTvLcd = contadorTvLcd + auxCantidad;
            retorno = contadorTvLcd;
        }
    }

    return retorno;
}

///****************************FIN DE LAS FUNCIONES CRITERIO*****************************************************
