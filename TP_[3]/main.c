#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn_inputs.h"
#include "utn_validaciones.h"
#include "ultimoID.h"
#include "parser.h"
#include "sorts.h"


/****************************************************
    Menu:
    "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)."
     "2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)."
     "3. Alta de pasajero"
     "4. Modificar datos de pasajero"
     "5. Baja de pasajero"
     "6. Listar pasajeros"
     "7. Ordenar pasajeros"
     "8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)."
     "9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)."
    "10. Salir"
*****************************************************/



int main(void)
{
	setbuf(stdout,NULL);

    int opcion;
    int flagAltaPasajero;
    int flagCargaTexto;
    int flagCargaBinaria;
    int flagGuardado;

     flagAltaPasajero=0;
     flagCargaTexto=0;
	 flagCargaBinaria=0;
	 flagGuardado=0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	pedirNumeroEnteroValidado(&opcion, "----------------------------------------------------------------------------------\n"
											"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
										 	 "2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
											 "3. Alta de pasajero\n"
											 "4. Modificar datos de pasajero\n"
											 "5. Baja de pasajero\n"
											 "6. Listar pasajeros\n"
											 "7. Ordenar pasajeros\n"
											 "8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
											 "9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
											"10. Salir\n"
											"----------------------------------------------------------------------------------\n"
											"Ingrese una opcion: ",
											"----------------------------------------------------------------------------------\n"
											"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
											"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
											"3. Alta de pasajero\n"
											"4. Modificar datos de pasajero\n"
											"5. Baja de pasajero\n"
											"6. Listar pasajeros\n"
											"7. Ordenar pasajeros\n"
											"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
											"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
											"10. Salir\n"
											"----------------------------------------------------------------------------------n"
											"Error. Ingrese una opcion correcta: ", 1, 10);

        switch(opcion)
        {
            case 1:
            	if(flagCargaBinaria==0 && flagCargaTexto==0)
            	{
                    controller_loadFromText("data.csv",listaPasajeros);
                    flagCargaTexto=1;
            	}
            	else
            	{
            		printf("\nActualmente hay un archivo cargado!!!\n");
            	}

                break;
            case 2:
            	if(flagCargaTexto==0 && flagCargaBinaria==0)
            	{
            		controller_loadFromBinary("data.bin", listaPasajeros);
					flagCargaBinaria=1;
            	}
            	else
            	{
            		printf("\nActualmente hay un archivo cargado!!!\n");
            	}
				break;
            case 3:
            	controller_addPassenger(listaPasajeros);
            	flagAltaPasajero=1;
            	break;
            case 4:
            	if(flagAltaPasajero==1 || flagCargaBinaria==1 || flagCargaTexto==1)
            	{
            		controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nCargue un archivo o cargue pasajeros para modificar!!!\n");
            	}

				break;
            case 5:
            	if(flagAltaPasajero==1 || flagCargaBinaria==1 || flagCargaTexto==1)
				{
            		controller_removePassenger(listaPasajeros);
				}
				else
				{
					printf("\nCargue un archivo o cargue pasajeros para dar de baja!!!\n");
				}

            	break;
            case 6:
            	if(flagAltaPasajero==1 || flagCargaBinaria==1 || flagCargaTexto==1)
            	{
					controller_ListPassenger(listaPasajeros);
				}
				else
				{
					printf("\nCargue un archivo o cargue pasajeros para mostrarlos!!!\n");
				}

            	break;
            case 7:
            	if(flagAltaPasajero==1 || flagCargaBinaria==1 || flagCargaTexto==1)
            	{
					controller_sortPassenger(listaPasajeros);
				}
				else
				{
					printf("\nCargue un archivo o cargue pasajeros para oredenarlos!!!\n");
				}

				break;
            case 8:
            	ultimoID_saveMaxIdAsText(listaPasajeros);
            	controller_saveAsText("data.csv", listaPasajeros);
            	flagGuardado=1;
				break;
            case 9:
            	ultimoID_saveMaxIdAsText(listaPasajeros);
            	controller_saveAsBinary("data.bin", listaPasajeros);
            	flagGuardado=1;
				break;
            case 10:
            	if(flagGuardado==1)
            	{
            		printf("\nElegio Salir del programa!!!!\n");
            	}
            	else
            	{
            		printf("\nGuarde el archivo antes de salir del programa!!!\n");
            	}
				break;
        }

        if(opcion != 10)
        {
        	system("pause");
        }

    }while(opcion != 10);


    return EXIT_SUCCESS;
}

