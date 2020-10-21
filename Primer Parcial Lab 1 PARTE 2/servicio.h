#ifndef SERVICIO_H_INCLUDED

typedef struct
{
    int id; // EMPIEZA EN 20000
    char descripcion[25];
    float precio;
} eServicio;

#define SERVICIO_H_INCLUDED

void mostrarServicio(eServicio servicio);
void mostrarServicios(eServicio servicios[], int tamS);
int validarServicio(eServicio servicios[], int tamS, int id);
void cargarDescripcionServicio(eServicio servicios[], int tamS, int id, char servicio[]);

#endif // SERVICIO_H_INCLUDED
