#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "informes.h"

int menuInformes()
{
    int opcion;

    system("cls");

    printf("*** MENU DE INFORMES ***\n\n");

    printf("1- Mostrar motos por color.\n");
    printf("2- Mostrar motos por tipo.\n");
    printf("3- Informar motos de mayor cilindrada.\n");
    printf("4- Listar motos separadas por tipo.\n");
    printf("5- Contar motos por color y tipo.\n");
    printf("6- Color mas elegido.\n");
    printf("7- Listar trabajos por moto.\n");
    printf("8- Suma de importes por moto.\n");
    printf("9- Mostrar motos por servicio.\n");
    printf("10- Mostrar trabajos por fecha.\n");
    printf("11- Salir.\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void informes(eMoto motos[], int tamMoto, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eServicio servicios[], int tamServ, eTrabajo trabajos[], int tamTrabajo)
{
    char seguir = 'n';

    do
    {
        switch( menuInformes() )
        {
        case 1:
            mostrarMotosPorColor(motos, tamMoto, colores, tamColor, tipos, tamTipo);
            break;

        case 2:
            mostrarMotosPorTipo(motos, tamMoto, colores, tamColor, tipos, tamTipo);
            break;

        case 3:
            motosMayorCilindrada(motos, tamMoto, colores, tamColor, tipos, tamTipo);
            break;

        case 4:
            motosSeparadasPorTipo(motos, tamMoto, colores, tamColor, tipos, tamTipo);
            break;

        case 5:
            motosPorColorTipo(motos, tamMoto, colores, tamColor, tipos, tamTipo);
            break;

        case 6:
            colorMasElegido(motos, tamMoto, colores, tamColor, tipos, tamTipo);
            break;

        case 7:
            trabajosPorMoto(trabajos, tamTrabajo, motos, tamMoto, colores, tamColor, tipos, tamTipo, servicios, tamServ);
            break;

        case 8:
            importesPorTrabajo(trabajos, tamTrabajo, motos, tamMoto, colores, tamColor, tipos, tamTipo, servicios, tamServ);
            break;

        case 9:
            mostrarMotosPorServicio(trabajos, tamTrabajo, motos, tamMoto, colores, tamColor, tipos, tamTipo, servicios, tamServ);
            break;

        case 10:
            mostrarTrabajosPorFecha(trabajos, tamTrabajo, motos, tamMoto, colores, tamColor, tipos, tamTipo, servicios, tamServ);
            break;

        case 11:
            printf("\nPresione 's' para salir: ");
            fflush(stdin);
            seguir = getche();
            break;

        default:
            printf("\nOpcion invalida.\n");
            break;
        }

        printf("\n");
        system("pause");

    }
    while(seguir != 's');
}


void mostrarMotosPorColor(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int color;
    int flag = 0;

    system("cls");

    mostrarColores(colores, tamC);

    printf("Ingrese el id del color elegido: ");
    scanf("%d", &color);

    while(validarColor(colores, tamC, color) == 1)
    {
        printf("Error, reingrese el id del color: ");
        scanf("%d", &color);
    }

    printf("------------------------------------------------------------\n");
    printf(" ID       Marca         Tipo         Color      Cilindrada \n");
    printf("------------------------------------------------------------\n");
    for(int i = 0; i < tamM; i++)
    {
        if(motos[i].isEmpty == 0 && motos[i].idColor == color)
        {
            mostrarMoto(motos[i], tipos, tamT, colores, tamC);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\nNo hay motos del color elegido.\n");
    }

    printf("\n");

}



void mostrarMotosPorTipo(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int tipo;
    int flag = 0;

    system("cls");

    mostrarTipos(tipos, tamT);

    printf("Ingrese el id del tipo elegido: ");
    scanf("%d", &tipo);

    while(validarTipo(tipos, tamT, tipo) == 1)
    {
        printf("Error, reingrese el id del tipo: ");
        scanf("%d", &tipo);
    }

    printf("------------------------------------------------------------\n");
    printf(" ID       Marca         Tipo         Color      Cilindrada \n");
    printf("------------------------------------------------------------\n");

    for(int i = 0; i < tamM; i++)
    {
        if(motos[i].isEmpty == 0 && motos[i].idTipo == tipo)
        {
            mostrarMoto(motos[i], tipos, tamT, colores, tamC);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\nNo hay motos del tipo elegido.\n");
    }

    printf("\n");

}


void motosMayorCilindrada(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int mayor = 50;
    int flag = 0;

    system("cls");

    for(int i = 0; i < tamM; i++)
    {
        if(motos[i].isEmpty == 0 && motos[i].cilindrada > mayor)
        {
            mayor = motos[i].cilindrada;
        }
    }

    printf("------------------------------------------------------------\n");
    printf(" ID       Marca         Tipo         Color      Cilindrada \n");
    printf("------------------------------------------------------------\n");
    for(int i = 0; i < tamM; i++)
    {
        if(motos[i].isEmpty == 0 && motos[i].cilindrada == mayor)
        {
            mostrarMoto(motos[i], tipos, tamT, colores, tamC);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\nNo hay motos que mostrar.\n");
    }

    printf("\n");
}


void motosSeparadasPorTipo(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int flag = 0;

    for(int i = 0; i < tamT; i++)
    {
        printf("--------------------------\n");
        printf("   ID    Descripcion\n");
        printf("--------------------------\n");
        mostrarTipo(tipos[i]);
        printf("--------------------------\n\n");

        flag = 0;

        for(int m = 0; m < tamM; m++)
        {
            if(motos[m].isEmpty == 0 && motos[m].idTipo == tipos[i].id)
            {
                mostrarMoto(motos[m], tipos, tamT, colores, tamC);
                flag = 1;
            }


        }

        if(flag == 0)
        {
            printf("\nNo hay motos que mostrar.\n");
        }

        printf("\n\n");
    }

}


void motosPorColorTipo(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int tipo;
    int color;
    int cont = 0;

    system("cls");

    mostrarTipos(tipos, tamT);

    printf("Ingrese el id del tipo elegido: ");
    scanf("%d", &tipo);

    while(validarTipo(tipos, tamT, tipo) == 1)
    {
        printf("Error, reingrese el id del tipo: ");
        scanf("%d", &tipo);
    }

    mostrarColores(colores, tamC);

    printf("Ingrese el id del color elegido: ");
    scanf("%d", &color);

    while(validarColor(colores, tamC, color) == 1)
    {
        printf("Error, reingrese el id del color: ");
        scanf("%d", &color);
    }

    for(int i = 0; i < tamM; i++)
    {
        if(motos[i].isEmpty == 0 && motos[i].idTipo == tipo && motos[i].idColor == color)
        {
            //mostrarMoto(motos[i], tipos, tamT, colores, tamC);
            cont++;
        }
    }

    if(cont == 0)
    {
        printf("\nNo hay motos del color y tipo elegido.");
    }
    else
    {
        printf("\nHay %d motos del tipo y el color elegido.", cont);
    }

    printf("\n");
}


void colorMasElegido(eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int contColor[tamC];
    int mayor;
    int flag = 0;

    for(int i = 0; i < tamC; i++)
    {
        contColor[i] = 0;
    }

    for(int i = 0; i < tamC; i++)
    {
        for(int m = 0; m < tamM; m++)
        {
            if(motos[m].isEmpty == 0 && motos[m].idColor == colores[i].id)
            {
                contColor[i]++;
            }
        }
    }

    for(int i = 0; i < tamC; i++)
    {
        if(contColor[i] > mayor || flag == 0)
        {
            mayor = contColor[i];
            flag = 1;
        }
    }


    printf("\nEl o los colores mas elegidos son: \n");

    for(int i = 0; i < tamC; i++)
    {
        if(contColor[i] == mayor)
        {
            printf("\n%s\n", colores[i].descripcion);
        }
    }
}

void trabajosPorMoto(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamServ)
{
    int moto;

    system("cls");

    mostrarMotos(motos, tamM, tipos, tamT, colores, tamC);

    printf("\nIngrese id de la moto: ");
    scanf("%d", &moto);

    while(buscarMoto(motos, tamM, moto) == -1)
    {
        printf("\nError, reingrese id de la moto: ");
        scanf("%d", &moto);
    }


    printf("---------------------------------------------------------\n");
    printf("  ID Trabajo   ID Moto        Servicio         Fecha\n");
    printf("---------------------------------------------------------\n");

    for(int i = 0; i < tamTrabajo; i++)
    {
        if(trabajos[i].isEmpty == 0 && trabajos[i].idMoto == moto)
        {
            mostrarTrabajo(trabajos[i], servicios, tamServ);
        }
    }
}


void importesPorTrabajo(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamServ)
{
    float contador = 0;
    int moto;

    system("cls");

    mostrarMotos(motos, tamM, tipos, tamT, colores, tamC);

    printf("\nIngrese id de la moto: ");
    scanf("%d", &moto);

    while(buscarMoto(motos, tamM, moto) == -1)
    {
        printf("\nError, reingrese id de la moto: ");
        scanf("%d", &moto);
    }

    for(int i = 0; i < tamTrabajo; i++)
    {
        if(trabajos[i].isEmpty == 0 && trabajos[i].idMoto == moto)
        {
            for(int s = 0; s < tamServ; s++)
            {
                if(trabajos[i].idServicio == servicios[s].id)
                {
                    contador += servicios[s].precio;
                }
            }
        }
    }

    printf("\nEl precio que debe pagar esta moto por todos los trabajos es: %.2f\n", contador);
}


void mostrarMotosPorServicio(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamServ)
{
    int servicio;

    system("cls");

    mostrarServicios(servicios, tamServ);

    printf("\nIngrese id del servicio: ");
    scanf("%d", &servicio);

    while(validarServicio(servicios, tamServ, servicio) == -1)
    {
        printf("\nError, reingrese id del servicio: ");
        scanf("%d", &servicio);
    }


    printf("---------------------------------------------------------\n");
    printf("  ID Trabajo   ID Moto        Servicio         Fecha\n");
    printf("---------------------------------------------------------\n");

    for(int i = 0; i < tamTrabajo; i++)
    {
        if(trabajos[i].isEmpty == 0 && trabajos[i].idServicio == servicio)
        {
            mostrarTrabajo(trabajos[i], servicios, tamServ);
        }
    }

}


void mostrarTrabajosPorFecha(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamServ)
{
    eFecha auxFecha;
    int flag = 0;

    system("cls");

    printf("\nIngrese una fecha para ver los trabajos dd/mm/aaaa : ");
    fflush(stdin);
    scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);

    while(validarFecha(auxFecha.dia, auxFecha.mes, auxFecha.anio) == 1)
    {
        printf("Error, fecha invalida. Reingrese fecha del trabajo dd/mm/aaaa : ");
        fflush(stdin);
        scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
    }

    printf("---------------------------------------------------------\n");
    printf("  ID Trabajo   ID Moto        Servicio         Fecha\n");
    printf("---------------------------------------------------------\n");

    for(int i = 0; i < tamTrabajo; i++)
    {
        if(trabajos[i].isEmpty == 0 && trabajos[i].fecha.dia == auxFecha.dia && trabajos[i].fecha.mes == auxFecha.mes && trabajos[i].fecha.anio == auxFecha.anio)
        {
            mostrarTrabajo(trabajos[i], servicios, tamServ);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\n     No hay trabajos realizados este dia.\n");
    }
}





