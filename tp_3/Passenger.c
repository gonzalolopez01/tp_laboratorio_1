/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"



sPassenger* Passenger_new(){
	sPassenger* newPassenger = NULL;

	return newPassenger = (sPassenger*)malloc(sizeof(sPassenger));
}
sPassenger* Passenger_newParametrosStr(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr , char* statusFlightStr){
	sPassenger* pPassenger = Passenger_new();
	if(pPassenger != NULL){
		if(Passenger_setId(pPassenger, atoi(idStr)) ||
			Passenger_setNombre(pPassenger, nombreStr) ||
			Passenger_setApellido(pPassenger, apellidoStr) ||
			Passenger_setPrecio(pPassenger, atof(precioStr)) ||
			Passenger_setCodigoVuelo(pPassenger, codigoVueloStr) ||
			Passenger_setTipoPasajero(pPassenger, Passenger_typeStrtoInt(tipoPasajeroStr)) ||
			Passenger_setStatusFlight(pPassenger, Passenger_statusFtoint(statusFlightStr))){

			Passenger_delete(pPassenger);
			pPassenger = NULL;
		}
	}

	return pPassenger;
}
sPassenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, char* codigoVueloStr, int tipoPasajero, int statusFlight){
	sPassenger* pPassenger = Passenger_new();
	if(pPassenger != NULL){
		if(Passenger_setId(pPassenger, id) ||
			Passenger_setNombre(pPassenger, nombre) ||
			Passenger_setApellido(pPassenger, apellido) ||
			Passenger_setPrecio(pPassenger, precio) ||
			Passenger_setCodigoVuelo(pPassenger, codigoVueloStr) ||
			Passenger_setTipoPasajero(pPassenger, tipoPasajero) ||
			Passenger_setStatusFlight(pPassenger,statusFlight)){

			Passenger_delete(pPassenger);
			pPassenger = NULL;
		}
	}

	return pPassenger;
}
void Passenger_delete(sPassenger* pPassenger){
	free(pPassenger);
}
//-----------------------------------------------------
int Passenger_setId(sPassenger* this, int id){//hacer validacion con static
	int ret = -1;
	if(this != NULL && id > 0){
		this->id = id;
		ret = 0;
	}

	return ret;
}

int Passenger_getId(sPassenger* this, int* id){
	int ret = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		ret = 0;
	}
	return ret;
}
//----------------------------------------------------
int Passenger_setNombre(sPassenger* this, char* nombre){
	int ret = -1;
	if(this != NULL && nombre != NULL){//hacer un is valid
		//stringToProperName(nombre);

		strcpy(this->nombre, nombre);
		ret = 0;
	}
	return ret;
}

int Passenger_getNombre(sPassenger* this, char* nombre){
	int ret = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		ret = 0;
	}
	return ret;
}
//----------------------------------------------------
int Passenger_setApellido(sPassenger* this,char* apellido){
	int ret = -1;
	if(this != NULL && apellido != NULL){//hacer un is valid
		//stringToProperName(apellido);
		strcpy(this->apellido, apellido);
		ret = 0;
	}
	return ret;
}
int Passenger_getApellido(sPassenger* this, char* apellido){
	int ret = -1;
	if(this != NULL && apellido != NULL){
		strcpy(apellido, this->apellido);
		ret = 0;
	}
	return ret;
}
//----------------------------------------------------
int Passenger_setCodigoVuelo(sPassenger* this,char* codigoVuelo){
	int ret = -1;
	if(this != NULL && codigoVuelo != NULL){
		strcpy(this->codigoVuelo, codigoVuelo);
		ret = 0;
	}
	return ret;
}
int Passenger_getCodigoVuelo(sPassenger* this,char* codigoVuelo){
	int ret = -1;
	if (this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		ret = 0;
	}
	return ret;
}


//----------------------------------------------------
int Passenger_setTipoPasajero(sPassenger* this,int tipoPasajero){
	int ret = -1;
	if(this != NULL && (tipoPasajero == 1 || tipoPasajero == 2 || tipoPasajero == 3)){
		this->tipoPasajero = tipoPasajero;
		ret = 0;
	}
	return ret;
}
int Passenger_getTipoPasajero(sPassenger* this, int* tipoPasajero){
	int ret = -1;
	if(this != NULL && tipoPasajero != NULL){
		*tipoPasajero = this->tipoPasajero;
		ret = 0;
	}
	return ret;
}
//----------------------------------------------------

