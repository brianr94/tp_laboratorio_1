/*
TP 1 Blibioteca Inputs

BRIAN RIANI, DIVISION 1°D.
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>

/// @fn int pedirFlotante(float*, char*, char*, int)
/// @brief Se solicita al usuario el ingreso de un numero flotante, se hace la validacion y se le da intentos al usuarios para ingresar. en caso de ser numero
/// retorna 0, en caso contrario retorna -1.
///
/// @param pResultado puntero para retornar si el numero fue validado correctamente.
/// @param mensaje recibe un mensaje de ingreso de datos para el usuario.
/// @param mensajeError mensaje de error en caso de que el usuario haya ingresado incorrectamente el dato solicitado.
/// @param reintentos intentos que se le da al usuario para ingresar el dato solicitado.
/// @return retorna 0 si el dato fue ingresado correctamente y en caso contrario retorna -1.
int pedirFlotante(float* pResultado, char* mensaje, char* mensajeError, int reintentos);

/// @fn int pedirNumeroEnteroValidado(char*, char*, int, int)
/// @brief se solicita al usuario el ingreso de un entero, se valida entre un maximo y un minimo solicitado y en caso de correcto retorna el numero
/// ingresado y en caso contrario se da aviso de ingresar correctamente el numero.
///
/// @param mensaje recibe un mensaje de ingreso de datos para el usuario.
/// @param mensajeError Mensaje de error en caso de que el usuario haya ingresado incorrectamente el dato solicitado.
/// @param min limite establecido para que el numero ingresado no exceda el minimo establecido.
/// @param max limite establecido para que el numero ingresado no exceda el maximo establecido.
/// @return retorna el numero ingresado que fue correctamente validado.
int pedirNumeroEnteroValidado(char* mensaje, char* mensajeError, int min, int max);

/// @fn void limpiarConsola(void)
/// @brief al no contar con la funcion system("cls"), esta reeemplaza y cada vez que el usuario elige una opcion
/// se ejecutan un conjunto de contrabarra n para hacer mas legible el menu.
void limpiarConsola(void);

/// @fn int verificarSigno(float)
/// @brief recibe un numero y verifica su signo, en caso de ser positivo retorna 1 y en caso de ser negativo retorna -1.
///
/// @param numeroAVerificar numero ingresado por el usuario para evaluar su signo
/// @return retorna 1 en caso de ser positivo y en caso de negativo retorna -1.
int verificarSigno(float numeroAVerificar);

/// @fn void mostrarPrimerNumero(float)
/// @brief recibe por parametro el numero y lo muestra al usuario cuando lo ingresa.
///
/// @param numeroA numero que recibe para mostrar en la interfaz.
void mostrarPrimerNumero(float numeroA);

/// @fn void mostrarSegundoNumero(float)
/// @brief recibe por parametro el numero y lo muestra al usuario cuando lo ingresa.
///
/// @param numeroB numero que recibe para mostrar en la interfaz.
void mostrarSegundoNumero(float numeroB);

/// @fn void numeroVacioUno(char)
/// @brief recibe un caracter por parametro para mostrar en el menu, al usuario que el primer operando no fue ingresado aun.
///
/// @param num1 caracter ya inicializado, para poder avisar al usuario que no fue ingresado el operando.
void numeroVacioUno(char num1);

/// @fn void numeroVacioDos(char)
/// @brief recibe un caracter por parametro para mostrar en el menu, al usuario que el segundo operando no fue ingresado aun.
///
/// @param num2 caracter ya inicializado, para poder avisar al usuario que no fue ingresado el operando.
void numeroVacioDos(char num2);
#include <stdio.h>
#include <stdlib.h>

#endif /* INPUTS_H_ */
