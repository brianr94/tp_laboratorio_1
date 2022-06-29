/*
 * sorts.c
 *
 *  Created on: 28 jun. 2022
 *      Author: brian
 */

#include "sorts.h"
#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int Passenger_sortById(void* passengerI, void* passengerJ)
{
	int retorno=0;
	int idAuxI;
	int idAuxJ;
	Passenger* pPasajeroI;
	Passenger* pPasajeroJ;


	if(passengerI!=NULL && passengerJ!=NULL)
	{
		pPasajeroI=(Passenger*)passengerI;
		pPasajeroJ=(Passenger*)passengerJ;

		Passenger_getId(pPasajeroI, &idAuxI);
		Passenger_getId(pPasajeroJ, &idAuxJ);

		if(idAuxI>idAuxJ)
		{
			retorno=1;
		}
		else
		{
			if(idAuxJ > idAuxI)
			{
				retorno=-1;
			}
		}

	}
	return retorno;
}

int Passenger_sortByPrice(void* passengerI, void* passengerJ)
{
	int retorno=0;
	float precioAuxI;
	float precioAuxJ;
	Passenger* pPasajeroI;
	Passenger* pPasajeroJ;


	if(passengerI != NULL && passengerJ!=NULL)
	{
		pPasajeroI=(Passenger*)passengerI;
		pPasajeroJ=(Passenger*)passengerJ;

		Passenger_getPrecio(pPasajeroI, &precioAuxI);
		Passenger_getPrecio(pPasajeroJ, &precioAuxJ);

		if(precioAuxI>precioAuxJ)
		{
			retorno=1;
		}
		else
		{
			if(precioAuxJ > precioAuxI)
			{
				retorno=-1;
			}
		}

	}
	return retorno;
}

int Passenger_sortByName(void* passengerI, void* passengerJ)
{
	int retorno;
	char nombreI[TAMSTRING];
	char nombreJ[TAMSTRING];

	Passenger* pPasajeroI;
	Passenger* pPasajeroJ;

	if(passengerI != NULL && passengerJ != NULL)
	{
		pPasajeroI=(Passenger*)passengerI;
		pPasajeroJ=(Passenger*)passengerJ;

		Passenger_getNombre(pPasajeroI, nombreI);
		Passenger_getNombre(pPasajeroJ, nombreJ);

		retorno=strcmp(nombreI,nombreJ);
		if(retorno < 0)
		{
			retorno=-1;
		}
		else
		{
			if(retorno> 0)
			{
				retorno=1;
			}
		}
	}

	return retorno;
}

int Passenger_sortByLastName(void* passengerI, void* passengerJ)
{
	int retorno;
	char apellidoI[TAMSTRING];
	char apellidoJ[TAMSTRING];

	Passenger* pPasajeroI;
	Passenger* pPasajeroJ;

	if(passengerI != NULL && passengerJ != NULL)
	{
		pPasajeroI=(Passenger*)passengerI;
		pPasajeroJ=(Passenger*)passengerJ;

		Passenger_getApellido(pPasajeroI, apellidoI);
		Passenger_getApellido(pPasajeroJ, apellidoJ);

		retorno=strcmp(apellidoI,apellidoJ);
		if(retorno < 0)
		{
			retorno=-1;
		}
		else
		{
			if(retorno> 0)
			{
				retorno=1;
			}
		}
	}

	return retorno;
}

int Passenger_sortByFlyCode(void* passengerI, void* passengerJ)
{
	int retorno;
	char codigoVueloI[TAMSTRING];
	char codigoVueloJ[TAMSTRING];

	Passenger* pPasajeroI;
	Passenger* pPasajeroJ;

	if(passengerI != NULL && passengerJ != NULL)
	{
		pPasajeroI=(Passenger*)passengerI;
		pPasajeroJ=(Passenger*)passengerJ;

		Passenger_getCodigoVuelo(pPasajeroI, codigoVueloI);
		Passenger_getCodigoVuelo(pPasajeroJ, codigoVueloJ);

		retorno=strcmp(codigoVueloI,codigoVueloJ);
		if(retorno < 0)
		{
			retorno=-1;
		}
		else
		{
			if(retorno> 0)
			{
				retorno=1;
			}
		}
	}

	return retorno;
}

int Passenger_sortByTypePassenger(void* passengerI, void* passengerJ)
{
	int retorno=0;
	int tipoPasajeroAuxI;
	int tipoPasajeroAuxJ;
	Passenger* pPasajeroI;
	Passenger* pPasajeroJ;


	if(passengerI != NULL && passengerJ!=NULL)
	{
		pPasajeroI=(Passenger*)passengerI;
		pPasajeroJ=(Passenger*)passengerJ;

		Passenger_getTipoPasajero(pPasajeroI, &tipoPasajeroAuxI);
		Passenger_getTipoPasajero(pPasajeroJ, &tipoPasajeroAuxJ);

		if(tipoPasajeroAuxI>tipoPasajeroAuxJ)
		{
			retorno=1;
		}
		else
		{
			if(tipoPasajeroAuxJ > tipoPasajeroAuxI)
			{
				retorno=-1;
			}
		}

	}
	return retorno;
}

int Passenger_sortByStatusFligth(void* passengerI, void* passengerJ)
{
	int retorno=0;
	int estadoVueloAuxI;
	int estadoVueloAuxJ;
	Passenger* pPasajeroI;
	Passenger* pPasajeroJ;


	if(passengerI != NULL && passengerJ!=NULL)
	{
		pPasajeroI=(Passenger*)passengerI;
		pPasajeroJ=(Passenger*)passengerJ;

		Passenger_getEstadoVuelo(pPasajeroI, &estadoVueloAuxI);
		Passenger_getEstadoVuelo(pPasajeroJ, &estadoVueloAuxJ);

		if(estadoVueloAuxI>estadoVueloAuxJ)
		{
			retorno=1;
		}
		else
		{
			if(estadoVueloAuxJ > estadoVueloAuxI)
			{
				retorno=-1;
			}
		}

	}
	return retorno;
}
