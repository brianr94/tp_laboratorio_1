/*
 * BRIAN RIANI, DIVISION 1°D
 */
#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"


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

int verificarSigno(float numeroAVerificar)
{

    int retorno= 0;

    if(numeroAVerificar>0)
    {
        retorno = 1;
    }
    else
    {
        if(numeroAVerificar<0)
        {
            retorno = -1;
        }
    }

    return retorno;

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

void mostrarPrimerNumero(float numeroA)
{
	printf("\nA = %.2f\n", numeroA);
}

void mostrarSegundoNumero(float numeroB)
{
	printf("B = %.2f\n", numeroB);
}
void limpiarConsola(void)
{
	printf("\n\n\n\n\n\n\n");
}

void numeroVacioUno(char num1)
{
	printf("\nA = %c\n", num1);
}

void numeroVacioDos(char num2)
{
	printf("B = %c\n", num2);
}
