#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* listaVenta);
int controller_saveAsText(char* path , LinkedList* listaVenta);
int controller_ListarEmpleados(LinkedList* listaVentas);

#endif



