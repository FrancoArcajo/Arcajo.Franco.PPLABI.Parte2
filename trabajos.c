#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "trabajos.h"
#include "validaciones.h"
#include "dataStoreTrabajo.h"


int inicializarTrabajo(eTrabajo trabajos[], int tamTrabajos)
{
    int error = 1;

    if(trabajos != NULL && tamTrabajos > 0)
    {
        for(int i=0; i<tamTrabajos; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarTrabajo(eTrabajo unTrabajo, eNotebook notebooks[], int tam, eServicio servicios[], int tamServicios)
{
    char auxServicio[20];
    char auxNotebook[20];
    if(!cargarDescripcionServicio(servicios, tamServicios, unTrabajo.idServicio, auxServicio) && (!cargarDescripcionNotebook(notebooks, tam, unTrabajo.idNotebook, auxNotebook)))
    {
        printf("%4d     %8s       %15s       %2d/%2d/%4d\n", unTrabajo.id, auxNotebook, auxServicio, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);
    }
    else
    {
        printf("Problema para recuperar la descripcion\n");
    }
}
int mostrarTrabajos(eTrabajo trabajos[], int tamTrabajos, eNotebook notebooks[], int tamNote, eServicio servicios[], int tamServicios)
{
    int flag = 0;
    int error = 1;

    if(trabajos != NULL && tamTrabajos > 0 && notebooks != NULL && tamNote > 0 && servicios != NULL && tamServicios > 0)
    {
        printf("  *** LISTADO DE TRABAJOS ***  \n\n");
        printf("    ID      NOTEBOOK         SERVICIO          FECHA   \n");
        for(int i = 0; i < tamTrabajos; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i], notebooks, tamNote, servicios, tamServicios);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("No hay trabajos en la lista\n");
        }
        error = 0;
    }
    return error;
}

int altaTrabajos(eTrabajo trabajos[], int tamTrabajo,int idTrabajo,eNotebook notebooks[],int tamNote, eMarca marcas[], int tamMarca,eTipo tipos[],int tamTipo,eServicio servicios[],int tamServicio, eCliente clientes[], int tamCliente)
{
    int error = 1;
    int indice;
    int idNotebook;
    int idServicio;
    eTrabajo nuevoTrabajo;

    if(trabajos != NULL && tamTrabajo > 0 && notebooks != NULL && tamNote > 0 && servicios != NULL && tamServicio > 0 && clientes != NULL && tamCliente > 0){

        system("cls");
        printf("  *** ALTA DE TRABAJO ***\n\n");

        indice = buscarLibreTrabajo(trabajos, tamTrabajo);
        if(indice == -1){
            printf("Sistema Completo.\n");
        }else{
            nuevoTrabajo.id = idTrabajo;
            nuevoTrabajo.isEmpty = 0;

            mostrarNotebooks(notebooks, tamNote, tipos, tamTipo, marcas, tamMarca, clientes, tamCliente);
            printf("Ingrese id de la notebook: ");
            scanf("%d", &idNotebook);
            while(validarNotebook(notebooks, tamNote, idNotebook)){
                printf("Id invalido. Reingrese id de la notebook: ");
                scanf("%d", &idNotebook);
            }
            nuevoTrabajo.idNotebook = idNotebook;

            mostrarServicios(servicios, tamServicio);
            printf("Ingrese id del servicio: ");
            scanf("%d", &idServicio);
            while(validarServicio(servicios, tamServicio, idServicio) == 1){
                printf("Id invalido. Reingrese id del servicio: ");
                scanf("%d", &idServicio);
            }
            nuevoTrabajo.idServicio = idServicio;

            printf("Ingrese fecha del trabajo dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
            while(validarFecha(nuevoTrabajo.fecha) == 1){
                printf("Fecha invalida. Reingrese fecha del trabajo dd/mm/aaaa(año no menor a 2010 o mayor a 2021): ");
                scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
            }

            trabajos[indice] = nuevoTrabajo;
            error = 0;
            printf("Alta realizada con exito\n");
        }

    }
    return error;
}

int cargarDescripcionNotebook(eNotebook notebooks[], int tam, int idNote,char descripcionNote[])
{
    int error = 1;

    if(notebooks != NULL && tam > 0 && idNote > 0 && descripcionNote != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(notebooks[i].idNote == idNote)
            {
                strcpy(descripcionNote,notebooks[i].modelo);
                error = 0;
                break;
            }
        }
    }
    return error;
}

int harcodearTrabajos(eTrabajo trabajos[],int tam,int cant)
{
    int retorno = -1;

    if(trabajos != NULL && tam > 0 && cant <= tam)
    {
        retorno = 0 ;

        for(int i=0; i<cant; i++)
        {
            trabajos[i].id = idTrabajos[i];
            trabajos[i].idNotebook = idNotebook[i];
            trabajos[i].idServicio = idServ[i];
            trabajos[i].fecha = fechaTrabajo[i];
            trabajos[i].isEmpty = 0;

            retorno++;
        }
    }
    return retorno;
}
