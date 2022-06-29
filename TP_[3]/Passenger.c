/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "sorts.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "utn_inputs.h"
#include "utn_validaciones.h"


int Passenger_setId(Passenger* this,int id)
{
	int seCargo=-1;

	if(this != NULL && id >= 0)
	{
		this->id=id;
		seCargo=0;
	}

	return seCargo;

}

int Passenger_getId(Passenger* this,int* id)
{
	int seCargo=-1;

	if(this != NULL && id != NULL)
	{
		*id=this->id;
		seCargo=0;
	}

	return seCargo;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int seCargo=-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		seCargo=0;
	}

	return seCargo;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int seCargo=-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		seCargo=0;
	}

	return seCargo;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int seCargo=-1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido,apellido);
		seCargo=0;
	}

	return seCargo;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int seCargo=-1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		seCargo=0;
	}

	return seCargo;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int seCargo=-1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		seCargo=0;
	}

	return seCargo;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int seCargo=-1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		seCargo=0;
	}

	return seCargo;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int seCargo=-1;

	if(this != NULL && tipoPasajero >0) //validar rango
	{
		this->tipoPasajero=tipoPasajero;
		seCargo=0;
	}

	return seCargo;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int seCargo=-1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero=this->tipoPasajero;
		seCargo=0;
	}

	return seCargo;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int seCargo=-1;

	if(this != NULL && precio > 0)
	{
		this->precio=precio;
		seCargo=0;
	}

	return seCargo;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int seCargo=-1;

	if(this != NULL && precio != NULL)
	{
		*precio=this->precio;
		seCargo=0;
	}

	return seCargo;
}

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int seCargo=-1;

	if(this != NULL && estadoVuelo>0)
	{
		this->estadoVuelo=estadoVuelo;
		seCargo=0;
	}

	return seCargo;
}
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo)
{
	int seCargo=-1;

	if(this != NULL && estadoVuelo>0)
	{
		*estadoVuelo=this->estadoVuelo;
		seCargo=0;
	}

	return seCargo;
}

Passenger* Passenger_new()
{
	Passenger* pasajero=NULL;

	pasajero=(Passenger*)malloc(sizeof(Passenger));

	return pasajero;

}

Passenger* Passenger_newParametros(char* idStr ,char* nombreStr ,char* apellidoStr ,char* precioStr ,char* codigoDeVueloStr ,char* tipoPasajeroStr ,char* estadoDeVueloStr)
{

	int auxId;
	int auxTipoPasajero;
	float auxPrecio;
	int auxEstadoVuelo;

	Passenger* pasajero=NULL;
	pasajero=Passenger_new();

	if(pasajero != NULL)
	{
		if(idStr != NULL && nombreStr != NULL && tipoPasajeroStr != NULL && apellidoStr != NULL && precioStr != NULL && codigoDeVueloStr != NULL && estadoDeVueloStr != NULL)
		{
			Passenger_getNumEstadoVuelo(estadoDeVueloStr);
			Passenger_getNumTipoPasajero(tipoPasajeroStr);

			auxId=atoi(idStr);
			auxTipoPasajero=atoi(tipoPasajeroStr);
			auxPrecio=atof(precioStr);
			auxEstadoVuelo=atoi(estadoDeVueloStr);

			Passenger_setId(pasajero, auxId);
			Passenger_setNombre(pasajero, nombreStr);
			Passenger_setApellido(pasajero, apellidoStr);
			Passenger_setCodigoVuelo(pasajero, codigoDeVueloStr);
			Passenger_setPrecio(pasajero, auxPrecio);
			Passenger_setTipoPasajero(pasajero, auxTipoPasajero);
			Passenger_setEstadoVuelo(pasajero, auxEstadoVuelo);

		}
		else
		{
			Passenger_delete(pasajero);
		}

	}

	return pasajero;
}

