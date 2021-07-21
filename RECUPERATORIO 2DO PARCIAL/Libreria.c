#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria.h"
#include "LinkedList.h"

/** \brief Crea un nueva estructura de libreria de manera dinamica.
 *
 * \return nuevoEnvio eLibreria*
 *
 */
eLibreria* envio_new()
{
	eLibreria* nuevoEnvio;
	nuevoEnvio = (eLibreria*)malloc(sizeof(eLibreria));

	return nuevoEnvio;
}

/** \brief Crea una estructura de libreria mediante mediante el parseo de sus pasajes en cadena.
 *
 * \param idCajaStr char*
 * \param idTipoStr char*
 * \param tipoStr char*
 * \param unidadesStr char*
 * \param idSucursalLibreriaStr char*
 * \return envio eLibreria*
 *
 */
eLibreria* envio_newParametros(char* idCajaStr, char* idTipoStr, char* tipoStr, char* unidadesStr, char* idSucursalLibreriaStr)
{
	eLibreria* envio = envio_new();

	int idCaja;
	int unidades;
	int idSucursalLibreria;
	int idTipo;

	if(idCajaStr!=NULL && tipoStr!=NULL && unidadesStr!=NULL && idSucursalLibreriaStr!=NULL)
	{

		idCaja = atoi(idCajaStr);
		unidades = atoi(unidadesStr);
		idSucursalLibreria = atoi(idSucursalLibreriaStr);
		idTipo = atoi(idTipoStr);

		if(envio_setIdCaja(envio, idCaja)==1 && envio_setIdTipo(envio, idTipo)==1 && envio_setTipo(envio, tipoStr)==1 && envio_setUnidades(envio, unidades)==1 && envio_setIdSucursal(envio, idSucursalLibreria)==1)
		{

		}
		else
		{
			printf("Error al tratar de ingresar el ENVIO al sistema!\n");
		}
	}

	return envio;
}

/** \brief Setea el id dentro de una estructura de libreria.
 *
 * \param envio eLibreria*
 * \param _idCaja int
 * \return int
 *
 */
int envio_setIdCaja(eLibreria* envio,int _idCaja)
{
	if(envio!=NULL)
	{
		envio->idCaja = _idCaja;

	}

	return 1;
}


/** \brief Setea el tipo dentro de una estructura de libreria.
 *
 * \param envio eLibreria*
 * \param _tipo char*
 * \return int
 *
 */
int envio_setTipo(eLibreria* envio,char* _tipo)
{

	if(envio!=NULL)
	{
		strcpy(envio->tipo, _tipo);

	}

	return 1;
}


/** \brief Setea las unidades dentro de una estructura de libreria.
 *
 * \param envio eLibreria*
 * \param _unidades int
 * \return int
 *
 */
int envio_setUnidades(eLibreria* envio, int _unidades)
{

	if(envio!=NULL)
	{
		envio->unidades = _unidades;

	}

	return 1;
}


/** \brief Setea el id de la sucursal dentro de una estructura de libreria.
 *
 * \param envio eLibreria*
 * \param _idSucursalLibreria int
 * \return int
 *
 */
int envio_setIdSucursal(eLibreria* envio, int _idSucursalLibreria)
{

	if(envio!=NULL)
	{
		envio->idSucursalLibreria = _idSucursalLibreria;

	}

	return 1;
}

/** \brief Setea el id del tipo dentro de una estructura de libreria.
 *
 * \param envio eLibreria*
 * \param _idTipo int
 * \return int
 *
 */
int envio_setIdTipo(eLibreria* envio, int _idTipo)
{

	if(envio!=NULL)
	{
		envio->idTipo = _idTipo;

	}

	return 1;
}


/** \brief Crea una nueva estructura de sucursal de manera dinamica.
 *
 * \return nuevaSucursal eSucursal*
 *
 */
eSucursal* sucursal_new()
{
	eSucursal* nuevaSucursal;
	nuevaSucursal = (eSucursal*)malloc(sizeof(eSucursal));

	return nuevaSucursal;
}

/** \brief Crea un nueva estructura de sucursal mediante mediante el parseo de sus pasajes en cadena.
 *
 * \param idSucursalLibreriaStr char*
 * \param sucursalStr char*
 * \return sucursal eSucursal*
 *
 */
eSucursal* sucursal_newParametros(char* idSucursalLibreriaStr, char* sucursalStr)
{
	eSucursal* sucursal = sucursal_new();


	int idSucursalLibreria;

	if(idSucursalLibreriaStr!=NULL && sucursalStr!=NULL)
	{

		idSucursalLibreria = atoi(idSucursalLibreriaStr);

		if(envio_setIdSucursalLibreria(sucursal, idSucursalLibreria)==1 && envio_setSucursalNombre(sucursal, sucursalStr)==1)
		{

		}
		else
		{
			printf("Error al tratar de ingresar la sucursal al sistema!\n");
		}
	}

	return sucursal;
}

/** \brief Setea el id de la sucursal dentro de una estructura de sucursal.
 *
 * \param envio eSucursal*
 * \param _idSucursalLibreria int
 * \return int
 *
 */
int envio_setIdSucursalLibreria(eSucursal* sucursal,int _idSucursalLibreria)
{
	if(sucursal!=NULL)
	{
		sucursal->idSucursalLibreria = _idSucursalLibreria;

	}

	return 1;
}

/** \brief Setea el nombre de la sucursal dentro de una estructura de sucursal.
 *
 * \param envio eSucursal*
 * \param _sucursalNombre char*
 * \return int
 *
 */
int envio_setSucursalNombre(eSucursal* sucursal,char* _sucursalNombre)
{

	if(sucursal!=NULL)
	{
		strcpy(sucursal->sucursal, _sucursalNombre);

	}

	return 1;
}

/** \brief Devuelve el id del tipo de unidad dentro de una estructura de libreria.
 *
 * \param envio eLibreria*
 * \param idTipo int*
 * \return int
 *
 */
int envio_getIdTipo(eLibreria* envio,int* idTipo)
{

	if(envio!=NULL && idTipo!=NULL)
	{
		*idTipo = envio->idTipo;

	}

	return 1;
}


/** \brief Devuelve las unidades dentro de una estructura de libreria.
 *
 * \param envio eLibreria*
 * \param unidades int*
 * \return int
 *
 */
int envio_getUnidades(eLibreria* envio,int* unidades)
{

	if(envio!=NULL && unidades!=NULL)
	{
		*unidades = envio->unidades;

	}

	return 1;
}

/** \brief Devuelve el id de la sucursal dentro de una estructura de libreria.
 *
 * \param envio eLibreria*
 * \param idSucursal int*
 * \return int
 *
 */
int envio_getIdSucursal(eLibreria* envio,int* idSucursal)
{

	if(envio!=NULL && idSucursal!=NULL)
	{
		*idSucursal = envio->idSucursalLibreria;

	}

	return 1;
}


