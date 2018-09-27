#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}


static int getLugarLibre(Pantalla* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int pantalla_init(Pantalla* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            array[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

Pantalla* pantalla_getById(Pantalla* array, int len,int id)
{
    Pantalla* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].id == id)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}

int pantalla_alta(Pantalla* array, int len)
{
    int retorno = -1;
    int indice;

    char nombre[50];
    char direccion[200];
    float precio;
    int tipo;

    indice = getLugarLibre(array,len);

    if( array != NULL && len > 0 &&
        indice >= 0 && indice < len
        && array[indice].isEmpty)
    {
        if( !utn_getNumero(&tipo,"1- cargar LCD \n2- cargar LED","Error, ingrese una opcion valida",1,2,2) &&
            !utn_getNombre(nombre,50,"Nombre pantalla?\n","nombre no valido\n",2) &&
            !utn_getDescription(direccion,200,"Direccion pantalla?\n","direccion no valida\n",2)&&
            !utn_getNumeroConComa(&precio,"ingrese el precio","Error reingrese el precio",0,10000,2))
        {
            array[indice].tipo = tipo;
            strncpy(array[indice].nombre,nombre,50);
            strncpy(array[indice].direccion,direccion,200);
            array[indice].precio = precio;
            array[indice].isEmpty = 0;
            array[indice].id = getNextId();
            retorno = 0;
        }
    }
    return retorno;
}

int pantalla_modificar(Pantalla* array, int len)
{
    Pantalla* pantalla;//pantalla a modificar
    char auxNombre[50];
    char auxDireccion[200];
    float auxPrecio;
    int tipo;
    int idIngresado;
    int retorno = -1;

    if(utn_getNumero(&idIngresado,"Ingrese el ID de la pantalla a modificar","Error ingrese un ID valido!",0,10000,2) == -1)
    {
        return retorno;
    }
    pantalla = pantalla_getById(array,len,idIngresado);
    if(pantalla != NULL)
    {
        if(array != NULL && len > 0 &&
        !pantalla->isEmpty)
        {
              if(!utn_getNumero(&tipo,"1- tipo LCD \n2- tipo LED","Error, ingrese una opcion valida",1,2,2) &&
                 !utn_getNombre(auxNombre,50,"\n Ingrese el nuevo nombre: ","\n Error,nombre invalido.",2)&&
                 !utn_getDescription(auxDireccion,200,"Ingrese la nueva direccion","Error direccion invalida",2)&&
                 !utn_getNumeroConComa(&auxPrecio,"\n Ingrese el nuevo precio: ","\n Error,precio invalido.",0,10000,2))
             {
                pantalla->tipo = tipo;
                strncpy(pantalla->nombre,auxNombre,50);
                strncpy(pantalla->direccion,auxDireccion,200);
                pantalla->precio = auxPrecio;

                retorno = 0;
             }

        }
    }
    return retorno;
}

int pantalla_baja(Pantalla* array, int len)
{
     Pantalla* pantalla;//pantalla a borrar
    int retorno = -1;
    int idIngresado;

  if(utn_getNumero(&idIngresado,"Ingrese el ID de la pantalla a borrar","Error ingrese un ID valido!",0,10000,2) == -1)
    {
        return retorno;
    }
    pantalla = pantalla_getById(array,len,idIngresado);
    if(pantalla != NULL)
    {
        if(array != NULL && len > 0 &&
            pantalla->isEmpty == 0)
        {
            pantalla->isEmpty = 1;

            retorno = 0;
        }
        else
        {
            printf("\nNo hay pantalla.");
        }
    }
    return retorno;
}

//int pantalla_mostrar(Pantalla* array, int len)
//{
//    Pantalla* pantalla;//pantalla a borrar
//    int retorno = -1;
//    int indice;
//    int auxNumero;
//
//    if(utn_getNumero(&idIngresado,"Ingrese el ID de la pantalla a mostrar","Error ingrese un ID valido!",0,10000,2) == -1)
//    {
//        return retorno;
//    }
//    pantalla = pantalla_getById(array,len,idIngresado);
//    if(pantalla != NULL)
//    {
//
//        if(array != NULL && len > 0 )
//        {
//            printf("\n El nombre de la pantalla es: %s",pantalla->nombre);
//            if(pantalla->tipo == 1)
//                printf("\n La pantalla es tipo LCD");
//            else
//                printf("\n La pantalla es tipo LED");
//
//            printf("\n La direccion del pantalla es: %s",pantalla->direccion);
//            printf("\n El precio de la pantalla es: %.2f",pantalla->precio);
//            printf("\n\n");
//
//            retorno = 0;
//        }
//        fflush(stdin);
//        //__fpurge(stdin);
//    }
//    return retorno;
//}
//
//void pantalla_ordenar(Pantalla* array, int len)
//{
//    int aux;
//	for(int i = 0; i < len -1; i++)
//    {
//        for(int j = i + 1; j < len; j++)
//        {
//            if(array[i].precio > array[j].precio)
//            {
//                aux = array[i];
//                array[i] = array[j];
//                array[j] = aux;
//            }
//        }
//    }
//}

