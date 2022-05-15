/*
 * utn_Libreria.c
 *
 *  Created on: 14 may. 2022
 *      Author: brian
 */

#include "utn_Libreria.h"

int pedirCadena(char* cadena,char* mensaje,char* mensajeError,int maxTam)
{
	int retorno=-1;
	char cadenaAux[200];

	if(cadena!=NULL && maxTam>0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",cadenaAux);

		while(strlen(cadenaAux)>maxTam || esNumero(cadenaAux)==-1 || validarSignos(cadenaAux)==0)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%s",cadenaAux);
		}

		cadenaEnMinuscula(cadenaAux);
		primerLetraMayuscula(cadenaAux);
		strcpy(cadena,cadenaAux);
		retorno=0;
	}

	return retorno;
}

int pedirNumero(int* numero,char* mensaje,char* mensajeError,int min, int max)
{
	int retorno=-1;
	char numeroAux[51];
	int numeroEnteroAux;


	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{

		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",numeroAux);
		numeroEnteroAux=atoi(numeroAux);


		while((!esNumero(numeroAux) && !validarEspacio(mensaje)) || (numeroEnteroAux>max||numeroEnteroAux<min))
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%s",numeroAux);
			numeroEnteroAux=atoi(numeroAux);
		}

		*numero=atoi(numeroAux);
		retorno=0;

	}

	return retorno;
}

int pedirNumeroFlotante(float* numero, char* mensaje,char* mensajeError,int min,int max)
{
	int retorno=-1;
	char numeroAux[51];
	float numeroFlotAux;

	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",numeroAux);
		numeroFlotAux=atof(numeroAux);

		while((!esNumero(numeroAux) && !validarEspacio(mensaje)) || (numeroFlotAux<min ||numeroFlotAux>max))
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",numeroAux);
			numeroFlotAux=atof(numeroAux);
		}

		*numero=atof(numeroAux);
		retorno=0;
	}
	return retorno;
}

int esNumero(char* cadena)
{
	int retorno=-1;
	int i;
	int tamanioCadena;

	if(cadena!=NULL)
	{
		tamanioCadena=strlen(cadena);

		for(i=0;i<tamanioCadena;i++)
		{
			if(isdigit(cadena[i])==0 && cadena[i]!='.' && cadena[0]!='+' && cadena[0]!='-')
			{
				retorno=0;
				break;
			}

		}

	}
	return retorno;
}

int validarSignos(char* cadena)
{
	int i;
	int tamanioCadena;
	int retorno=-1;

	if(cadena!=NULL)
	{
		tamanioCadena=strlen(cadena);
		cadenaEnMinuscula(cadena);

		for(i=0;i<tamanioCadena;i++)
		{

			if(cadena[i] < 97 || cadena[i] > 122)
			{

				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int validarEspacio(char* cadena)
{
	int retorno=-1;
	int i;
	int tamanioCadena;

	tamanioCadena=strlen(cadena);

	for(i=0;i<tamanioCadena;i++)
	{
		if(cadena[i] == ' ' || cadena[i] == '\t' || cadena[i] == '\v')
		{
			retorno=0;
			break;
		}

	}
	return retorno;
}

int primerLetraMayuscula(char* cadena)
{
	int retorno=-1;
	int tamanioCadena;
	int i;

	if(cadena!=NULL)
	{
		tamanioCadena=strlen(cadena);

		for(i=0;i<tamanioCadena;i++)
		{
			if(i==0)
			{
				cadena[i]=toupper(cadena[i]);
			}
			if(cadena[i]==' ')
			{
				cadena[i+1]=toupper(cadena[i+1]);
			}
		}

		retorno=0;
	}

	return retorno;
}

int cadenaEnMinuscula(char* cadena)
{
	int retorno=-1;
	int i;
	int tamanioCadena;

	if(cadena!=NULL)
	{

		tamanioCadena=strlen(cadena);

		for(i=0;i<tamanioCadena;i++)
		{
			cadena[i]=tolower(cadena[i]);
		}

		retorno=0;
	}
	return retorno;
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
