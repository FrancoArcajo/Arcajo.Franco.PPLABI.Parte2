#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicios.h"
#include "trabajos.h"

void mostrarServicio(eServicio servicios)
{
    printf("   %4d%20s    %3.2f\n",servicios.id,servicios.descripcion, servicios.precio);
}

void mostrarServicios(eServicio servicios[], int tam)
{
    if(servicios != NULL && tam > 0)
    {
        printf("\n  *** LISTADO DE SERVICIOS ***  \n\n");
        printf("     ID             DESCRIPCION PRECIO\n\n");
        for(int i = 0; i < tam; i++)
        {
          mostrarServicio(servicios[i]);
        }
        printf("\n\n");
    }
}

int cargarDescripcionServicio(eServicio servicios[], int tamServicio, int idServicio, char descripcion[])
{
    int error = 1;
    if(servicios != NULL && tamServicio > 0 && idServicio > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tamServicio; i++)
        {
            if(servicios[i].id == idServicio)
            {
                strcpy(descripcion, servicios[i].descripcion);
                error = 0;
                break;
            }
        }
    }
    return error;
}
