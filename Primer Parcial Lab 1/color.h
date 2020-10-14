#ifndef COLOR_H_INCLUDED

typedef struct
{
    int id; // EMPIEZA EN 10000
    char descripcion[20];
} eColor;

#define COLOR_H_INCLUDED

void mostrarColor(eColor color);
void mostrarColores(eColor colores[], int tamC);
int validarColor(eColor colores[], int tamC, int id);
void cargarDescripcionColor(eColor colores[], int tamC, int id, char desc[]);

#endif // COLOR_H_INCLUDED
