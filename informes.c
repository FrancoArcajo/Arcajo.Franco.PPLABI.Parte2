#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "informes.h"
#include "menu.h"
#include "notebooks.h"
#include "trabajos.h"

int notebooksTipoSeleccionado(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca,eCliente clientes[], int tamCliente)
{
    int error = -1;
    int idTipo;
    int flag =0;

    if(notebooks != NULL && tamN > 0 && marcas != NULL && tamMarca > 0 && tipos != NULL && tamTipo > 0)
    {
        system("cls");
        printf("LISTADO DE NOTEBOOKS POR TIPO\n");

        mostrarTipos(tipos,tamTipo);
        printf("Ingrese el id del tipo que desea listar: \n");
        fflush(stdin);
        scanf("%d",&idTipo);
        while(validarTipo(tipos,tamTipo,idTipo))
        {
            system("cls");
            mostrarTipos(tipos,tamTipo);
            printf("Reingrese el id del tipo por uno valido: \n");
            fflush(stdin);
            scanf("%d",&idTipo);
        }
        system("cls");
        printf("   ID              MODELO          PRECIO             MARCA               TIPO            CLIENTE\n\n");
        for(int i=0; i < tamN; i++)
        {
            if(!notebooks[i].isEmpty && (notebooks[i].idTipo == idTipo))
            {
                mostrarNotebook(notebooks[i],tipos, tamTipo, marcas,tamMarca,clientes, tamCliente);
                flag = 1;
            }
        }
        printf("\n\n");
        if(!flag)
        {
            printf("No se ingreso ninguna notebook\n");
        }
        error = 0;
    }
    return error;
}

int notebooksMarcaSeleccionada(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente)
{
     int error = -1;
    int idMarca;
    int flag =0;

    if(notebooks != NULL && tamN > 0 && marcas != NULL && tamMarca > 0 && tipos != NULL && tamTipo > 0)
    {
        system("cls");
        printf("LISTADO DE NOTEBOOKS POR MARCA\n");

        mostrarMarcas(marcas,tamMarca);
        printf("Ingrese el id de la marca que desea listar: \n");
        fflush(stdin);
        scanf("%d",&idMarca);
        while(validarMarca(marcas,tamMarca,idMarca))
        {
            system("cls");
            mostrarMarcas(marcas,tamMarca);
            printf("Reingrese el id de la marca por uno valido: \n");
            fflush(stdin);
            scanf("%d",&idMarca);
        }
        system("cls");
        printf("   ID              MODELO          PRECIO             MARCA               TIPO            CLIENTE\n\n");
        for(int i=0; i < tamN; i++)
        {
            if(!notebooks[i].isEmpty && (notebooks[i].idMarca == idMarca))
            {
                mostrarNotebook(notebooks[i],tipos, tamTipo, marcas,tamMarca,clientes, tamCliente);
                flag = 1;
            }
        }
        printf("\n\n");
        if(!flag)
        {
            printf("No se ingreso ninguna notebook\n");
        }
        error = 0;
    }
    return error;
}

int buscarMasBarata(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente)
{
    int flag = 0;
    int menor;
    int flagMenor = 0;
    int error = 1;

    if(notebooks != NULL && tamN > 0 && tipos != NULL &&  tamTipo > 0 && marcas != NULL && tamMarca > 0 && clientes != NULL && tamCliente > 0)
    {

        printf("  *** NOTEBOOK MAS BARATA ***  \n\n");
        printf("    ID             MODELO          PRECIO             MARCA               TIPO             CLIENTE\n");
        for(int i = 0; i < tamN; i++)
        {
            if(!notebooks[i].isEmpty && (notebooks[i].precio < menor || flagMenor == 0))
            {
                menor = notebooks[i].precio;
                flagMenor = 1;
            }
        }
        for(int i = 0; i < tamN; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].precio == menor)
            {
                mostrarNotebook(notebooks[i],tipos,tamTipo,marcas,tamMarca,clientes,tamCliente);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf(" No hay notebooks en la lista\n");
        }
        error = 0;
    }
    return error;

}

