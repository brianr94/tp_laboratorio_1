#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

#define MAXLINE 7
#define TAMSTR 50

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pasajero=NULL;
	char id[TAMSTR];
	char nombre[TAMSTR];
	char apellido[TAMSTR];
	char precio[TAMSTR];
	char codigoVuelo[TAMSTR];
	char tipoPasajero[TAMSTR];
	char estadoVuelo[TAMSTR];
	int cantidadLineas;

	int retorno=1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{


		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

		do
		{

			cantidadLineas=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

			if(cantidadLineas==MAXLINE)
			{
				pasajero=Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

				if(pasajero != NULL)
				{
					ll_add(pArrayListPassenger, pasajero);
					retorno=0;
				}
			}
			else
			{
				break;
			}


		}while(!feof(pFile));

		fclose(pFile);

	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pasajero=NULL;
	int cantidad;
	int retorno=1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{

		do
		{
			pasajero=Passenger_new();
			cantidad=fread(pasajero,sizeof(Passenger),1,pFile);

			if(cantidad != 0 && pasajero != NULL)
			{
				ll_add(pArrayListPassenger, pasajero);
				retorno=0;
			}

		}while(!feof(pFile));

		fclose(pFile);

	}

    return retorno;
}
