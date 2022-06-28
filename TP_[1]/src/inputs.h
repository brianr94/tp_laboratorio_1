/*
TP 1 Blibioteca Inputs

BRIAN RIANI, DIVISION 1°D.
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>

/// @fn int pedirNumeroEnteroMayorACero(char*, char*)
/// @brief Se solicita al usuario el ingreso de numero entero mayor a cero, valida que el numero ingresado sea correecto y retorna el numero ingresado.
/// caso contrario imprime mensaje de error en pantalla hasta que el numero sea correcto
///
/// @param mensaje recibe un mensaje de ingreso de datos para el usuario.
/// @param mensajeError mensaje de error en caso de que el usuario haya ingresado incorrectamente el dato solicitado.
/// @return retorna el numero si es correcta la validacion, caso contrario vuelve a pedir el dato.
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

/// @fn int cargaDatosForzada(int*, float*, float*)
/// @brief carga los datos con valores pre-establecidos ,calcula las operaciones e imprime en pantalla los resultados .
///
/// @param kms parametro donde se va a cargar el dato pre-establecido.
/// @param precioAero parametro donde se va a cargar el dato pre-establecido.
/// @param precioLatam parametro donde se va a cargar el dato pre-establecido.
/// @return retorna 0 si se calculo bien, sin retorna -1 si salio mal.
int cargaDatosForzada(int* kms, float* precioAero, float* precioLatam);

/// @fn void subMenu_Aerolineas(float*, float*, int*, int*)
/// @brief submenu para ingresar y cargar los precios de las aerolineas.
///
/// @param aerolinea1 paramatro para guardar el precio de la primer aerolineas
/// @param aerolinea2 paramatro para guardar el precio de la segunda aerolineas
/// @param flagAero1 bandera para confirmar el ingreso del dato de la primer aerolinea
/// @param flagAero2 bandera para confirmar el ingreso del dato de la segunda aerolinea
void subMenu_Aerolineas(float* aerolinea1, float* aerolinea2, int* flagAero1, int* flagAero2);

/// @fn void mostrarResultados(char*, float, float, float, float, float)
/// @brief muestra en pantalla el resultado de los calculos.
///
/// @param nombreAerolinea recibe el nombre de la aerolinea para imprimir en pantalla.
/// @param precioVuelo recibe el precio de vuelo para imprimir en pantalla
/// @param totalDebito recibe el total del calculo para imprimir en pantalla
/// @param totalCredito recibe el total del calculo para imprimir en pantalla
/// @param totalBitcoin recibe el total del calculo para imprimir en pantalla
/// @param precioUnitario recibe el total del calculo para imprimir en pantalla
void mostrarResultados(char* nombreAerolinea, float precioVuelo, float totalDebito, float totalCredito, float totalBitcoin, float precioUnitario);

/// @fn void MostrarMenu(int, int, int, int, float, float)
/// @brief muestra el menu y sus datos ingresados.
///
/// @param flagKm bandera para confirmar y poder imprimir el dato en pantalla.
/// @param flagPrecioAerolineas bandera para confirmar y poder imprimir el dato en pantalla.
/// @param flagPrecioLatam bandera para confirmar y poder imprimir el dato en pantalla.
/// @param kms valor para mostrar en pantalla.
/// @param precioVuelo1 valor para mostrar en pantalla.
/// @param precioVuelo2 valor para mostrar en pantalla.
void MostrarMenu(int flagKm, int flagPrecioAerolineas, int flagPrecioLatam, int kms, float precioVuelo1, float precioVuelo2);

/// @fn void limpiarConsola(void)
/// @brief al no contar con la funcion system("cls"), esta reeemplaza y cada vez que el usuario elige una opcion
/// se ejecutan un conjunto de contrabarra n para hacer mas legible el menu.
void limpiarConsola(void);



#endif /* INPUTS_H_ */
