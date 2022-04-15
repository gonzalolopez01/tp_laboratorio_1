/*
 * operaciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: gonzalo
 */


#include "operaciones.h"

/// realiza un descuento sobre el importe
/// @param importe: valor del importe
/// @param precioDebito: guarda el precio con debito
/// @return -1 Error, no realizo su funcion, 0 se ejecuto bien
float operaciones_descontar(float importe, float* precioDebito){
	float retorno = -1;
	float descuento = 0.90;//descuento 10%

	if(precioDebito != NULL){
		*precioDebito = importe * descuento;
		retorno = 0;
	}

	return retorno;
}
/// realiza un recargo sobre el importe
/// @param importe: valor del importe
/// @param precioCredito: guarda el precio con credito
/// @return -1 Error, no realizo su funcion, 0 se ejecuto bien
float operaciones_interes(float importe, float* precioCredito){
	float retorno = -1;
	float interes = 1.25; //aumento 25%

	if(precioCredito != NULL){
		*precioCredito = importe * interes;
		retorno = 0;
	}

	return retorno;
}
/// pasa el importe de pesos a BTC
///  @param importe: valor del importe
/// @param precioBitcoin: precio actualizado del BTC
/// @return -1 Error, no realizo su funcion, 0 se ejecuto bien
float operaciones_bitcoin(float importe, float* precioBitcoin){
	float retorno = -1;
	float precioMonedaBitcoin = 4649830.87;

	if(precioBitcoin != NULL){
		*precioBitcoin = importe / precioMonedaBitcoin;
		retorno = 0;
	}

	return retorno;
}
/// obtiene el precio por km
/// @param importe: valor del importe
/// @param kms: valor de los kms
/// @param precioKilometro: guarda precio por km
/// @return -1 Error, no realizo su funcion, 0 se ejecuto bien
float operaciones_precioKilometro(float importe, float kms, float* precioKilometro){
	float retorno = -1;
	if(precioKilometro != NULL){
		*precioKilometro = importe/kms;
		retorno = 0;
	}

	return retorno;
}
