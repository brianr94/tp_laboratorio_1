/*
 * BRIAN RIANI, DIVISION 1°D
 */
#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "calculos.h"

int pedirNumeroEnteroMayorACero(char* mensaje, char* mensajeError)
{
	int numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	while(numeroIngresado<1)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}

int pedirNumeroEnteroValidado(char* mensaje, char* mensajeError, int min, int max)
{
	int numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}


int pedirFlotante(float* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno;
	float numeroIngresado;

	while(reintentos>0)
	{
		printf("%s", mensaje);
		if(scanf("%f",&numeroIngresado)==1)
		{
				break;
		}
		fflush(stdin);
		reintentos--;
		printf("%s", mensajeError);
	}
	if(reintentos==0)
	{
		retorno=-1;
	}
	else
	{
		retorno=0;
		*pResultado = numeroIngresado;
	}

	return retorno;
}

int cargaDatosForzada(int* kms, float* precioAero, float* precioLatam)
{
	int auxKms;
	float auxPrecioAero;
	float auxPrecioLatam;
	int retorno=-1;

	char aerolinea[]="Aerolineas";
	char latam[]="Latam";

	float debitoAerolinea;
	float creditoAerolinea;
	float bitcoinAerolinea;
	float precioUnitarioKmAerolinea;

	float debitoLatam;
	float creditoLatam;
	float bitcoinLatam;
	float precioUnitarioKmLatam;

	float totalDiferencia;

	auxKms= 7090;
	auxPrecioAero= 162965;
	auxPrecioLatam= 159339;

	*kms= auxKms;
	*precioAero=auxPrecioAero;
	*precioLatam= auxPrecioLatam;


	//Precio AeroLineas
	debitoAerolinea= calculo_TarjetaDebito(auxPrecioAero);
	creditoAerolinea= calculo_TarjetaCredito(auxPrecioAero);
	bitcoinAerolinea= calculo_Bitcoins(auxPrecioAero);
	precioUnitarioKmAerolinea= calculo_PrecioKm(auxPrecioAero, auxKms);

	//Precio Latam
	debitoLatam= calculo_TarjetaDebito(auxPrecioLatam);
	creditoLatam= calculo_TarjetaCredito(auxPrecioLatam);
	bitcoinLatam= calculo_Bitcoins(auxPrecioLatam);
	precioUnitarioKmLatam= calculo_PrecioKm(auxPrecioLatam, auxKms);

	//Diferecia de precios
	totalDiferencia= calculo_DiferenciaPrecios(auxPrecioAero, auxPrecioLatam);


	printf("\nKMs Ingresado: %d\n\n", auxKms);

	mostrarResultados(aerolinea, auxPrecioAero, debitoAerolinea, creditoAerolinea, bitcoinAerolinea, precioUnitarioKmAerolinea);
	mostrarResultados(latam, auxPrecioLatam, debitoLatam, creditoLatam, bitcoinLatam, precioUnitarioKmLatam);

	printf("La diferencia de precio es: $ %.2f\n", totalDiferencia);
	retorno=0;

	return retorno;
}


void subMenu_Aerolineas(float* aerolinea1, float* aerolinea2, int* flagAero1, int* flagAero2)
{
	int opcion;
	float pAerolinea;
	float pLatam;
	int flagAerolinea;
	int flagLatam;

	flagAerolinea=1;
	flagLatam= 1;

	do
	{
		opcion= pedirNumeroEnteroValidado("----------------------------\n"
								  "1. Precio vuelo Aerolineas: \n"
								  "2. Precio vuelo Latam: \n"
								  "3. Volver.\n"
								  "----------------------------\n"
								  "Ingrese una opcion: ",
								  "----------------------------\n"
								  "1. Precio vuelo Aerolineas: \n"
								  "2. Precio vuelo Latam: \n"
								  "3. Volver.\n"
								  "----------------------------\n"
								  "Opcion incorrecta. Re-ingrese opcion correcta: ", 1, 3);

		switch(opcion)
		{
			case 1:
				pedirFlotante(&pAerolinea, "Ingrese precio vuelo Aerolineas: ", "Error. Ingrese precio vuelo Aerolineas: ", 20);
				flagAerolinea=0;
				break;
			case 2:
				pedirFlotante(&pLatam, "Ingrese precio vuelo Latam: ", "Error. Ingrese precio vuelo Latam:", 20);
				flagLatam=0;
				break;
			case 3:
				break;
		}

		if(opcion != 3)
		{
			system("pause");
		}

	}while(opcion != 3);

	if(flagAerolinea==0){
		*aerolinea1= pAerolinea;
		*flagAero1= flagAerolinea;
	}

	if(flagLatam== 0)
	{
		*aerolinea2= pLatam;
		*flagAero2=flagLatam;
	}
}

