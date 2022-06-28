/*
 * ArrayPassenger.c
 *
 *  Created on: 8 may. 2022
 *      Author: brian
 */

#include "ArrayPassenger.h"
#include "utn_inputs.h"
#include "utn_validaciones.h"

int initPassengers(Passenger* list, int len)
{
	int retorno=-1;
	int i;


	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=EMPTY;
			retorno=0;
		}
	}


	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno=-1;
	int index;



	if(list != NULL && len>0 && name != NULL && lastName != NULL && typePassenger != 0 && flycode != NULL && statusFlight != 0)
	{

		searchEmptyIndex(list, len, &index);

		if(index !=-1)
		{

			list[index].id=id;
			strcpy(list[index].name,name);
			strcpy(list[index].lastName,lastName);
			list[index].price=price;
			list[index].typePassenger=typePassenger;
			strcpy(list[index].flyCode,flycode);
			list[index].statusFlight=statusFlight;
			list[index].isEmpty=FULL;
			retorno=0;
		}
		else
		{
			printf("\nNo hay espacio en la lista!!!\n");
		}

	}

	return retorno;
}

int requestPassenger(Passenger* list, int len, int* id)
{
	int retorno=-1;
	int ultimoId;
	Passenger auxPassenger;

	if(list != NULL && len>0)
	{
		ultimoId=*id;

		if(pedirCadenaCompuesta("Ingrese el nombre del pasajero(Max caracteres 51): ", "Error.", auxPassenger.name, NAME, 10)==-1)
		{
			printf("Error.No se pudo guardar correctamente el nombre del pasajero.\n");
		}

		if(pedirCadenaValidada(auxPassenger.lastName, "Ingrese el apellido del pasajero: ", "Error. Ingrese correctamente el apellido (Max caracteres 51): ", LASTNAME)==-1)
		{
			printf("Error.No se pudo guardar correctamente el apellido del pasajero.\n");
		}

		if(pedirNumeroEnteroValidado(&auxPassenger.typePassenger, "Ingrese el tipo de pasajero (1-CLASE ECONOMICA 2-CLASE EJECUTIVA 3-PRIMERA CLASE): ", "Error. Ingrese correctamente el tipo de pasajero (1-CLASE TURISTA 2-CLASE ECONOMICA 3-PRIMERA CLASE): ", 1, 3)==-1)
		{
			printf("Error.No se pudo guardar correctamente el tipo de pasajero.\n");
		}

		if(pedirNumeroFlotante(&auxPassenger.price, "Ingrese el precio del vuelo: ", "Error. Ingrese correctamente el precio: ")==-1)
		{
			printf("Error.No se pudo guardar correctamente el precio del vuelo.\n");
		}

		if(pedirCadenaAlfaNumerica(auxPassenger.flyCode, "Ingrese el codigo de vuelo: ", "Error. Ingrese correctamente el codigo de vuelo (Max caracteres 10): ", FLYCODE)==-1)
		{
			printf("Error.No se pudo guardar correctamente el codigo del vuelo.\n");
		}

		if(pedirNumeroEnteroValidado(&auxPassenger.statusFlight, "Ingrese estado del vuelo(1- ACTIVO 2- INACTIVO 3- DEMORADO): ", "Error. Ingrese correctamente el estado del Vuelo(1- ACTIVO 2- INACTIVO 3- DEMORADO): ", 1, 3)==-1)
		{
			printf("Error.No se pudo guardar correctamente el estado del vuelo.\n");
		}

		auxPassenger.id=0;

		printf("\nAl confirmar el alta del pasajero se le asignara un ID\n");

		printf("\nPasajero a cargar:\n\n%-5s %-20s %-20s %-20s %-20s %-20s %-25s\n", "ID", "Nombre", "Apellido", "TipoPasajero", "Precio", "EstadoDelVuelo", "CodigoDeVuelo");
		printPassenger(auxPassenger);

		if(verificarConfirmacion("Ingrese 's' para confirmar la carga: ")==0)
		{
			auxPassenger.id=ultimoId+1;

			if(addPassenger(list, len, auxPassenger.id, auxPassenger.name, auxPassenger.lastName, auxPassenger.price, auxPassenger.typePassenger, auxPassenger.flyCode, auxPassenger.statusFlight)==0)
			{
				printf("\n Se realizo correctamente la carga del pasajero!!!\n");
				*id=auxPassenger.id;
				retorno=0;
			}
			else
			{
				printf("\nError. No se pudo realizar la carga del pasajero!!!\n");
			}
		}
		else
		{
			printf("\nSe cancelo la carga de pasajero!!\n");
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
			if(list[i].isEmpty==FULL && list[i].id==id)
			{
				index=i;
				break;
			}
		}
	}

	return index;

}

