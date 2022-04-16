/*
RIANI BRIAN 1°D

TP 1
 */

#include "calculos.h"

float calculo_TarjetaDebito(float precioVuelo)
{
	float descuentoTotal;
	float descuentoDebito;

	descuentoDebito= (precioVuelo*DESCUENTO) / 100;

	descuentoTotal= precioVuelo - descuentoDebito;

	return descuentoTotal;


}

float calculo_TarjetaCredito(float precioVuelo)
{
	float totalInteres;

	totalInteres= precioVuelo * INTERES;

	return totalInteres;

}

float calculo_Bitcoins(float precioVuelo)
{

	float totalPrecioBitcoin;

	totalPrecioBitcoin= precioVuelo / BITCOIN;

	return totalPrecioBitcoin;
}

float calculo_PrecioKm(float precioVuelo, int kms)
{
	float precioKms;

	precioKms= precioVuelo/kms;

	return precioKms;
}

float calculo_DiferenciaPrecios(float precioAerolinea1, float precioAerolinea2)
{
	float totalDiferencia;

	if(precioAerolinea1>precioAerolinea2)
	{
		totalDiferencia= precioAerolinea1 - precioAerolinea2;
	}
	else
	{
		totalDiferencia= precioAerolinea2 - precioAerolinea1;
	}

	return totalDiferencia;
}


