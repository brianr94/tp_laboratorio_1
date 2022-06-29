/*
 * ultimoID.c
 *
 *  Created on: 29 jun. 2022
 *      Author: brian
 */

#include "ultimoID.h"
#include "Passenger.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>


int ultimoID_findMaxId(LinkedList* pArrayListPassenger)
{
	int id;
	int idMax;
	int length;
	int i;
	Passenger* pasajero = NULL;
	idMax = 0;

	if(pArrayListPassenger != NULL)
	{
		length = ll_len(pArrayListPassenger);

		if (length > 0)
		{
			for (i= 0; i < length; i++)
			{
				pasajero = ll_get(pArrayListPassenger, i);
				Passenger_getId(pasajero, &id);

				if(id>idMax)
				{
					idMax = id;
				}
			}
		}
	}

	return idMax;
}

int ultimoID_saveMaxIdAsText(LinkedList* pArrayListPassenger)
{
	int idMax;
	FILE* pFile;
	int retorno=-1;


	if(pArrayListPassenger != NULL)
	{
		idMax = ultimoID_findMaxId(pArrayListPassenger);

		pFile = fopen("lastIds.csv", "w");

		if (pFile != NULL)
		{
			fprintf(pFile,"%d\n",idMax);
			fclose(pFile);
			retorno = 0;
		}
	}

	return retorno;
}

int ultimoID_parser_getMaxId()
{
	int idAux2;
	char idAux1[50];
	int cantidadlineas;
	FILE* pFile;

	idAux2 = -1;

	pFile = fopen("lastIds.csv", "r");

	if (pFile != NULL)
	{
		fscanf(pFile, "%[^\n]\n", idAux1);
		do
		{
			cantidadlineas = fscanf(pFile, "%[^\n]\n", idAux1);
			if (cantidadlineas == 1)
			{
				if (idAux2 < atoi(idAux1))
				{
					idAux2 = atoi(idAux1);
				}
			}

		} while (!feof(pFile));
	}

	return idAux2;
}