int Passenger_setPrecio(sPassenger* this,float precio){
	int ret = -1;
	if(this != NULL && precio > 0){
		this->precio = precio;
		ret = 0;
	}
	return ret;
}
int Passenger_getPrecio(sPassenger* this, float* precio){
	int ret = -1;
	if(this != NULL && precio != NULL){
		*precio = this->precio;
		ret = 0;
	}
	return ret;
}
//----------------------------------------------------
int Passenger_setStatusFlight(sPassenger* this, int statusFlight){
	int ret = -1;
	if(this != NULL && (statusFlight == 1 || statusFlight == 2 || statusFlight == 3)){
		this->statusFlight = statusFlight;
		ret = 0;
	}
	return ret;
}
int Passenger_getStatusFlight(sPassenger* this, int* statusFlight){
	int ret = -1;
	if(this != NULL && statusFlight != NULL){
		*statusFlight = this->statusFlight;
		ret = 0;
	}
	return ret;
}
//-------------------------------------------------------------
//-------------------------------------------------------------

int Passenger_showPassenger(sPassenger* pPassenger){
	int ret = -1;
	if(pPassenger != NULL){
		int id;
		char nombre[20];
		char apellido[20];
		float precio;
		int tipoPasajero;
		char codigoVuelo[20];
		int statusFlight;

		char tipoStr[20];
		char statusStr[20];

		Passenger_getId(pPassenger, &id);
		Passenger_getNombre(pPassenger, nombre);
		Passenger_getApellido(pPassenger, apellido);
		Passenger_getPrecio(pPassenger, &precio);
		Passenger_getTipoPasajero(pPassenger, &tipoPasajero);
		Passenger_getCodigoVuelo(pPassenger, codigoVuelo);
		Passenger_getStatusFlight(pPassenger, &statusFlight);

		Passenger_statusFInttoStr(statusFlight, statusStr);
		Passenger_typeInttoStr(tipoPasajero, tipoStr);

		printf("||%4d||%12s||%12s||%10.2f||%11s||%16s||%12s||\n", id, nombre, apellido, precio, codigoVuelo, tipoStr, statusStr);
		ret = 0;
	}
	return ret;
}
int Passenger_showPassengerColumns(sPassenger* pPassenger){
	int ret = -1;
	if(pPassenger != NULL){
		int id;
		char nombre[20];
		char apellido[20];
		float precio;
		int tipoPasajero;
		char codigoVuelo[20];
		int statusFlight;

		char tipoStr[20];
		char statusStr[20];

		Passenger_getId(pPassenger, &id);
		Passenger_getNombre(pPassenger, nombre);
		Passenger_getApellido(pPassenger, apellido);
		Passenger_getPrecio(pPassenger, &precio);
		Passenger_getTipoPasajero(pPassenger, &tipoPasajero);
		Passenger_getCodigoVuelo(pPassenger, codigoVuelo);
		Passenger_getStatusFlight(pPassenger, &statusFlight);

		Passenger_statusFInttoStr(statusFlight, statusStr);
		Passenger_typeInttoStr(tipoPasajero, tipoStr);

		printf("Id: %d\nNombre: %s\nApellido: %s\nPrecio: %.2f\nCodigoVuelo: %s\nTipo: %s\nStatusFlight: %s\n", id, nombre, apellido, precio, codigoVuelo, tipoStr, statusStr);
		ret = 0;
	}
	return ret;
}
//-------------------------------------------------------------
int Passenger_compareByID(void* aux1, void* aux2)
{
	int compare = 0;
	sPassenger* pAux1;
	sPassenger* pAux2;
	pAux1 = (sPassenger*)aux1;
	pAux2 = (sPassenger*)aux2;
	int pAux1Id;
	int pAux2Id;

	if(pAux1!=NULL && pAux2!=NULL){
		Passenger_getId(pAux1, &pAux1Id);
		Passenger_getId(pAux2, &pAux2Id);
		if(pAux1Id > pAux2Id){
			compare = 1;
		}else{
			if(pAux1Id < pAux2Id){
				compare = -1;
			}
		}
	}
	return compare;
}
int Passenger_compareByName(void* aux1, void* aux2)
{
	int compare = 0;
	sPassenger* pAux1;
	sPassenger* pAux2;
	pAux1 = (sPassenger*)aux1;
	pAux2 = (sPassenger*)aux2;

	char pAux1Name[20];
	char pAux2Name[20];

	if(pAux1!=NULL && pAux2!=NULL){
		Passenger_getNombre(pAux1, pAux1Name);
		Passenger_getNombre(pAux2, pAux2Name);
		compare = strcmp(pAux1Name,pAux2Name);
	}
	return compare;
}
int Passenger_compareByLastname(void* aux1, void* aux2)
{
	int compare = 0;
	sPassenger* pAux1;
	sPassenger* pAux2;
	pAux1 = (sPassenger*)aux1;
	pAux2 = (sPassenger*)aux2;

	char pAux1Lastname[20];
	char pAux2Lastname[20];

	if(pAux1!=NULL && pAux2!=NULL){
		Passenger_getApellido(pAux1, pAux1Lastname);
		Passenger_getApellido(pAux2, pAux2Lastname);
		compare = strcmp(pAux1Lastname,pAux2Lastname);
	}
	return compare;
}
int Passenger_compareByPrice(void* aux1, void* aux2)
{
	int compare = 0;
	sPassenger* pAux1;
	sPassenger* pAux2;
	pAux1 = (sPassenger*)aux1;
	pAux2 = (sPassenger*)aux2;
	float pAux1Pr;
	float pAux2Pr;

	if(pAux1!=NULL && pAux2!=NULL){
		Passenger_getPrecio(pAux1, &pAux1Pr);
		Passenger_getPrecio(pAux2, &pAux2Pr);
		if(pAux1Pr > pAux2Pr){
			compare = 1;
		}else{
			if(pAux1Pr < pAux2Pr){
				compare = -1;
			}
		}
	}
	return compare;
}
int Passenger_compareByType(void* aux1, void* aux2)
{
	int compare = 0;
	sPassenger* pAux1;
	sPassenger* pAux2;
	pAux1 = (sPassenger*)aux1;
	pAux2 = (sPassenger*)aux2;
	int pAux1Pr;
	int pAux2Pr;

	if(pAux1!=NULL && pAux2!=NULL){
		Passenger_getTipoPasajero(pAux1, &pAux1Pr);
		Passenger_getTipoPasajero(pAux2, &pAux2Pr);
		if(pAux1Pr > pAux2Pr){
			compare = 1;
		}else{
			if(pAux1Pr < pAux2Pr){
				compare = -1;
			}
		}
	}
	return compare;
}
int Passenger_compareByFlightCode(void* aux1, void* aux2)
{
	int compare = 0;
	sPassenger* pAux1;
	sPassenger* pAux2;
	pAux1 = (sPassenger*)aux1;
	pAux2 = (sPassenger*)aux2;

	char pAux1Code[20];
	char pAux2Code[20];

	if(pAux1!=NULL && pAux2!=NULL){
		Passenger_getCodigoVuelo(pAux1, pAux1Code);
		Passenger_getCodigoVuelo(pAux2, pAux2Code);
		compare = strcmp(pAux1Code,pAux2Code);
	}
	return compare;
}
int Passenger_compareByStatus(void* aux1, void* aux2)
{
	int compare = 0;
	sPassenger* pAux1;
	sPassenger* pAux2;
	pAux1 = (sPassenger*)aux1;
	pAux2 = (sPassenger*)aux2;
	int pAux1Pr;
	int pAux2Pr;

	if(pAux1!=NULL && pAux2!=NULL){
		Passenger_getStatusFlight(pAux1, &pAux1Pr);
		Passenger_getStatusFlight(pAux2, &pAux2Pr);
		if(pAux1Pr > pAux2Pr){
			compare = 1;
		}else{
			if(pAux1Pr < pAux2Pr){
				compare = -1;
			}
		}
	}
	return compare;
}


