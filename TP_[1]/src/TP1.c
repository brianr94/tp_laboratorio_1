/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "calculos.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int kmIngresado;
	char aerolinea[]="Aerolineas";
	char latam[]="Latam";
	int flagKmIngresado;
	int flagAeroIngresado;
	int flagLatamIngresado;
	int flagDatosCargados;
	int flagCalculos;
	float precioVueloAerolinea;
	float precioVueloLatam;
	float totalDebitoAerolinea;
	float totalCreditoAerolinea;
	float totalBitcoinAerolinea;
	float precioUnitarioKmAerolinea;
	float totalDebitoLatam;
	float totalCreditoLatam;
	float totalBitcoinLatam;
	float precioUnitarioKmLatam;
	float totalDiferencia;

	flagKmIngresado=1;
	flagAeroIngresado=1;
	flagLatamIngresado=1;
	flagKmIngresado=1;
	flagDatosCargados=1;
	flagCalculos=1;




	do
	{
		MostrarMenu(flagKmIngresado, flagAeroIngresado, flagLatamIngresado, flagDatosCargados, kmIngresado, precioVueloAerolinea, precioVueloLatam);

		opcion=pedirNumeroEnteroValidado("Ingrese la opcion: ", "Error. Ingrese opcion correcta: ", 1, 6);


		switch(opcion) {

				case 1:
					kmIngresado= pedirNumeroEnteroMayorACero("Ingrese los Kms: ", "Error. Ingrese los Kms mayor a 0: ");
					flagKmIngresado=0;
					break;
				case 2:
					subMenu_Aerolineas(&precioVueloAerolinea, &precioVueloLatam, &flagAeroIngresado, &flagLatamIngresado);
					break;
				case 3:
					if((flagKmIngresado==0 && flagAeroIngresado==0 && flagLatamIngresado==0) || flagDatosCargados==0)
					{
						totalDebitoAerolinea= calculo_TarjetaDebito(precioVueloAerolinea);
						totalDebitoLatam= calculo_TarjetaDebito(precioVueloLatam);
						totalCreditoAerolinea= calculo_TarjetaCredito(precioVueloAerolinea);
						totalCreditoLatam= calculo_TarjetaCredito(precioVueloLatam);
						totalBitcoinAerolinea= calculo_Bitcoins(precioVueloAerolinea);
						totalBitcoinLatam= calculo_Bitcoins(precioVueloLatam);
						precioUnitarioKmAerolinea= calculo_PrecioKm(precioVueloAerolinea, kmIngresado);
						precioUnitarioKmLatam= calculo_PrecioKm(precioVueloLatam, kmIngresado);
						totalDiferencia= calculo_DiferenciaPrecios(precioVueloAerolinea, precioVueloLatam);
						flagCalculos=0;
					}
					else
					{
						printf("Ingrese los datos correspondiestes para realizar los calculos.\n");
					}
					break;

				case 4:
					if(flagCalculos==0)
					{
					printf("\nKMs Ingresado: %d\n\n", kmIngresado);

					mostrarResultados(aerolinea, precioVueloAerolinea, totalDebitoAerolinea, totalCreditoAerolinea, totalBitcoinAerolinea, precioUnitarioKmAerolinea);
					mostrarResultados(latam, precioVueloLatam, totalDebitoLatam, totalCreditoLatam, totalBitcoinLatam, precioUnitarioKmLatam);

					printf("La diferencia de precio es: $ %.2f\n", totalDiferencia);
					}
					else
					{
						printf("Realice el calculos de costos en la opcion 3 primero!!.\n");
					}
					break;
				case 5:
					cargaDatosForzada(&kmIngresado, &precioVueloAerolinea, &precioVueloLatam);
					flagDatosCargados=0;
					break;
				case 6:
					printf("Eligio Salir del Programa!!!.\n");
					break;
			}

		if(opcion != 6)
		{
			system("pause");
			limpiarConsola();
		}

	}while(opcion != 6);




	return EXIT_SUCCESS;
}
