#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
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

Contratacion* contratacion_getByCuit(Contratacion* array, int len,char cuit[])
{
    Contratacion retorno [len];
    contratacion_init(retorno,len);
    int i;
    int lugarLibre;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && strcmp(array[i].cuit, cuit) == 0)
            {
                lugarLibre = getLugarLibre(retorno,len);
                retorno[lugarLibre] = array[i];
            }
        }
    }
    return retorno;
}

Contratacion* contratacion_getByPantalla(Contratacion* array,int len,int pantallaId)
{
    for(int i = 0; i < len; i++)
    {
        if(array[i].pantallaId == pantallaId)
        {
            return &array[i];
        }
    }
    return NULL;
}

int contratacion_alta(Contratacion* array,Pantalla* arrayPantalla, int len,int lenPantalla)
{
    int retorno = -1;
    int indice;
    char cuit[14];
    int dias;
    char nombreVideo[100];
    int idIngresado;

    if(utn_getNumero(&idIngresado,"ingrese el id de la pantalla","error ingrese un id valido",0,10000,2)== -1)
    {
        return retorno;
    }
    if(pantalla_getById(arrayPantalla,lenPantalla,idIngresado)!= NULL)
    {
        indice = getLugarLibre(array,len);

        if( array != NULL && len > 0 &&
            indice >= 0 && indice < len
            && array[indice].isEmpty)
        {
            if( !utn_getCuit(cuit,"Ingrese cuit del cliente\n","No es un cuit valido, reingrese",2) &&
                !utn_getNombre(nombreVideo,100,"Ingrese el nombre del archivo de video\n","nombre no valido\n",2) &&
                !utn_getNumero(&dias,"ingrese la duracion de la publicidad en dias\n","Error reingrese el dia",1,365,2))
            {
                strncpy(array[indice].cuit,cuit,14);
                strncpy(array[indice].nombreVideo,nombreVideo,100);
                array[indice].dias = dias;
                array[indice].isEmpty = 0;
                array[indice].id = getNextId();
                retorno = 0;
            }

        }

    }
    return retorno;
}


int contratacion_modificar(Contratacion* array, int len, char cuit[],Pantalla* arrayPantallas, int lenPantallas)
{
    int auxDias;
    char cuitIngresado[14];
    int retorno = -1;
    int idIngresado;
    Contratacion* contratacionesDelCuit;
    Contratacion* contratacionElegida;

    utn_getCuit(cuitIngresado,"Ingrese el cuit del cliente","Error ingrese un cuit valido!",2);//ya le tome el cuit....

    contratacionesDelCuit = contratacion_getByCuit(array,len,cuitIngresado);
    //tiene contrataciones?  o estan todas empty?

    //se listaran todas las pantallas de video que el cliente tiene contratadas mostrando todos sus campos.

    utn_getNumero(&idIngresado,"ingrese el id de la pantalla","ingrese un id valido",0,10000,2);//tengo el id de la pantalla...
    contratacionElegida = contratacion_getByPantalla(contratacionesDelCuit,len,idIngresado);
    if(contratacionElegida != NULL)
    {
    //Luego de ingresar el ID de la pantalla,se permitirá modificar la cantidad de días contratados para la misma.
        if(!utn_getNumero(&auxDias,"ingrese la cantidad de dias de contratacion","Error reingrese el dia",1,365,2))
        {
            contratacionElegida->dias = auxDias;
            retorno = 0;
        }

    }
    else{
        printf("El id de la pantalla no pertence al cuit ingresado");
    }
    return retorno;
}


//int contratacion_baja(Contratacion* array, int len, char cuit[], Pantalla* arrayPantallas, int lenPantallas)
//{
//    int retorno = -1;
//    int indice;
//    int idIngresado;
//    char cuitIngresado[];
//
//
//    if(utn_getCuit(cuitIngresado,"Ingrese su cuit","Error ingrese un cuit valido!",0,10000,2) == 0);//ya tengo el cuit..
//    //se listaran todas las pantallas de video que el cliente tiene contratadas mostrando todos sus campos.?????
//     utn_getNumero(&idIngresado"ingrese el id de la pantalla","ingrese un id valido",0,10000,2)//tengo el id de la pantalla...
//    //Luego ingresar el ID de la pantalla la cual se quiere dar de baja ???.
//    {
//        if(array != NULL && len > 0 &&
//            indice >= 0 && indice < len && array[indice].isEmpty == 0)//donde declaras el indice???donde lo pide? que es indice?
//        {
//            array[indice].isEmpty = 1;
//            retorno = 0;
//        }
//        else
//        {
//            printf("\nNo hay contratacion.");
//        }
//
//        return retorno;
//
//    }


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
