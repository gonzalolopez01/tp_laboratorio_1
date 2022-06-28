/*
 * dataInput.c
 *
 *  Created on: 11 jun. 2022
 *      Author: gon
 */

#include "dataInput.h"


int dataInput_nombre(char* nombre) {
	int success = -1;
	if(nombre!=NULL) {

		input_AlphaText(nombre, 50, "Ingrese nombre: ", "Error. Ingrese Nombre: ");
		stringToProperName(nombre);
		success = 0;
	}
	return success;
}
int dataInput_apellido(char* apellido) {
	int success = -1;
	if(apellido != NULL) {

		input_AlphaText(apellido, 50, "Ingrese apellido: ", "Error. Ingrese Nombre: ");
		stringToProperName(apellido);
		success = 0;
	}
	return success;
}
int dataInput_precio(float* precio) {
	int success = -1;
	if(precio != NULL) {
		input_DecimalNumberMin(precio, "Ingrese precio: ", "Error. ", 1, "Valor incorrecto. ");
		success = 0;
	}
	return success;
}
int dataInput_codigo(char* codigo){
	int success = -1;
	if(codigo != NULL) {
		input_Text(codigo, 10, "Ingrese codigo de vuelo: ");
		stringToUpper(codigo);
		//stringToProperName(codigo);
		success = 0;
	}
	return success;
}
int dataInput_tipo(int* tipo){
	int success = -1;
	if(tipo != NULL) {
		printf("   Tipo de Pasajero\n");
		printf("1 - FirstClass\n");
		printf("2 - ExecutiveClass\n");
		printf("3 - EconomyClass\n");
		input_IntNumberMinMax(tipo, "Ingrese tipo 1 2 3: ", "Error. ", 1, 3, "Valor, fuera de rango. ");
		success = 0;
	}
	return success;
}

int dataInput_id(int* id){
	int success = -1;
	if(id != NULL){
		input_IntNumberMin(id, "Ingrese numero de id: ", "Error. ", 1, "Valor invalido. ");
		success = 0;
	}
	return success;
}
