/*
BRIAN RIANI, DIVISION 1°D
*/

#include "Operaciones.h"

int calcularSuma(float numeroA, float numeroB)
{
	float resultadoSuma;

	resultadoSuma= numeroA + numeroB;

	return resultadoSuma;
}

int calcularResta(float numeroA, float numeroB)
{
	float resultadoResta;

	resultadoResta= numeroA - numeroB;

	return resultadoResta;
}

int calcularDivision(float numeroA, float numeroB, float* refDivision)
{
	int resultado;
	float totalDivision;

	if(numeroB==0)
	{
		resultado= 0;
	}
	else
	{
		totalDivision= numeroA / numeroB;
		resultado= 1;
	}
	*refDivision = totalDivision;

	return resultado;
}

int calcularMultiplicacion(float numeroA, float numeroB)
{
	float resultadoMultiplicacion;

	resultadoMultiplicacion= numeroA * numeroB;

	return resultadoMultiplicacion;
}

int calcularFactorial(float numero)
{
	int factorial= 1;

	if(numero!= 1 && numero != 0 )
	{
		factorial= (int)numero * calcularFactorial(numero - 1);
	}

	return factorial;
}