int notebookSeparadaPorTipo(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca,eCliente clientes[], int tamCliente)
{
    int flag;
    int error = -1;
    system("cls");
    printf("***** INFORME NOTEBOOKS POR TIPO *****\n\n");
    for(int i=0; i < tamTipo; i++)
    {
        flag=0;
        printf(" \n Tipo: %s\n",tipos[i].descripcion);
        printf(" ------\n\n");
        for(int j=0; j<tamN; j++)
        {
            if(notebooks[j].isEmpty == 0 && notebooks[j].idTipo == tipos[i].idTipo)
            {
                mostrarNotebook(notebooks[j],tipos,tamTipo, marcas, tamMarca, clientes,tamCliente);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay notebook en este sector\n\n");
        }
    }
    return error;
}


int contarPorTipoYMarca(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente)
{
    int idTipo;
    int idMarca;
    int contador = 0;
    int error = 1;

    if(notebooks != NULL  && tamN > 0 && tipos != NULL && tamTipo > 0 && marcas != NULL && tamMarca > 0  && clientes != NULL &&  tamCliente > 0)
    {
        system("cls");
        mostrarMarcas(marcas, tamMarca);
        printf("Ingrese id de la marca: ");
        fflush(stdin);
        scanf("%d", &idMarca);

        while(validarMarca(marcas, tamMarca, idMarca) == 1)
        {
            printf("Id invalido. Reingrese id de la marca: ");
            fflush(stdin);
            scanf("%d", &idMarca);
        }

        system("cls");
        mostrarTipos(tipos, tamTipo);
        printf("Ingrese id del tipo: ");
        fflush(stdin);
        scanf("%d", &idTipo);

        while(validarTipo(tipos, tamTipo, idTipo) == 1)
        {
            printf("Id invalido. Reingrese id del tipo: ");
            fflush(stdin);
            scanf("%d", &idTipo);
        }


        system("cls");
        printf("*** CONTADOR POR TIPO Y MARCA ***\n\n");

        for(int i = 0; i < tamN; i++)
        {
            if(notebooks[i].idMarca == idMarca && notebooks[i].idTipo == idTipo)
            {
                contador++;
            }
        }
        printf("Hay %d notebooks de esa marca  y tipo\n\n", contador);

    }
    return error;
}

int mostrarMarcaMasElegida(eNotebook notebooks[], int tamN, eMarca marcas[], int tamMarca)
{
    int mayor;
    int flag = 0;
    int contadores[tamMarca];
    int error = 1;

    if(notebooks != NULL && tamN > 0 && marcas != NULL && tamMarca > 0)
    {
        for(int i = 0; i < tamMarca; i++)
        {
            contadores[i] = 0;
        }

        for(int i = 0; i < tamMarca; i++)
        {
            for(int j = 0; j < tamN; j++)
            {
                if(notebooks[j].isEmpty == 0 && notebooks[j].idMarca == marcas[i].idMarca)
                {
                    contadores[i]++;
                }
            }
        }

        for(int i = 0; i < tamMarca; i++)
        {
            if(contadores[i] > mayor || flag == 0)
            {
                mayor = contadores[i];
                flag = 1;
            }
        }

        printf("*** MARCA CON MAYOR CANTIDAD ***\n\n");
        printf("\nLa o las marcas  mas elegidas son: \n");

        for(int i = 0; i < tamMarca; i++)
        {
            if(contadores[i] == mayor)
            {
                printf("%s\n", marcas[i].descripcion);
            }
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int mostrarTrabajosNotebooks(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamN, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamClientes)
{
    int error = -1;
    int idNotebook;

    if(trabajos != NULL && tamTr > 0 && notebooks != NULL && tamN > 0 && servicios != NULL && tamServ > 0 && marcas != NULL && tamMarca > 0 && tipos != NULL && tamTipo > 0 && clientes != NULL && tamClientes > 0)
    {
        system("cls");
        mostrarNotebooks(notebooks,tamN,tipos, tamTipo, marcas,tamMarca,clientes, tamClientes);
        printf("Ingrese id de la notebook: ");
        fflush(stdin);
        scanf("%d", &idNotebook);
        while(validarNotebook(notebooks,tamN,idNotebook))
        {
            printf("Reingrese id de la notebook: ");
            fflush(stdin);
            scanf("%d", &idNotebook);;
        }
        system("cls");

        printf("TRABAJO POR NOTEBOOK\n\n");
        printf("  ID           MODELO              SERVICIO           FECHA\n\n");

        for(int i=0; i < tamTr; i++)
        {
            if(trabajos[i].idNotebook == idNotebook && !trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i],notebooks,tamN,servicios,tamServ);
                error = 0;
            }
        }
    }
    return error;
}

int notebookImporteServicio(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamN, eServicio servicios[], int tamServ, int id, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamClientes)
{
    int error = 1;
    int flag = 0;
    int idNotebook;
    int precioServicios = 0;

    if(trabajos != NULL && tamTr > 0 && notebooks != NULL && tamN > 0 && servicios != NULL && tamServ > 0 && clientes != NULL && tamClientes > 0)
    {
        system("cls");
        printf("*** IMPORTE POR NOTEBOOK ***\n\n");
        mostrarNotebooks(notebooks, tamN, tipos, tamTipo, marcas, tamMarca, clientes, tamClientes);
        printf("Ingrese id de la notebook: ");
        fflush(stdin);
        scanf("%d", &idNotebook);
        while(validarNotebook(notebooks, tamN, idNotebook))
        {
            printf("Id invalido. Reingrese id de la notebook: ");
            fflush(stdin);
            scanf("%d", &idNotebook);
        }
        system("cls");
        for(int i = 0; i < tamTr; i++)
        {
            if(!trabajos[i].isEmpty && trabajos[i].idNotebook == idNotebook)
            {
                for(int j = 0; j < tamN; j++)
                {
                    if(servicios[j].id == trabajos[i].idServicio)
                    {
                        precioServicios += servicios[j].precio;
                        flag = 1;
                    }
                }
            }
        }

        printf("    *** IMPORTE POR NOTEBOOK ***  \n\n");
        printf("La suma de los importes por los servicios de esta notebook es de $%d\n\n", precioServicios);

        if(!flag)
        {
            printf("No se le realizo ningun trabajo a esta notebook.\n\n");
        }
    }
    return error;
}

int listarNotebooksPorFechaServicio(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamN, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamClientes)
{
    int error;
    int auxIdServ;
    int flag = 0;

    mostrarServicios(servicios,tamServ);
    printf("\n\n");

    if(!(utn_getEntero(&auxIdServ,2,"Ingrese el ID del servicio: ","Error. Ingrese un id valido.\n",20000,20003)))
    {
        system("cls");
        printf("  ID         MODELO               DESCRIPCION     FECHA\n\n");
        for(int i = 0; i < tamServ; i++)
        {
            for(int j = 0;  j< tamTr; j++)
            {
                if(auxIdServ == servicios[i].id && trabajos[j].idServicio == auxIdServ)
                {
                    mostrarTrabajo(trabajos[j],notebooks, tamN, servicios,tamServ);
                    error = 0;
                    flag = 1;
                }
            }
        }

        if(!flag)
        {
            printf("No hay notebooks con ese servicio.\n\n");
        }
    }

    return error;
}

int fechaServicioNotebook(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamN, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamClientes)
{
    int error = 1;
    int flag = 0;
    eFecha fecha;

    if(trabajos != NULL && tamTr > 0 && notebooks != NULL && tamN > 0 && servicios != NULL && tamServ > 0 && clientes != NULL && tamClientes > 0)
    {
        system("cls");
        printf("*** SERVICIOS POR FECHA ***\n\n");
        printf("Ingrese fecha del trabajo dd/mm/aaaa: ");
        fflush(stdin);
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
        while(validarFecha(fecha) == 1)
        {
            printf("Fecha invalida. Reingrese fecha del trabajo dd/mm/aaaa: ");
            fflush(stdin);
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
        }
        system("cls");
        printf("Los servicios realizados en la fecha %d/%d/%d son: \n\n\n", fecha.dia, fecha.mes, fecha.anio);
        printf("     ID         DESCRIPCION       PRECIO\n");

        for(int i = 0; i < tamTr; i++)
        {
            if(!trabajos[i].isEmpty && trabajos[i].fecha.dia == fecha.dia && trabajos[i].fecha.mes == fecha.mes && trabajos[i].fecha.anio == fecha.anio)
            {
                for(int j = 0; j < tamServ; j++)
                {
                    if(servicios[j].id == trabajos[i].idServicio)
                    {
                        mostrarServicio(servicios[j]);
                        flag = 1;
                    }
                }
                if(!flag)
                {
                    printf("No se le realizo ningun trabajo a esta notebook.\n\n");
                }
            }
        }
    }
    return error;
}
