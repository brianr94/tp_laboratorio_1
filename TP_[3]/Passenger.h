/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "LinkedList.h"
//price range
#define MIN_PRECIO 10000
#define MAX_PRECIO 50000

#define TAMSTRING 50
#define TAMCODIGOVUELO 8


//status Fligth
#define ATERRIZADO 1
#define ENVUELO 2
#define DEMORADO 3
#define ENHORARIO 4

//type Passegers
#define ECONOMYCLASS 1
#define EXECUTIVECLASS 2
#define FIRSTCLASS 3

typedef struct
{
	int id;
	char nombre[TAMSTRING];
	char apellido[TAMSTRING];
	float precio;
	int tipoPasajero;
	int estadoVuelo;
	char codigoVuelo[TAMCODIGOVUELO];
	int isEmpty;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr ,char* nombreStr ,char* apellidoStr ,char* precioStr ,char* codigoDeVueloStr ,char* tipoPasajeroStr ,char* estadoDeVueloStr);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_getNumEstadoVuelo(char* codigoVueloStr);
int Passenger_getStrEstadoVuelo(char* codigoVueloStr);

int Passenger_getStrTipoPasajero(char* tipoPasajeroStr);
int Passenger_getNumTipoPasajero(char* tipoPasajeroStr);

Passenger* Passenger_requestDataPassenger(int* id);
int Passenger_modifyPassenger(Passenger* this);
int Passenger_printSortMenu(LinkedList* pArrayListPassenger);
Passenger* Passenger_findPassegerById(LinkedList* pArrayPassenger, int id ,int* index);
void Passenger_printPassenger(Passenger* this);

#endif /* PASSENGER_H_ */
