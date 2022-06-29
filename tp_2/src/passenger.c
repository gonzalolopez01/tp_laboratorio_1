/*
 * passenger.c
 *
 *  Created on: 28 jun. 2022
 *      Author: gonzalo
 */
#include "passenger.h"


int passengers_menu(){

	int opcion;
	printf("\n-----AEROLINEA------\n");
	printf("--------------------\n");
	printf("1- Altas\n");
	printf("2- Modificar\n");
	printf("3- Baja\n");
	printf("4- Informar\n");
	printf("5- Mostrar pasajeros\n");
	printf("6- Salir\n\n");
	input_IntNumberMinMax(&opcion, "Ingrese opcion: ", "ERROR, valor invalido. ", 1, 6, "ERROR, opcion Invalida");
	return opcion;
}
/**
 * carga de datos en la lista de manera manual
 * @param list: nombre
 * @param len: tama�o de la lista
 * @param quantity: cantidad a cargar
 * @param pNextId: id del elemento
 * @return 1: ok
 * 			0: error
 */
int harcodearPassengers(sPassenger* list, int len, int quantity, int* pNextId){
	int retOk = 0;
	sPassenger passengers[10]={{1, "Juan", "Lopez",         3200, "WBA374", 100, 1, 0},
                                {2, "Miguel", "Fernandez",  1000, "JNT371", 100, 0, 0},
                                {3, "Maria", "Mela",        3200, "WBA374", 100, 1, 0},
                                {4, "Lucas", "Ontivero",     450, "RYT364", 102, 0, 0},
                                {5, "Lorena", "Garcia",     1200, "WBA374", 101, 1, 0},
                                {6, "Rosa", "Gimenez",       450, "RYT364", 102, 0, 0},
                                {7, "Manuel", "Belgrano",   5500, "XNY374", 100, 1, 0},
                                {8, "Myriam", "Bregman",    1700, "XNY374", 101, 1, 0},
                                {9, "Andy", "Johnson",      1100, "JNT371", 102, 0, 0},
                                {10, "Marta", "Mars",       1700, "XNY914", 100, 0, 0}
                                };

	if(list != NULL && len > 0 && quantity <= len               ){
		for(int i = 0; i < quantity; i++){
			list[i] = passengers[i];
			list[i].id = *pNextId;
			(*pNextId)++;

		}
		retOk = 1;
	}
	return retOk;
}
//------------------
/**
 * actualiza el campo isEmpty en 1 para indicar que cada indice de la lista esta vacia
 * @param list
 * @param len: tamano
 * @return 0: error
 * 			1: ok
 */
int passengers_initPassengers(sPassenger* list, int len){
    int retOk = 0;
    if(list != NULL && len > 0){
        for(int i=0; i<len; i++){
        	list[i].isEmpty = 1;
        }
        retOk = 1;
    }
    return retOk;
}

//-------------------
int passengers_printPassenger(sPassenger passenger, sTypePassenger* types, int lenT, sFlycode* codes, int lenC){
    int retOk = 0;
	if(types != NULL && lenT > 0 && codes != NULL && lenC > 0){
        char type[25];
        char state[10];

        typeP_loadType(types, lenT, passenger.typePassenger, type);
        flycode_loadStatus(codes, lenC, passenger.flycode, state);
        printf("Id: %d\nNombre: %s\nApellido: %s\nPrecio: $%.2f\nFlycode: %s\nTipo de Pasajero: %s\nEstado: %s\n", passenger.id,
                                                        passenger.name,
                                                        passenger.lastname,
                                                        passenger.price,
                                                        passenger.flycode,
                                                        type,
                                                        state);
        retOk = 1;
	}
	return retOk;
}
int passengers_printPassengerRow(sPassenger passenger, sTypePassenger* types, int lenT, sFlycode* codes, int lenC){
    int retOk = 0;
	if(types != NULL && lenT > 0 && codes != NULL && lenC > 0){
        char type[25];
        char state[10];

        typeP_loadType(types, lenT, passenger.typePassenger, type);
        flycode_loadStatus(codes, lenC, passenger.flycode, state);
        printf(" %-4d %-10s %-12s $%8.2f %10s   %-15s %10s\n", passenger.id,
                                                        passenger.name,
                                                        passenger.lastname,
                                                        passenger.price,
                                                        passenger.flycode,
                                                        type,
                                                        state);
        retOk = 1;
	}
	return retOk;
}


