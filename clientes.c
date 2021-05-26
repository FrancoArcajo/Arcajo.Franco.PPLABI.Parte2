#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "clientes.h"

void mostrarCliente(eCliente cliente)
{
    printf("   %4d%20s          %c\n",cliente.id, cliente.nombre, cliente.sexo);
}

void mostrarClientes(eCliente clientes[], int tam)
{
    if(clientes != NULL && tam > 0)
    {
        printf("\n  *** LISTADO DE CLIENTES ***  \n\n");
        printf("     ID             NOMBRE           SEXO\n");

        for(int i = 0; i < tam; i++)
        {
            mostrarCliente(clientes[i]);
        }
        printf("\n\n");
    }
}

int cargarNombreCliente(eCliente clientes[], int tam, int id, char nombre[])
{
    int error = 1;
    if(clientes != NULL && tam > 0 && id > 0 && nombre != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(clientes[i].id == id)
            {
                strcpy(nombre, clientes[i].nombre);
                error = 0;
                break;
            }
        }
    }
    return error;
}
