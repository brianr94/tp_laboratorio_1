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
#define TRUE 0
#define FALSE 1

struct
{
	int id;
	char name[NAME];
	char lastName[LASTNAME];
	float price;
	char flycode[FLYCODE];
	int typePassenger;
	int isEmpty;

}typedef Passenger;

/// @fn int initPassengers(Passenger*, int)
/// @brief
///
/// @param list
/// @param len
/// @return
int initPassengers(Passenger* list, int len);

/// @fn int addPassenger(Passenger*, int, int, char[], char[], float, int, char[])
/// @brief
///
/// @param list
/// @param len
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flycode
/// @return
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);

/// @fn int findPassengerById(Passenger*, int, int)
/// @brief
///
/// @param list
/// @param len
/// @param id
/// @return
int findPassengerById(Passenger* list, int len,int id);

/// @fn int removePassenger(Passenger*, int, int)
/// @brief
///
/// @param list
/// @param len
/// @param id
/// @return
int removePassenger(Passenger* list, int len, int id);

/// @fn int sortPassengers(Passenger*, int, int)
/// @brief
///
/// @param list
/// @param len
/// @param order
/// @return
int sortPassengers(Passenger* list, int len, int order);

/// @fn int printPassenger(Passenger*, int)
/// @brief
///
/// @param list
/// @param length
/// @return
int printPassenger(Passenger* list, int length);

/// @fn int sortPassengers(Passenger*, int, int)
/// @brief
///
/// @param list
/// @param len
/// @param order
/// @return
int sortPassengers(Passenger* list, int len, int order);

#endif /* ARRAYPASSENGER_H_ */
