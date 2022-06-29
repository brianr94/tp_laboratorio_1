/*
 * sorts.h
 *
 *  Created on: 28 jun. 2022
 *      Author: brian
 */

#ifndef SORTS_H_
#define SORTS_H_

int Passenger_sortById(void* passengerI, void* passengerJ);
int Passenger_sortByPrice(void* passengerI, void* passengerJ);
int Passenger_sortByName(void* passengerI, void* passengerJ);
int Passenger_sortByLastName(void* passengerI, void* passengerJ);
int Passenger_sortByStatusFligth(void* passengerI, void* passengerJ);
int Passenger_sortByFlyCode(void* passengerI, void* passengerJ);
int Passenger_sortByTypePassenger(void* passengerI, void* passengerJ);


#endif /* SORTS_H_ */
