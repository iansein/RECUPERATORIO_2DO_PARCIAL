#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "LinkedList.h"
#include "Libreria.h"


/** \brief Listado general de envios
 *
 * \param listaLibreria LinkedList*
 * \param sucursalesLibreria LinkedList*
 * \return int
 *
 */
int ListaEnviosLibreria(LinkedList* listaLibreria, LinkedList* sucursalesLibreria)
{
	int lenListaLibreria;
	int i;
	eLibreria* auxLibreria;
	eSucursal* auxSucursal;

	lenListaLibreria = ll_len(listaLibreria);

	if(listaLibreria!=NULL && sucursalesLibreria!=NULL)
	{
		if(ll_isEmpty(listaLibreria)==0 && ll_isEmpty(listaLibreria)==0)
		{

			for(i=0;i<lenListaLibreria;i++)
			{
				auxLibreria = (eLibreria*) ll_get(listaLibreria, i);
				auxSucursal = ObtenerSucursalPorId(auxLibreria, sucursalesLibreria);

				printf("————————————————————————————————————————————————————————————————\n");
				printf("TIPO: %s | UNIDADES : %d | SUCURSAL : %s \n", auxLibreria->tipo, auxLibreria->unidades, auxSucursal->sucursal);

			}
			printf("————————————————————————————————————————————————————————————————\n");
		}
		else
		{
			printf("La lista es inexistente, por lo que no se puede listar\n");
		}
	}

	return 1;

}

/** \brief Obtiene una estructura de sucursal por ID
 *
 * \param auxLibreria eLibreria*
 * \param sucursalesLibreria LinkedList*
 * \return auxSucursal eSucursal*
 *
 */
eSucursal* ObtenerSucursalPorId(eLibreria* auxLibreria, LinkedList* sucursalesLibreria)
{
	int i;
	int lenSucursales;
	eSucursal* auxSucursal;

	if(auxLibreria!=NULL && sucursalesLibreria!=NULL)
	{
		lenSucursales = ll_len(sucursalesLibreria);

		for(i=0;i<lenSucursales;i++)
		{
			auxSucursal = (eSucursal*)ll_get(sucursalesLibreria, i);
			if(auxLibreria->idSucursalLibreria == auxSucursal->idSucursalLibreria)
			{
				return auxSucursal;
				break;
			}
		}
	}

	return 0;
}

/** \brief Obtiene las unidades de un envio
 *
 * \param pElement void*
 * \return unidades int
 *
 */
int UnidadesEnviadasPorPedido(void* pElement)
{
	int unidades;

	unidades = 0;

	if(pElement != NULL)
	{

		envio_getUnidades((eLibreria*)pElement,&unidades);
	}

	return unidades;
}

/** \brief Obtiene todas las unidades en general de todos los envios y las muestra
 *
 * \param listaLibreria LinkedList*
 * \return int
 *
 */
int CalcularTotalUnidadesEnviadas(LinkedList* listaLibreria)
{
	int resultadoTotal;

	if(listaLibreria!=NULL)
	{
		resultadoTotal = ll_count(listaLibreria, UnidadesEnviadasPorPedido);

		printf("\n\nSe enviaron %d unidades en total\n\n", resultadoTotal);
	}

	return 1;
}


/** \brief Obtiene las unidades de un envio a Caballito
 *
 * \param pElement void*
 * \return unidades int
 *
 */
int UnidadesEnviadasACaballito(void* pElement)
{
	int idSucursal;
	int unidades;

	unidades = 0;

	if(pElement!=NULL)
	{
		envio_getIdSucursal((eLibreria*)pElement, &idSucursal);

		if(idSucursal == 1)
		{
			envio_getUnidades((eLibreria*)pElement, &unidades);

		}
	}

	return unidades;
}

/** \brief Obtiene todas las unidades en general de todos los envios a Caballito y las muestra
 *
 * \param listaLibreria LinkedList*
 * \return int
 *
 */
int CalcularTotalUnidadesEnviadasACaballito(LinkedList* listaLibreria)
{
	int resultadoTotal;

	if(listaLibreria!=NULL)
	{
		resultadoTotal = ll_count(listaLibreria, UnidadesEnviadasACaballito);

		printf("\n\nSe enviaron %d unidades en total a Caballito\n\n", resultadoTotal);
	}

	return 1;
}


/** \brief Valida si hay que agregar el elemento a la lista
 *
 * \param pElement void*
 * \return int validacion / Retorna 1 si hay que agregar el elemento / Retorna 0 si no hay que agregarlo porque su sucursal es Medrano.
 *
 */
int FiltrarEnvioAMedrano(void* pElement)
{
	int validacion;
	int idSucursal;
	validacion = 1;

	if(pElement != NULL)
	{
		envio_getIdSucursal((eLibreria*)pElement, &idSucursal);

		if(idSucursal == 4)
		{
			validacion = 0;
		}
	}

	return validacion;
}


