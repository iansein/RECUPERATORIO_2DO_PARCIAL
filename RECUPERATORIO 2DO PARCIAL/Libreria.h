#ifndef LIBRERIA_H_
#define LIBRERIA_H_
#include "LinkedList.h"

typedef struct
{
	int idSucursalLibreria;
	char sucursal[50];
}eSucursal;

typedef struct
{
	int idCaja;
	int idTipo;
	char tipo[50];
	int unidades;
	int idSucursalLibreria;
}eLibreria;


eLibreria* envio_new(void);
eLibreria* envio_newParametros(char* idCajaStr, char* idTipoStr, char* tipoStr, char* unidadesStr, char* idSucursalLibreriaStr);
int envio_setIdCaja(eLibreria* envio,int _idCaja);
int envio_setTipo(eLibreria* envio,char* _tipo);
int envio_setUnidades(eLibreria* envio,int _unidades);
int envio_setIdSucursal(eLibreria* envio,int _idSucursalLibreria);
int envio_setIdTipo(eLibreria* envio, int _idTipo);

eSucursal* sucursal_new(void);
eSucursal* sucursal_newParametros(char* idSucursalLibreriaStr, char* sucursalStr);
int envio_setIdSucursalLibreria(eSucursal* sucursal,int _idSucursalLibreria);
int envio_setSucursalNombre(eSucursal* sucursal,char* _sucursalNombre);


int envio_getIdTipo(eLibreria* envio,int* idTipo);
int envio_getUnidades(eLibreria* envio,int* unidades);
int envio_getIdSucursal(eLibreria* envio,int* idSucursal);

#endif /* EMPRESA_H_ */
