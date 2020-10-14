#ifndef TRABAJO_H_INCLUDED

typedef struct
{
    int id; // AUTOINCREMENTAL
    int idMoto;
    int idServicio;
    eFecha fecha; // VALIDAR
    int isEmpty;
} eTrabajo;

#define TRABAJO_H_INCLUDED

#include "moto.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"

void inicializarTrabajos(eTrabajo trabajos[], int tamT);
int buscarTrabajoLibre(eTrabajo trabajos[], int tamT);
int altaTrabajo(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamMoto, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, int idTrabajo);
eTrabajo trabajoNuevo(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamMoto, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, int idTrabajo);
void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamS);
void mostrarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamServ);

#endif // TRABAJO_H_INCLUDED
