#include "tipos.h"
#include "clientes.h"
#include "marcas.h"

#ifndef NOTEBOOKS_H_INCLUDED
#define NOTEBOOKS_H_INCLUDED

typedef struct{
int idNote;
char modelo[20];
int idTipo;
int idMarca;
float precio;
int idCliente;
int isEmpty;
}eNotebook;

#endif // NOTEBOOKS_H_INCLUDED

/** \brief indica con el isEmpty en 1 que las notebooks estan vacios
 *
 * \param array de notebooks
 * \param tamaño de notebooks
 * \return return 0 si esta todo ok, o 1 si fallo al inicializar
 *
 */

int inicializarNotebooks(eNotebook notebooks[], int tam);

/** \brief busca espacio libre dentro del array de notebooks.
 *
 * \param array de estructura notebooks.
 * \param tamaño de array notebooks.
 * \return 1 si no hay libre, o el primer indice libre.
 *
*/

int buscarLibre(eNotebook notebooks[], int tam);
/** \brief busca una notebook por su id
 *
 * \param array de estructura notebooks
 * \param tam tamaño de array notebooks
 * \param id buscado
 * \return -1 si se produjo el error, o el indice buscado
 *
 */

int buscarNotebooks(eNotebook notebooks[], int tam, int id);

/** \brief Hace un alta de notebook
 *
 * \param  array de estructura notebooks
 * \param tamaño de estructura notebooks
 * \param id de notebooks
 * \param array de estructuras tipos
 * \param tamaño de estructura tipos
 * \param array de estructura marcas
 * \param tamaño de estructura marcas
* \param array de estructura clientes
 * \param tamaño de estructura cliente
 * \return 0 si esta todo ok, 1 si se produjo un error
 *
 */

int altaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente, int id);
/** \brief muestra el listado de notebooks
 *
 * \param array de estructura notebooks
 * \param tamaño de array notebooks
 * \param array de estructura marcas
 * \param tamaño de array marcas
 * \param array de estructura Tipos
 * \param tamaño de array Tipos
  * \param array de estructura Clientes
 * \param tamaño de array Clientes
 * \return 0 si esta todo ok, 1 si se produjo un error
 *
 */

int mostrarNotebooks(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente);
/** \brief Muestra una notebook
 *
 * \param array de estructura notebook
 * \param  array de marcas
 * \param  tamaño de array marcas
 * \param  array de Tipos
 * \param  tamaño de array Tipos
 * \param  array de Clientes
 * \param  tamaño de array clientes
 *
 */

void mostrarNotebook(eNotebook unaNotebook, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente);
/** \brief produce una baja en el array de estructuras eNotebook
 *
 * \param array de estructura notebooks
 * \param tamaño de array notebooks
 * \param array de marcas
 * \param tamaño de array marcas
 * \param array de Tipos
 * \param tamaño de array Tipos
 * \param array de Clientes
 * \param tamaño de array Clientes
 *
 * \return 0 si esta todo ok, 1 si se produjo un error
 *
 */

int bajaNotebook(eNotebook notebooks[], int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente);
/** \brief Hace una modificacion de una notebooks
 *
 * \param array de estructura notebooks
 * \param tamaño de estructura notebooks
 * \param array de estructuras tipo
 * \param tamaño de estructura tipo
 * \param array de estructura marcas
 * \param tamaño de estructura marcas
 * \param array de estructura clientes
 * \param tamaño de estructura clientes
 * \return 0 si esta todo ok, 1 si se produjo un error
 *
 */
int modificarNotebook(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente);

/** \brief Ordena el array de notebooks por marca y precio
 *
 * \param array de estructura notebooks
 * \param tamaño de array notebooks
 * \param array de estructura tipos
 * \param tamaño de array tipos
 * \param puntero de array de clientes
 * \param tamaño de array cliente
 * \return 0 si esta todo ok, 1 si se produjo un error
 *
 */

int ordenarNotebooksPorMarcayPrecio(eNotebook notebooks[],int tam, eMarca marcas[],int tamMarca, eCliente clientes[], int tamCliente);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int harcodearNotebooks(eNotebook notebooks[],int tam,int cant);

int buscarNotebooksPorId(int idNote, eNotebook notebooks[], int tamNote);
