typedef struct
{
    int cuit;//cuit del cliente
    int dias;//duracion de la publicacion
    char nombreVideo[100];//nombre del archivo de video
    //********************
    int id;
    int isEmpty;

    int pantallaId;
}Contratacion;

int contratacion_init(Contratacion* array, int len);
int contratacion_alta(Contratacion* array, int len);
int contratacion_modificar(Contratacion* array, int len);
int contratacion_baja(Contratacion* array, int len);
int contratacion_mostrar(Contratacion* array, int len);
int contratacion_ordenar(Contratacion* array, int len);
Contratacion* contratacion_getById(Contratacion* array, int len,int id);