int searchEmptyIndex(Passenger* list, int len, int* index)
{
	int i;
	int retorno=-1;

	if(list!= NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==EMPTY)
			{
				*index=i;
				break;
			}
			retorno=0;
		}
	}

	return retorno;

}


int sortPassengersByLastName(Passenger* list, int len, int order)
{
	int retorno=-1;
	int i;
	int j;
	int ordenAscDesc;
	Passenger auxPassenger;


	if(list != NULL && len>0)
	{
		if(order==1)
		{
			ordenAscDesc=1;
		}
		else
		{
			ordenAscDesc=-1;
		}


		for(i=0;i<len;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(list[i].isEmpty==FULL && list[j].isEmpty==FULL)
				{
					if(strcmp(list[i].lastName,list[j].lastName)==0 && list[i].typePassenger>list[j].typePassenger)
					{
						auxPassenger=list[i];
						list[i]=list[j];
						list[j]=auxPassenger;
						retorno=0;
					}
					else
					{
						if(strcmp(list[i].lastName,list[j].lastName)==ordenAscDesc)
						{
							auxPassenger=list[i];
							list[i]=list[j];
							list[j]=auxPassenger;
							retorno=0;
						}
					}
				}
			}
		}
	}

	return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order, int statusFligth)
{
	int retorno=-1;
	int i;
	int j;
	int ordenAscDesc;
	Passenger auxPassenger;


	if(list != NULL && len>0)
	{
		if(order==1)
		{
			ordenAscDesc=1;
		}
		else
		{
			ordenAscDesc=-1;
		}

		for(i=0;i<len;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(list[i].isEmpty==FULL && list[j].isEmpty==FULL)
				{
						if(stricmp(list[i].flyCode,list[i+1].flyCode)==0 && list[i].typePassenger>list[j].typePassenger)
						{
							auxPassenger=list[i];
							list[i]=list[j];
							list[j]=auxPassenger;
							retorno=0;
						}
						else
						{
							if(stricmp(list[i].flyCode,list[i+1].flyCode)==ordenAscDesc)
							{
								auxPassenger=list[i];
								list[i]=list[j];
								list[j]=auxPassenger;
								retorno=0;
							}
						}
					}
				}
			}
	}

	if(retorno==0)
	{
		printf("\nPasajeros ordenados:\n\n%-5s %-20s %-20s %-20s %-20s %-20s %-25s\n", "ID", "Nombre", "Apellido", "TipoPasajero", "Precio", "EstadoDelVuelo", "CodigoDeVuelo");
		for(i=0;i<len;i++)
		{
			if(list[i].statusFlight==statusFligth)
			{
				printPassenger(list[i]);
			}
		}
	}

	return retorno;
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno=-1;
	int index;

	if(list != NULL && len>0)
	{
		printPassengers(list,len);
		pedirNumeroEnteroValidado(&id, "Ingrese el ID del Pasajero a dar de baja (1-2000): ", "Error, ingrese correctamente el ID (de 0 a 2000): ", 1, 2000);
		index=findPassengerById(list, len, id);

		if(index != -1)
		{
			printf("\nPasajero que se dara de baja:\n\n%-5s %-20s %-20s %-20s %-20s %-20s %-25s\n", "ID", "Nombre", "Apellido", "TipoPasajero", "Precio", "EstadoDelVuelo", "CodigoDeVuelo");
			printPassenger(list[index]);

			if(verificarConfirmacion("Ingrese 's' para confirmar la baja: ")==0)
			{
				list[index].isEmpty=EMPTY;
				printf("\nLa baja del pasajero fue dado correctamente!!\n");
				retorno=0;
			}
			else
			{
				printf("\nSe cancelo la baja del pasajero!!!\n");
			}
		}
		else
		{
			printf("\nEl ID del pasajero no existe!!!\n");
		}

	}

	return retorno;
}

