#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct{
int idTipo;
char descripcion[20];
}eTipo;

#endif // TIPOS_H_INCLUDED
/** \brief muestra la lista de tipo
 *
 * \param estructura tipo
 * \param tamaño de array tipo
 * \return 1 si se produjo un error, 0 si esta todo ok
 */
void mostrarTipos(eTipo tipos[], int tam);


/** \brief muestra un tipo
 *
 * \param unTipo estructura
 *
 */

void mostrarTipo(eTipo tipos);

/** \brief Carga en la marca del tipo utilizando el id
 *
 * \param array de estructura tipo
 * \param tamaño de array tipo
 * \param id a cargar
 * \param donde va a ser guardada la marca
 * \return 0 si esta todo ok, 1 si se produjo un error
 *
 */

int cargarDescripcionTipo(eTipo tipos[], int tam, int idTipo, char descripcion[]);




