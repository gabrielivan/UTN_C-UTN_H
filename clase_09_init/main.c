#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "producto.h"
#define CANTIDAD_PRODUCTO 3
/*
1)  Definir un tipo de dato que represente un producto.
    El producto tiene un nombre, una descripcion y un precio

2)  Definir un array de 200 productos, indicar de alguna manera
    que la info de cada item no esta cargada.

3)  Realizar una funcion que reciba el array, un indice, y le
    permita al usuario cargar los datos en el item de la posicion especificada por el indice.

4)  Realizar una funcion que reciba el array y un indice e imprima
    los datos del item de la posicion especificada por el indice.

5)  Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).


6) Realizar un programa con un menu de dos opciones:
    a) Cargar un producto
    b) Imprimir lista productos


7)  Agregar al tipo de dato el campo ID que represente un identificador unico.
    Modificar el codigo anterior para que el ID se genere automaticamente. Se debera cargar el ID automaticamente al cargar un producto, y se debera imprimir al imprimir la lista.

8)  Realizar una funcion que reciba el array y un ID, y me devuelva el indice
    del item con dicho ID.

9)  Realizar una funcion que reciba el array, un indice, y le permita al usuario
    modificar los campos nombre y precio del item del array en la posicion especificada por el indice.


10)  Agregar una opcion en el menu. "Editar producto" que pida al usuario el ID del
    mismo y le permita cambiar el nombre y el precio.

11)  Agregar una opcion en el menu "Borrar producto" que pida al usuario el ID del
    mismo.

*/
int main()
{
    int opcionMenu = 1;
    int indiceVacio;
    int idBuscado,indiceEncontrado;
    Producto arrayProducto[CANTIDAD_PRODUCTO];
    producto_initArrayProducto(arrayProducto,CANTIDAD_PRODUCTO,1);
    while(opcionMenu >= 1 && opcionMenu <=5)
    {
         opcionMenu = getInt("\n1 - cargar \n2 - imprimir \n3 - modificar \n4 - borrar  \n5 - salir\n");
         switch(opcionMenu)
         {
            case 1:
                indiceVacio = producto_buscarIndiceArray(arrayProducto,CANTIDAD_PRODUCTO);
                producto_altaArray(arrayProducto,indiceVacio,CANTIDAD_PRODUCTO);
                break;

            case 2:
               producto_mostrarArrayCompleto(arrayProducto,CANTIDAD_PRODUCTO);
            break;

            case 3:
                    idBuscado = getInt("\ningrese id:");
                    indiceEncontrado = producto_buscarIndiceArrayById(arrayProducto,idBuscado,CANTIDAD_PRODUCTO);
                    if(indiceEncontrado != -1)
                    {
                        printf("El indice del id %d es %d", idBuscado, indiceEncontrado);
                    }
                    else
                    {
                        printf("No se encontro");
                    }

                    producto_modificar(arrayProducto,indiceEncontrado,CANTIDAD_PRODUCTO);

                break;

            case 4:

                    idBuscado = getInt("\ningrese id:");
                    indiceEncontrado = producto_buscarIndiceArrayById(arrayProducto,idBuscado,CANTIDAD_PRODUCTO);
                    if(indiceEncontrado != -1)
                    {
                        printf("El indice del id %d es %d", idBuscado, indiceEncontrado);
                    }
                    else
                    {
                        printf("No se encontro");
                    }

                    producto_bajaLogica(arrayProducto,indiceEncontrado,CANTIDAD_PRODUCTO);

                break;


            case 5: printf("Adios");
            break;

            default: printf("error ingrese una opcion valida");
         }
    }


    return 0;
}