void printPassenger(Passenger list)
{
	if(list.typePassenger == 1)
	{
		switch(list.statusFlight)
		{
		case 1:
			printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"CLASE ECONOMICA", list.price, "ACTIVO", list.flyCode);
			break;
		case 2:
			printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"CLASE ECONOMICA", list.price, "INACTIVO", list.flyCode);
			break;
		case 3:
			printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"CLASE ECONOMICA", list.price, "DEMORADO", list.flyCode);
			break;
		}

	}

		if(list.typePassenger == 2)
		{
			switch(list.statusFlight)
			{
				case 1:
					printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"CLASE EJECUTIVA", list.price, "ACTIVO", list.flyCode);
					break;
				case 2:
					printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ," CLASE EJECUTIVA", list.price, "INACTIVO", list.flyCode);
					break;
				case 3:
					printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"CLASE EJECUTIVA", list.price, "DEMORADO", list.flyCode);
					break;
			}
		}

		if(list.typePassenger == 3)
		{
			switch(list.statusFlight)
			{
				case 1:
					printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"PRIMERA CLASE", list.price, "ACTIVO", list.flyCode);
					break;
				case 2:
					printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"PRIMERA CLASE", list.price, "INACTIVO", list.flyCode);
					break;
				case 3:
					printf("%-5d %-20s %-20s %-20s %-20.2f %-20s %-25s\n", list.id, list.name, list.lastName ,"PRIMERA CLASE", list.price, "DEMORADO", list.flyCode);
					break;
			}
		}
}

int printPassengers(Passenger* list, int length)
{
	int retorno=-1;
	int i;

	if(list != NULL && length>0)
	{
		printf("\nDatos de los pasajeros:\n\n%-5s %-20s %-20s %-20s %-20s %-20s %-25s\n", "ID", "Nombre", "Apellido", "TipoPasajero", "Precio", "EstadoDelVuelo", "CodigoDeVuelo");

		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==FULL)
			{
				printPassenger(list[i]);
				retorno=0;
			}
		}
	}

	return retorno;
}