int passengers_printPassengers(sPassenger list[], int len, sTypePassenger types[], int lenT, sFlycode codes[], int lenC){
	int retOK = 0;
	int flag = 1;
	if(list != NULL && len > 0 && types != NULL && lenT > 0 && codes != NULL && lenC > 0){

        printf("\n                   *** LISTA DE PASAJEROS ***\n");
        printf(" id   Nombre     Apellido      Precio       Flycode  TipoPasajero  EstadoVuelo\n");
        printf("------------------------------------------------------------------------------\n");
		for (int i=0; i < len; i++){
			if(!list[i].isEmpty){
                passengers_printPassengerRow(list[i], types, lenT, codes, lenC);
				flag=0;
			}
		}
		if(flag){
			printf("no hay pasajeros en el sistema\n");
		}
		retOK = 1;
	}
    return retOK;
}



//------------
int passengers_setId(int* id, int* pNextId){
    int retOk = 0;
	if(id != NULL && *id > 0){
		*id = *pNextId;
        (*pNextId)++;
		retOk = 1;
	}
	return retOk;
}

int passengers_entryName(char name[]){
	int retOk = 0;
	if(name != NULL){
		input_AlphaText(name, 50, "Ingrese Nombre: ", "ERROR. ");
		stringToProperName(name);
		retOk = 1;
	}
	return retOk;
}
int passengers_entryLastaName(char lastName[]){
	int retOk = 0;
	if(lastName != NULL){
		input_AlphaText(lastName, 50, "Ingrese Apellido: ", "ERROR. ");
		stringToProperName(lastName);
		retOk = 1;
	}
	return retOk;
}
/**
 * permite obtener un flycode validado
 * @param fCode:recibe el codigo de vuelos
 * @param flycodes
 * @param len
 * @return 1 ok
 * 			0 error de punteros o tamano de la lista
 */
int passengers_entryFlycode(char* fCode, sFlycode flycodes[], int len){
	int retOk = 0;
	if(fCode != NULL && flycodes != NULL && len > 0){
        flycode_printFlycodes(flycodes, len);
		input_Text(fCode, 12, "Ingrese flycode: ");
		while(!flycode_isValidFlycode(flycodes, len, fCode)){
            input_Text(fCode, 12, "Codigo Invalido. Ingrese flycode: ");
		}
		stringToUpper(fCode);
		retOk = 1;
	}
	return retOk;
}
/**
 * obtiene el status de determinada vuelo
 * @param flycodes: codigo de vuelo
 * @param len tamano
 * @param fCode codigo
 * @param statusF recibe el estado del vuelo (1 o 0)
 * @return 1 ok
 * 			0 ok
 */
int passengers_setStatusFlight(sFlycode flycodes[], int len, char fCode[], int* statusF){
    int retOk = 0;
	if(flycodes != NULL && len > 0 && fCode != NULL && statusF != NULL){
	    for(int i = 0; i < len; i++){
            if(strcmpi(flycodes[i].flycode, fCode) == 0){
                *statusF = flycodes[i].statusFlight;
                retOk = 1;
                break;
            }
	    }
	}
    return retOk;
}
/**
 * permite obtener un tipo de pasajero validad
 * @param type: recibe el id del tipo de pasajero
 * @param list
 * @param len: tamano
 * @return 1 ok
 * 			0 error en punteros o tamano
 */
int passengers_entryType(int* type, sTypePassenger* list, int len){
	int retOk = 0;
	if(type != NULL && list != NULL && len > 0){
        typeP_printTypes(list, len);
		input_IntegerNumber(type, "Ingrese Id de Tipo de Pasajero: ", "ERROR. ");
		while(!typeP_isValidType(list, len, *type)){
            input_IntegerNumber(type, "Valor invalido. Ingrese Id de Tipo de Pasajero: ", "ERROR. ");
		}
		retOk = 1;
	}
	return retOk;
}
int passengers_entryPrice(float* price){
	int retOk = 0;
	if(price != NULL){
		input_DecimalNumberMin(price, "Ingrese precio: ", "Error. ", 1, "Valor fuera de rango. ");
		retOk = 1;
	}
	return retOk;
}

//------------------------------
int passengers_findFree(sPassenger list[], int len, int* pIndex){
	int retOk = 0;
	*pIndex = -1; //sin lugar vacio
	if(list != NULL && len > 0){
		for(int i=0; i < len; i++){
			if(list[i].isEmpty){
				*pIndex = i;
				break;
			}
		}
		retOk = 1;
	}
	return retOk;
}
/**
 * carga todos los atributos de un pasajero en variables.
 * carga a un pasajero con estos atributos
 * busca un lugar libre en un lista y ,si puede, lo agrega
 * @param passengers
 * @param lenP
 * @param types
 * @param lenT
 * @param codes
 * @param lenC
 * @param pNextId
 * @return 0: error, no hay lugar o algo ocurrio al setear los atributos del pasajero
 * 			1: carga exitosa
 */
