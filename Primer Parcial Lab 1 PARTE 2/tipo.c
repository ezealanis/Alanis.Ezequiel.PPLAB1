#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "tipo.h"

void mostrarTipo(eTipo tipo)
{
    printf("  %d   %10s \n", tipo.id, tipo.descripcion);
}

void mostrarTipos(eTipo tipos[], int tamT)
{
    if(tipos != NULL && tamT > 0)
    {
        printf("\n");

        printf("--------------------------\n");
        printf("   ID    Descripcion\n");
        printf("--------------------------\n");

        for(int i = 0; i < tamT; i++)
        {
            mostrarTipo(tipos[i]);
        }

        printf("--------------------------\n");
    }

    printf("\n");
}

int validarTipo(eTipo tipos[], int tamT, int id)
{
    int error = -1;

    if(tipos != NULL && tamT > 0)
    {
        for(int i = 0; i < tamT; i++)
        {
            if(tipos[i].id == id)
            {
                error = 0;
            }
        }
    }

    return error;
}

void cargarDescripcionTipo(eTipo tipos[], int tamT, int id, char desc[])
{
    for(int i = 0; i < tamT; i++)
    {
        if(tipos[i].id == id)
        {
            strcpy(desc, tipos[i].descripcion);
            break;
        }
    }
}
