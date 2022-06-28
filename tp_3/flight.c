/*
 * vuelos.c
 *
 *  Created on: 14 jun. 2022
 *      Author: gon
 */
#include "flight.h"


static int Flight_statusFtoint(char* statusStr);
static int Flight_statusFInttoStr(int statusInt, char* statusStr);

sFlight* Flight_new(){
	sFlight* newFlight = NULL;

	return newFlight = (sFlight*)malloc(sizeof(sFlight));
}
sFlight* Flight_newParametrosStr(char* codigoVueloStr, char* statusFlightStr){
	sFlight* pFlight = Flight_new();
	if(pFlight != NULL){
		if( Flight_setCodigoVuelo(pFlight, codigoVueloStr) ||
			Flight_setStatusFlight(pFlight, Flight_statusFtoint(statusFlightStr))){

			Flight_delete(pFlight);
			pFlight = NULL;
		}
	}

	return pFlight;
}
void Flight_delete(sFlight* pFlight){
	free(pFlight);
}
//----------------------------------------------------
int Flight_setCodigoVuelo(sFlight* this, char* codigoVuelo){
	int ret = -1;
	if(this != NULL && codigoVuelo != NULL){
		strcpy(this->codigoVuelo, codigoVuelo);
		ret = 0;
	}
	return ret;
}
int Flight_getCodigoVuelo(sFlight* this, char* codigoVuelo){
	int ret = -1;
	if (this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		ret = 0;
	}
	return ret;
}

//----------------------------------------------------
int Flight_setStatusFlight(sFlight* this, int statusFlight){
	int ret = -1;
	if(this != NULL && (statusFlight == 1 || statusFlight == 2 || statusFlight == 3)){
		this->statusFlight = statusFlight;
		ret = 0;
	}
	return ret;
}
int Flight_getStatusFlight(sFlight* this, int* statusFlight){
	int ret = -1;
	if(this != NULL && statusFlight != NULL){
		*statusFlight = this->statusFlight;
		ret = 0;
	}
	return ret;
}
//-------------------------------------------------------------

int Flight_showFlight(sFlight* pFlight){
	int ret = -1;
	if(pFlight != NULL){
		char codigoVuelo[20];
		int statusFlight;

		char statusStr[20];

		Flight_getCodigoVuelo(pFlight, codigoVuelo);
		Flight_getStatusFlight(pFlight, &statusFlight);

		Flight_statusFInttoStr(statusFlight, statusStr);

		printf("||%15s||%15s||\n", codigoVuelo, statusStr);
		ret = 0;
	}
	return ret;
}

//-------------------------------------------------------------

static int Flight_statusFtoint(char* statusStr){
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
static int Flight_statusFInttoStr(int statusInt, char* statusStr){
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
