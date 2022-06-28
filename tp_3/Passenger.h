/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include <string.h>

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int statusFlight;

}sPassenger;

sPassenger* Passenger_new();
sPassenger* Passenger_newParametrosStr(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr , char* statusFlightStr);
sPassenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, char* codigoVueloStr, int tipoPasajero, int statusFlight);
void Passenger_delete(sPassenger* pPassenger);

int Passenger_setId(sPassenger* this,int id);
int Passenger_getId(sPassenger* this,int* id);

int Passenger_setNombre(sPassenger* this,char* nombre);
int Passenger_getNombre(sPassenger* this,char* nombre);

int Passenger_setApellido(sPassenger* this,char* apellido);
int Passenger_getApellido(sPassenger* this,char* apellido);

int Passenger_setCodigoVuelo(sPassenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(sPassenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(sPassenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(sPassenger* this,int* tipoPasajero);

int Passenger_setPrecio(sPassenger* this,float precio);
int Passenger_getPrecio(sPassenger* this,float* precio);

int Passenger_setStatusFlight(sPassenger* this, int statusFlight);
int Passenger_getStatusFlight(sPassenger* this, int* statusFlight);

//--------------------------
int Passenger_showPassenger(sPassenger* pPassenger);

int Passenger_showPassengerColumns(sPassenger* pPassenger);

int Passenger_compareByID(void* aux1, void* aux2);
int Passenger_compareByName(void* aux1, void* aux2);
int Passenger_compareByLastname(void* aux1, void* aux2);
int Passenger_compareByPrice(void* aux1, void* aux2);
int Passenger_compareByType(void* aux1, void* aux2);
int Passenger_compareByFlightCode(void* aux1, void* aux2);
int Passenger_compareByStatus(void* aux1, void* aux2);

int Passenger_typeStrtoInt(char* typeStr);
int Passenger_typeInttoStr(int typeInt, char* typeStr);

int Passenger_statusFtoint(char* statusStr);
int Passenger_statusFInttoStr(int statusInt, char* statusStr);

#endif /* PASSENGER_H_ */
