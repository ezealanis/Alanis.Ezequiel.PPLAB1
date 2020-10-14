#ifndef MOTO_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int isEmpty;
} eMoto;

#define MOTO_H_INCLUDED

#include "tipo.h"
#include "color.h"

void inicializarMotos(eMoto motos[], int tamM);
int buscarLibre(eMoto motos[], int tamM);
int altaMoto(eMoto motos[], int tamMoto, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, int idMoto);
eMoto motoNueva(eMoto motos[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, int idMoto);
void mostrarMoto(eMoto moto, eTipo tipos[], int tamT, eColor colores[], int tamC);
void mostrarMotos(eMoto motos[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC);
int buscarMoto(eMoto motos[], int tamM, int id);
void bajaMoto(eMoto motos[], int tamMoto, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);
int menuModificar(eMoto moto, eTipo tipos[], int tamT, eColor colores[], int tamC);
void modificarMoto(eMoto motos[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC);

#endif // MOTO_H_INCLUDED
