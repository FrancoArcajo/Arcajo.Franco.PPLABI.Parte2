#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "notebooks.h"
#include "tipos.h"
#include "marcas.h"
#include "validaciones.h"
#include "dataStore.h"

int inicializarNotebooks(eNotebook notebooks[], int tam)
{
    int error = 1;

    if(notebooks != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            notebooks[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int altaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente, int id)
{

    int error = 1;
    int indice;
    int idMarca;
    int idTipo;
    int idCliente;
    eNotebook nuevaNotebook;

    if(notebooks != NULL && tam > 0 && tipos != NULL && tamTipo > 0 && marcas != NULL && tamMarca > 0 && clientes != NULL && tamCliente > 0)
    {

        system("cls");
        printf("  *** ALTA DE NOTEBOOK ***\n\n");

        indice = buscarLibre(notebooks, tam);
        if(indice == -1)
        {
            printf("Sistema Completo.\n");
        }
        else
        {
            nuevaNotebook.idNote = id;
            nuevaNotebook.isEmpty = 0;

            printf("Ingrese modelo: ");
            fflush(stdin);
            normalizeStr(gets(nuevaNotebook.modelo));

            while(validacionCadena(nuevaNotebook.modelo) == 1)
            {
                printf("Modelo invalido. Reingrese modelo: ");
                fflush(stdin);
                normalizeStr(gets(nuevaNotebook.modelo));
            }

            mostrarTipos(tipos, tamTipo);
            printf("Ingrese id del tipo: \n");
            fflush(stdin);
            scanf("%d", &idTipo);

            while(validarTipo(tipos, tamTipo, idTipo))
            {
                printf("Reingrese id del tipo: ");
                fflush(stdin);
                scanf("%d", &idTipo);
            }

            nuevaNotebook.idTipo = idTipo;

            mostrarMarcas(marcas, tamMarca);
            printf("Ingrese id de la marca: ");
            fflush(stdin);
            scanf("%d", &idMarca);

            while(validarMarca(marcas, tamMarca, idMarca) == 1)
            {
                printf("Reingrese id del color: ");
                fflush(stdin);
                scanf("%d", &idMarca);
            }

            nuevaNotebook.idMarca = idMarca;

             printf("Ingrese precio (entre 5000 y 99999): ");
            fflush(stdin);
            scanf("%f", &nuevaNotebook.precio);

            while(validarPrecio(nuevaNotebook.precio) == 1)
            {
                printf("Reingrese precio (entre 5000 y 99999): ");
                fflush(stdin);
                scanf("%f", &nuevaNotebook.precio);
            }

            mostrarClientes(clientes, tamCliente);
            printf("Ingrese id del cliente: ");
            fflush(stdin);
            scanf("%d", &idCliente);
            while(validarCliente(clientes, tamCliente, idCliente) == 1)
            {
                printf("Id invalido. Reingrese id del cliente: ");
                fflush(stdin);
                scanf("%d", &idCliente);
            }

            nuevaNotebook.idCliente = idCliente;
            notebooks[indice] = nuevaNotebook;

            error = 0;
        }
    }
    return error;
}

int buscarLibre(eNotebook notebooks[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(notebooks[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarNotebooks(eNotebook notebooks[], int tam, int id)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(notebooks[i].idNote == id && !notebooks[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int mostrarNotebooks(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente)
{
    int flag = 0;
    int error = 1;

    if(notebooks != NULL && tam > 0 && tipos != NULL && tamTipo > 0 && marcas != NULL && tamMarca > 0 && clientes != NULL && tamCliente > 0)
    {

        printf("                                      *** NOTEBOOKS ***  \n\n");
        printf("   ID               MODELO         PRECIO             MARCA                TIPO              CLIENTE               \n\n");
        for(int i = 0; i < tam; i++)
        {
            if(!notebooks[i].isEmpty)
            {
                mostrarNotebook(notebooks[i], tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("        No hay notebooks en la lista\n");
        }
        error = 0;
    }
    return error;
}

void mostrarNotebook(eNotebook unaNotebook, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente)
{
    char descNotebookTipo[20];
    char descNotebookMarca[20];
    char nombreCliente[20];
    if(!cargarDescripcionTipo(tipos, tamTipo, unaNotebook.idTipo, descNotebookTipo) && (!cargarDescripcionMarca(marcas, tamMarca, unaNotebook.idMarca, descNotebookMarca)) && (!cargarNombreCliente(clientes, tamCliente, unaNotebook.idCliente, nombreCliente)))
    {
        printf(" %5d    %15s         %.2f    %15s     %15s     %15s  \n",unaNotebook.idNote, unaNotebook.modelo,unaNotebook.precio, descNotebookMarca, descNotebookTipo, nombreCliente);
    }/*else{
        printf("Problema para recuperar la descripcion\n");
    }*/
}

int bajaNotebook(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente)
{
    int id;
    int indice;
    int error = 1;
    char confirma;

    if(notebooks != NULL && tam > 0 && tipos != NULL && tamTipo > 0 && marcas != NULL && tamMarca > 0 && clientes != NULL && tamCliente > 0 )
    {
        system("cls");
        printf("  *** BAJA DE NOTEBOOK ***\n\n");

        mostrarNotebooks(notebooks, tam, tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
        printf("Ingrese id: ");
        fflush(stdin);
        scanf("%d", &id);

        indice = buscarNotebooks(notebooks, tam, id);

        if(indice == -1)
        {
            printf("No hay ninguna notebook con ese id\n");
        }
        else
        {
            mostrarNotebook(notebooks[indice],tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
            printf("Confirma baja(s/n)? ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's' || confirma == 'S')
            {
                notebooks[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }
    return error;
}

int modificarNotebook(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente)
{
    char confirmacion;
    int id;
    int indice;
    int error = 1;
    int opcion;
    int flagSalir = 0;
    int flagDef = 0;
    int idTipo;
    eNotebook auxNotebook;

    if(notebooks != NULL && tamN > 0 && tipos != NULL && tamTipo > 0 && marcas != NULL && tamMarca > 0 && clientes != NULL && tamCliente > 0)
    {

        system("cls");
        printf("        *** MODIFICAR NOTEBOOK ***\n\n");

        mostrarNotebooks(notebooks, tamN, tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarNotebooks(notebooks, tamN, id);
        auxNotebook = notebooks[indice];

        if(indice == -1)
        {
            printf("No hay ninguna notebook con ese ID\n");
        }
        else
        {
            system("cls");

            printf("*** MODIFICAR NOTEBOOKS ***\n\n");
            mostrarNotebook(notebooks[indice], tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
            printf("1) MODIFICAR TIPO.\n");
            printf("2) MODIFICAR PRECIO.\n");
            printf("3) MENU ANTERIOR.\n");
            printf("Seleccione una opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                mostrarTipos(tipos, tamTipo);
                printf("Ingrese id del nuevo tipo: ");
                fflush(stdin);
                scanf("%d", &idTipo);
                while(validarTipo(tipos, tamTipo, idTipo) == 1)
                {
                    printf("Id invalido. Reingrese id del tipo: ");
                    fflush(stdin);
                    scanf("%d", &idTipo);
                }
                auxNotebook.idTipo = idTipo;
                break;
            case 2:
                printf("Ingrese nuevo precio (entre 5000 a 99999): ");
                scanf("%f", &auxNotebook.precio);

                while(validarPrecio(auxNotebook.precio))
                {
                    printf("Reingrese precio (entre 5000 a 99999): ");
                    fflush(stdin);
                    scanf("%f", &auxNotebook.precio);
                }
                break;
            case 3:
                flagSalir = 1;
                error = 2;
                break;
            default:
                flagDef = 1;
                printf("Opcion no valida\n");
                break;
            }
            if(!flagSalir && !flagDef)
            {
                printf("Confirma la modificacion(s/n)? ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                if(confirmacion == 's')
                {
                    notebooks[indice] = auxNotebook;
                    error = 0;
                }
                else
                {
                    error = 2;
                }
            }
        }
    }
    return error;
}

int ordenarNotebooksPorMarcayPrecio(eNotebook notebooks[],int tamN, eMarca marcas[],int tamMarca, eCliente clientes[], int tamCliente)
{
    eNotebook auxNotebook;
    int todoOk = 0;

    if(notebooks != NULL && tamN > 0)
    {

        for(int i = 0; i < tamN -1; i++)
        {
            for(int j = i +1; j < tamN; j++)
            {
                if(notebooks[i].idMarca > notebooks[j].idMarca || (notebooks[i].idMarca == notebooks[j].idMarca && notebooks[i].precio > notebooks[j].precio))
                {
                    auxNotebook = notebooks[i];
                    notebooks[i] = notebooks[j];
                    notebooks[j] = auxNotebook;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int harcodearNotebooks(eNotebook notebooks[],int tam,int cant)
{
    int retorno = -1;

    if(notebooks != NULL && tam > 0 && cant <= tam)
    {
        retorno = 0 ;

        for(int i=0; i<cant; i++)
        {
            notebooks[i].idNote = idNote[i];
            strcpy(notebooks[i].modelo, modelos[i]);
            notebooks[i].idTipo = idDeTipos[i];
            notebooks[i].idMarca = idMarca[i];
            notebooks[i].precio = precio[i];
            notebooks[i].idCliente = idCliente[i];
            notebooks[i].isEmpty = 0;

            retorno++;
        }
    }
    return retorno;
}

int buscarNotebooksPorId(int idNote, eNotebook notebooks[], int tamNote)
{
    int indice = -1;

    for(int i=0; i < tamNote; i++)
    {
        if(notebooks[i].idNote == idNote && notebooks[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
