#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "fecha.h"

int validarTipo(eTipo tipos[], int tamT, int idTipo)
{
    int esValido = 1;

    if(tipos != NULL && tamT > 0 && idTipo > 0)

        for(int i=0; i < tamT; i++)
        {
            if(tipos[i].idTipo == idTipo)
            {
                esValido = 0;
                break;
            }
        }
    return esValido;
}

int validarNotebook(eNotebook notebooks[],int tam,int idNote)
{
    int esValido = 1;

    if(notebooks != NULL && tam > 0 && idNote > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(notebooks[i].idNote == idNote && notebooks[i].isEmpty == 0)
            {
                esValido = 0;
                break;
            }
        }
    }
    return esValido;
}

int validarServicio(eServicio servicios[], int tam, int idServicio)
{

    int esValido = 1;

    for(int i=0; i < tam; i++)
    {

        if(servicios[i].id == idServicio)
        {
            esValido = 0;
            break;
        }
    }
    return esValido;
}

int validarMarca(eMarca marcas[], int tam, int idMarca)
{
    int esValido = 1;

    for(int i=0; i < tam; i++)
    {

        if(marcas[i].idMarca == idMarca)
        {

            esValido = 0;

            break;
        }
    }
    return esValido;
}

int validarFecha(eFecha fecha)
{
    int error = 0;

    if(fecha.dia < 1 || fecha.dia > 31 || fecha.mes < 1 || fecha.mes > 12 || fecha.anio < 2010 || fecha.anio > 2021)
    {
        error = 1;
    }

    return error;
}


int validacionCadena(char cadena[])
{
    int error = 0;
    int flag = 0;
    int tamanio;

    tamanio = strlen(cadena);
    for(int i = 0; i < tamanio; i++)
    {
        if(!((cadena[i] >= 65 && cadena[i] <= 90) || (cadena[i] >= 97 && cadena[i] <= 122) || cadena[i] == ' '))
        {
            flag = 1;
            error = 1;
        }
    }
    if(cadena[0] == '\0' || cadena[0] == ' ')
    {
        flag = 1;
        error = 1;
    }
    if(flag == 1)
    {
        printf("Ingrese cadena valida(solo letras o espacios).\n");
    }
    return error;
}

int strLwr(char* str)
{
	int todoOk = -1;
	int i = 0;

	if(str != NULL)
	{
		while(str[i] != '\0')
		{
			str[i] = tolower(str[i]);
			i++;
		}
		todoOk = 0;
	}
	return todoOk;
}

int normalizeStr(char* str)
{
	int todoOk = -1;
	int i = 0;

	if(str != NULL)
	{
		strLwr(str);
		str[0] = toupper(str[0]);

		while(str[i] != '\0')
		{
			if(str[i] == ' ')
			{
				str[i + 1] = toupper(str[i + 1]);
				todoOk = 0;
			}
			i++;
		}
	}
	return todoOk;
}

int utn_getEntero(int* pEntero, int reintentos, char* mensaje, char* mensajeError, int minimo, int maximo)
{
    int todoOk = -1;
    int auxInt;

    if(pEntero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s", mensaje);

            if(getInt(&auxInt) == 0 && auxInt >= minimo && auxInt <= maximo)
            {
                *pEntero = auxInt;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}

int getInt(int* pAux)
{
    char auxString[400];
    int todoOk = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *pAux = atoi(auxString);
        todoOk = 0;
    }
    return todoOk;
}

int isInt(char *pAux)
{
    int todoOk = -1;
    int i = 0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) < '0' || *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        todoOk = 0;
    }

    return todoOk;
}

int getCadena(char* pAux, int limit)
{
    char auxString[4000];
    int todoOk = -1;

    if (pAux != NULL && limit > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limit)
        {
            strncpy(pAux, auxString, limit);
            todoOk = 0;
        }
    }
    return todoOk;
}

int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max)
{
    int isOk = -1;
    float auxFloat;

    if(pFloat != NULL&& msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat <= max)
            {
                *pFloat= auxFloat;
                isOk = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(retry >= 0);
    }
    return isOk;
}

int getFloat(float*pAux)
{
    char auxString[200];
    int isOk =-1;

    if(getCadena(auxString,200) == 0 && isFloat(auxString) == 0)
    {
        *pAux = atof(auxString);
        isOk = 0;
    }
    return isOk;
}

int isFloat(char* pAux)
{
    int isOk = -1;
    int i = 0;
    int dotCount=0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) == '.')
        {
            dotCount++;
            if(dotCount == 2)
            {
                break;
            }
        }
        else if(*(pAux + i) < '0'|| *(pAux + i) > '9')
        {
            break;
        }

        i++;
    }while (i < stringLong);

    if(i == stringLong)
    {
        isOk = 0;
    }
    return isOk;
}

int validarCliente(eCliente clientes[], int tam, int idCliente)
{
    int esValido = 1;

    for(int i =  0; i < tam; i++)
    {

        if(clientes[i].id == idCliente)
        {

            esValido = 0;

            break;
        }
    }
    return esValido;
}

int validarPrecio(float precio)
{
    int esValido = 1;

    if((precio > 4999) && (precio < 100000))
    {
        esValido = 0;
    }
    return esValido;
}
