#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"
#include "LinkedList.h"
#include "Libreria.h"

/** \brief Parsea los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param listaLibreria LinkedList*
 * \return int
 *
 */
int parser_EnviosFromText(char* path , LinkedList* listaLibreria)
{
	eLibreria* envio;
	FILE* pFile;
	char auxIdCaja[50];
	char auxTipo[50] ;
	char auxUnidades[50] ;
	char auxIdEmpresa[50];
	char auxIdTipo[50];
	ll_clear(listaLibreria);

	pFile = fopen(path, "r");

	if(path!=NULL && listaLibreria!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]" , auxIdCaja, auxIdTipo, auxTipo, auxUnidades, auxIdEmpresa);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxIdCaja, auxIdTipo, auxTipo, auxUnidades, auxIdEmpresa);
			envio = envio_newParametros(auxIdCaja, auxIdTipo, auxTipo,auxUnidades,auxIdEmpresa);
			ll_add(listaLibreria, envio);
		}

		fclose(pFile);


		printf("\nSe ha cargado el listado de envios CORRECTAMENTE!!\n\n");
	}

    return 1;
}

/** \brief Parsea los datos de las sucursales desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param listaLibreria LinkedList*
 * \return int
 *
 */
int parser_SucursalesFromText(char* path , LinkedList* sucursalesLibreria)
{
	eSucursal* sucursal;
	FILE* pFile;
	char auxIdSucursalLibreria[50];
	char auxSucursal[50];

	ll_clear(sucursalesLibreria);

	pFile = fopen(path, "r");

	if(path!=NULL && sucursalesLibreria!=NULL)
	{
		fscanf(pFile, "%[^,],%[^\n]" , auxIdSucursalLibreria, auxSucursal);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^\n]\n", auxIdSucursalLibreria, auxSucursal);
			sucursal = sucursal_newParametros(auxIdSucursalLibreria, auxSucursal);
			ll_add(sucursalesLibreria, sucursal);
		}

		fclose(pFile);

		printf("\nSe ha cargado el listado de sucursales CORRECTAMENTE!!\n\n");
	}

    return 1;
}
