/*
 * ArrayPassenger.c
 *
 *  Created on: 8 may. 2022
 *      Author: brian
 */

#include "ArrayPassenger.h"

int initPassengers(Passenger* list, int len)
{
	int retorno=-1;
	int i;


	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=TRUE;
			retorno=0;
		}
	}


	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int retorno=-1;
	int index;

	index=findPassengerById(list, len, index);

	if(list != NULL && len>0 && name != NULL && lastName != NULL && typePassenger != 0 && flycode != NULL)
	{
		if(index !=-1)
		{



		}
		else
		{
			printf("No hay espacio en la lista!!!");
		}



	}

	return retorno;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int i;
	int index=-1;

	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id==id)
			{
				index=i;
				break;
			}
		}
	}

	return index;

}

