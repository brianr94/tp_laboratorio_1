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

/// @fn float calculo_TarjetaDebito(float)
/// @brief
///
/// @param precioVuelo
/// @return
float calculo_TarjetaDebito(float precioVuelo);

/// @fn float calculo_TarjetaCredito(float)
/// @brief
///
/// @param precioVuelo
/// @return
float calculo_TarjetaCredito(float precioVuelo);

/// @fn float calculo_Bitcoins(float)
/// @brief
///
/// @param precioVuelo
/// @return
float calculo_Bitcoins(float precioVuelo);

/// @fn float calculo_PrecioKm(float, int)
/// @brief
///
/// @param precioVuelo
/// @param kms
/// @return
float calculo_PrecioKm(float precioVuelo, int kms);

/// @fn float calculo_DiferenciaPrecios(float, float)
/// @brief
///
/// @param precioAerolinea1
/// @param precioAerolinea2
/// @return
float calculo_DiferenciaPrecios(float precioAerolinea1, float precioAerolinea2);


#endif /* CALCULOS_H_ */
