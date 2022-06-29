#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>

#include "parser.h"
#include "Controller.h"
#include "Passenger.h"
#include "flight.h"
#include "inputs.h"
#include "dataInput.h"



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int returnAux = -1;
	if(path != NULL && pArrayListPassenger != NULL){
		returnAux = -2; // pfile null
		FILE* pFile = NULL;
		pFile = fopen(path,"r");
		if(pFile != NULL) {
			returnAux = 0;
			returnAux = parser_PassengerFromText(pFile, pArrayListPassenger);
		}
		fclose(pFile);
	}
	return returnAux;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int returnAux = -1;
	if(pArrayListPassenger != NULL && path != NULL){
		returnAux = -2;// pfile null
		FILE* pFile = NULL;
		pFile = fopen(path,"rb");
		if(pFile!=NULL){
			returnAux = 0;//minimamente abrio el archivo
			returnAux = parser_PassengerFromBinary(pFile, pArrayListPassenger);
		}
		fclose(pFile);
	}
	return returnAux;
}

int controller_loadFromTextFlight(char* path , LinkedList* pArrayListFlights)
{
	int returnAux = -1;
	if(path != NULL && pArrayListFlights != NULL){
		FILE* pFile;
		pFile = fopen(path,"r");
		if(pFile != NULL) {
			returnAux = 0;
			returnAux = parser_FlightFromText(pFile, pArrayListFlights);
			fclose(pFile);
		}
	}
	return returnAux;
}
//----------------------------------------------------------------

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlight, int* id)
{
	int returnAux = -1;
	if(pArrayListPassenger != NULL && id != NULL) {
		returnAux = 0;//los puntero no son null y no se pudo agregar un pasajero
		char nombre[20];
		char apellido[20];
		float precio;
		char codigoVuelo[20];
		int tipoPasajero;
		int statusFlight;

		printf("****************************************************************************\n");
		printf("Alta Pasajero\n");
		printf("****************************************************************************\n");
		//if(!(dataInput_loadParametros(nombre, apellido, &precio, codigoVuelo, &tipoPasajero, &statusFlight))){
		if(!dataInput_nombre(nombre) &&
			!dataInput_apellido(apellido) &&
			!dataInput_precio(&precio) &&
			!controller_inputFlightCode(pArrayListFlight, codigoVuelo) &&
			!dataInput_tipo(&tipoPasajero) &&
			!controller_loadStatusFlight(pArrayListFlight, codigoVuelo, &statusFlight)){

			sPassenger* pPassenger = Passenger_newParametros(*id, nombre, apellido, precio, codigoVuelo, tipoPasajero, statusFlight);
			if(pPassenger!= NULL){
				if(!ll_add(pArrayListPassenger, pPassenger)){
					(*id)++;
					returnAux = 1;//los punteros no son null y se agrego un elemento al lklist
				}
			}
		}else{
			printf("No se pudo cargar el pasajero\n");
		}
	}
	return returnAux;

}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlight)
{
	int returnAux = -1;
	if(pArrayListPassenger != NULL && pArrayListFlight != NULL){
		controller_editMenu(pArrayListPassenger, pArrayListFlight);
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	 int returnAux = -1;
	    if(pArrayListPassenger != NULL){
		sPassenger* passengerAux;
		int index;
		int idPassenger;
		char confirm;

		controller_ListPassenger(pArrayListPassenger);
		printf("****************************************************************************\n");
		printf("Baja Pasajero\n");
		printf("****************************************************************************\n");
		controller_inputIdPassenger(pArrayListPassenger, &idPassenger);
		controller_searchIdPasajero(pArrayListPassenger, idPassenger, &index);
		if(index != -1){
			passengerAux = (sPassenger*)ll_get(pArrayListPassenger, index);
			Passenger_showPassengerColumns(passengerAux);
			confirm = input_ClosedQuestion("Este empleado se eliminara, desea continuar? [S/N]", "Error, opcion invalida \n");
			if(confirm == 's'){
				if(!ll_remove(pArrayListPassenger, index)){
					Passenger_delete(passengerAux);
					printf("El pasajero ingresado fue eliminado con exito\n");
					returnAux = 0;
				}
			}
		}
	}
	return returnAux;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int returnAux = -1;
	int len;
	sPassenger *pPassenger;
	if (pArrayListPassenger != NULL) {
		printf("||ID  ||NOMBRE      ||APELLIDO    ||PRECIO    ||CODIGO     ||TIPO            ||ESTADO      ||\n");
		len = ll_len(pArrayListPassenger);
		for (int i = 0; i < len; i++) {
			pPassenger = ll_get(pArrayListPassenger, i);

			Passenger_showPassenger(pPassenger);
		}
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassengerId(LinkedList* pArrayListPassenger, int order)
{
	int returnAux = -1;
	if (pArrayListPassenger != NULL && (order == 0 || order == 1)) {
		if(!ll_sort(pArrayListPassenger, Passenger_compareByID, order)){
		returnAux = 0;
		}
	}
	return returnAux;
}
int controller_sortPassengerName(LinkedList* pArrayListPassenger, int order)
{
	int returnAux = -1;
	if (pArrayListPassenger != NULL && (order == 0 || order == 1)) {
		if(!ll_sort(pArrayListPassenger, Passenger_compareByName, order)){
		returnAux = 0;
		}
	}
	return returnAux;
}
int controller_sortPassengerLastname(LinkedList* pArrayListPassenger, int order)
{
	int returnAux = -1;
	if (pArrayListPassenger != NULL && (order == 0 || order == 1)) {
		if(!ll_sort(pArrayListPassenger, Passenger_compareByLastname, order)){
		returnAux = 0;
		}
	}
	return returnAux;
}
int controller_sortPassengerPrice(LinkedList* pArrayListPassenger, int order)
{
	int returnAux = -1;
	if (pArrayListPassenger != NULL && (order == 0 || order == 1)) {
		if(!ll_sort(pArrayListPassenger, Passenger_compareByPrice, order)){
		returnAux = 0;
		}
	}
	return returnAux;
}
int controller_sortPassengerType(LinkedList* pArrayListPassenger, int order)
{
	int returnAux = -1;
	if (pArrayListPassenger != NULL && (order == 0 || order == 1)) {
		if(!ll_sort(pArrayListPassenger, Passenger_compareByType, order)){
		returnAux = 0;
		}
	}
	return returnAux;
}
int controller_sortPassengerFlightCode(LinkedList* pArrayListPassenger, int order)
{
	int returnAux = -1;
	if (pArrayListPassenger != NULL && (order == 0 || order == 1)) {
		if(!ll_sort(pArrayListPassenger, Passenger_compareByFlightCode, order)){
		returnAux = 0;
		}
	}
	return returnAux;
}
int controller_sortPassengerStatus(LinkedList* pArrayListPassenger, int order)
{
	int returnAux = -1;
	if (pArrayListPassenger != NULL && (order == 0 || order == 1)) {
		if(!ll_sort(pArrayListPassenger, Passenger_compareByStatus, order)){
		returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int returnAux = -1;
	int len;
	int i;
	sPassenger* pAux;
	if (pArrayListPassenger != NULL){
		char estado[20];
		char tipo[20];
		len = ll_len(pArrayListPassenger);
		FILE* pFile;
		pFile = fopen(path,"w");
		fprintf(pFile,"id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo\n");
		if(pFile!=NULL && len > 0){
			for(i=0; i<len; i++){
				pAux = ll_get(pArrayListPassenger, i);
				if(pAux!=NULL){
					Passenger_statusFInttoStr(pAux->statusFlight, estado);
					Passenger_typeInttoStr(pAux->tipoPasajero, tipo);
					fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n",pAux->id,
												  	  pAux->nombre,
													  pAux->apellido,
													  pAux->precio,
													  pAux->codigoVuelo,
													  tipo,
													  estado);
				}else{
					break;
				}
			}
			if(i == len){
				returnAux = 0;
			}
		}
		fclose(pFile);
	}
	return returnAux;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int returnAux= -1;
	int len;
	int i;
	sPassenger* pAux;
	if (pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);
		FILE* pFile;
		pFile = fopen(path,"wb");
		if(pFile!=NULL && len > 0){
			for(i=0; i<len; i++){
				pAux = ll_get(pArrayListPassenger, i);
				if(pAux!=NULL){
					fwrite(pAux,sizeof(sPassenger),1,pFile);
				}
				else{
					break;
				}
			}
			if(i == len){
				returnAux = 0;
			}
		}
		fclose(pFile);
	}

	return returnAux;
}

//--------------------------------------------------------

int controller_loadStatusFlight(LinkedList* pArrayListFlight, char* flightCode, int* statusFlight){
	int returnAux = -1;
	sFlight* pFlight = NULL;
	char flightCodeAux[10];
	if(pArrayListFlight != NULL && flightCode != NULL && statusFlight != NULL){
		int len = ll_len(pArrayListFlight);
		for(int i = 0; i < len; i++){
			pFlight = ll_get(pArrayListFlight, i);
			Flight_getCodigoVuelo(pFlight, flightCodeAux);
			if(strcmp(flightCode, flightCodeAux) == 0){
				Flight_getStatusFlight(pFlight, statusFlight);
				returnAux = 0;
				break;
			}
		}
	}
	return returnAux;
}
int controller_isValidFlightCode(LinkedList* pArrayListFlight, char* flightCode){
	int returnAux = 0;
	sFlight* pFlight = NULL;
	if(pArrayListFlight != NULL && flightCode != NULL){
		int len = ll_len(pArrayListFlight);
		char flightCodeAux[10];

		for(int i = 0; i < len; i++){
			pFlight = ll_get(pArrayListFlight, i);
			Flight_getCodigoVuelo(pFlight, flightCodeAux);
			if(strcmp(flightCode, flightCodeAux) == 0){
				returnAux = 1;
				break;
			}
		}
	}
	return returnAux;
}
int controller_inputFlightCode(LinkedList* pArrayListFlight, char* flightCode){
	int returnAux = -1;
	if(pArrayListFlight != NULL && flightCode != NULL){
		int counter = 0;
		controller_ListFlight(pArrayListFlight);
		dataInput_codigo(flightCode);
		while(!(controller_isValidFlightCode(pArrayListFlight, flightCode))){
			counter++;
			if(counter == 3){
				break;
			}else{
				printf("Codigo invalido. ");
				dataInput_codigo(flightCode);
			}
		}
		if(counter < 3){
			returnAux = 0;
		}
	}
	return returnAux;
}
int controller_searchIdPasajero(LinkedList* pArrayPassenger, int id, int* index){
	int returnAux = -1;
	sPassenger* passengerAux;
	int idAux;
	if(pArrayPassenger != NULL && index != NULL){
		*index = -1;
		int len = ll_len(pArrayPassenger);
		for(int i = 0; i < len; i++){
			passengerAux = ll_get(pArrayPassenger, i);
			Passenger_getId(passengerAux, &idAux);
			if(idAux == id){
				*index = i;
				break;
			}
		}
		returnAux = 0;
	}
	return returnAux;
}
int controller_isPassengerIdValid(LinkedList* pArray, int id){
	int returnAux = 0;
	int index;
	if(pArray != NULL){
		if(!controller_searchIdPasajero(pArray, id, &index)){
			if(index != -1){
				returnAux = 1;
			}
		}
	}
	return returnAux;
}
int controller_inputIdPassenger(LinkedList* pArray, int* id){
	int returnAux = -1;
	if(pArray != NULL && id != NULL){
		int counter = 0;

		dataInput_id(id);
		while(!(controller_isPassengerIdValid(pArray, *id))){
			counter++;
			if(counter == 3){
				break;
			}else{
				printf("Id invalida. ");
				dataInput_id(id);
			}
		}
		if(counter < 3){
			returnAux = 0;//se cargo dato valido
		}
	}
	return returnAux;
}
int controller_editMenu_option(){
	int option;
	printf("****************************************************************************\n");
	printf("Modificar Pasajero\n");
	printf("****************************************************************************\n");
	printf("Campos:\n");
	printf("1. Nombre.\n");
	printf("2. Apellido.\n");
	printf("3. Precio.\n");
	printf("4. Codigo de vuelo.\n");
	printf("5. Tipo de Pasajero\n");
	printf("6. Salir\n");
	printf("*****************************************************************************\n");
	input_IntNumberMinMax(&option, "Ingrese la opcion deseada: ", "Error, valor incorrecto. ",1,6, "Valor fuera de rango. ");
	return option;
}
void controller_editMenu(LinkedList* pArrayPassenger, LinkedList* pArrayFlight){
	if(pArrayPassenger != NULL && pArrayFlight != NULL){
		char confirm;

		int id;
		int index;

		char nombre[20];
		char apellido[20];
		float precio;
		char codigoVuelo[10];
		int tipoPasajero;
		int statusFlight;

		sPassenger* passengerAux = NULL;

		controller_ListPassenger(pArrayPassenger);
		if(!(controller_inputIdPassenger(pArrayPassenger, &id))){
			controller_searchIdPasajero(pArrayPassenger, id, &index);
			passengerAux = ll_get(pArrayPassenger, index);
			Passenger_showPassengerColumns(passengerAux);

			switch(controller_editMenu_option()){
			case 1:
				dataInput_nombre(nombre);
				confirm = input_ClosedQuestion("Ha realizado un cambio, desea continuar? [s/n]: ", "Error. ");
				if(confirm == 's'){
					Passenger_setNombre(passengerAux, nombre);
				}
				break;
			case 2:
				dataInput_apellido(apellido);
				confirm = input_ClosedQuestion("Ha realizado un cambio, desea continuar? [s/n]: ", "Error. ");
				if(confirm == 's'){
					Passenger_setApellido(passengerAux, apellido);
				}
				break;
			case 3:
				dataInput_precio(&precio);
				confirm = input_ClosedQuestion("Ha realizado un cambio, desea continuar? [s/n]: ", "Error. ");
				if(confirm == 's'){
					Passenger_setPrecio(passengerAux, precio);
				}

				break;
			case 4:
				controller_inputFlightCode(pArrayFlight, codigoVuelo);
				controller_loadStatusFlight(pArrayFlight, codigoVuelo, &statusFlight);
				confirm = input_ClosedQuestion("Ha realizado un cambio, desea continuar? [s/n]: ", "Error. ");
				if(confirm == 's'){
					Passenger_setCodigoVuelo(passengerAux, codigoVuelo);
					Passenger_setStatusFlight(passengerAux, statusFlight);
				}
				break;
			case 5:
				dataInput_tipo(&tipoPasajero);
				confirm = input_ClosedQuestion("Ha realizado un cambio, desea continuar? [s/n]: ", "Error. ");
				if(confirm == 's'){
					Passenger_setTipoPasajero(passengerAux, tipoPasajero);
				}
				break;
			default:
				printf("---opcion invalida---\n");
				break;
			}
		}
	}
}
int controller_sortMenuOption(){
	int option;
	printf("****************************************************************************\n");
	printf("Ordenar Pasajeros\n");
	printf("****************************************************************************\n");
	printf("Ordenar por:\n");
	printf("1. Id.\n");
	printf("2. Nombre.\n");
	printf("3. Apellido.\n");
	printf("4. Precio.\n");
	printf("5. Codigo de vuelo.\n");
	printf("6. Tipo de Pasajero\n");
	printf("7. Estado de Vuelo\n");
	printf("8. Salir\n");
	printf("*****************************************************************************\n");
	input_IntNumberMinMax(&option, "Ingrese la opcion deseada: ", "Error, valor incorrecto. ",1,8, "Valor fuera de rango. ");
	return option;
}
void controller_sortMenu(LinkedList* pArray)
{
	int option;
	int order;
	LinkedList* pClon;
	pClon = ll_clone(pArray);
	if(pArray != NULL && pClon!= NULL){
		do{
			switch(controller_sortMenuOption()){
				case 1:
					input_MenuOption(&option, "--ORDEN--\n1.Ascendente\n2.Descendente\n3.Salir\n", "Valor invalido. ", 1, 2, 3, "Valor fuera de rango ");
					if(option == 1){
						order = 1;
					}else{
						order = 0;
					}
					controller_sortPassengerId(pClon, order);
					controller_ListPassenger(pClon);
					break;
				case 2:
					input_MenuOption(&option, "--ORDEN--\n1.Ascendente\n2.Descendente\n3.Salir\n", "Valor invalido. ", 1, 2, 3, "Valor fuera de rango ");
					if(option == 1){
						order = 1;
					}else{
						order = 0;
					}
					controller_sortPassengerName(pClon, order);
					controller_ListPassenger(pClon);
					break;
				case 3:
					input_MenuOption(&option, "--ORDEN--\n1.Ascendente\n2.Descendente\n3.Salir\n", "Valor invalido. ", 1, 2, 3, "Valor fuera de rango ");
					if(option == 1){
						order = 1;
					}else{
						order = 0;
					}
					controller_sortPassengerLastname(pClon, order);
					controller_ListPassenger(pClon);
					break;
				case 4:
					input_MenuOption(&option, "--ORDEN--\n1.Ascendente\n2.Descendente\n3.Salir\n", "Valor invalido. ", 1, 2, 3, "Valor fuera de rango ");
					if(option == 1){
						order = 1;
					}else{
						order = 0;
					}
					controller_sortPassengerPrice(pClon, order);
					controller_ListPassenger(pClon);
					break;
				case 5:
					if(option == 1){
						order = 1;
					}else{
						order = 0;
					}
					input_MenuOption(&option, "--ORDEN--\n1.Ascendente\n2.Descendente\n3.Salir\n", "Valor invalido. ", 1, 2, 3, "Valor fuera de rango ");
					controller_sortPassengerFlightCode(pClon, order);
					controller_ListPassenger(pClon);
					break;
				case 6:
					input_MenuOption(&option, "--ORDEN--\n1.Ascendente\n2.Descendente\n3.Salir\n", "Valor invalido. ", 1, 2, 3, "Valor fuera de rango ");
					if(option == 1){
						order = 1;
					}else{
						order = 0;
					}
					controller_sortPassengerType(pClon, order);
					controller_ListPassenger(pClon);
					break;
				case 7:
					input_MenuOption(&option, "--ORDEN--\n1.Ascendente\n2.Descendente\n3.Salir\n", "Valor invalido. ", 1, 2, 3, "Valor fuera de rango ");
					if(option == 1){
						order = 1;
					}else{
						order = 0;
					}
					controller_sortPassengerStatus(pClon, order);
					controller_ListPassenger(pClon);
					break;
				case 8:
					option = 8;
					break;
			}
		}while(option != 8);
		ll_clear(pClon);
		ll_deleteLinkedList(pClon);
	}
}
int controller_menu_option() {
	int option;
	printf("****************************************************************************\n");
	printf("Trabajo practico 3 - Implementacion biblioteca LinkedList \n");
	printf("Aerolinea \n");
	printf("****************************************************************************\n");
	printf("Menu:\n");
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
	printf("3. Alta de pasajero\n");
	printf("4. Modificar datos de pasajero\n");
	printf("5. Baja de pasajero\n");
	printf("6. Listar pasajero\n");
	printf("7. Ordenar pasajero\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
	printf("10. Salir\n");
	printf("*****************************************************************************\n");
	input_IntegerNumber(&option, "Ingrese la opcion deseada: ", "Error, valor incorrecto \n");
	return option;
}

void controller_Menu(LinkedList *pArrayListPassenger, LinkedList *pArrayListFlight) {
	if(pArrayListFlight != NULL && pArrayListFlight != NULL){
		int option;
		int qVuelos;
		int cant = 0;
		int pId = 1;
		int isSaved = 1;
		int isLoaded = 0;
		char salir = 'n';
		char path[50];
		char confirm;

		qVuelos = controller_loadFromTextFlight("vuelos.csv", pArrayListFlight);
		printf("Se cargaron %d vuelos con exito...\n", qVuelos );

		do {
			option = controller_menu_option();
			switch (option) {
			case 1:
				if(isLoaded == 1){
					confirm = input_ClosedQuestion("Ya hay una lista en memoria. Si no guarda la lista se perdera el trabajo, desea continuar de todas formas?[s/n]", "Error. ");
					if(confirm == 'n'){
						printf("Carga cancelada.\n");
						break;
					}
				}
				if(input_strFileFormat(path, 50, "Nombre del archivo (sugerido data.csv): ", "Error. ") == 0){
					if(isThereFileTxt(path) && isStrFileFormat(path) == 1){
						ll_clear(pArrayListPassenger);
						cant = controller_loadFromText(path, pArrayListPassenger);
						controller_getMaxId(pArrayListPassenger, &pId);
						printf("Se cargaron %d pasajeros.\n", cant);
						isSaved = 0;
						isLoaded = 1;
					}else{
						printf("Archivo inexistente o formato incorrecto.\n");
					}
				}
				break;
			case 2:
				if(isLoaded == 1){
					confirm = input_ClosedQuestion("Ya hay una lista en memoria. Si no guarda la lista se perdera el trabajo, desea continuar de todas formas?[s/n]", "Error. ");
					if(confirm == 'n'){
						printf("Carga cancelada.\n");
						break;
					}
				}
				if(input_strFileFormat(path, 50, "Nombre del archivo: ", "Error. ") == 0){
					if(isThereFileBin(path) && isStrFileFormat(path) == 2){
						ll_clear(pArrayListPassenger);
						cant = controller_loadFromBinary(path, pArrayListPassenger);
						controller_getMaxId(pArrayListPassenger, &pId);
						printf("Se cargaron %d pasajeros.\n", cant);
						isSaved = 0;
						isLoaded = 1;
					}else{
						printf("Archivo inexistente o formato incorrecto.\n");
					}
				}
				break;
			case 3:
				if(controller_addPassenger(pArrayListPassenger, pArrayListFlight, &pId) == 1){
					printf("Pasajero cargado con exito.\n");
					isSaved = 0;
					isLoaded = 1;
				}
				break;
			case 4:
				if(ll_len(pArrayListPassenger) > 0){
					if(controller_editPassenger(pArrayListPassenger, pArrayListFlight) == 0)
					isSaved = 0;
				}else{
					printf("No hay elementos cargados para editar. Debe ingresar o cargar pasajeros.\n");
				}
				break;
			case 5:
				if(ll_len(pArrayListPassenger) > 0){
					if(controller_removePassenger(pArrayListPassenger) == 0){
						printf("Pasajero dado de baja con exito. \n");
						isSaved = 0;
					}
				}else{
					printf("No hay elementos cargados para dar de baja. Debe ingresar o cargar pasajeros.\n");
				}
				break;
			case 6:
				if(ll_len(pArrayListPassenger) > 0){
					controller_ListPassenger(pArrayListPassenger);
				}else{
					printf("No hay elementos cargados que mostrar. Debe ingresar o cargar pasajeros.\n");
				}
				break;
			case 7:
				if(ll_len(pArrayListPassenger) > 0){
					controller_sortMenu(pArrayListPassenger);
				}else{
					printf("No hay elementos cargados para ordenar. Debe ingresar o cargar pasajeros.\n");
				}
				break;
			case 8:
				input_strFileFormat(path, 50, "Nombre del archivo (extension csv/txt): ", "Error. Nombre del archivo (extension csv/txt): ");
				while(isStrFileFormat(path) == 2){
					input_strFileFormat(path, 50, "Error. Nombre del archivo (extension csv/txt): ", "Error. Nombre del archivo (extension csv/txt):");
				}
				if(isThereFileBin(path) == 1){
					confirm = input_ClosedQuestion("Existe un archivo con ese nombre, desea sobreescribirlo?[s/n]", "Valor invalido. ");
					if(confirm == 's'){
						controller_saveAsText(path, pArrayListPassenger);
						printf("El archivo se guardo con exito.\n");
						isSaved = 1;
					}else{
						printf("Archivado de datos cancelado.\n");
					}
				}else{
					controller_saveAsText(path, pArrayListPassenger);
					printf("El archivo se guardo con exito.\n");
					isSaved = 1;
				}
				break;
			case 9:
				input_strFileFormat(path, 50, "Nombre del archivo (extension bin/dat): ", "Error. Nombre del archivo (extension bin/dat): ");
					while(isStrFileFormat(path) == 1){
						input_strFileFormat(path, 50, "Error. Nombre del archivo (extension bin/dat): ", "Error. Nombre del archivo (extension bin/dat):");
					}
				if(isThereFileBin(path) == 1){
					confirm = input_ClosedQuestion("Existe un archivo con ese nombre, desea sobreescribirlo?[s/n]", "Valor invalido. ");
					if(confirm == 's'){
						controller_saveAsBinary(path, pArrayListPassenger);
						printf("El archivo se guardo con exito.\n");
						isSaved = 1;
					}else{
						printf("Archivado de datos cancelado.\n");
					}
				}else{
					controller_saveAsBinary(path, pArrayListPassenger);
					printf("El archivo se guardo con exito.\n");
					isSaved = 1;
				}
				break;
			case 10:
				if(isSaved == 0){
					printf("No se han guardado los cambios. Guarde las modificaciones antes de salir.\n");
				}else{
					salir = 's';
					printf("Fin del programa.\n");
				}
				break;
			default:
				printf("---opcion invalida---\n");
				break;
			}
		} while (salir != 's');
	}
}
//----------------------------------------------------------
int controller_ListFlight(LinkedList* pArrayListFlight)
{
	int returnAux = -1;
	if(pArrayListFlight != NULL){
		sFlight* pFlight;
		int len;
		len = ll_len(pArrayListFlight);
		for (int i = 0; i < len; i++) {
			pFlight = ll_get(pArrayListFlight, i);
			Flight_showFlight(pFlight);
		}
		returnAux = 0;


	}
	return returnAux;
}
int controller_getMaxId(LinkedList* pArray, int* id){
	int returnAux = -1;
	int mayorId;
	int idAux;
	sPassenger* pAux;
	if(pArray != NULL && id != NULL){
		int len = ll_len(pArray);
		for(int i=0; i < len; i++){
			pAux = ll_get(pArray, i);
			Passenger_getId(pAux, &idAux);
			if(i == 0 || idAux > mayorId){
				mayorId = idAux;
			}
		}
		*id = mayorId + 1;
		returnAux = 0;
	}
	return returnAux;
}
