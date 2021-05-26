#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "marcas.h"
#include "notebooks.h"
#include "tipos.h"

void mostrarMarca(eMarca unaMarca)
{
    printf("   %4d%20s\n",unaMarca.idMarca,unaMarca.descripcion);
}

void mostrarMarcas(eMarca marcas[], int tam)
{
    if(marcas != NULL && tam > 0)
    {
        printf("\n  *** LISTADO DE MARCAS ***  \n\n");
        printf("     ID          DESCRIPCION\n");

        for(int i = 0; i < tam; i++)
        {
            mostrarMarca(marcas[i]);
        }
        printf("\n\n");
    }
}

int cargarDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[])
{
    int error = 1;
    if(marcas != NULL && tam > 0 && id > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(marcas[i].idMarca == id)
            {
                strcpy(descripcion, marcas[i].descripcion);
                error = 0;
                break;
            }
        }
    }
    return error;
}
