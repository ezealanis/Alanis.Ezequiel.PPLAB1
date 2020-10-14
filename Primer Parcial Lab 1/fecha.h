#ifndef FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

#define FECHA_H_INCLUDED

int validarFecha(int dia, int mes, int anio);
char menu();

#endif // FECHA_H_INCLUDED
