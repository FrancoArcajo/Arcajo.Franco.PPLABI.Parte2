#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "notebooks.h"
#include "trabajos.h"
#include "tipos.h"
#include "marcas.h"
#include "servicios.h"
#include "clientes.h"
#include "informes.h"
#include "menu.h"

#define TAM 50
#define TAM_M 4
#define TAM_T 4
#define TAM_S 4
#define TAM_TR 50
#define TAM_CL 10

int main()
{
    int flag = 0;
    char seguir = 's';
    char confirma;
    int proximoId = 100;
    int proximoIdTrabajo = 1;
    int rta;

    eNotebook lista[TAM];
    eTrabajo listaTr [TAM_TR];

    eTipo tipos[TAM_T] =
    {
        {5000, "Gamer"},
        {5001, "Disenio"},
        {5002, "Ultrabook"},
        {5003, "Normalita"}
    };

    eMarca marcas[TAM_M] =
    {
        {1000, "Asus"},
        {1001, "Acer"},
        {1002, "HP"},
        {1003, "Compaq"}
    };

    eServicio servicios[TAM_S] =
    {
        {20000, "Bateria", 250},
        {20001, "Antivirus", 300},
        {20002, "Actualizacion", 400},
        {20003, "Fuente", 600}
    };

    eCliente listaCliente[TAM_CL] =
    {
        {2000,"Franco", 'm'},
        {2001,"Victoria", 'f'},
        {2002,"Fernando", 'm'},
        {2003,"Federico", 'm'},
        {2004,"Damian", 'm'},
        {2005,"Gabriela", 'f'},
        {2006,"Marcelo", 'm'},
        {2007,"Juana", 'f'},
        {2008,"Silvina", 'f'},
        {2009,"Florencia", 'f'}
    };

    if(!inicializarNotebooks(lista,TAM))
    {
        printf("Inicializacion exitosa!\n");
    }
    else
    {
        printf("Fallo al inicializar");
    }

    proximoId += harcodearNotebooks(lista, TAM, 20);

    if(!inicializarTrabajo(listaTr,TAM_TR))
    {
        printf("Inicializacion exitosa!\n");
    }
    else
    {
        printf("Fallo al inicializar");
    }

    proximoIdTrabajo += harcodearTrabajos(listaTr, TAM_TR, 20);

    do
    {
        switch(menu())
        {

        case 1:
            if(!altaNotebook(lista, TAM, marcas, TAM_M, tipos, TAM_T, listaCliente, TAM_CL, proximoId))
            {
                proximoId++;
                printf("Alta realizada con exito\n\n");
                flag = 1;
            }
            else
            {
                printf("No se pudo realizar el alta.\n\n");
            }
            break;
        case 2:
            if(flag == 1)
            {
                rta = modificarNotebook(lista, TAM, tipos, TAM_T, marcas, TAM_M, listaCliente, TAM_CL);

                if(!rta)
                {
                    printf("Se ha modificado con exito.\n\n");
                }
                else if(rta == 2)
                {
                    printf("Modificacion cancelada por el usuario. \n\n");
                }
                else
                {
                    printf("Hubo un problema al intentar realizar la modificacion. \n\n");
                }
            }
            else
            {
                printf("Primero debe realizar un alta. \n");
            }
            break;
        case 3:
            if(flag == 1)
            {
                rta = bajaNotebook(lista, TAM, tipos, TAM_T, marcas, TAM_M, listaCliente, TAM_CL);

                if(!rta)
                {
                    printf("Se ha dado de baja con exito.\n\n");
                }
                else if(rta == 2)
                {
                    printf("baja cancelada por el usuario. \n\n");
                }
                else
                {
                    printf("Hubo un problema al intentar realizar la baja. \n\n");
                }
            }
            else
            {
                printf("Primero debe realizar un alta. \n");
            }
            break;
        case 4:
            if(flag == 1)
            {
                system("cls");
                ordenarNotebooksPorMarcayPrecio(lista, TAM, marcas, TAM_M, listaCliente, TAM_CL);
                mostrarNotebooks(lista, TAM, tipos,TAM_T, marcas, TAM_M, listaCliente, TAM_CL);
            }
            else
            {
                printf("Primero debe realizar un alta. \n");
            }
            break;
        case 5:
            system("cls");
            mostrarTipos(tipos, TAM_T);
            break;
        case 6:
            system("cls");
            mostrarMarcas(marcas, TAM_M);
            break;
        case 7:
            system("cls");
            mostrarServicios(servicios, TAM_S);
            break;
        case 8:
            system("cls");
            if(flag == 1)
            {
                if(!altaTrabajos(listaTr, TAM_TR, proximoIdTrabajo, lista, TAM, marcas, TAM_M, tipos, TAM_T, servicios,TAM_S, listaCliente, TAM_CL))
                {
                    proximoIdTrabajo++;
                    flag=1;
                }
            }
            else
            {
                printf("Primero hacer un alta de bicicleta\n");
            }
            break;
        case 9:
            system("cls");
            mostrarTrabajos(listaTr,TAM_TR, lista, TAM, servicios, TAM_S);
            break;
        case 10:
            switch(menuInformes())
            {
            case 1:
                system("cls");
                notebooksTipoSeleccionado(lista, TAM, tipos, TAM_T, marcas, TAM_M, listaCliente,TAM_CL);
                break;
            case 2:
                system("cls");
                notebooksMarcaSeleccionada(lista, TAM, tipos, TAM_T, marcas, TAM_M, listaCliente,TAM_CL);
                break;
            case 3:
                system("cls");
                buscarMasBarata(lista, TAM, tipos, TAM_T, marcas, TAM_M, listaCliente,TAM_CL);
                break;
            case 4:
                system("cls");
                notebookSeparadaPorTipo(lista, TAM, tipos, TAM_T, marcas, TAM_M, listaCliente,TAM_CL);
                break;
            case 5:
                system("cls");
                contarPorTipoYMarca(lista, TAM, tipos, TAM_T, marcas, TAM_M, listaCliente,TAM_CL);
                break;
            case 6:
                system("cls");
                mostrarMarcaMasElegida(lista, TAM, marcas, TAM_M);
                break;
            case 7:
                system("cls");
                mostrarTrabajosNotebooks(listaTr, TAM_TR, lista, TAM, servicios, TAM_S,tipos, TAM_T,marcas, TAM_M, listaCliente, TAM_CL);
                break;
            case 8:
                system("cls");
                notebookImporteServicio(listaTr, TAM_TR, lista, TAM, servicios, TAM_S, proximoIdTrabajo, tipos, TAM_T,marcas, TAM_M, listaCliente, TAM_CL);
                break;
            case 9:
                system("cls");
                listarNotebooksPorFechaServicio(listaTr, TAM_TR, lista, TAM, servicios, TAM_S, tipos, TAM_T,marcas, TAM_M, listaCliente, TAM_CL);
                break;
            case 10:
                system("cls");
                fechaServicioNotebook(listaTr, TAM_TR, lista, TAM, servicios, TAM_S, tipos, TAM_T,marcas, TAM_M, listaCliente, TAM_CL);
                break;
            case 11:
                printf("Confirma salida?(s/n): ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                if(confirma == 's')
                {
                    seguir = 'n';
                }

                break;
            default:
                printf("Opcion invalida!!!\n");
            }
        }
        system("pause");

    }
    while( seguir == 's');

    return 0;
}
