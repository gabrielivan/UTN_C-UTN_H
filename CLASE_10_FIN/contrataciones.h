typedef struct
{
    int cuit;
    int dias;
    char nombreVideo[100];
    //********************
    int id;
    int isEmpty;
}Contratacion;

int contratacion_init(Contratacion* array, int len);
int contratacion_alta(Contratacion* array, int len);
int contratacion_modificar(Contratacion* array, int len);
int contratacion_baja(Contratacion* array, int len);
int contratacion_mostrar(Contratacion* array, int len);
int contratacion_ordenar(Contratacion* array, int len);
Contratacion* contratacion_getById(Contratacion* array, int len,int id);