int modifyPasseger(Passenger* list, int len)
{
	int idIngresado;
	int index;
	int opcion;
	int retorno=-1;
	Passenger auxPassenger;

	if(list != NULL && len>0)
	{
		printPassengers(list, len);

		pedirNumeroEnteroValidado(&idIngresado, "Ingrese el ID del pasajero a modificar(1-2000): ", "Error. Ingrese correctamente el ID (1-2000): ", 1, 2000);
		index=findPassengerById(list, len, idIngresado);

		if(index != -1)
		{

			do
			{
				printf("\nPasajero a modificar:\n\n%-5s %-20s %-20s %-20s %-20s %-20s %-25s\n", "ID", "Nombre", "Apellido", "TipoPasajero", "Precio", "EstadoDelVuelo", "CodigoDeVuelo");
				printPassenger(list[index]);

				auxPassenger=list[index];

				pedirNumeroEnteroValidado(&opcion,
													"-------------------------------------\n"
													"1.Modificar nombre del pasajero.\n"
													"2.Modificar apellido del pasajero\n"
													"3.Modificar tipo de pasajero\n"
													"4.Modificar precio del vuelo\n"
													"5.Modificar estado del vuelo\n"
													"6.Modificar codigo de vuelo\n"
													"7.Volver\n"
													"-------------------------------------\n"
													"Ingrese una opcion: ",
													"-------------------------------------\n"
													"1.Modificar nombre del pasajero.\n"
													"2.Modificar apellido del pasajero\n"
													"3.Modificar tipo de pasajero\n"
													"4.Modificar precio del vuelo\n"
													"5.Modificar estado del vuelo\n"
													"6.Modificar codigo de vuelo\n"
													"7.Volver\n"
													"--------------------------------------\n"
													"Error. Ingrese una opcion correcta: ", 1, 7);


				switch(opcion)
				{
					case 1:
						pedirCadenaCompuesta("Ingrese el nombre del pasajero: ", "Error. Ingrese correctamente el nombre (Max caracteres 51): ", auxPassenger.name, NAME, 10);

						if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
						{
							list[index]=auxPassenger;
							printf("\nSe realizo correctamente la modificacion del nombre del pasajero!!\n");
						}
						else
						{
							printf("\nSe cancelo la modificacion del nombre del pasajero!!!\n");
						}
						break;
					case 2:
						pedirCadenaValidada(auxPassenger.lastName, "Ingrese el apellido del pasajero: ", "Error. Ingrese correctamente el apellido (Max caracteres 51): ", LASTNAME);

						if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
						{
							list[index]=auxPassenger;
							printf("\nSe realizo correctamente la modificacion del apellido del pasajero!!\n");
						}
						else
						{
							printf("\nSe cancelo la modificacion del apellido del pasajero!!!\n");
						}
						break;
					case 3:
						pedirNumeroEnteroValidado(&auxPassenger.typePassenger, "Ingrese el tipo de pasajero (1-CLASE ECONOMICA 2-CLASE EJECUTIVA 3-PRIMERA CLASE): ", "Error. Ingrese correctamente el tipo de pasajero (1-CLASE TURISTA 2-CLASE ECONOMICA 3-PRIMERA CLASE): ", 1, 3);

						if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
						{
							list[index]=auxPassenger;
							printf("\nSe realizo correctamente la modificacion del tipo del pasajero!!\n");
						}
						else
						{
							printf("\nSe cancelo la modificacion del tipo del pasajero!!!\n");
						}
						break;
					case 4:
						pedirNumeroFlotante(&auxPassenger.price, "Ingrese el precio del vuelo: ", "Error. Ingrese correctamente el precio: ");

						if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
						{
							list[index]=auxPassenger;
							printf("\nSe realizo correctamente la modificacion del precio del vuelo!!\n");
						}
						else
						{
							printf("\nSe cancelo la modificacion del precio del vuelo!!!\n");
						}
						break;
					case 5:
						pedirNumeroEnteroValidado(&auxPassenger.statusFlight, "Ingrese estado del vuelo(1- ACTIVO 2- INACTIVO 3- DEMORADO): ", "Error. Ingrese correctamente el estado del Vuelo(1- ACTIVO 2- INACTIVO 3- DEMORADO): ", 1, 3);

						if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
						{
							list[index]=auxPassenger;
							printf("\nSe realizo correctamente la modificacion del estado del vuelo!!\n");
						}
						else
						{
							printf("\nSe cancelo la modificacion del estado del vuelo!!!\n");
						}
						break;
					case 6:
						pedirCadenaAlfaNumerica(auxPassenger.flyCode, "Ingrese el codigo de vuelo: ", "Error. Ingrese correctamente el codigo de vuelo (Max caracteres 10): ", FLYCODE);

						if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
						{
							list[index]=auxPassenger;
							printf("\nSe realizo correctamente la modificacion del codigo de vuelo!!\n");
						}
						else
						{
							printf("\nSe cancelo la modificacion del codigo de vuelo!!!\n");
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
		else
		{
			printf("\nEl ID ingresado no existe!!\n");
		}

	}


	return retorno;
}

int subMenuReport(Passenger* list, int len)
{
	int retorno=-1;
	int opcion;

	if(list != NULL && len>0)
	{

		do
		{
			pedirNumeroEnteroValidado(&opcion,
												"-------------------------------------------------------\n"
												"1.Listar pasajeros por apellido y tipo de pasajero\n"
												"2.Listar total, promedio de los precios de pasajes y cantidad de pasajeros que superan precio promedio\n"
												"3.Listar pasajeros por codigo de vuelo y estados de vuelo\n"
												"4.Volver\n"
												"--------------------------------------------------------\n"
												"Ingrese una opcion: ",
												"--------------------------------------------------------\n"
												"1.Listar pasajeros por apellido y tipo de pasajero\n"
												"2.Listar total, promedio de los precios de pasajes y cantidad de pasajeros que superan precio promedio\n"
												"3.Listar pasajeros por codigo de vuelo y estados de vuelo\n"
												"4.Volver\n"
												"---------------------------------------------------------\n"
												"Error. Ingrese una opcion correcta: ", 1, 4);

			switch(opcion)
			{
				case 1:
					sortPassengersByLastName(list, len, ASCENDENTE);
					printf("\nOrdenamiento realizado correctamente!!!\n");
					printPassengers(list, len);
					break;
				case 2:
					totalPriceAndAveragedPrice(list, len);
					break;
				case 3:
					sortPassengersByCode(list, len, ASCENDENTE, 1);
					printf("\nOrdenamiento realizado correctamente!!!\n");
					break;

				case 4:
					break;
			}

			if(opcion != 4)
			{
				system("pause");
			}

		}while(opcion != 4);
	}

	return retorno;
}

int totalPriceAndAveragedPrice(Passenger* list, int len)
{
	int retorno=-1;
	int i;
	int contadorPasajero;
	float precioPromedio;
	int contMayorPromedio;
	float acumuladorPrecio;

	contadorPasajero=0;
	contMayorPromedio=0;
	acumuladorPrecio=0;

	if(list != NULL && len>0)
	{

		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FULL)
			{
				acumuladorPrecio=list[i].price+acumuladorPrecio;
				contadorPasajero++;
			}
		}

		calcularDivision(acumuladorPrecio, contadorPasajero, &precioPromedio);

		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FULL)
			{
				if(list[i].price>precioPromedio)
				{
					contMayorPromedio++;
				}
			}
		}

		if(contadorPasajero != 0)
		{
			printf("\nEl total de ls precios de vuelos es: %.2f\n\nEl promedio de los precios de vuelo es: %.2f\n\nLa cantidad de pasajeros que superan el precio promedio de vuelo es: %d\n\n", acumuladorPrecio, precioPromedio, contMayorPromedio);
			retorno=0;
		}

	}

	return retorno;
}

