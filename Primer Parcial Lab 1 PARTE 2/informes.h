#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "moto.h"
#include "trabajo.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"

int menuInformes();
void informes(eMoto motos[], int tamMoto, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eServicio servicios[], int tamServ, eTrabajo trabajos[], int tamTrabajo);

//INFORMES AUTOS
void mostrarMotosPorColor(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
void mostrarMotosPorTipo(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
void motosMayorCilindrada(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
void motosSeparadasPorTipo(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
void motosPorColorTipo(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
void colorMasElegido(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);

//INFORMES TRABAJOS
void trabajosPorMoto(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamServ);
void importesPorTrabajo(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamServ);
void mostrarMotosPorServicio(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamServ);
void mostrarTrabajosPorFecha(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamServ);

#endif // INFORMES_H_INCLUDED
