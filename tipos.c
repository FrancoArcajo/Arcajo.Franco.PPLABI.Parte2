#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipos.h"
#include "notebooks.h"
#include "marcas.h"

void mostrarTipo(eTipo tipos)
{
    printf("   %4d%20s\n",tipos.idTipo,tipos.descripcion);
}

void mostrarTipos(eTipo tipos[], int tam)
{
    if(tipos != NULL && tam > 0)
    {
        printf("\n *** LISTADO DE TIPOS ***  \n\n");
        printf("     ID          DESCRIPCION\n");

        for(int i = 0; i < tam; i++)
        {
            mostrarTipo(tipos[i]);
        }
        printf("\n\n");
    }
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[])
{
    int error = 1;
    if(tipos != NULL && tam > 0 && id > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(tipos[i].idTipo == id)
            {
                strcpy(descripcion, tipos[i].descripcion);
                error = 0;
                break;
            }
        }
    }
    return error;
}

