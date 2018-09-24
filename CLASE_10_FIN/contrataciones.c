#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "producto.h"
#include "contrataciones.h"


static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}

static int getLugarLibre(Contratacion* array, int len)
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


int contratacion_init(Contratacion* array, int len)
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

Contratacion* contratacion_getById(Contratacion* array, int len,int id)
{
    Contratacion* retorno = NULL;
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

int contratacion_alta(Contratacion* array, int len)
{
    int retorno = -1;
    int indice;
    int cuit;
    int dias;
    char nombreVideo[100];

    indice = getLugarLibre(array,len);

    if( array != NULL && len > 0 &&
        indice >= 0 && indice < len
        && array[indice].isEmpty)
    {
        if( !utn_getNombre(nombreVideo,100,"Nombre contratacion?\n","nombre no valido\n",2) &&
            !utn_getNumero(&dias,"ingrese el dia","Error reingrese el dia",1,31,2))
        {
            strncpy(array[indice].nombreVideo,nombreVideo,100);
            array[indice].dias = dias;
            array[indice].isEmpty = 0;
            array[indice].id = getNextId();
            retorno = 0;
        }
    }
    return retorno;
}


int contratacion_modificar(Contratacion* array, int len)
{
    char auxNombreVideo[100];
    int auxDias;
    int indice;
    int cuit;
    int retorno = -1;
    int auxNumero;

    indice = utn_getNumero(&auxNumero,"Ingrese el indice de la pantalla a modificar","Error ingrese un numero valido!",0,1000,2);

    if(array != NULL && len > 0 &&
        indice >= 0 && indice < len && array[indice].isEmpty == 0)
      {
            if( !utn_getNombre(auxNombreVideo,100,"Nombre contratacion?\n","nombre no valido\n",2) &&
                !utn_getNumero(&auxDias,"ingrese el dia","Error reingrese el dia",1,31,2))
            {
                strncpy(array[indice].nombreVideo,auxNombreVideo,100);
                array[indice].dias = auxDias;

                retorno = 0;
            }

      }

    return retorno;
}


int contratacion_baja(Contratacion* array, int len)
{
    int retorno = -1;
    int indice;
    int auxNumero;

    indice = utn_getNumero(&auxNumero,"Ingrese el indice de la contratacion a borrar","Error ingrese un numero valido!",0,1000,2);

    if(array != NULL && len > 0 &&
        indice >= 0 && indice < len && array[indice].isEmpty == 0)
    {
        array[indice].isEmpty = 1;

        retorno = 0;
    }
    else
    {
        printf("\nNo hay contratacion.");
    }

    return retorno;
}


int contratacion_mostrar(Contratacion* array, int len)
{
    int retorno = -1;
    int indice;
    int auxNumero;

    indice = utn_getNumero(&auxNumero,"Ingrese el indice de la contratacion a mostrar","Error reingrese un indice correcto",0,1000,2);

    if(array != NULL && len > 0 && indice >= 0 && indice < len)
    {
        printf("\n El nombre del archivo video es: %s",array[indice].nombreVideo);
        printf("\n Los dias de duracion de la contratacion es: %d",array[indice].dias);
        printf("\n\n");

        retorno = 0;
    }
    fflush(stdin);
    //__fpurge(stdin);
    return retorno;
}
