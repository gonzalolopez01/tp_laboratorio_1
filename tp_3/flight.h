/*
 * vuelos.h
 *
 *  Created on: 14 jun. 2022
 *      Author: gon
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FLIGHT_H_
#define FLIGHT_H_

typedef struct{
	char codigoVuelo[10];
	int statusFlight;
}sFlight;



#endif /* FLIGHT_H_ */


sFlight* Flight_new();
sFlight* Flight_newParametrosStr(char* codigoVueloStr, char* statusFlightStr);
void Flight_delete(sFlight* pFlight);
int Flight_setCodigoVuelo(sFlight* this, char* codigoVuelo);
int Flight_getCodigoVuelo(sFlight* this, char* codigoVuelo);

int Flight_setStatusFlight(sFlight* this, int statusFlight);
int Flight_getStatusFlight(sFlight* this, int* statusFlight);

int Flight_showFlight(sFlight* pFlight);
