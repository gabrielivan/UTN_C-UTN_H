#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

//#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"
#include "utn.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* listaVenta);
int parser_SaveToText(FILE* pFile,LinkedList* listaVentas);

#endif
