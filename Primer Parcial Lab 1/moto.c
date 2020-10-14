#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "moto.h"

void inicializarMotos(eMoto motos[], int tamM)
{
    if(motos != NULL && tamM > 0)
    {
        for(int i = 0; i < tamM; i++)
        {
            motos[i].isEmpty = 1; // PONE EN 1 TODOS LOS LUGARES, CUANDO SE CARGA UN DATO SE CAMBIA A 0.
        }
    }
}

int buscarLibre(eMoto motos[], int tamM)
{
    int indice = -1;  // DEVUELVE -1 SI NO ENCUENTRA LUGAR.

    if(motos != NULL && tamM > 0)
    {
        for(int i = 0; i < tamM; i++)
        {
            if(motos[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int altaMoto(eMoto motos[], int tamMoto, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, int idMoto)
{
    int error = 1;
    int indice;

    system("cls");
    printf("\n   *** ALTA DE MOTO ***\n\n");

    indice = buscarLibre(motos, tamMoto);

    if(indice == -1)
    {
        printf("Error, sistema completo.\n");
    }
    else
    {
        motos[indice] = motoNueva(motos, tamMoto, tipos, tamTipo, colores, tamColor, idMoto);
        error = 0;
    }

    return error;
}

eMoto motoNueva(eMoto motos[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, int idMoto)
{
    eMoto auxMoto;
    char auxMarca[100];
    int auxIdTipo;
    int auxIdColor;
    int auxCilindrada;

    auxMoto.id = idMoto;
    auxMoto.isEmpty = 0;

    printf("Ingrese marca de la moto: ");
    scanf("%s", auxMarca);

    while(strlen(auxMarca)> 20)
    {
        printf("Error, demasiado largo. Reingrese marca de la moto: ");
        scanf("%s", auxMarca);
    }
    strcpy(auxMoto.marca, auxMarca);

    mostrarTipos(tipos, tamT);

    printf("Ingrese el id del tipo de moto: ");
    scanf("%d", &auxIdTipo);

    while(validarTipo(tipos, tamT, auxIdTipo) == -1)
    {
        printf("Error, id invalido. Ingrese el id del tipo de moto: ");
        scanf("%d", &auxIdTipo);
    }

    auxMoto.idTipo = auxIdTipo;

    mostrarColores(colores, tamC);

    printf("Ingrese el id del color de la moto: ");
    scanf("%d", &auxIdColor);

    while(validarColor(colores, tamC, auxIdColor) == -1)
    {
        printf("Error, id invalido. Ingrese el id del color de la moto: ");
        scanf("%d", &auxIdColor);
    }

    auxMoto.idColor = auxIdColor;

    printf("Ingrese cilindrada (50, 125, 500, 600, 750): ");
    scanf("%d", &auxCilindrada);

    while(auxCilindrada != 50 &&auxCilindrada != 125 &&auxCilindrada != 500 &&auxCilindrada != 600 &&auxCilindrada != 750)
    {
        printf("Error, reingrese cilindrada (50, 125, 500, 600, 750): ");
        scanf("%d", &auxCilindrada);
    }

    auxMoto.cilindrada = auxCilindrada;

    return auxMoto;
}

void bajaMoto(eMoto motos[], int tamMoto, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int indice;
    int idMoto;
    char confirma;

    system("cls");

    printf("Baja de Moto\n\n");

    mostrarMotos(motos, tamMoto, tipos, tamTipo, colores, tamColor);

    printf("\nIngrese id de la moto: ");
    scanf("%d", &idMoto);

    indice = buscarMoto(motos, tamMoto, idMoto);

    if(indice==-1)
    {
        printf("No hay ninguna moto con ese id\n\n");
    }
    else
    {
        mostrarMoto(motos[indice], tipos, tamTipo, colores, tamColor);

        printf("Confirma eliminar a la moto?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma=='s')
        {
            motos[indice].isEmpty = 1;
            printf("Baja exitosa!!\n\n");
        }
        else
        {
            printf("Baja cancelada.\n\n");
        }
    }

}


int buscarMoto(eMoto motos[], int tamM, int idMoto)
{
    int indice = -1;

    for(int i = 0; i < tamM; i++)
    {
        if(motos[i].isEmpty == 0 && motos[i].id == idMoto)
        {
            indice = i;
        }
    }

    return indice;
}


void mostrarMoto(eMoto moto, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    char descTipo[20];
    char descColor[20];

    cargarDescripcionTipo(tipos, tamT, moto.idTipo, descTipo);
    cargarDescripcionColor(colores, tamC, moto.idColor, descColor);

    printf("%d  %s  %s  %s         %d\n", moto.id, moto.marca, descTipo, descColor, moto.cilindrada);
}

void mostrarMotos(eMoto motos[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int flag = 0;

    printf("ID   Marca      Tipo      Color   Cilindrada\n\n");
    for(int i = 0; i < tamM; i++)
    {
        if(motos[i].isEmpty == 0)
        {
            mostrarMoto(motos[i], tipos, tamT, colores, tamC);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay motos cargadas.\n\n");
    }
}

void modificarMoto(eMoto motos[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int idMoto;
    int indice;
    int auxColor;
    int auxCilindrada;
    char seguir = 'n';

    system("cls");

    printf("\n   ***   Modificar Moto   ***\n\n");

    mostrarMotos(motos, tamM, tipos, tamT, colores, tamC);

    printf("\n\nIngrese el ID de la moto a modificar: ");
    scanf("%d", &idMoto);

    indice = buscarMoto(motos, tamM, idMoto);

    if(indice == -1)
    {
        printf("\nError. No se encontro ninguna moto con ese id.\n");
    }
    else
    {

        do
        {
            switch( menuModificar(motos[indice], tipos, tamT, colores, tamC) )
            {
            case 1:
                mostrarColores(colores, tamC);

                printf("Ingrese el id del color: ");
                scanf("%d", &auxColor);

                while(validarColor(colores, tamC, auxColor) == -1)
                {
                    printf("Id invalido, reingrese: ");
                    scanf("%d", &auxColor);
                }

                motos[indice].idColor = auxColor;
                printf("Se modifico con exito el color.\n\n");
                system("pause");
                break;

            case 2:

                printf("Ingrese cilindrada (50, 125, 500, 600, 750): ");
                scanf("%d", &auxCilindrada);

                while(auxCilindrada != 50 && auxCilindrada != 125 && auxCilindrada != 500 && auxCilindrada != 600 && auxCilindrada != 750)
                {
                    printf("Error, reingrese cilindrada (50, 125, 500, 600, 750): ");
                    scanf("%d", &auxCilindrada);
                }

                motos[indice].cilindrada = auxCilindrada;
                printf("Se modifico con exito la cilindrada.\n\n");
                system("pause");
                break;

            case 3:
                printf("\nPresione 's' para salir: ");
                fflush(stdin);
                seguir = getche();
                break;

            default:
                printf("\nOpcion invalida.\n\n");
                system("pause");
                break;
            }
        }
        while(seguir != 's');
    }

}

int menuModificar(eMoto moto, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int opcion;

    system("cls");

    mostrarMoto(moto, tipos, tamT, colores, tamC);

    printf("\n\n   *** MENU DE MODIFICACION ***\n\n");
    printf("1- Modificar Color.\n");
    printf("2- Modificar Cilindrada.\n");
    printf("3- Salir.\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}
