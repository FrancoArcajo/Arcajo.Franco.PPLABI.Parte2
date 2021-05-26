#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include <string.h>
#include "menu.h"
#include "validaciones.h"

int menu()
{
    int opcion;

    system("cls");
    printf("*** ABM NOTEBOOKS ***\n\n");
    printf("1. ALTA NOTEBOOK.\n");
    printf("2. MODIFICAR NOTEBOOK.\n");
    printf("3. BAJA NOTEBOOK.\n");
    printf("4. LISTAR NOTEBOOKS.\n");
    printf("5. LISTAR TIPOS.\n");
    printf("6. LISTAR MARCAS.\n");
    printf("7. LISTAR SERVICIOS.\n");
    printf("8. ALTA TRABAJO.\n");
    printf("9. LISTAR TRABAJOS.\n");
    printf("10. INFORMES.\n");

   utn_getEntero(&opcion, 10, "Ingrese opcion: ", "Error, opcion invalida\n", 1, 11);

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("*********** INFORMES COMPLEMENTARIOS ***********\n");
    printf("1. Mostrar notebooks del tipo seleccionado.\n");
    printf("2. Mostrar notebooks de una marca seleccionada.\n");
    printf("3. Informar la o las notebooks mas baratas.\n");
    printf("4. Mostrar un listado de las notebooks separadas por tipo.\n");
    printf("5. Informar cuantas notebooks hay de un tipo y marca seleccionados.\n");
    printf("6. Mostrar la o las marcas mas elegidas.\n");
    printf("7. Pedir una notebook y mostrar todos los trabajos que se le hicieron.\n");
    printf("8. Pedir una notebook e informar la suma de los importes de los servicios que se le hicieron a la misma.\n");
    printf("9. Pedir un servicio y mostrar las notebooks a las que se le realizo ese servicio y la fecha.\n");
    printf("10. Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
    printf("11. SALIR\n\n");

    utn_getEntero(&opcion, 4, "Ingrese opcion: ", "Error, opcion invalida\n", 1, 11);

    return opcion;
}