int passengers_entryPassenger(sPassenger passengers[], int lenP, sTypePassenger types[], int lenT, sFlycode codes[], int lenC, int* pNextId){
	int retOk = 0;
    int index;
	sPassenger passengerAux;
	if (passengers != NULL && lenP > 0 && types != NULL && lenT > 0 && codes != NULL && lenC > 0 && pNextId) {

		passengers_findFree(passengers, lenP, &index);
		if (index != -1) {
			if (passengers_entryName(passengerAux.name)&&
                passengers_entryLastaName(passengerAux.lastname) &&
                passengers_entryFlycode(passengerAux.flycode, codes, lenC) &&
                passengers_entryType(&passengerAux.typePassenger,types, lenT) &&
                passengers_entryPrice(&passengerAux.price) &&
                passengers_setStatusFlight(codes, lenC, passengerAux.flycode, &passengerAux.statusFlight) &&
                passengers_setId(&passengerAux.id, pNextId)){

                retOk = passangers_addPassenger(passengers, lenP, passengerAux.name, passengerAux.lastname, passengerAux.flycode, passengerAux.typePassenger, passengerAux.price, passengerAux.statusFlight, passengerAux.id, index);
			}else{
                printf("Algo ocurrio mal.\n");
			}

		} else {
			printf("No hay lugar disponible.\n");
		}
	}

	return retOk;
}
/**
 * agrega un pasjero en un lista en el indice indicado
 * @param list
 * @param len
 * @param name
 * @param lastName
 * @param flycode
 * @param type
 * @param price
 * @param statusFlight
 * @param idea
 * @param index: indice en el que se agrega el pasajero
 * @return 0 error
 * 			1 ok
 */
int passangers_addPassenger(sPassenger list[], int len, char name[], char lastName[], char flycode[], int type, float price, int statusFlight, int idea, int index){
    int retOk = 0;
    if(list != NULL && len > 0 && name != NULL && lastName != NULL){
        list[index].id = idea;
        strcpy(list[index].name, name);
        strcpy(list[index].lastname, lastName);
        strcpy(list[index].flycode, flycode);
        list[index].typePassenger = type;
        list[index].price = price;
        list[index].statusFlight = statusFlight;
        list[index].isEmpty = 0;
        retOk = 1;
    }

    return retOk;
}



