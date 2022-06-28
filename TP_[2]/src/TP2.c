/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_inputs.h"
#include "utn_validaciones.h"
#include "ArrayPassenger.h"

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int pasajeroIngresado;
	int ultimoId;
	int flagCargaForzada;


	pasajeroIngresado=0;
	flagCargaForzada=0;
	ultimoId=0;

	Passenger pasajeros[LENGTHPASSENGERS];

	initPassengers(pasajeros, LENGTHPASSENGERS);

	do
	{

		pedirNumeroEnteroValidado(&opcion,
											"------------------------------------\n"
											"1. ALTA DE PASAJERO\n"
											"2. MODIFICAR PASAJERO\n"
											"3. BAJA DE PASAJERO\n"
											"4. INFORMAR PASAJERO\n"
											"5. CARGA DE DATOS FORZADA\n"
											"6. SALIR\n"
											"---------------------------------\n"
											"Ingrese una opcion: ",
											"---------------------------------\n"
											"1. ALTA DE PASAJERO\n"
											"2. MODIFICAR PASAJERO\n"
											"3. BAJA DE PASAJERO\n"
											"4. INFORMAR PASAJERO\n"
											"5. CARGA DE DATOS FORZADA\n"
											"6. SALIR\n"
											"----------------------------------\n"
											"Error.Ingrese una opcion correcta: ", 1, 6);


		switch(opcion)
		{
			case 1:
				if(requestPassenger(pasajeros, LENGTHPASSENGERS, &ultimoId)==0)
				{
					pasajeroIngresado++;
				}
				break;

			case 2:
				if(pasajeroIngresado>0 || flagCargaForzada==1)
				{
					modifyPasseger(pasajeros, LENGTHPASSENGERS);
				}
				else
				{
					printf("\nError. Primero debe dar de alta a los pasajeros y/o realice la carga forzada!!!\n");
				}
				break;

			case 3:
				if(pasajeroIngresado>0 || flagCargaForzada==1)
				{
					if(removePassenger(pasajeros, LENGTHPASSENGERS, ultimoId)==0)
					{
						pasajeroIngresado--;
					}
				}
				else
				{
					printf("\nError. Primero debe dar de alta a los pasajeros y/o realice la carga forzada!!!\n");
				}
				break;
			case 4:
				if(pasajeroIngresado>0 || flagCargaForzada==1)
				{
					subMenuReport(pasajeros, LENGTHPASSENGERS);
				}
				else
				{
					printf("\nError. Primero debe dar de alta a los pasajeros y/o realice la carga forzada!!!\n");
				}
				break;
			case 5:
				cargaForzadaDatos(pasajeros, LENGTHPASSENGERS, &ultimoId);
				printf("\nCarga Forzada realizada con exito!!!\n");
				flagCargaForzada=1;
				break;

			case 6:
				printf("\nEligio salir del programa!!!!\n");
				break;
		}

		if(opcion != 6)
		{
			system("pause");
		}

	}while(opcion != 6);




	return EXIT_SUCCESS;
}
