/*
 ============================================================================
TRABAJO PRACTICO N° 1.

BRIAN RIANI. DIVISION 1-D
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
#include "inputs.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	float numeroA;
	float numeroB;
	char numVacio1;
	char numVacio2;
	float totalSuma;
	float totalResta;
	float totalDivision;
	int division;
	float totalMultiplicacion;
	float factorialA;
	float factorialB;
	int flagNumeroIngresadoA;
	int flagNumeroIngresadoB;
	int flagCalculoOperaciones;

	 flagNumeroIngresadoA= 0;
	 flagNumeroIngresadoB= 0;
	 flagCalculoOperaciones= 0;
	 numVacio1= 'x';
	 numVacio2= 'y';

	printf("Bienvenido a calculadora UTN!!!\n");
	do
	{
		opcion = pedirNumeroEnteroValidado("------------------------------------\n"
											"1. Ingrese 1er operando.\n"
											"2. Ingrese 2do operando.\n"
											"3. Calcular las operaciones.\n"
											"4. Informe de resultados.\n"
											"5. Salir.\n"
											"-------------------------------------\n"
											"Ingrese una opcion: ",
											"--------------------------------------\n"
											"1. Ingrese 1er operando.\n"
											"2. Ingrese 2do operando.\n"
											"3. Calcular las operaciones.\n"
											"4. Informe de resultados.\n"
											"5. Salir.\n"
											"-------------------------------------\n"
											"Opcion incorrecta, reingrese opcion valida: ", 1, 5);

		if(flagNumeroIngresadoA==0 && flagNumeroIngresadoB==0)
		{
			numeroVacioUno(numVacio1);
			numeroVacioDos(numVacio2);
		}
		else
		{
			if(flagNumeroIngresadoA==1 && flagNumeroIngresadoB==0)
			{
			mostrarPrimerNumero(numeroA);
			numeroVacioDos(numVacio2);
			}
			else
			{
				if(flagNumeroIngresadoA==0 && flagNumeroIngresadoB==1)
				{
					numeroVacioUno(numVacio1);
					mostrarSegundoNumero(numeroB);
				}
				else
				{
					mostrarPrimerNumero(numeroA);
					mostrarSegundoNumero(numeroB);

				}
			}
		}


		switch(opcion)
		{
			case 1:
				pedirFlotante(&numeroA, "\nIngrese el 1er operando: ", "\nNumero invalido, re-ingrese numero", 99);
				flagNumeroIngresadoA=1;
				mostrarPrimerNumero(numeroA);
				break;
			case 2:
				pedirFlotante(&numeroB, "\nIngrese el 2do operando: ", "\nNumero invalido, re-ingrese numero", 99);
				flagNumeroIngresadoB=1;
				mostrarSegundoNumero(numeroB);
				break;
			case 3:
				if(flagNumeroIngresadoA == 1 && flagNumeroIngresadoB == 1)
				{
					totalSuma= calcularSuma(numeroA, numeroB);
					totalResta= calcularResta(numeroA, numeroB);
					division= calcularDivision(numeroA, numeroB, &totalDivision);
					totalMultiplicacion= calcularMultiplicacion(numeroA, numeroB);

					if(verificarSigno(numeroA)==1 && verificarSigno(numeroB)==1)
					{
						factorialA= calcularFactorial(numeroA);
						factorialB= calcularFactorial(numeroB);
					}
					else
					{
						if(verificarSigno(numeroA)==-1 && verificarSigno(numeroB)==1)
						{
							factorialA=-1;
							factorialB= calcularFactorial(numeroB);
						}
						else
						{
							if(verificarSigno(numeroA)==1 && verificarSigno(numeroB)==-1)
							{
								factorialA= calcularFactorial(numeroA);
								factorialB= -1;
							}
							else
							{
								factorialA=-1;
								factorialB= -1;

							}
						}

					}


					flagCalculoOperaciones= 1;
				}
				else
				{
					printf("\nIngrese los 2 operandos correctamente para realizar las operaciones.\n");
				}
				break;
			case 4:
				if(flagCalculoOperaciones==1){
					printf("El resultado de %.2f + %.2f es: %.2f\n",  numeroA, numeroB, totalSuma);
					printf("El resultado de %.2f - %.2f es: %.2f\n",  numeroA, numeroB, totalResta);

					if(division==0)
					{
						printf("No es posible dividir por cero\n");
					}
					else
					{
						printf("El resultado de %.2f/ %.2f es: %.2f\n",  numeroA, numeroB, totalDivision);
					}

					printf("El resultado de %.2f * %.2f es: %.2f\n",  numeroA, numeroB, totalMultiplicacion);

					if(factorialA>0 && factorialB>0)
					{
						printf("El factorial de %.0f es: %.0f y El factorial de %.0f es: %.0f\n", numeroA, factorialA, numeroB, factorialB);
					}
					else
					{
						if(factorialA>0 && factorialB==-1)
						{
							printf("El factorial de %.0f es %.0f y no se pudo calcular el factorial de B por ser negativo\n", numeroA, factorialB);
						}
						else
						{
							if(factorialA==-1 && factorialB>0)
							{
								printf("No se pudo calcular el factorial de A por ser negativo y el factorial de %.0f es %.0f\n", numeroB, factorialB);
							}
							else
							{
								printf("No pudo calcular el factorial de A y B por ser negativos\n");
							}
						}
					}

				}
				else
				{
					printf("\nPrimero ingrese los operandos, y luego realice las operaciones con la opcion 3\n");
				}
				break;
			case 5:
				printf("\nEligio salir, fin del programa\n");
				break;
		}

			if (opcion != 5)
			{
				system("pause");
				limpiarConsola();
			}

		}while(opcion != 5);


	return EXIT_SUCCESS;
}