/** \brief Construye una nueva lista enlazada con el filtro de sucursal MEDRANO y la muestra
 *
 * \param listaLibreria LinkedList*
 * \param sucursalesLibreria LinkedList*
 * \return int
 *
 */
int FiltrarTodosLosEnviosAMedrano(LinkedList* listaLibreria, LinkedList* sucursalesLibreria)
{
	LinkedList* listaFiltrada;
	eLibreria* auxLibreria;
	eSucursal* auxSucursal;
	int i;
	int len;

	if(listaLibreria!=NULL)
	{
		listaFiltrada = ll_filter(listaLibreria, FiltrarEnvioAMedrano);

		len = ll_len(listaFiltrada);

		if(ll_isEmpty(listaFiltrada)==0)
		{
			for(i=0;i<len;i++)
			{
				auxLibreria = ll_get(listaFiltrada, i);
				auxSucursal = ObtenerSucursalPorId(auxLibreria, sucursalesLibreria);

				printf("————————————————————————————————————————————————————————————————\n");
				printf("TIPO: %s | UNIDADES : %d | SUCURSAL : %s \n", auxLibreria->tipo, auxLibreria->unidades, auxSucursal->sucursal);
			}

			printf("————————————————————————————————————————————————————————————————\n");
		}
	}

	ll_deleteLinkedList(listaFiltrada);

	return 1;
}

/** \brief Valida si hay que agregar el elemento a la lista
 *
 * \param pElement void*
 * \return int validacion / Retorna 1 si hay que agregar el elemento / Retorna 0 si no hay que agregarlo porque el tipo de unidad es libro.
 *
 */
int FiltrarLibro(void* pElement)
{
	int validacion;
	int idTipo;
	validacion = 1;

	if(pElement != NULL)
	{
		envio_getIdTipo((eLibreria*)pElement, &idTipo);

		if(idTipo == 2)
		{
			validacion = 0;
		}
	}

	return validacion;
}

/** \brief Construye una nueva lista enlazada con el filtro de tipo LIBRO y la muestra
 *
 * \param listaLibreria LinkedList*
 * \param sucursalesLibreria LinkedList*
 * \return int
 *
 */
int FiltrarTodosLosLibros(LinkedList* listaLibreria, LinkedList* sucursalesLibreria)
{
	LinkedList* listaFiltrada;
	eLibreria* auxLibreria;
	eSucursal* auxSucursal;
	int i;
	int len;

	if(listaLibreria!=NULL)
	{
		listaFiltrada = ll_filter(listaLibreria, FiltrarLibro);

		len = ll_len(listaFiltrada);

		if(ll_isEmpty(listaFiltrada)==0)
		{
			for(i=0;i<len;i++)
			{
				auxLibreria = ll_get(listaFiltrada, i);
				auxSucursal = ObtenerSucursalPorId(auxLibreria, sucursalesLibreria);

				printf("————————————————————————————————————————————————————————————————\n");
				printf("TIPO: %s | UNIDADES : %d | SUCURSAL : %s \n", auxLibreria->tipo, auxLibreria->unidades, auxSucursal->sucursal);
			}

			printf("————————————————————————————————————————————————————————————————\n");
		}
	}

	ll_deleteLinkedList(listaFiltrada);

	return 1;
}


/** \brief Guarda como archivo CSV la lista con filtro
 *
 * \param listaLibreria LinkedList*
 * \param sucursalesLibreria LinkedList*
 * \param path char*
 * \return int
 *
 */
int GuardarListaComoTexto(LinkedList* listaLibreria, LinkedList* sucursalesLibreria,  char* path)
{
    int len;
    eLibreria* pAuxLibreria;
    eSucursal* pAuxSucursal;
    LinkedList* listaFiltrada;
    FILE* pFile;

    listaFiltrada = ll_filter(listaLibreria, FiltrarEnvioAMedrano);

    pFile = fopen(path, "w");

    if (pFile != NULL && listaFiltrada != NULL && sucursalesLibreria != NULL)
    {
        len = ll_len(listaFiltrada);

        fprintf(pFile, "%s,%s,%s,%s,%s\n","Id Caja","Id Tipo","Tipo","Unidades","Sucursal");

        for (int i = 0; i < len; i++)
        {
        	pAuxLibreria = ll_get(listaFiltrada, i);
        	pAuxSucursal = ObtenerSucursalPorId(pAuxLibreria, sucursalesLibreria);

            if (pAuxLibreria != NULL)
            {

              fprintf(pFile, "%d,%d,%s,%d,%s\n", pAuxLibreria->idCaja, pAuxLibreria->idTipo, pAuxLibreria->tipo, pAuxLibreria->unidades, pAuxSucursal->sucursal);

            }
        }
    }

    fclose(pFile);

    return 1;
}

