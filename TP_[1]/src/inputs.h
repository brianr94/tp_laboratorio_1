/*
TP 1 Blibioteca Inputs

BRIAN RIANI, DIVISION 1°D.
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>

/// @fn int pedirNumeroEnteroMayorACero(char*, char*)
/// @brief
///
/// @param mensaje
/// @param mensajeError
/// @return
int pedirNumeroEnteroMayorACero(char* mensaje, char* mensajeError);

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

/// @fn void cargaDatosForzada(int*, float*, float*)
/// @brief
///
/// @param kms
/// @param precioAero
/// @param precioLatam
void cargaDatosForzada(int* kms, float* precioAero, float* precioLatam);

/// @fn void subMenu_Aerolineas(float*, float*, int*, int*)
/// @brief
///
/// @param aerolinea1
/// @param aerolinea2
/// @param flagAero1
/// @param flagAero2
void subMenu_Aerolineas(float* aerolinea1, float* aerolinea2, int* flagAero1, int* flagAero2);

/// @fn void mostrarResultados(char*, float, float, float, float, float)
/// @brief
///
/// @param nombreAerolinea
/// @param precioVuelo
/// @param totalDebito
/// @param totalCredito
/// @param totalBitcoin
/// @param precioUnitario
void mostrarResultados(char* nombreAerolinea, float precioVuelo, float totalDebito, float totalCredito, float totalBitcoin, float precioUnitario);

/// @fn void MostrarMenu(int, int, int, int, int, float, float)
/// @brief
///
/// @param flagKm
/// @param flagPrecioAerolineas
/// @param flagPrecioLatam
/// @param flagDatosCargados
/// @param kms
/// @param precioVuelo1
/// @param precioVuelo2
void MostrarMenu(int flagKm, int flagPrecioAerolineas, int flagPrecioLatam, int flagDatosCargados, int kms, float precioVuelo1, float precioVuelo2);

/// @fn void limpiarConsola(void)
/// @brief al no contar con la funcion system("cls"), esta reeemplaza y cada vez que el usuario elige una opcion
/// se ejecutan un conjunto de contrabarra n para hacer mas legible el menu.
void limpiarConsola(void);



#endif /* INPUTS_H_ */
