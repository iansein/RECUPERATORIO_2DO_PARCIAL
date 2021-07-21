#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

/** \brief Menu de opcion
 * \param void
 * \return numero int
 *
 */
int MenuDeOpciones(void)
{
	int opcion;

	opcion = getInt("\n———————————————————————————————————————— LIBRERIA SEIN ————————————————————————————————————————————————\n\nIngrese una opcion:\n\n1-Cargar LISTADO de envios\n2-Cargar LISTADO de sucursales\n3-Listado de envios\n4-Total de unidades enviadas\n5-Total de unidades enviadas a Caballito\n6-Listado que no incluye envios a Medrano\n7-Listado que no incluye envios con libros\n8-Guardar la lista filtrada que no incluye a Medrano como archivo de texto\n9-Salir\n\n————————————————————————————————————————————————————————————————————————————————————————————————————————\nTu opcion: ");

	return opcion;
}

/** \brief Pide un numero y lo valida
 *
 * \param mensaje char*
 * \return numero int
 *
 */
int getInt(char *mensaje)
{
    int numero;
    while((ValideGetInt(&numero, mensaje)) == -1)
    {
        printf("\nERROR: Recuerde no dejar espacios en blanco y no utilizar letras\n");
    }
    return numero;
}


/** \brief Valida si el valor ingresado es un entero o no
 *
 * \param numero int*
 * \param mensaje char*
 * \return int Devuelve -1 si no es un entero o es un entero mas otro valor no entero, o 0 si es entero
 *
 */
int ValideGetInt(int* numero, char* mensaje)
{
    int validacion = 1;
    char cadena [20];
    int i;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);

    for(i=0; i<strlen(cadena) ; i++)
    {
        if(cadena[i]==' ')
        {
        	validacion = -1;
            break;
        }

        if(cadena[i]!='\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9')
            {
            	validacion = -1;
            }
        }
    }

    if(validacion == 1)
    {
        *numero = atoi (cadena);
    }

    return validacion;
}
