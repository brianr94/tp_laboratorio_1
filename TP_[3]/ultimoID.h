/*
 * ultimoID.h
 *
 *  Created on: 29 jun. 2022
 *      Author: brian
 */

#ifndef ULTIMOID_H_
#define ULTIMOID_H_

#include "LinkedList.h"


/// @fn int ultimoID_findMaxId(LinkedList*)
/// @brief recorre la linkedlist y busca que el id maximo.
///
/// @param pArrayListPassenger
/// @return
int ultimoID_findMaxId(LinkedList* pArrayListPassenger);

/// @fn int ultimoID_saveMaxIdAsText(LinkedList*)
/// @brief guarda el maximo id en un archivo.
///
/// @param pArrayListPassenger
/// @return
int ultimoID_saveMaxIdAsText(LinkedList* pArrayListPassenger);


/// @fn int ultimoID_parser_getMaxId()
/// @brief
///
/// @return
int ultimoID_parser_getMaxId();

#endif /* ULTIMOID_H_ */
