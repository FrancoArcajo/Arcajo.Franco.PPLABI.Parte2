#include "fecha.h"
#include "notebooks.h"
#include "servicios.h"
#include "tipos.h"
#include "marcas.h"
#include "clientes.h"

#ifndef ETRABAJO_H_INCLUDED
#define ETRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // ETRABAJO_H_INCLUDED

/** \brief indica con el isEmpty en 1 que los trabajos estan vacios
 *
 * \param array de trabajo
 * \param  tamanio de trabajos
 * \return return 0 si esta todo ok, o 1 si fallo al inicializar
 *
 */

int inicializarTrabajo(eTrabajo trabajos[], int tamTrabajos);

/** \brief busca espacio libre dentro del array de trabajos.
 *
 * \param array de estructura trabajo.
 * \param tamanio de array trabajo.
 * \return 1 si no hay libre, o el primer indice libre.
 *
  */

int buscarLibreTrabajo(eTrabajo trabajos[], int tam);

/** \brief Muestra todos los trabajos
 *
 * \param array de estructuras trabajos
 * \param tamaño de estructura trabajos
 * \param array de estructuras notebooks
 * \param tamaño de estructura notebooks
 * \param tamaño de estructura servicio
 * \param  tamaño de estructura servicio
 * \return 0 si esta todo bien , 1 si se produjo un error
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamTrabajos, eNotebook notebooks[], int tamNote, eServicio servicios[], int tamServicios);

/** \brief Muestra un trabajo
 *
 * \param una estructura trabajo
 * \param array de notebooks
 * \param  tamaño de array notebooks
 * \param array de Servicios
 * \param tamaño de array servicios
 *
 */

void mostrarTrabajo(eTrabajo unTrabajo, eNotebook notebooks[], int tam, eServicio servicios[], int tamServicios);
/** \brief Hace un alta de trabajo con id autoincremental.
 *
 * \param array de estructura trabajo
 * \param tamaño de estructura trabajo
 * \param id del trabajo
 * \param array de estructuras notebooks
 * \param tamaño de estructura notebooks
 * \param array de estructura marcas
 * \param tamaño de estructura marcas
 * \param array de estructuras tipos
 * \param tamaño de estructura tipos
 * \param array de estructura servicios
 * \param tamaño de estructura servicios
 * \return 0 si esta todo ok, 1 si se produjo un error
 *
 */
int altaTrabajos(eTrabajo trabajos[], int tamTrabajo,int idTrabajo,eNotebook notebooks[],int tamNote, eMarca marcas[], int tamMarca,eTipo tipos[],int tamTipo,eServicio servicios[],int tamServicio, eCliente clientes[], int tamCliente);
/** \brief Carga en la marca de la notebook utilizando el id
 *
 * \param array de estructura notebooks
 * \param tamaño de array notebooks
 * \param id a cargar
 * \param donde va a ser guardada la marca
 * \return 0 si esta bien ,1 si se produjo un error
 *
 */

int cargarDescripcionNotebook(eNotebook notebooks[], int tam, int idNote,char descripcionNote[]);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int harcodearTrabajos(eTrabajo trabajos[],int tam,int cant);
