#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

typedef struct{
int idMarca;
char descripcion[20];
}eMarca;

#endif // MARCAS_H_INCLUDED

/** \brief muestra una marca
 *
 * \param unaMarca estructura
 *
 */

void mostrarMarca(eMarca unaMarca);

/** \brief muestra la lista de marca
 *
 * \param estructura marca
 * \param tamaño de array marca
 * \return 1 si se produjo un error, 0 si esta todo ok
 */

void mostrarMarcas(eMarca marcas[], int tam);

/** \brief Carga en la marca utilizando el id
 *
 * \param array de estructura marca
 * \param tamaño de array marca
 * \param id a cargar
 * \param donde va a ser guardada la marca
 * \return 0 si esta todo ok, 1 si se produjo un error
 *
 */

int cargarDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[]);
