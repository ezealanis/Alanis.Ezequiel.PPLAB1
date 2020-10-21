#ifndef TIPO_H_INCLUDED

typedef struct
{
    int id; // EMPIEZA EN 1000
    char descripcion[20];
} eTipo;

#define TIPO_H_INCLUDED

void mostrarTipo(eTipo tipo);
void mostrarTipos(eTipo tipos[], int tamT);
int validarTipo(eTipo tipos[], int tamT, int id);
void cargarDescripcionTipo(eTipo tipos[], int tamT, int id, char desc[]);

#endif // TIPO_H_INCLUDED
