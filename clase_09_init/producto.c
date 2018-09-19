#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "producto.h"


void producto_initArrayProducto(Producto arrayProducto[],int size,int valor)
{
    int i;
    for(i=0;i < size; i++)
    {
        arrayProducto[i].isEmpty = valor;
    }

}

int producto_altaArray(Producto arrayProducto[],int indice,int size)
{
    char auxNombre[50];
    char auxDescripcion[100];
    float auxPrecio;
    int retorno = -1;

    if(arrayProducto[indice].isEmpty == 1)
    {
        if( !utn_getNombre(auxNombre,50,"\n Ingrese el nombre del producto: ","\n Error,nombre invalido.",2)&&
            !utn_getDescription(auxDescripcion,100,"\n Ingrese la descripcion: ","\n Error,descripcion invalida.",2)&&
            !utn_getNumeroConComa(&auxPrecio,"\n Ingrese el precio: ","\n Error,precio invalido.",0,10000,2))
        {
            strncpy(arrayProducto[indice].nombre,auxNombre,50);
            strncpy(arrayProducto[indice].descripcion,auxDescripcion,100);
            arrayProducto[indice].precio = auxPrecio;

            retorno = 0;
        }

    }
    return retorno;
}

int producto_mostrarArray(Producto arrayProducto[],int indice,int size)
{
    int retorno = -1;

    if(arrayProducto != NULL && size > 0 && indice >= 0 && indice < size)
    {
        printf("\n El nombre del producto es: %s",arrayProducto[indice].nombre);
        printf("\n La descripcion del producto es: %s",arrayProducto[indice].descripcion);
        printf("\n El precio del producto es: %.2f",arrayProducto[indice].precio);

        retorno = 0;
    }
    return retorno;
}

int producto_buscarIndiceArray(Producto arrayProducto[],int size)
{
    int i;
    int indiceVacio;

    for(i=0;i < size; i++)
    {
        if(arrayProducto[i].isEmpty == 1)
        {
            indiceVacio = i;
            return indiceVacio;
        }

    }
    return -1;
}



