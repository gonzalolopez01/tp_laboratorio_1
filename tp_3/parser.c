#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"
#include "flight.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)//devuelve cantidad de parseados
{
	int ret = -1;
	if(pFile != NULL && pArrayListPassenger != NULL){
		ret = 0;
		//char array[7][15];
		char id[20];
		char nombre[20];
		char apellido[20];
		char precio[20];
		char tipo[20];
		char codigo[20];
		char status[20];

		sPassenger* pPassenger;
		//fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", array[0], array[1], array[2], array[3], array[4], array[5], array[6]);
		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigo, tipo, status) == 7){
				//fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigo, tipo, status);
				pPassenger = Passenger_newParametrosStr(id, nombre, apellido, precio, codigo, tipo, status);
				if(pPassenger != NULL){
					ll_add(pArrayListPassenger, pPassenger);
					ret++;
					if(ret == 50){
						break;
					}
				}
			}
		}
	}
    return ret;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	sPassenger* pPassenger;
	if(pFile != NULL && pArrayListPassenger!= NULL){
		ret = 0;
		while(!feof(pFile)){
			pPassenger = Passenger_new();
			fread(pPassenger,sizeof(sPassenger),1,pFile);
			if(feof(pFile)){
				break;
			}
			ll_add(pArrayListPassenger, pPassenger);
			ret++;
		}
	}
	return ret;
}

int parser_FlightFromText(FILE* pFile , LinkedList* pArrayListFlights)
{
	int ret = -1;
	if(pFile != NULL && pArrayListFlights != NULL){
		ret = 0;

		char codigo[20];
		char status[20];

		sFlight* pFlight;

		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^\n]\n", codigo, status) == 2){
				pFlight = Flight_newParametrosStr(codigo, status);
				if(pFlight != NULL){
					ll_add(pArrayListFlights, pFlight);
					ret++;
				}
			}
		}
	}
    return ret;
}