int Passenger_getStrEstadoVuelo(char* codigoVueloStr)
{
	int retorno=-1;
	char estadoAterrizado[]="Aterrizado";
	char estadoEnVuelo[]="En Vuelo";
	char estadoDemorado[]="Demorado";
	char estadoHorario[]="En Horario";

	if(codigoVueloStr != NULL)
	{
		if(strcmp(codigoVueloStr, "1")==0)
		{
			strcpy(codigoVueloStr, estadoAterrizado);
			retorno=0;
		}
		else
		{
			if(strcmp(codigoVueloStr, "4")==0)
			{
				strcpy(codigoVueloStr, estadoHorario);
				retorno=0;
			}
			else
			{
				if(strcmp(codigoVueloStr,"2")==0)
				{
					strcpy(codigoVueloStr, estadoEnVuelo);
					retorno=0;
				}
				else
				{
					strcpy(codigoVueloStr, estadoDemorado);
					retorno=0;
				}
			}
		}

	}

	return retorno;
}

int Passenger_getStrTipoPasajero(char* tipoPasajeroStr)
{
	int	retorno=-1;
	char tipoEconomico[]="EconomyClass";
	char tipoEjecutivo[]="ExecutiveClass";
	char tipoPrimera[]="FirstClass";

	if(tipoPasajeroStr != NULL)
	{
		if(strcmp(tipoPasajeroStr, "1")==0)
		{
			strcpy(tipoPasajeroStr, tipoEconomico);
			retorno=0;
		}
		else
		{
			if(strcmp(tipoPasajeroStr,"2")==0)
			{
				strcpy(tipoPasajeroStr, tipoEjecutivo);
				retorno=0;
			}
			else
			{
				strcpy(tipoPasajeroStr, tipoPrimera);
				retorno=0;
			}
		}

	}

	return retorno;
}

int Passenger_getNumEstadoVuelo(char* codigoVueloStr)
{
	int retorno=-1;
	char estadoAterrizado[]="1";
	char estadoEnVuelo[]="2";
	char estadoDemorado[]="3";
	char estadoHorario[]="4";

	if(codigoVueloStr != NULL)
	{
		if(strcmp(codigoVueloStr, "Aterrizado")==0)
		{
			strcpy(codigoVueloStr, estadoAterrizado);
			retorno=0;
		}
		else
		{
			if(strcmp(codigoVueloStr, "En Horario")==0)
			{
				strcpy(codigoVueloStr, estadoHorario);
				retorno=0;
			}
			else
			{
				if(strcmp(codigoVueloStr,"En Vuelo")==0)
				{
					strcpy(codigoVueloStr, estadoEnVuelo);
					retorno=0;
				}
				else
				{
					strcpy(codigoVueloStr, estadoDemorado);
					retorno=0;
				}
			}
		}

	}

	return retorno;
}

int Passenger_getNumTipoPasajero(char* tipoPasajeroStr)
{
	int	retorno=-1;
	char tipoEconomico[]="1";
	char tipoEjecutivo[]="2";
	char tipoPrimera[]="3";

	if(tipoPasajeroStr != NULL)
	{
		if(strcmp(tipoPasajeroStr, "EconomyClass")==0)
		{
			strcpy(tipoPasajeroStr, tipoEconomico);
			retorno=0;
		}
		else
		{
			if(strcmp(tipoPasajeroStr,"ExecutiveClass")==0)
			{
				strcpy(tipoPasajeroStr, tipoEjecutivo);
				retorno=0;
			}
			else
			{
				strcpy(tipoPasajeroStr, tipoPrimera);
				retorno=0;
			}
		}

	}

	return retorno;
}

