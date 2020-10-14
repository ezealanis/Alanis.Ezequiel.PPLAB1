#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "servicio.h"

void mostrarServicio(eServicio servicio)
{
    printf("  %d   %10s   %3.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

void mostrarServicios(eServicio servicios[], int tamS)
{
    if(servicios != NULL && tamS > 0)
    {
        printf("   ID    Descripcion   Precio\n\n");
        for(int i = 0; i < tamS; i++)
        {
            mostrarServicio(servicios[i]);
        }
    }

    printf("\n\n");
}

int validarServicio(eServicio servicios[], int tamS, int id)
{
    int error = -1;

    if(servicios != NULL && tamS > 0)
    {
        for(int i = 0; i < tamS; i++)
        {
            if(servicios[i].id == id)
            {
                error = 0;
            }
        }
    }

    return error;
}

void cargarDescripcionServicio(eServicio servicios[], int tamS, int id, char servicio[])
{

    for(int i = 0; i < tamS; i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(servicio, servicios[i].descripcion);
            break;
        }
    }
}