//-------------------------------------------------------
int Passenger_typeStrtoInt(char* typeStr){
	int ret = -1;
	if(typeStr != NULL){
		if(strcmp(typeStr, "FirstClass") == 0){
			ret = 1;
		}else{
			if(strcmp(typeStr, "ExecutiveClass") == 0){
				ret  = 2;
			}else{
				if(strcmp(typeStr, "EconomyClass") == 0){
					ret = 3;
				}
			}
		}
	}
	return ret;
}
int Passenger_typeInttoStr(int typeInt, char* typeStr){
	int ret = -1;
	if(typeStr != NULL){
		if(typeInt == 1){
			strcpy(typeStr, "FirstClass");
		}else{
			if(typeInt == 2){
				strcpy(typeStr, "ExecutiveClass");
			}else{
					strcpy(typeStr, "EconomyClass");
			}
		}
		ret = 0;
	}
	return ret;
}
int Passenger_statusFtoint(char* statusStr){
	int ret = -1;
	if(statusStr != NULL){
		if(strcmp(statusStr, "Aterrizado") == 0){
			ret = 1;
		}else{
			if(strcmp(statusStr, "En Vuelo") == 0){
				ret  = 2;
			}else{
				ret = 3;
			}
		}
	}
	return ret;
}
int Passenger_statusFInttoStr(int statusInt, char* statusStr){
	int ret = -1;
	if(statusStr != NULL){
		if(statusInt == 1){
			strcpy(statusStr, "Aterrizado");
		}else{
			if(statusInt == 2){
				strcpy(statusStr, "En Vuelo");
			}else{
					strcpy(statusStr, "En Horario");
			}
		}
		ret = 0;
	}
	return ret;
}