Passenger* Passenger_requestDataPassenger(int* id)
{
	Passenger* pasajero=NULL;

	char nombre[TAMSTRING];
	char apellido[TAMSTRING];
	char idAux[50];
	int ultimoId;
	float precio;
	char codigoVuelo[TAMCODIGOVUELO];
	int tipoPasajero;
	int estadoVuelo;
	char precioAux[50];
	char tipoPasajeroAux[50];
	char estadoVueloAux[50];

	ultimoId=*id+1;

	if(pasajero != NULL)
	{

		if(pedirCadenaValidada(nombre, "Ingrese el nombre del pasajero: ", "Error. Ingrese correctamente el nombre(Max caracteres 50): ", TAMSTRING)==-1)
		{
			printf("Error.No se pudo guardar correctamente el nombre del pasajero.\n");
		}

		if(pedirCadenaValidada(apellido, "Ingrese el apellido del pasajero: ", "Error. Ingrese corectamente el apellido(Max caracteres 50): ", TAMSTRING)==-1)
		{
			printf("Error.No se pudo guardar correctamente el nombre del pasajero.\n");
		}

		if(pedirNumeroFlotanteConRango(&precio, "Ingrese el precio del vuelo(Min: 10000 - Max: 50000): ", "Error. Ingrese correctamente el precio(Min: 10000 - Max: 50000): ", MIN_PRECIO, MAX_PRECIO)==-1)
		{
			printf("Error.No se pudo guardar correctamente el precio del vuelo.\n");
		}
		else
		{
			sprintf(precioAux,"%f",precio);
		}

		if(pedirNumeroEnteroValidado(&tipoPasajero, "Ingrese el tipo de pasajero(1-ECONOMYCLASS 2-EXECUTIVECLASS 3-FIRSTCLASS): ", "Error. Ingrese correctamente el tipo de pasajero(1-ECONOMYCLASS 2-EXECUTIVECLASS 3-FIRSTCLASS): ", 1, 3)==-1)
		{
			printf("Error.No se pudo guardar correctamente el tipo de pasajero.\n");
		}
		else
		{
			itoa(tipoPasajero,tipoPasajeroAux,10);
		}

		if(pedirCadenaAlfaNumerica(codigoVuelo, "Ingrese el codigo de vuelo: ", "Error. Ingrese correctamente el codigo de vuelo(Max caracteres 8): ", TAMCODIGOVUELO)==-1)
		{
			printf("Error.No se pudo guardar correctamente el codigo del vuelo.\n");
		}

		if(pedirNumeroEnteroValidado(&estadoVuelo, "Ingrese el estado de vuelo(1-ATERRIZADO 2-EN VUELO 3- DEMORADO 4- EN HORARIO): ", "Error. Ingrese correctamente el estado de vuelo(1-ATERRIZADO 2-EN VUELO 3- DEMORADO 4- EN HORARIO): ", 1, 4)==-1)
		{
			printf("Error.No se pudo guardar correctamente el codigo del vuelo.\n");
		}
		else
		{
			itoa(estadoVuelo,estadoVueloAux,10);
		}

		itoa(ultimoId,idAux,10);

		printf("\nPasajero a cargar:\n\n%-5s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "TipoPasajero", "Precio", "EstadoDelVuelo", "CodigoDeVuelo");
		printf("%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n", idAux, nombre, apellido, tipoPasajeroAux, precioAux, estadoVueloAux, codigoVuelo);

		if(verificarConfirmacion("Ingrese 's' para confirmar la carga del pasajero: ")==0)
		{
			itoa(ultimoId,idAux,10);
			pasajero=Passenger_newParametros(idAux, nombre, apellido, precioAux, codigoVuelo, tipoPasajeroAux, estadoVueloAux);
		}
		else
		{
			printf("\nSe cancelo la carga del pasajero!!!\n");
		}

	}

	return pasajero;
}

int Passenger_modifyPassenger(Passenger* this)
{
	int retorno=-1;
	int opcion;
	char nombreAux[TAMSTRING];
	char apellidoAux[TAMSTRING];
	char codigoVuelo[TAMCODIGOVUELO];
	int tipoPasajero;
	int estadoVuelo;
	float precio;
	Passenger* pasajero=this;


	if(this != NULL)
	{

		do{
			printf("\nPasajero a modificar:\n\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n\n","ID", "Nombre", "Apellido", "Tipo Pasajero", "Precio","Codigo VUelo", "Estado Vuelo");
			Passenger_printPassenger(pasajero);

			pedirNumeroEnteroValidado(&opcion, "---------------------------------------\n"
												"1. Modificar nombre del pasajero\n"
												"2. Modificar apellido del pasajero\n"
												"3. Modificar tipo del pasajero\n"
												"4. Modificar precio del pasajero\n"
												"5. Modifificar codigo del vuelo\n"
												"6. Modificar estado del vuelo\n"
												"7. Salir\n"
												"---------------------------------------\n"
												"Ingrese una opcion: ",
												"----------------------------------------\n"
												"1. Modificar nombre del pasajero\n"
												"2. Modificar apellido del pasajero\n"
												"3. Modificar tipo del pasajero\n"
												"4. Modificar precio del pasajero\n"
												"5. Modifificar codigo del vuelo\n"
												"6. Modificar estado del vuelo\n"
												"7. Salir\n"
												"-----------------------------------------\n"
												"Error. Ingrese una opcion correcta: ", 1, 7);



			switch(opcion)
			{
				case 1:
					pedirCadenaValidada(nombreAux, "Ingrese el nombre del pasajero: ", "Error. Ingrese correctamente el nombre del pasajero(Max 50 caracteres): ", TAMSTRING);

					if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
					{
						Passenger_setNombre(this, nombreAux);
						printf("\nSe realizo correctamente la modificacion del nombre del pasajero!!\n");
					}
					else
					{
						printf("\nSe cancelo la modificacion del nombre del pasajero!!!\n");
					}

					break;
				case 2:
					pedirCadenaValidada(apellidoAux, "Ingrese el apellido del pasajero: ", "Error. Ingrese correctamente el apellido (Max caracteres 50): ", TAMSTRING);

					if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
					{
						Passenger_setApellido(this, apellidoAux);
						printf("\nSe realizo correctamente la modificacion del apellido del pasajero!!\n");
					}
					else
					{
						printf("\nSe cancelo la modificacion del apellido del pasajero!!!\n");
					}

					break;
				case 3:
					pedirNumeroEnteroValidado(&tipoPasajero, "Ingrese el tipo de pasajero(1-ECONOMYCLASS 2-EXECUTIVECLASS 3-FIRSTCLASS): ", "Error. Ingrese correctamente el tipo de pasajero(1-ECONOMYCLASS 2-EXECUTIVECLASS 3-FIRSTCLASS): ", 1, 3);

					if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
					{
						Passenger_setTipoPasajero(this, tipoPasajero);
						printf("\nSe realizo correctamente la modificacion del tipo del pasajero!!\n");
					}
					else
					{
						printf("\nSe cancelo la modificacion del tipo del pasajero!!!\n");
					}

					break;
				case 4:
					pedirNumeroFlotanteConRango(&precio,"Ingrese el precio del vuelo(Min: 10000 - Max: 50000): ", "Error. Ingrese correctamente el precio(Min: 10000 - Max: 50000): ", MIN_PRECIO, MAX_PRECIO);

					if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
					{
						Passenger_setPrecio(this, precio);
						printf("\nSe realizo correctamente la modificacion del precio del vuelo!!\n");
					}
					else
					{
						printf("\nSe cancelo la modificacion del precio del vuelo!!!\n");
					}

					break;
				case 5:
					pedirCadenaAlfaNumerica(codigoVuelo, "Ingrese el codigo de vuelo: ", "Error. Ingrese correctamente el codigo de vuelo (Max caracteres 8): ", TAMCODIGOVUELO);

					if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
					{
						Passenger_setCodigoVuelo(this, codigoVuelo);
						printf("\nSe realizo correctamente la modificacion del codigo de vuelo!!\n");
					}
					else
					{
						printf("\nSe cancelo la modificacion del codigo de vuelo!!!\n");
					}

					break;
				case 6:
					pedirNumeroEnteroValidado(&estadoVuelo, "Ingrese el estado de vuelo(1-ATERRIZADO 2-EN VUELO 3- DEMORADO 4- EN HORARIO): ", "Error. Ingrese correctamente el estado de vuelo(1-ATERRIZADO 2-EN VUELO 3- DEMORADO 4- EN HORARIO): ",1,4);

					if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
					{
						Passenger_setEstadoVuelo(this, estadoVuelo);
						printf("\nSe realizo correctamente la modificacion del estado del vuelo!!\n");
					}
					else
					{
						printf("\nSe cancelo la modificacion del estado del vuelo!!!\n");
					}

					break;
				case 7:
					break;
			}

			if(opcion != 7)
			{
				system("pause");
			}


		}while(opcion != 7);

		retorno=0;

	}

	return retorno;

}


void Passenger_printPassenger(Passenger* this)
{
	int id;
	char nombre[TAMSTRING];
	char apellido[TAMSTRING];
	float precio;
	int tipoPasajero;
	int estadoVuelo;
	char codigoVuelo[TAMCODIGOVUELO];
	char estadoVueloAux[TAMSTRING];
	char tipoPasajeroAux[TAMSTRING];

	if(this != NULL)
	{
		Passenger_getId(this, &id);
		Passenger_getNombre(this, nombre);
		Passenger_getApellido(this, apellido);
		Passenger_getTipoPasajero(this, &tipoPasajero);
		Passenger_getPrecio(this, &precio);
		Passenger_getCodigoVuelo(this, codigoVuelo);
		Passenger_getEstadoVuelo(this, &estadoVuelo);

		if(tipoPasajero >0 && estadoVuelo >0)
		{
			itoa(estadoVuelo,estadoVueloAux,10);
			itoa(tipoPasajero,tipoPasajeroAux,10);

			Passenger_getStrEstadoVuelo(estadoVueloAux);
			Passenger_getStrTipoPasajero(tipoPasajeroAux);

			printf("%-5d %-15s %-20s %-20s %-15.2f %-20s %-20s\n", id, nombre, apellido, tipoPasajeroAux, precio, codigoVuelo, estadoVueloAux);

		}
	}
}

Passenger* Passenger_findPassegerById(LinkedList* pArrayPassenger, int id ,int* index)
{
	int length;
	int idAux;
	int i;
	Passenger* pasajero=NULL;

	*index=-1;
	if(pArrayPassenger != NULL)
	{
		length=ll_len(pArrayPassenger);
		if(length>0)
		{
			for(i=0;i<length;i++)
			{
				pasajero=ll_get(pArrayPassenger, i);
				Passenger_getId(pasajero, &idAux);

				if(id==idAux)
				{
					*index = i;
					break;
				}
			}
		}
	}

	return pasajero;
}

int Passenger_printSortMenu(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int opcion;
	int orden;


	do{

		pedirNumeroEnteroValidado(&opcion, "---------------------------------------------\n"
											"1. Ordenar pasajeros por ID\n"
											"2. Ordenar pasajeros por nombre\n"
											"3. Ordenar pasajeros por apellido\n"
											"4. Ordenar pasajeros por tipo\n"
											"5. Ordenar pasajeros por precio\n"
											"6. Ordenar pasajeros por codigo de vuelo\n"
											"7. Ordenar pasajeros por estado de vuelo\n"
											"8. Salir\n"
											"---------------------------------------------\n"
											"Ingrese una opcion: ",
											"----------------------------------------------\n"
											"1. Ordenar pasajeros por ID\n"
											"2. Ordenar pasajeros por nombre\n"
											"3. Ordenar pasajeros por apellido\n"
											"4. Ordenar pasajeros por tipo\n"
											"5. Ordenar pasajeros por precio\n"
											"6. Ordenar pasajeros por codigo de vuelo\n"
											"7. Ordenar pasajeros por estado de vuelo\n"
											"8. Salir\n"
											"------------------------------------------------\n"
											"Error. Ingrese una opcion correcta: ", 1, 8);


				switch(opcion)
				{
					case 1:

						pedirNumeroEnteroValidado(&orden, 	"---------------------------\n"
															"1. ordenar ID de forma ascendente\n"
															"2. ordenar ID de forma descendente\n"
															"3. Volver\n"
															"---------------------------\n"
															"Ingrese una opcion",
															"----------------------------\n"
															"1. ordenar ID de forma ascendente\n"
															"2. ordenar ID de forma descendente\n"
															"3. Volver\n"
															"---------------------------\n"
															"Error. Ingrese una opcion correcta: ", 1, 3);

						switch(orden)
						{
							case 1:
								if(ll_sort(pArrayListPassenger, Passenger_sortById, 1)==0)
								{
									printf("\nLista ordenada correctamente por ID ascendente\n");
									retorno=0;
								}
								break;
							case 2:
								if(ll_sort(pArrayListPassenger, Passenger_sortById, -1)==0)
								{
									printf("\nLista ordenada correctamente por ID descendente\n");
									retorno=0;
								}

								break;

							case 3:
								break;
						}

						break;
					case 2:

						pedirNumeroEnteroValidado(&orden,
														"---------------------------\n"
														"1. Ordenar nombres de 'A' a la 'Z'\n"
														"2. Ordenar nombres de 'Z' a la 'A'\n"
														"3. Volver\n"
														"---------------------------\n"
														"Ingrese una opcion",
														"----------------------------\n"
														"1. Ordenar de 'A' a la 'Z'\n"
														"2. Ordenar de 'Z' a la 'A'\n"
														"3. Volver\n"
														"---------------------------\n"
														"Error. Ingrese una opcion correcta: ", 1, 3);

							switch(orden)
							{
								case 1:
									if(ll_sort(pArrayListPassenger, Passenger_sortByName, 1)==0)
									{
										printf("\nLista ordenada correctamente por nombre ascendente\n");
										retorno=0;
									}
									break;
								case 2:
									if(ll_sort(pArrayListPassenger, Passenger_sortByName, -1)==0)
									{
										printf("\nLista ordenada correctamente por nombre descendente\n");
										retorno=0;
									}

									break;

								case 3:
									break;
							}

						break;
					case 3:

						pedirNumeroEnteroValidado(&orden, 	"---------------------------\n"
															"1. Ordenar apellidos de 'A' a la 'Z'\n"
															"2. Ordenar apellidos de 'Z' a la 'A'\n"
															"3. Volver\n"
															"---------------------------\n"
															"Ingrese una opcion",
															"----------------------------\n"
															"1. Ordenar de 'A' a la 'Z'\n"
															"2. Ordenar de 'Z' a la 'A'\n"
															"3. Volver\n"
															"---------------------------\n"
															"Error. Ingrese una opcion correcta: ", 1, 3);

							switch(orden)
							{
								case 1:
									if(ll_sort(pArrayListPassenger, Passenger_sortByLastName, 1)==0)
									{
										printf("\nLista ordenada correctamente por apellido de la 'A' a la 'Z'\n");
										retorno=0;
									}
									break;
								case 2:
									if(ll_sort(pArrayListPassenger, Passenger_sortByLastName, -1)==0)
									{
										printf("\nLista ordenada correctamente por apellido de la 'Z' a la 'A'\n");
										retorno=0;
									}

									break;
								case 3:
									break;
							}

						break;
					case 4:
						pedirNumeroEnteroValidado(&orden, 	"---------------------------\n"
															"1. ordenar tipos de forma ascendente\n"
															"2. ordenar tipos de forma descendente\n"
															"3. Volver\n"
															"---------------------------\n"
															"Ingrese una opcion",
															"----------------------------\n"
															"1. ordenar tipos de forma ascendente\n"
															"2. ordenar tipos de forma descedente\n"
															"3. Volver\n"
															"---------------------------\n"
															"Error. Ingrese una opcion correcta: ", 1, 3);

							switch(orden)
							{
								case 1:
									if(ll_sort(pArrayListPassenger, Passenger_sortByTypePassenger, 1)==0)
									{
										printf("\nLista ordenada correctamente por tipos de forma ascendente\n");
										retorno=0;
									}
									break;
								case 2:
									if(ll_sort(pArrayListPassenger, Passenger_sortByTypePassenger, -1)==0)
									{
										printf("\nLista ordenada correctamente por tipos de forma descendente\n");
										retorno=0;
									}

									break;

								case 3:
									break;
							}


						break;
					case 5:
						pedirNumeroEnteroValidado(&orden, 	"---------------------------\n"
															"1. ordenar precios de forma ascendente\n"
															"2. ordenar precios de forma descendente\n"
															"3. Volver\n"
															"---------------------------\n"
															"Ingrese una opcion",
															"----------------------------\n"
															"1. ordenar precios de forma ascendente\n"
															"2. ordenar precios de forma descedente\n"
															"3. Volver\n"
															"---------------------------\n"
															"Error. Ingrese una opcion correcta: ", 1, 3);

							switch(orden)
							{
								case 1:
									if(ll_sort(pArrayListPassenger, Passenger_sortByPrice, 1)==0)
									{
										printf("\nLista ordenada correctamente por precio ascendente\n");
										retorno=0;
									}
									break;
								case 2:
									if(ll_sort(pArrayListPassenger, Passenger_sortByPrice, -1)==0)
									{
										printf("\nLista ordenada correctamente por precio descendente\n");
										retorno=0;
									}

									break;

								case 3:
									break;
							}

						break;
					case 6:
						pedirNumeroEnteroValidado(&orden, 	"-----------------------------------------------\n"
															"1. Ordenar codigos de vuelo de 'A' a la 'Z'\n"
															"2. Ordenar codigos de vuelo de 'Z' a la 'A'\n"
															"3. Volver\n"
															"------------------------------------------------\n"
															"Ingrese una opcion",
															"----------------------------\n"
															"1. Ordenar codigos de vuelo de 'A' a la 'Z'\n"
															"2. Ordenar codigos de vuelo de 'Z' a la 'A'\n"
															"3. Volver\n"
															"---------------------------\n"
															"Error. Ingrese una opcion correcta: ", 1, 3);

							switch(orden)
							{
								case 1:
									if(ll_sort(pArrayListPassenger, Passenger_sortByFlyCode, 1)==0)
									{
										printf("\nLista ordenada correctamente por codigo de vuelo de la 'A' a la 'Z'\n");
										retorno=0;
									}
									break;
								case 2:
									if(ll_sort(pArrayListPassenger, Passenger_sortByFlyCode, -1)==0)
									{
										printf("\nLista ordenada correctamente por codigo de vuelo de la 'Z' a la 'A'\n");
										retorno=0;
									}

									break;
								case 3:
									break;
							}

						break;
					case 7:

					pedirNumeroEnteroValidado(&orden, 	"---------------------------\n"
														"1. ordenar estado de vuelo de forma ascendente\n"
														"2. ordenar estado de vuelo de forma descendente\n"
														"3. Volver\n"
														"---------------------------\n"
														"Ingrese una opcion",
														"----------------------------\n"
														"1. ordenar estado de vuelo de forma ascendente\n"
														"2. ordenar estado de vuelo de forma descedente\n"
														"3. Volver\n"
														"---------------------------\n"
														"Error. Ingrese una opcion correcta: ", 1, 3);

							switch(orden)
							{
								case 1:
									if(ll_sort(pArrayListPassenger, Passenger_sortByStatusFligth, 1)==0)
									{
										printf("\nLista ordenada correctamente por estado de vuelo ascendente\n");
										retorno=0;
									}
									break;
								case 2:
									if(ll_sort(pArrayListPassenger, Passenger_sortByStatusFligth, -1)==0)
									{
										printf("\nLista ordenada correctamente por estado de vuelo descendente\n");
										retorno=0;
									}

									break;

								case 3:
									break;
							}

						break;

					case 8:
						break;
				}

				if(opcion != 8)
				{
					system("pause");
				}


	}while(opcion != 8);

	retorno=0;

	return retorno;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
		this=NULL;
	}
}


