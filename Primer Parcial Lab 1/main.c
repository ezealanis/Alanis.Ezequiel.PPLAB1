#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "fecha.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#include "moto.h"
#include "trabajo.h"

#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_MOTO 5
#define TAM_SERVICIO 4
#define TAM_TRABAJO 10


int main()
{

    char seguir = 'n';
    int idMoto = 100;
    int idTrabajo = 1;

    eTipo tipos[TAM_TIPO] = { {1000, "Enduro"}, {1001, "Chopera"}, {1002, "Scooter"}, {1003, "Ciclomotor"} };
    eColor colores[TAM_COLOR] = { {10000, "Gris"}, {10001, "Negro"}, {10002, "Blanco"}, {10003, "Azul"}, {10004, "Rojo"} };
    eMoto motos[TAM_MOTO];
    eServicio servicios[TAM_SERVICIO] = { {20000, "Limpieza", 250}, {20001, "Ajuste", 300}, {20002, "Balanceo", 17}, {20003, "Cadena", 190} };
    eTrabajo trabajos[TAM_TRABAJO];

    inicializarMotos(motos, TAM_MOTO);
    inicializarTrabajos(trabajos, TAM_TRABAJO);

    do
    {

        switch(menu())
        {
        case 'a':
            if(altaMoto(motos, TAM_MOTO, tipos, TAM_TIPO, colores, TAM_COLOR, idMoto) == 0)
            {
                printf("\nAlta de moto exitosa.\n\n");
                idMoto++;
            }
            else
            {
                printf("\nError, no se realizo el alta.\n\n");
            }

            break;

        case 'b':

            modificarMoto(motos, TAM_MOTO, tipos, TAM_TIPO, colores, TAM_COLOR);
            break;

        case 'c':

            bajaMoto(motos, TAM_MOTO, tipos, TAM_TIPO, colores, TAM_COLOR);
            break;

        case 'd':
            system("cls");
            mostrarMotos(motos, TAM_MOTO, tipos, TAM_TIPO, colores, TAM_COLOR);
            break;

        case 'e':
            system("cls");
            mostrarTipos(tipos, TAM_TIPO);
            break;

        case 'f':
            system("cls");
            mostrarColores(colores, TAM_COLOR);
            break;

        case 'g':
            system("cls");
            mostrarServicios(servicios, TAM_SERVICIO);
            break;

        case 'h':
            if(altaTrabajo(trabajos, TAM_TRABAJO, motos, TAM_MOTO, servicios, TAM_SERVICIO, tipos, TAM_TIPO, colores, TAM_COLOR, idTrabajo) == 0)
            {
                printf("\nAlta de trabajo exitosa.\n\n");
                idTrabajo++;
            }
            else
            {
                printf("\nError, no se realizo el alta.\n\n");
            }
            break;

        case 'i':
            system("cls");
            mostrarTrabajos(trabajos, TAM_TRABAJO, servicios, TAM_SERVICIO);
            break;

        case 'j':
            printf("\nPresione 's' para salir: ");
            fflush(stdin);
            seguir = getche();
            break;

        default:
            printf("Opcion invalida.\n\n");
            break;
        }
        printf("\n\n");
        system("pause");

    }
    while(seguir != 's');


    return 0;
}

