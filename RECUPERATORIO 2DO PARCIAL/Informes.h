#include "Libreria.h"
#ifndef INFORMES_H_
#define INFORMES_H_

int ListaEnviosLibreria(LinkedList* listaLibreria, LinkedList* sucursalesLibreria);
eSucursal* ObtenerSucursalPorId(eLibreria* auxLibreria, LinkedList* sucursalesLibreria);
int UnidadesEnviadasPorPedido(void* pElement);
int CalcularTotalUnidadesEnviadas(LinkedList* listaLibreria);
int UnidadesEnviadasACaballito(void* pElement);
int CalcularTotalUnidadesEnviadasACaballito(LinkedList* listaLibreria);
int FiltrarEnvioAMedrano(void* pElement);
int FiltrarTodosLosEnviosAMedrano(LinkedList* listaLibreria, LinkedList* sucursalesLibreria);
int FiltrarLibro(void* pElement);
int FiltrarTodosLosLibros(LinkedList* listaLibreria, LinkedList* sucursalesLibreria);
int GuardarListaComoTexto(LinkedList* listaLibreria, LinkedList* sucursalesLibreria,  char* path);


#endif /* INFORMES_H_ */