int passengers_menuModify(){

	int opcion;

	printf("\n***Modificar Empleado***\n");
	printf("--------------------------\n");
	printf("1- Nombre.\n");
	printf("2- Apellido.\n");
	printf("3- Precio.\n");
	printf("4- Codigo de vuelo.\n");
	printf("5- Tipo de Pasajero.\n");
	printf("6- Salir\n");
	input_IntNumberMinMax(&opcion, "Ingrese opcion: ", "ERROR, valor invalido. ", 1, 6, "ERROR, opcion Invalida");
	return opcion;
}
int passengers_findId(sPassenger* list, int len, int id, int* pIndice){
	int retOk = 0;
	if (list != NULL && len > 0 && pIndice != NULL) {
		*pIndice = -1;//id no existe
		for(int i = 0; i<len; i++) {
			if(id == list[i].id && list[i].isEmpty == 0){
				*pIndice = i;
				break;
			}
		}
		retOk = 1;
	}
	return retOk;
}
int passengers_modifyPassenger(sPassenger passengers[], int lenP, sTypePassenger types[], int lenT, sFlycode codes[], int lenC, int* pNextId){
	int retOk = 0;
	int index;
	int id;
	char confirm;

	//campos auxiliares
	char auxName[20];
	char auxLastname[20];
	char auxFlycode[20];
	float auxPrice;
	int auxType;

	if (passengers != NULL && lenP > 0 && types != NULL && lenT > 0 && codes != NULL && lenC > 0 && pNextId) {
		passengers_printPassengers(passengers, lenP, types, lenT, codes, lenC);
		input_IntNumberMin(&id, "Ingrese id: ", "ERROR. ", 1,"Valor invalido. ");
		if (passengers_findId(passengers, lenP, id, &index)) {
			if (index == -1) {
				printf("El id %d no esta registrado en el sistema.\n", id);
			} else {
				passengers_printPassenger(passengers[index], types, lenT, codes, lenC);
				switch(passengers_menuModify()){
				case 1:
					passengers_entryName(auxName);
					confirm = input_ClosedQuestion("Confirma el cambio? [s/n] ", "ERROR, opcion invalida. ");
					if(confirm == 's'){
						strcpy(passengers[index].name, auxName);
						printf("Modificacion realizada con exito.\n");
					}
					break;
				case 2:
				    passengers_entryLastaName(auxLastname);
					confirm = input_ClosedQuestion("Confirma el cambio? [s/n] ", "ERROR, opcion invalida. ");
					if(confirm == 's'){
						strcpy(passengers[index].lastname, auxLastname);
						printf("Modificacion realizada con exito.\n");
					}
					break;
				case 3:
					passengers_entryPrice(&auxPrice);
					confirm = input_ClosedQuestion("Confirma el cambio? [s/n] ", "ERROR, opcion invalida. ");
					if(confirm == 's'){
						passengers[index].price = auxPrice;
						printf("Modificacion realizada con exito.\n");
					}
					break;
				case 4:
					passengers_entryFlycode(auxFlycode, codes, lenC);
					confirm = input_ClosedQuestion("Confirma el cambio? [s/n] ", "ERROR, opcion invalida. ");
					if(confirm == 's'){
						strcpy(passengers[index].flycode, auxFlycode);
						passengers_setStatusFlight(codes, lenC, passengers[index].flycode, &passengers[index].statusFlight);
						printf("Modificacion realizada con exito.\n");
					}
					break;
				case 5:
					passengers_entryType(&auxType, types, lenT);
					confirm = input_ClosedQuestion("Confirma el cambio? [s/n] ", "ERROR, opcion invalida. ");
					if(confirm == 's'){
						passengers[index].typePassenger = auxType;
						printf("Modificacion realizada con exito.\n");
					}
					break;
				}
			}
		}
	}
	return retOk;
}
int passengers_removePassenger(sPassenger passengers[], int lenP, sTypePassenger types[], int lenT, sFlycode codes[], int lenC){
	int retOk = 0;
	int index;
	int id;
	char confirm;
	if(passengers !=NULL && lenP > 0 && codes !=NULL && lenC > 0 && types !=NULL && lenT > 0){
		passengers_printPassengers(passengers, lenP, types, lenT, codes, lenC);
		input_IntNumberMin(&id, "Ingrese id: ", "ERROR. ", 1, "Valor invalido. ");
		if(passengers_findId(passengers, lenP, id, &index)){
			if(index == -1){
				printf("El id %d no esta registrado en el sistema\n", id);
			} else {
				passengers_printPassenger(passengers[index], types, lenT, codes, lenC);
				confirm = input_ClosedQuestion("Confirma la baja? [s/n] ", "ERROR. ");
				if(confirm == 's'){
					passengers[index].isEmpty = 1;
					retOk = 1;
				} else {
					printf("Baja cancelada\n");
				}
			}
		}
	}
	return retOk;
}
int passengers_sort(sPassenger passengers[], int len, sTypePassenger types[], int lenT, int order){
    int retOk = -1;
    sPassenger auxPassenger;

    char typeI[20];
    char typeJ[20];

    if( passengers != NULL && len > 0 && types != NULL && lenT > 0 && (order == 1 || order == 0)){
        for(int i=0; i < len - 1; i++){
            for(int j= i+1; j < len; j++){
            	typeP_loadType(types, lenT, passengers[i].typePassenger, typeI);
                typeP_loadType(types, lenT, passengers[j].typePassenger, typeJ);
                if( (((strcmp(typeI, typeJ) > 0) ||
                    (strcmp(typeI, typeJ) == 0 && (strcmp(passengers[i].lastname, passengers[j].lastname) > 0))) && order == 1) ||
					(((strcmp(typeI, typeJ) < 0) ||
                	(strcmp(typeI, typeJ) == 0 && (strcmp(passengers[i].lastname, passengers[j].lastname) < 0))) && order == 0)  ){

                    auxPassenger = passengers[i];
                    passengers[i] = passengers[j];
                    passengers[j] = auxPassenger;
                }
            }
        }
        retOk = 0;
    }
    return retOk;
}
int passengers_sortByCode(sPassenger passengers[], int len, sFlycode codes[], int lenC, int order){
    int retOk = -1;
    sPassenger auxPassenger;

    char statusI[20];
    char statusJ[20];

    if( passengers != NULL && len > 0 && codes != NULL && lenC > 0 && (order == 1 || order == 0)){
        for(int i=0; i < len - 1; i++){
            for(int j= i+1; j < len; j++){
				flycode_loadStatus(codes, lenC, passengers[i].flycode, statusI);
            	flycode_loadStatus(codes, lenC, passengers[j].flycode, statusJ);
                if( ( ((strcmp(statusI, statusJ) > 0) ||
                    (strcmp(statusI, statusJ) == 0 && (strcmp(passengers[i].flycode, passengers[j].flycode) > 0))) && order == 1 ) ||
					( ((strcmp(statusI, statusJ) < 0) ||
                	 (strcmp(statusI, statusJ) == 0 && (strcmp(passengers[i].flycode, passengers[j].flycode) < 0))) && order == 0 )  ){

                    auxPassenger = passengers[i];
                    passengers[i] = passengers[j];
                    passengers[j] = auxPassenger;
                }
            }
        }
        retOk = 0;
    }
    return retOk;
}
int passengers_MenuLists(){
	int opcion;
	printf("\n***Informes***\n");
	printf("---------------\n");
	printf("1- Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero.\n");
	printf("2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n");
	printf("3- Listado de los pasajeros por Codigo de vuelo y estados de vuelos ‘ACTIVO’\n");
	printf("4- Salir\n");
	input_IntNumberMinMax(&opcion, "Ingrese opcion: ", "ERROR, valor invalido. ", 1, 4, "ERROR, opcion Invalida");
	return opcion;
}
int passengers_Lists(sPassenger passengers[], int lenP, sTypePassenger types[], int lenT, sFlycode codes[], int lenC){
    int retOk = 0;
    if(passengers != NULL && lenP > 0 && types != NULL && lenT > 0 && codes != NULL && lenC > 0){
    	int order;
        char salir = 'n';
        do{
            switch(passengers_MenuLists()){
            case 1:
            	input_IntNumberMinMax(&order, "Ingrese orden [1/0]: ", "Error. ", 0, 1, "Valor fuera de rango. ");
                passengers_sort(passengers, lenP, types, lenT, order);
                passengers_printPassengers(passengers, lenP, types, lenP, codes, lenC);
                break;
            case 2:
            	passengers_listsOption2(passengers, lenP);
                break;
            case 3:
            	passengers_sortByCode(passengers, lenP, codes, lenC, 1);
            	passengers_listsOption3(passengers, lenP, types, lenT, codes, lenC);
                break;

            case 4:
                salir = 's';
                break;
            }
        }while(salir != 's');
        retOk = 1;
    }
    return retOk;
}
int passengers_listsOption3(sPassenger list[], int len, sTypePassenger types[], int lenT, sFlycode codes[], int lenC){
	int retOK = 0;
	int flag = 1;
	if(list != NULL && len > 0 && types != NULL && lenT > 0 && codes != NULL && lenC > 0){

        printf("\n       *** LISTA DE PASAJEROS POR CODIGO DE VUELO Y ESTADO ACTIVO ***\n");
        printf(" id   Nombre     Apellido      Precio       Flycode  TipoPasajero  EstadoVuelo\n");
        printf("------------------------------------------------------------------------------\n");
		for (int i=0; i < len; i++){
			if(!list[i].isEmpty && list[i].statusFlight){
                passengers_printPassengerRow(list[i], types, lenT, codes, lenC);
				flag=0;
			}
		}
		if(flag){
			printf("no hay pasajeros en el sistema\n");
		}
		retOK = 1;
	}
    return retOK;
}
int passengers_listsOption2(sPassenger passengers[], int len){
	int retOk = 0;
	if(passengers != NULL && len > 0){
		float totalPrice = 0;
		float averagePrice;
		int q = 0;
		int qPassengersOverAverage = 0;
		for(int i = 0; i < len; i++){
			if(!passengers[i].isEmpty){
				totalPrice = totalPrice + passengers[i].price;
				q++;
			}
		}
		if(q != 0){
			averagePrice = totalPrice / q;
			for(int i=0; i < len; i++){
				if(!passengers[i].isEmpty && passengers[i].price > averagePrice){
					qPassengersOverAverage++;
				}
			}
			printf("Precio por el total de pasajes: $%.2f\n", totalPrice);
			printf("Precio promedio de pasajes: &%.2f\n", averagePrice);
			printf("Total de pasajeros que superan el precio promedio de los pasajes: %d\n", qPassengersOverAverage);
		}
	}
	return retOk;
}
