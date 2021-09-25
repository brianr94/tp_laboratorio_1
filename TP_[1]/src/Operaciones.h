/*
 TP 1 Bilbioteca Operaciones

 BRIAN RIANI, DIVISION 1°D
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#include <stdio.h>
#include <stdlib.h>

/// @fn int calcularSuma(float, float)
/// @brief Recibe por parametro el operando A y operando B y calcula la suma. Retorna el resultado
///
/// @param numeroA Operando A para realizar la suma.
/// @param numeroB Operando B para realizar la suma.
/// @return retorna el resultado de la suma entre los operandos A y B.
int calcularSuma(float numeroA, float numeroB);


/// @fn int calcularResta(float, float)
/// @brief Recibe por parametro el operando A y operando B y calcula la resta. Retorna el resultado
///
/// @param numeroA Operando A para realizar la resta
/// @param numeroB Operando B para realizar la resta.
/// @return retorna el resultado de la resta entre los operandos A y B.
int calcularResta(float numeroA, float numeroB);


/// @fn int calcularDivision(float, float, float*)
/// @brief Recibe los operandos A y B, calcula la division y retorna 1 en caso de que la division fue resuelta,
/// y en caso contrario retorna 0 sino fue resuelto,
///
/// @param numeroA Operando A para realizar la division.
/// @param numeroB Operando B para realizar la division.
/// @param refDivision referencia para pasar el resultado en caso de que el retorno sea 1.
/// @return retorna 1 si la divison fue resuelta y pasa por referencia el resultado y caso contrario retorna 0 sino fue resuelta, por ser 0 el divisor.
int calcularDivision(float numeroA, float numeroB, float* refDivision);


/// @fn int calcularMultiplicacion(float, float)
/// @brief Recibe los operandos A y B, calcula la multiplicacion y retorna el resultado de la multiplicacion.
///
/// @param numeroA Operando A para realizar la multiplicacion.
/// @param numeroB Operando B para realizar la multiplicacion.
/// @return retorna el resultado de la multiplicacion entre los operandos A y B.
int calcularMultiplicacion(float numeroA, float numeroB);

/// @fn int calcularFactorial(float)
/// @brief recibe el operando y realiza el factorial del primer operando menos uno, y la funcion se llama a si misma hasta llegar al resultado del factorial del operando ingresado, donde finaliza y retorna el total
///
/// @param numeroA Operando que recibe para realizar el factorial.
/// @return retorna el resutado del factorial.
int calcularFactorial(float numeroA);

#endif /* OPERACIONES_H_ */
