#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "fecha.h"
#include "trabajo.h"



void inicializarTrabajos(eTrabajo trabajos[], int tamT)
{
    if(trabajos != NULL && tamT > 0)
    {
        for(int i = 0; i < tamT; i++)
        {
            trabajos[i].isEmpty = 1; // PONE EN 1 TODOS LOS LUGARES, CUANDO SE CARGA UN DATO SE CAMBIA A 0.
        }
    }
}

int buscarTrabajoLibre(eTrabajo trabajos[], int tamT)
{
    int indice = -1;  // DEVUELVE -1 SI NO ENCUENTRA LUGAR.

    if(trabajos != NULL && tamT > 0)
    {
        for(int i = 0; i < tamT; i++)
        {
            if(trabajos[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int altaTrabajo(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamMoto, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, int idTrabajo)
{
    int error = 1;
    int indice;

    system("cls");

    indice = buscarTrabajoLibre(trabajos, tamTrabajo);

    if(indice == -1)
    {
        printf("Error. Sistema completo.\n");
    }
    else
    {
        trabajos[indice] = trabajoNuevo(trabajos, tamTrabajo, motos, tamMoto, servicios, tamServ, tipos, tamTipo, colores, tamColor, idTrabajo);
        error = 0;
    }

    return error;
}

eTrabajo trabajoNuevo(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamMoto, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, int idTrabajo)
{
    eTrabajo auxTrabajo;
    int auxIdMoto;
    int auxIdServicio;

    printf("*** ALTA DE TRABAJO ***\n\n");

    mostrarMotos(motos, tamMoto, tipos, tamTipo, colores, tamColor);

    printf("Ingrese el id de la moto elegida: ");
    scanf("%d", &auxIdMoto);

    while(buscarMoto(motos, tamMoto, auxIdMoto) == -1)
    {
        printf("Error, id invalido. Reingrese: ");
        scanf("%d", &auxIdMoto);
    }

    mostrarServicios(servicios, tamServ);

    printf("Ingrese el id del servicio elegido: ");
    scanf("%d", &auxIdServicio);

    while(validarServicio(servicios, tamServ, auxIdServicio) == -1)
    {
        printf("Error, id invalido. Reingrese: ");
        scanf("%d", &auxIdServicio);
    }

    printf("Ingrese fecha del trabajo dd/mm/aaaa : ");
    fflush(stdin);
    scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

    while(validarFecha(auxTrabajo.fecha.dia, auxTrabajo.fecha.mes, auxTrabajo.fecha.anio) == 1)
    {
        printf("Error, fecha invalida. Reingrese fecha del trabajo dd/mm/aaaa : ");
        fflush(stdin);
        scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
    }

    auxTrabajo.id = idTrabajo;
    auxTrabajo.idMoto = auxIdMoto;
    auxTrabajo.idServicio = auxIdServicio;
    auxTrabajo.isEmpty = 0;

    return auxTrabajo;
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamS)
{
    char servicio[25];

    cargarDescripcionServicio(servicios, tamS, trabajo.idServicio, servicio);

    printf("   %d         %d        %s       %d/%d/%d\n", trabajo.id, trabajo.idMoto, servicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}

void mostrarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamServ)
{
    int flag = 0;

    printf("*** LISTA DE TRABAJOS ***\n\n");

    printf("Id Trabajo   Id Moto   Servicio   Fecha\n\n");

    for(int i = 0; i < tamT; i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i], servicios, tamServ);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay trabajos cargados.\n\n");
    }
}


