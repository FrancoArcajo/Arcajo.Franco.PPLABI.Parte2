#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
int id;
char nombre[20];
int sexo;
}eCliente;


#endif // CLIENTE_H_INCLUDED

/** \brief muestra un cliente
 *
 * \param unCliente estructura
 *
 */

void mostrarCliente(eCliente clientes);

/** \brief muestra la lista de cliente
 *
 * \param estructura cliente
 * \param tamaño de array cliente
 * \return 1 si se produjo un error, 0 si esta todo ok
 */

void mostrarClientes(eCliente clientes[], int tam);

/** \brief Carga en la marca del cliente utilizando el id
 *
 * \param array de estructura cliente
 * \param tamaño de array cliente
 * \param id a cargar
 * \param donde va a ser guardada la marca
 * \return 0 si esta todo ok, 1 si se produjo un error
 *
 */

int cargarNombreCliente(eCliente clientes[], int tam, int id, char nombre[]);

#endif // CLIENTES_H_INCLUDED
