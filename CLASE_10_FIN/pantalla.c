#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "producto.h"

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
    //int tipo;

    indice = getLugarLibre(array,len);

    if( array != NULL && len > 0 &&
        indice >= 0 && indice < len
        && array[indice].isEmpty)
    {
        if( !utn_getNombre(nombre,50,"Nombre pantalla?\n","nombre no valido\n",2) &&
            !utn_getDescription(direccion,200,"Direccion pantalla?\n","direccion no valida\n",2)&&
            !utn_getNumeroConComa(&precio,"ingrese el precio","Error reingrese el precio",0,10000,2))
        {
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
    char auxNombre[50];
    char auxDireccion[200];
    float auxPrecio;
    //int tipo;
    int indice;
    int auxNumero;
    int retorno = -1;

    indice = utn_getNumero(&auxNumero,"Ingrese el indice de la pantalla a modificar","Error ingrese un numero valido!",0,1000,2);

    if(array != NULL && len > 0 &&
        indice >= 0 && indice < len && array[indice].isEmpty == 0)
      {
          if(!utn_getNombre(auxNombre,50,"\n Ingrese el nuevo nombre: ","\n Error,nombre invalido.",2)&&
             !utn_getDescription(auxDireccion,200,"Ingrese la nueva direccion","Error direccion invalida",2)&&
             !utn_getNumeroConComa(&auxPrecio,"\n Ingrese el nuevo precio: ","\n Error,precio invalido.",0,10000,2))
         {
            strncpy(array[indice].nombre,auxNombre,50);
            strncpy(array[indice].direccion,auxDireccion,200);
            array[indice].precio = auxPrecio;

            retorno = 0;
         }

      }

    return retorno;
}

int pantalla_baja(Pantalla* array, int len)
{
    int retorno = -1;
    int indice;
    int auxNumero;

    indice = utn_getNumero(&auxNumero,"Ingrese el indice del producto a borrar","Error ingrese un numero valido!",0,1000,2);

    if(array != NULL && len > 0 &&
        indice >= 0 && indice < len && array[indice].isEmpty == 0)
    {
        array[indice].isEmpty = 1;

        retorno = 0;
    }
    else
    {
        printf("\nNo hay pantalla.");
    }

    return retorno;
}

int pantalla_mostrar(Pantalla* array, int len)
{
    int retorno = -1;
    int indice;
    int auxNumero;

    indice = utn_getNumero(&auxNumero,"Ingrese el indice de la pantalla a mostrar","Error reingrese un indice correcto",0,1000,2);

    if(array != NULL && len > 0 && indice >= 0 && indice < len)
    {
        printf("\n El nombre de la pantalla es: %s",array[indice].nombre);
        printf("\n La direccion del producto es: %s",array[indice].direccion);
        printf("\n El precio del producto es: %.2f",array[indice].precio);
        printf("\n\n");

        retorno = 0;
    }
    fflush(stdin);
    //__fpurge(stdin);
    return retorno;
}

/*int pantalla_ordenar(Pantalla* array, int len)
{
	int i,j,auxiliar;

	for(i = 1; i < size; i++) {
		auxiliar = array[i];
		j = i;
		while(j > 0 && auxiliar < array[j - 1])
        {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = auxiliar;
	}
}
*/
