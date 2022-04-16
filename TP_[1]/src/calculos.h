/*
 * calculos.h
 *
 *  Created on: 13 abr. 2022
 *      Author: brian
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

#include <stdio.h>
#include <stdlib.h>

#define DESCUENTO 10
#define INTERES 1.25
#define BITCOIN 4620526.38

/// @fn float calculo_TarjetaDebito(float)
/// @brief recibe el precio del vuelo y realiza el descuento.
///
/// @param precioVuelo precio para realizar el calculo
/// @return retorna el total del precio con descuento incluido.
float calculo_TarjetaDebito(float precioVuelo);

/// @fn float calculo_TarjetaCredito(float)
/// @brief recibe el precio del vuelo y realiza el recargo del 25% por pago de tarjeta.
///
/// @param precioVuelo precio para realizar el calculo
/// @return retorna el total del precio con el recargo incluido.
float calculo_TarjetaCredito(float precioVuelo);

/// @fn float calculo_Bitcoins(float)
/// @brief recibe el precio del vuelo y realiza la conversion a bitcoin
///
/// @param precioVuelo precio para realizar la conversion.
/// @return retorna el valor del vuelo en bitcoin.
float calculo_Bitcoins(float precioVuelo);

/// @fn float calculo_PrecioKm(float, int)
/// @brief recibe el precio del vuelo y la cantidad de km para realizar el calculo del precio unitario del km.
///
/// @param precioVuelo precio para realizar el calculo.
/// @param kms cantidad de km para realizar el calculo
/// @return retorna el precio unitario del km.
float calculo_PrecioKm(float precioVuelo, int kms);

/// @fn float calculo_DiferenciaPrecios(float, float)
/// @brief recibe precios de vuelo de ambas aerolineas y reliza el calculo para obtener la diferencia
///
/// @param precioAerolinea1 precio de la primer aerolinea
/// @param precioAerolinea2 precio de la segunda aerolinea
/// @return retorna el valor de la diferencia entre ambos precios.
float calculo_DiferenciaPrecios(float precioAerolinea1, float precioAerolinea2);


#endif /* CALCULOS_H_ */
