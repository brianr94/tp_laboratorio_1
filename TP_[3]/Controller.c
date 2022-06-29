#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "parser.h"
#include "sorts.h"
#include "ultimoID.h"
#include "utn_inputs.h"
#include "utn_validaciones.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=1;
	FILE* pFile;

	pFile= fopen(path,"r");

	if(path != NULL && pArrayListPassenger != NULL)
	{
		retorno=parser_PassengerFromText(pFile, pArrayListPassenger);

	}


    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=1;

	FILE* pFile;

	pFile=fopen(path, "rb");

	if(path != NULL && pArrayListPassenger != NULL)
	{
		retorno=parser_PassengerFromBinary(pFile, pArrayListPassenger);
	}

    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=1;
	int ultimoId;
	int length;
	Passenger* newPasajero;

	length=ll_len(pArrayListPassenger);

	if(length >0)
	{
		ultimoId= ultimoID_findMaxId(pArrayListPassenger);
	}
	else
	{
		ultimoId= ultimoID_parser_getMaxId();
	}



	if(pArrayListPassenger != NULL)
	{
		newPasajero=Passenger_requestDataPassenger(&ultimoId);

		if(newPasajero != NULL)
		{
			ll_add(pArrayListPassenger, newPasajero);
			retorno=0;
			printf("\n Se realizo correctamente la carga del pasajero!!!\n");
		}

	}
	else
	{
		printf("\nError. No se pudo cargar el pasajero!!\n");
	}



    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=1;
	int index;
	int idPasajero;
	Passenger* pasajero=NULL;

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);

		pedirNumeroValidado(&idPasajero, "Ingrese el ID del pasajero a modificar: ", "Error. Ingrese correctamente el ID: ");

		pasajero= Passenger_findPassegerById(pArrayListPassenger, idPasajero, &index);

		if(pasajero != NULL && index != -1)
		{
			if(Passenger_modifyPassenger(pasajero)==0)
			{
				ll_set(pArrayListPassenger, index, pasajero);
				retorno=0;
			}

		}
		else
		{
			printf("\nError. El ID ingresado no existe!!!\n");
		}

	}


    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno=1;
	int idPasajero;
	int index;
	Passenger* pasajero=NULL;

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);

		pedirNumeroValidado(&idPasajero, "Ingrese el ID del pasajero a dar de baja: ", "Error. Ingrese correctamente el ID: ");

		pasajero=Passenger_findPassegerById(pArrayListPassenger, idPasajero, &index);

		if(pasajero != NULL && index != -1)
		{
			printf("\nEl pasajero que se va a eliminar es el siguiente: ");
			printf("\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n","ID", "Nombre", "Apellido", "Tipo Pasajero", "Precio","Codigo Vuelo", "Estado Vuelo");
			Passenger_printPassenger(pasajero);

			if(verificarConfirmacion("Ingrese 's' para confirmar la baja: ")==0)
			{
				ll_remove(pArrayListPassenger, index);
				pasajero=NULL;
				retorno=0;
			}
			else
			{
				printf("\nSe cancelo la Baja del Pasajero!!!\n");
			}
		}
		else
		{
			printf("\nError. El ID ingresado no existe!!!\n");
		}

	}


    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=1;
	int i;
	int len;
	Passenger* pasajero;

	if(pArrayListPassenger != NULL)
	{
		len=ll_len(pArrayListPassenger);
		printf("\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n","ID", "Nombre", "Apellido", "Tipo Pasajero", "Precio","Codigo Vuelo", "Estado Vuelo");
		for(i=0;i<len;i++)
		{
			pasajero=ll_get(pArrayListPassenger, i);
			Passenger_printPassenger(pasajero);
		}
		retorno=0;
	}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=1;

	if(pArrayListPassenger != NULL)
	{
		Passenger_printSortMenu(pArrayListPassenger);
		retorno=0;
	}


    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=1;
	int i;
	int length;
	int idAux;
	int tipoPasajero;
	int estadoVuelo;
	char nombreAux[TAMSTRING];
	char apellidoAux[TAMSTRING];
	float precio;
	char codigoVuelo[TAMCODIGOVUELO];
	char tipoPasajeroAux[TAMSTRING];
	char estadoVueloAux[TAMSTRING];

	Passenger* pasajero;

	FILE* pFile;

	pFile=fopen(path,"w");

	if(path != NULL && pArrayListPassenger != NULL)
	{
		length=ll_len(pArrayListPassenger);
		if(pFile != NULL)
		{
			fprintf(pFile,"%s\n","id,name,lastname,price,flycode,typePassenger,statusFlight");
			for(i=0;i<length;i++)
			{
				pasajero=ll_get(pArrayListPassenger, i);

				if(pasajero != NULL)
				{
					Passenger_getId(pasajero, &idAux);
					Passenger_getNombre(pasajero, nombreAux);
					Passenger_getApellido(pasajero, apellidoAux);
					Passenger_getPrecio(pasajero,&precio);
					Passenger_getCodigoVuelo(pasajero, codigoVuelo);
					Passenger_getTipoPasajero(pasajero, &tipoPasajero);
					Passenger_getEstadoVuelo(pasajero, &estadoVuelo);

					itoa(estadoVuelo,estadoVueloAux,10);
					itoa(tipoPasajero,tipoPasajeroAux,10);

					Passenger_getStrEstadoVuelo(estadoVueloAux);
					Passenger_getStrTipoPasajero(tipoPasajeroAux);

					fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",idAux,nombreAux,apellidoAux,precio,codigoVuelo,tipoPasajeroAux,estadoVueloAux);
				}
			}

			fclose(pFile);
			printf("Archivo '%s' guardado correctamente. \n",path);
		}
		else
		{
			printf("\nError.Archivo no creado!!!\n");
		}

		retorno=0;
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=1;
	int i;
	int length;
	Passenger* pasajero=NULL;


	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* pFile=fopen(path,"wb");

		if(pFile!=NULL)
		{
			length=ll_len(pArrayListPassenger);
			for(i=0;i<length;i++)
			{
				pasajero=ll_get(pArrayListPassenger, i);
				if(pasajero != NULL)
				{
					fwrite(pasajero, sizeof(Passenger), 1, pFile);
				}
			}
			retorno=0;
		}

		fclose(pFile);
	}



    return retorno;
}

