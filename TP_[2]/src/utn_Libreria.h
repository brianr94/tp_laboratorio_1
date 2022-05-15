/*
 * utn_Libreria.h
 *
 *  Created on: 14 may. 2022
 *      Author: brian
 */

#ifndef UTN_LIBRERIA_H_
#define UTN_LIBRERIA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int pedirCadena(char* cadena,char* mensaje,char* mensajeError,int maxTam);
int pedirNumero(int* numero,char* mensaje,char* mensajeError,int min, int max);
int pedirNumeroFlotante(float* numero, char* mensaje,char* mensajeError,int min,int max);
int pedirNumeroEnteroValidado(char* mensaje, char* mensajeError, int min, int max);


int esNumero(char* cadena);
int validarSignos(char* cadena);
int validarEspacio(char* cadena);
int primerLetraMayuscula(char* cadena);
int cadenaEnMinuscula(char* cadena);


#endif /* UTN_LIBRERIA_H_ */
