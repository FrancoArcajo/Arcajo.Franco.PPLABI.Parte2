#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "trabajos.h"
#include "notebooks.h"
#include "tipos.h"
#include "marcas.h"
#include "servicios.h"
#include "clientes.h"
#include "fecha.h"
#include "validaciones.h"

int notebooksTipoSeleccionado(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca,eCliente clientes[], int tamCliente);
int notebooksMarcaSeleccionada(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente);
int buscarMasBarata(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente);
int notebookSeparadaPorTipo(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca,eCliente clientes[], int tamCliente);
int contarPorTipoYMarca(eNotebook notebooks[], int tamN, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente);
int mostrarMarcaMasElegida(eNotebook notebooks[], int tamN, eMarca marcas[], int tamMarca);
int mostrarTrabajosNotebooks(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamN, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamClientes);
int notebookImporteServicio(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamN, eServicio servicios[], int tamServ, int id, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamClientes);
int listarNotebooksPorFechaServicio(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamN, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamClientes);
int fechaServicioNotebook(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamN, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca, eCliente clientes[], int tamClientes);

#endif // INFORMES_H_INCLUDED
