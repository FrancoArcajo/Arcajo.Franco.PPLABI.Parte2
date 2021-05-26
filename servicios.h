#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{
int id;
char descripcion[30];
float precio;

}eServicio;

#endif // SERVICIOS_H_INCLUDED

/** \brief muestra la lista de servicio
 *
 * \param estructura servicio
 * \param tamaño de array servicio
 * \return 1 si se produjo un error, 0 si esta todo ok
 */

void mostrarServicios(eServicio servicios[], int tam);

/** \brief muestra un servicio
 *
 * \param unServicio estructura
 *
 */

void mostrarServicio(eServicio servicios);

/** \brief Carga en la marca del servicio utilizando el id
 *
 * \param array de estructura servicio
 * \param tamaño de array servicio
 * \param id a cargar
 * \param donde va a ser guardada la marca
 * \return 0 si esta todo ok, 1 si se produjo un error
 *
 */

int cargarDescripcionServicio(eServicio servicios[], int tamServicio, int idServicio, char descripcion[]);


