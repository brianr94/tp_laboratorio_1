/*
 * ArrayPassenger.h
 *
 *  Created on: 8 may. 2022
 *      Author: brian
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>

#define NAME 51
#define LASTNAME 51
#define FLYCODE 10

#define LENGTHPASSENGERS 2000

//isEmpty Flag
#define EMPTY 0
#define FULL 1

// order type
#define ASCENDENTE 1
#define DESCENDENTE -1

//typePasseger
#define CLASETURISTA 1
#define CLASEEJECUTIVA 2
#define PRIMERACLASE 3

//statusFlight
#define ACTIVO 1
#define INACTIVO 2
#define DEMORADO 3

struct
{
	int id;
	char name[NAME];
	char lastName[LASTNAME];
	float price;
	char flyCode[FLYCODE];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}typedef Passenger;

/// @fn int initPassengers(Passenger*, int)
/// @brief To indicate that all position in the array are empty,this function put the flag (isEmpty) in TRUE in all
///
/// @param list Passenger* Pointer to array of passenger
/// @param len Array length
/// @return  int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initPassengers(Passenger* list, int len);

/// @fn int addPassenger(Passenger*, int, int, char[], char[], float, int, char[], int)
/// @brief add in a existing list of passengers the values received as parameters in the first empty position
///
/// @param list Passenger* Pointer to array of passenger
/// @param len Array length
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flycode
/// @param statusFlight
/// @return Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);

/// @fn int requestPassenger(Passenger*, int, int*)
/// @brief prompts user for array data to load into a helper and send to a function to load
///
/// @param list Passenger* Pointer to array of passenger
/// @param len Array length
/// @param id int
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int requestPassenger(Passenger* list, int len, int* id);

/// @fn int modifyPasseger(Passenger*, int)
/// @brief modify passenger values by id.
/// @param list Passenger* Pointer to array of passenger
/// @param len Array length
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int modifyPasseger(Passenger* list, int len);

/// @fn int findPassengerById(Passenger*, int, int)
/// @brief find a Passenger by Id en returns the index position in array.
///
/// @param list Passenger* Pointer to array of passenger
/// @param len Array length
/// @param id int
/// @return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
int findPassengerById(Passenger* list, int len,int id);


/// @fn int searchEmptyIndex(Passenger*, int, int*)
/// @brief looks for an empty space and returns the index if not found returns -1
///
/// @param list Passenger* Pointer to array of passenger
/// @param len Array Length
/// @param index pointer to index
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int searchEmptyIndex(Passenger* list, int len, int* index);

/// @fn int removePassenger(Passenger*, int, int)
/// @brief Remove a Passenger by Id (put isEmpty Flag in 1)
///
/// @param list Passenger* Pointer to array of passenger
/// @param len Array length
/// @param id int
/// @return Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
int removePassenger(Passenger* list, int len, int id);

/// @fn int sortPassengersByCode(Passenger*, int, int)
/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
///
/// @param list  Passenger* Pointer to array of passenger
/// @param len Array length
/// @param order [1] indicate UP - [0] indicate DOWN
/// @return  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengersByCode(Passenger* list, int len, int order);

/// @fn int sortPassengersByLastName(Passenger*, int, int)
/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
///
/// @param list  Passenger* Pointer to array of passenger
/// @param len Array length
/// @param order [1] indicate UP - [0] indicate DOWN
/// @return  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengersByLastName(Passenger* list, int len, int order);

/// @fn void printPassenger(Passenger)
/// @brief print the content of one passenger.
///
/// @param list Passenger
void printPassenger(Passenger list);


/// @fn int printPassengers(Passenger*, int)
/// @brief print the content of passengers array
///
/// @param list Passenger* Pointer to array of passenger
/// @param length Array length
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int printPassengers(Passenger* list, int length);


/// @fn int totalPriceAndAveragedPrice(Passenger*, int)
/// @brief totals Passenger salaries and shows the number of employees who exceed the average salary
///
/// @param list Passenger* Pointer to array of passenger
/// @param len Array length
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int totalPriceAndAveragedPrice(Passenger* list, int len);

/// @fn int subMenuReport(Passenger*, int)
/// @brief print the submenu report
///
/// @param list Passenger* Pointer to array of passenger
/// @param len Array length
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int subMenuReport(Passenger* list, int len);

/// @fn int cargaForzadaDatos(Passenger*, int, int*)
/// @brief Load passenger data already defined in the array list of Passengers
///
/// @param list Passenger* Pointer to array of passenger
/// @param len Array length
/// @param id pointer to id
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int cargaForzadaDatos(Passenger* list, int len, int* id);

/// @fn int cargarPasajeroForzado(Passenger*, int, int, char[], char[], float, int, char[], int)
/// @brief add in a existing list of passengers the values received as parameters in the first empty position
///
/// @param list Passenger* Pointer to array of passenger
/// @param len array length
/// @param id int
/// @param name char[]
/// @param lastName char[]
/// @param price float
/// @param typePassenger int
/// @param flycode char[]
/// @param statusFlight int
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int cargarPasajeroForzado(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);

#endif /* ARRAYPASSENGER_H_ */
