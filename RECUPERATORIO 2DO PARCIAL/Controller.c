#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "Parser.h"
#include "Informes.h"

/** \brief Carga los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param listaLibreria LinkedList*
 * \return int exit / Retorna -1 Si alguno de los parametros es NULL / Retorna 1 si se pudo
 *
 */
int Sein_controller_loadFromTextEnvios(char* path, LinkedList* listaLibreria)
{
	int exit = -1;

	if(path!=NULL && listaLibreria!=NULL)
	{

		if(parser_EnviosFromText(path, listaLibreria)==1)
		{
			exit = 1;
		}
		else
		{
			printf("Error\n");
		}

	}

    return exit;
}

/** \brief Carga los datos de las sucursales desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param sucursalesLibreria LinkedList*
 * \return int exit / Retorna -1 Si alguno de los parametros es NULL / Retorna 1 si se pudo
 *
 */
int Sein_controller_loadFromTextSucursales(char* path, LinkedList* sucursalesLibreria)
{
	int exit = -1;

	if(path!=NULL && sucursalesLibreria!=NULL)
	{

		if(parser_SucursalesFromText(path, sucursalesLibreria)==1)
		{
			exit = 1;
		}
		else
		{
			printf("Error\n");
		}

	}

	return exit;
}

/** \brief Listado de los envios de la libreria
 *
 * \param listaLibreria LinkedList*
 * \param sucursalesLibreria LinkedList*
 * \return int exit / Retorna -1 Si alguno de los parametros es NULL / Retorna 1 si se pudo
 *
 */
int Sein_controller_listLibreria(LinkedList* listaLibreria, LinkedList* sucursalesLibreria)
{

	int exit = -1;

	if(listaLibreria!=NULL && sucursalesLibreria!=NULL)
	{
		if(ListaEnviosLibreria(listaLibreria, sucursalesLibreria)==1)
		{
			exit = 1;
		}
		else
		{
			printf("Error\n");
		}
	}

	return exit;
}


/** \brief Total de unidades enviadas en general de la libreria
 *
 * \param listaLibreria LinkedList*
 * \return int exit / Retorna -1 Si alguno de los parametros es NULL / Retorna 1 si se pudo
 *
 */
int Sein_controller_TotalUnidades(LinkedList* listaLibreria)
{
	int exit = -1;

	if(listaLibreria!=NULL)
	{
		if(CalcularTotalUnidadesEnviadas(listaLibreria)==1)
		{
			exit = 1;
		}
		else
		{
			printf("Error\n");
		}
	}
	return exit;
}

/** \brief Total de unidades enviadas en general de la libreria a Caballito
 *
 * \param listaLibreria LinkedList*
 * \return int exit / Retorna -1 Si alguno de los parametros es NULL / Retorna 1 si se pudo
 *
 */
int Sein_controller_TotalUnidadesACaballito(LinkedList* listaLibreria)
{
	int exit = -1;

	if(listaLibreria!=NULL)
	{
		if(CalcularTotalUnidadesEnviadasACaballito(listaLibreria)==1)
		{
			exit = 1;
		}
		else
		{
			printf("Error\n");
		}
	}
	return exit;
}

/** \brief Lista filtrada que quita a Medrano de los envios
 *
 * \param listaLibreria LinkedList*
 * \param sucursalesLibreria LinkedList*
 * \return int exit / Retorna -1 Si alguno de los parametros es NULL / Retorna 1 si se pudo
 *
 */
int Sein_controller_ListaFiltradaMedrano(LinkedList* listaLibreria, LinkedList* sucursalesLibreria)
{

	int exit = -1;

	if(listaLibreria!=NULL && sucursalesLibreria!=NULL)
	{
		if(FiltrarTodosLosEnviosAMedrano(listaLibreria, sucursalesLibreria)==1)
		{
			exit = 1;
		}
		else
		{
			printf("Error\n");
		}
	}

	return exit;
}

/** \brief Lista filtrada que quita a el tipo libro de los envios
 *
 * \param listaLibreria LinkedList*
 * \param sucursalesLibreria LinkedList*
 * \return int exit / Retorna -1 Si alguno de los parametros es NULL / Retorna 1 si se pudo
 *
 */
int Sein_controller_ListaFiltradaDeLibros(LinkedList* listaLibreria, LinkedList* sucursalesLibreria)
{
	int exit = -1;

	if(listaLibreria!=NULL && sucursalesLibreria!=NULL)
	{
		if(FiltrarTodosLosLibros(listaLibreria, sucursalesLibreria)==1)
		{
			exit = 1;
		}
		else
		{
			printf("Error\n");
		}
	}

	return exit;
}

/** \brief Guarda la lista filtrada como un archivo CSV
 *
 * \param listaLibreria LinkedList*
 * \param sucursalesLibreria LinkedList*
 * \param path char*
 * \return int exit / Retorna -1 Si alguno de los parametros es NULL / Retorna 1 si se pudo
 *
 */
int Sein_controller_GuardadoListaFiltrada(LinkedList* listaLibreria, LinkedList* sucursalesLibreria, char* path)
{
	int exit = -1;

	if(listaLibreria!=NULL && sucursalesLibreria!=NULL && path !=NULL)
	{
		if(GuardarListaComoTexto(listaLibreria, sucursalesLibreria, "listafiltradamedrano.csv")==1)
		{
			exit = 1;
			printf("\n\nSe ha guardado el archivo correctamente!\n\n");
		}
		else
		{
			printf("Error\n");
		}
	}

	return exit;
}
