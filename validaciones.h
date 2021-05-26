#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "fecha.h"
#include "servicios.h"
#include "notebooks.h"

int validarNotebook(eNotebook notebooks[],int tam,int idNote);

/** \brief Valida que el id este en la lista
 *
 * \param array de estructuras tipo
 * \param tamaño de estructura tipo
 * \param  id de tipo ingresado
 * \return  1 si esta bien, 0 si se produjo un error.
 *
 */

int validarTipo(eTipo tipos[], int tamT, int idTipo);

/** \brief Valida que el id este en la lista
 *
 * \param array de estructuras servicio
 * \param tamaño de estructura servicio
 * \param  id de servicio ingresado
 * \return  0 si esta bien, 1 si se produjo un error.
 *
 */

int validarServicio(eServicio servicios[], int tam, int idServicio);

/** \brief Valida que el id este en la lista
 *
 * \param array de estructuras marca
 * \param tamaño de estruc marca
 * \param  id de servicio ingresado
 * \return  1 si esta bien, 0 si se produjo un error.
 *
 */

int validarMarca(eMarca marcas[], int tam, int idMarca);



/** \brief valida que la fecha sea logica
 *
 * \param  fecha ingresada por el usuario.
 * \return 1 si esta bien, 0 error
 *
 */

int validarFecha(eFecha fecha);

int validacionCadena(char cadena[]);
int strLwr(char* str);
int normalizeStr(char* str);
int isInt(char *pAux);
int getInt(int* pAux);
int utn_getEntero(int* pEntero, int reintentos, char* mensaje, char* mensajeError, int minimo, int maximo);
int getCadena(char* pAux, int limit);
int utn_getFlotante(float pFloat[], int retry, char* msg, char*msgError, float min, float max);
int getFloat(float*pAux);
int isFloat(char* pAux);
/** \brief Valida que el id este en la lista
 *
 * \param array de estructuras cliente
 * \param tamaño de estructura cliente
 * \param  id de tipo ingresado
 * \return  1 si esta bien, 0 si se produjo un error.
 *
 */
int validarCliente(eCliente clientes[], int tam, int idCliente);
int validarPrecio(float precio);

#endif // VALIDACIONES_H_INCLUDED