void mostrarResultados(char* nombreAerolinea, float precioVuelo, float totalDebito, float totalCredito, float totalBitcoin, float precioUnitario)
{

	printf("Precio %s : $ %.2f\n", nombreAerolinea, precioVuelo);
	printf( "a) Precio con tarjeta de debito: $ %.2f\n"
			"b) Precio con tarjeta de credito: $ %.2f\n"
			"c) Precio pagando con bitcoin: %f BTC\n"
			"d) Mostrar precio unitario: $ %.2f", totalDebito, totalCredito, totalBitcoin, precioUnitario);

	printf("\n\n");
}

void MostrarMenu(int flagKm, int flagPrecioAerolineas, int flagPrecioLatam, int kms, float precioVuelo1, float precioVuelo2)
{

	if(flagKm==1 && flagPrecioAerolineas==1 && flagPrecioLatam==1){
	printf("------------------------------------\n"
			"1. Ingresar Kilómetros: ( km=x).\n"
			"2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n"
			"3. Calcular todos los costos:\n"
			"4. Informar resultados.\n"
			"5. Carga forzada de datos.\n"
			"6. Salir.\n"
			"-------------------------------------\n");
	}
	else
	{
		if(flagKm==0 && flagPrecioAerolineas==0 && flagPrecioLatam==0)
		{
			printf("------------------------------------\n"
			"1. Ingresar Kilómetros: ( km=%d).\n"
			"2. Ingresar Precio de Vuelos: (Aerolíneas=%.2f, Latam=%.2f)\n"
			"3. Calcular todos los costos:\n"
			"4. Informar resultados.\n"
			"5. Carga forzada de datos.\n"
			"6. Salir.\n"
			"-------------------------------------\n", kms, precioVuelo1, precioVuelo2);
		}
		else
		{
			if(flagKm==0)
			{
				printf("------------------------------------\n"
						"1. Ingresar Kilómetros: ( km=%d).\n"
						"2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n"
						"3. Calcular todos los costos:\n"
						"4. Informar resultados.\n"
						"5. Carga forzada de datos.\n"
						"6. Salir.\n"
						"-------------------------------------\n", kms);
			}
			else
			{
				if(flagPrecioAerolineas==0)
				{
					printf("------------------------------------\n"
					"1. Ingresar Kilómetros: ( km=x).\n"
					"2. Ingresar Precio de Vuelos: (Aerolíneas=%.2f, Latam=z)\n"
					"3. Calcular todos los costos:\n"
					"4. Informar resultados.\n"
					"5. Carga forzada de datos.\n"
					"6. Salir.\n"
					"-------------------------------------\n", precioVuelo1);
				}
				else
				{
					if(flagPrecioLatam==0)
					{
						printf("------------------------------------\n"
								"1. Ingresar Kilómetros: ( km=x).\n"
								"2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=%.2f)\n"
								"3. Calcular todos los costos:\n"
								"4. Informar resultados.\n"
								"5. Carga forzada de datos.\n"
								"6. Salir.\n"
								"-------------------------------------\n", precioVuelo2);
					}
				}
			}
		}
	}

}

void limpiarConsola(void)
{
	printf("\n\n\n\n\n\n");
}
