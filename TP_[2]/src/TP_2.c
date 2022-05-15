/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_Libreria.h"
#include "ArrayPassenger.h"

int main(void) {
	setbuf(stdout,NULL);

	int opcion;

	Passenger pasajeros[LENGTHPASSENGERS];

	initPassengers(pasajeros, LENGTHPASSENGERS);

	do
	{

		opcion=pedirNumeroEnteroValidado("1. ALTA DE PASAJERO\n"
											 "2. MODIFICAR PASAJERO\n"
											 "3. BAJA DE PASAJERO\n"
											 "4. INFORMAR PASAJERO\n"
											 "5. CARGA DE DATOS FORZADA\n"
											 "ingrese opcion: ",
											 "1. ALTA DE PASAJERO\n"
											 "2. MODIFICAR PASAJERO\n"
											 "3. BAJA DE PASAJERO\n"
											 "4. INFORMAR PASAJERO\n"
											 "5. CARGA DE DATOS FORZADA\n"
											 "Re-ingrese opcion correcta: ", 1, 6);


		switch(opcion)
		{
		case 1:
			break;

		case 2:

			break;

		case 3:

			break;

		case 4:

		break;

		case 5:

		break;

		case 6:


			break;

		}


	}while(opcion != 6);




	return EXIT_SUCCESS;
}
