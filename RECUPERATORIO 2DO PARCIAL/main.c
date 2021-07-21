#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libreria.h"
#include "Controller.h"
#include "Input.h"
#include "Parser.h"

int main(void)
{

	LinkedList* listaLibreria = ll_newLinkedList();
	LinkedList* sucursalesLibreria = ll_newLinkedList();

	int opcion;
	int flagEnvios;
	int flagSucursales;
	int flagGuardado;

	setbuf(stdout, NULL);

	flagEnvios = 0;
	flagSucursales = 0;
	flagGuardado = 0;

	do
	{
		opcion = MenuDeOpciones();

		switch(opcion)
		{
			case 1:
			if(Sein_controller_loadFromTextEnvios("libreria.csv", listaLibreria)==1)
			{
				flagEnvios = 1;
			}
			else
			{
				printf("\n\nHubo un ERROR en el controlador de CARGAR LISTADO ENVIOS!\n\n");
			}
			break;

			case 2:
			if(Sein_controller_loadFromTextSucursales("sucursales.csv", sucursalesLibreria)==1)
			{
				flagSucursales = 1;
			}
			else
			{
				printf("\n\nHubo un error en el controlador de CARGAR LISTADO SUCURSALES!\n\n");
			}
			break;

			case 3:
			if(flagEnvios == 1 && flagSucursales == 1)
			{
				if(Sein_controller_listLibreria(listaLibreria, sucursalesLibreria) == -1)
				{
					printf("\n\nHubo un error en el controlador de listados!\n\n");
				}
			}
			else
			{
				printf("\n\nPara listar, primero debe cargar las listas!!\n\n");
			}
			break;

			case 4:
			if(flagEnvios == 1 && flagSucursales == 1)
			{
				if(Sein_controller_TotalUnidades(listaLibreria) == -1)
				{
					printf("\n\nHubo un error en el controlador de total de envios!\n\n");
				}

			}
			else
			{
				printf("\n\nPara obtener el total de unidades enviadas, primero debe cargar las listas!!\n\n");
			}
			break;

			case 5:
			if(flagEnvios == 1 && flagSucursales == 1)
			{
				if(Sein_controller_TotalUnidadesACaballito(listaLibreria) == -1)
				printf("\n\nHubo un error en el controlador de total de envios a Caballito!\n\n");

			}
			else
			{
				printf("\n\nPara obtener el total de unidades enviadas a Caballito, primero debe cargar las listas!!\n\n");
			}
			break;

			case 6:
			if(flagEnvios == 1 && flagSucursales == 1)
			{
				if(Sein_controller_ListaFiltradaMedrano(listaLibreria, sucursalesLibreria) == -1)
				{
					printf("\n\nHubo un error en el controlador de la lista filtrada de Medrano!\n\n");
				}
			}
			else
			{
				printf("\n\nPara obtener la lista filtrada, primero debe cargar las listas!!\n\n");
			}
			break;

			case 7:
			if(flagEnvios == 1 && flagSucursales == 1)
			{
				if(Sein_controller_ListaFiltradaDeLibros(listaLibreria, sucursalesLibreria) == -1)
				{
					printf("\n\nHubo un error en el controlador de la lista filtrada de libros!\n\n");
				}
			}
			else
			{
				printf("\n\nPara obtener la lista filtrada, primero debe cargar las listas!!\n\n");
			}
			break;

			case 8:
			if(flagEnvios == 1 && flagSucursales == 1 && flagGuardado == 0)
			{
				if(Sein_controller_GuardadoListaFiltrada(listaLibreria, sucursalesLibreria, "listafiltradamedrano.csv") == -1)
				{
					printf("\n\nHubo un error en el controlador del guardado de la lista filtrada!\n\n");
				}
				else
				{
					flagGuardado = 1;
				}
			}
			else
			{
				printf("\n\nYa ha guardado la lista en un archivo de texto o todavia no ha cargado las listas para proseguir con el guardado!\n\n");
			}
			break;

			case 9:
			break;
		}

	}while(opcion!=9);

	printf("\nHa salido del programa correctamente!\n");

	return EXIT_SUCCESS;
}
