#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int validarFecha(int dia, int mes, int anio) // devuelve 0 si la fecha es valida o 1 si es invalida.
{
    int error = 0;

    if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900 || anio > 2021)
    {
        error = 1;
    }

    return error;
}

char menu()
{
    char opcion;

    system("cls");

    printf("\n\n   *** MENU DE OPCIONES ***\n\n");
    printf("a- Alta de moto.\n");
    printf("b- Modificar moto.\n");
    printf("c- Baja de moto.\n");
    printf("d- Listar motos.\n");
    printf("e- Listar tipos.\n");
    printf("f- Listar colores.\n");
    printf("g- Listar servicios.\n");
    printf("h- Alta de trabajo.\n");
    printf("i- Listar trabajos.\n");
    printf("j- Informes.\n");
    printf("k- Salir.\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}
