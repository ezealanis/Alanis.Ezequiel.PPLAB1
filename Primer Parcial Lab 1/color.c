#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "color.h"


void mostrarColor(eColor color)
{
    printf("  %d   %10s \n", color.id, color.descripcion);
}

void mostrarColores(eColor colores[], int tamC)
{
    if(colores != NULL && tamC > 0)
    {
        printf("\n");

        printf("   ID    Descripcion\n\n");
        for(int i = 0; i < tamC; i++)
        {
            mostrarColor(colores[i]);
        }
    }

    printf("\n");
}

int validarColor(eColor colores[], int tamC, int id)
{
    int error = -1;

    if(colores != NULL && tamC > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            if(colores[i].id == id)
            {
                error = 0;
            }
        }
    }

    return error;
}

void cargarDescripcionColor(eColor colores[], int tamC, int id, char desc[])
{
    for(int i = 0; i < tamC; i++)
    {
        if(colores[i].id == id)
        {
            strcpy(desc, colores[i].descripcion);
            break;
        }
    }
}