int cargarPasajeroForzado(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno=-1;
	int index;
	Passenger auxPassenger;


	if(list != NULL && len>0 && name != NULL && lastName != NULL && typePassenger != 0 && flycode != NULL && statusFlight != 0)
	{
			searchEmptyIndex(list, len, &index);

			if(index != -1)
			{
				auxPassenger.id=id;
				strcpy(auxPassenger.name,name);
				strcpy(auxPassenger.lastName,lastName);
				auxPassenger.price=price;
				auxPassenger.typePassenger=typePassenger;
				strcpy(auxPassenger.flyCode,flycode);
				auxPassenger.statusFlight=statusFlight;
				auxPassenger.isEmpty=FULL;
				list[index]=auxPassenger;
				retorno=0;
			}
			else
			{
				retorno=-1;
			}

	}

	return retorno;
}

int cargaForzadaDatos(Passenger* list,int len, int* id)
{
	int retorno=-1;
	int ultimoId;


	if(list != NULL && len>0)
	{
		ultimoId=*id;

		if(cargarPasajeroForzado(list, len, ultimoId, "Olaf", "Riani", 20000, 1, "AA200", 1)==0)
		{
			list[ultimoId].id=ultimoId+1;
			*id=list[ultimoId].id;
		}

		ultimoId=*id;

		if(cargarPasajeroForzado(list, len, ultimoId, "Orion", "Riani", 32000, 2, "AA200", 1)==0)
		{
			list[ultimoId].id=ultimoId+1;
			*id=list[ultimoId].id;
		}

		ultimoId=*id;

		if(cargarPasajeroForzado(list, len, ultimoId, "Antonio", "Veron", 19000, 2, "AA220", 2)==0)
		{
			list[ultimoId].id=ultimoId+1;
			*id=list[ultimoId].id;
		}

		ultimoId=*id;

		if(cargarPasajeroForzado(list, len, ultimoId, "Nathaly", "Aguila", 10000, 1, "LA201", 1)==0)
		{
			list[ultimoId].id=ultimoId+1;
			*id=list[ultimoId].id;
		}

		ultimoId=*id;

		if(cargarPasajeroForzado(list, len, ultimoId, "Teresa", "Lopez", 45000, 2, "AA220", 2)==0)
		{
			list[ultimoId].id=ultimoId+1;
			*id=list[ultimoId].id;
		}

		retorno=0;

	}

	return retorno;
}
