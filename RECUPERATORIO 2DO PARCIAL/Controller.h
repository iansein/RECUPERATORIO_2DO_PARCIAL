#include "LinkedList.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int Sein_controller_loadFromTextEnvios(char* path , LinkedList* listaLibreria);
int Sein_controller_loadFromTextSucursales(char* path, LinkedList* sucursalesLibreria);
int Sein_controller_listLibreria(LinkedList* listaLibreria, LinkedList* sucursalesLibreria);
int Sein_controller_TotalUnidades(LinkedList* listaLibreria);
int Sein_controller_TotalUnidadesACaballito(LinkedList* listaLibreria);
int Sein_controller_ListaFiltradaMedrano(LinkedList* listaLibreria, LinkedList* sucursalesLibreria);
int Sein_controller_ListaFiltradaDeLibros(LinkedList* listaLibreria, LinkedList* sucursalesLibreria);
int Sein_controller_GuardadoListaFiltrada(LinkedList* listaLibreria, LinkedList* sucursalesLibreria, char* path);

#endif /* CONTROLLER_H_ */
