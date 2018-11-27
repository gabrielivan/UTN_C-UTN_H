#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

struct S_Venta
{
  int idVenta;
  char codigoProducto[128];
  char cuitCliente[14];
  int cantidad;
  float precioUnitario;
  char fecha[1024];
};
typedef struct S_Venta Venta;

Venta* Venta_new();
int Venta_delete();

Venta* Venta_newConParametros(char* idVenta,char* fecha,char* codigoProducto,char* cantidad,char* precioUnitario,char* cuitCliente);

int Venta_setId(Venta* this,int idVenta);
int Venta_getId(Venta* this,int* idVenta);

int Venta_setCodigoProducto(Venta* this,char* codigoProducto);
int Venta_getCodigoProducto(Venta* this,char* codigoProducto);

int Venta_setCuitCliente(Venta* this,char* cuitCliente);
int Venta_getCuitCliente(Venta* this,char* cuitCliente);

int Venta_setFecha(Venta* this,char* fecha);
int Venta_getFecha(Venta* this,char* fecha);

int Venta_setCantidad(Venta* this,int cantidad);
int Venta_getCantidad(Venta* this,int* cantidad);

float Venta_setPrecioUnitario(Venta* this,float precioUnitario);
float Venta_getPrecioUnitario(Venta* this,float* precioUnitario);

int Venta_getAll(Venta* this,char* codigoProducto,char* cuitCliente,char* fecha,int* cantidad,float* precioUnitario,int* idVenta);

Venta* Venta_getById(void* listaVenta,int idIngresado);

int Venta_mostrar(void* pVenta);

///************FUNCIONES CRITERIO***********

int Venta_Mayor(void* this);
int Venta_MayorMas(void* this);
int Venta_cantidadUnidadesTotal(void* this);
int Venta_cantidadTvLcd(void* this);

///******FIN DE LAS FUNCIONES CRITERIO*******

#endif // VENTA_H_INCLUDED
