/*
 * calculadora.h
 *
 *  Created on: 14 abr. 2022
 *      Author: calculdora
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "inputs.h"

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

int calculadora_opcion1(float* kms, int* flagOpcion1);
int calculadora_ingresoPrecio(float* precio);
int calculadora_menuVuelos(float aeroPrecio, float latamPrecio);
int calculadora_ingresoVuelos(float *aeroPrecio, float *latamPrecio, int *flagAerolineas, int* flagLatam);
int calculadora_opcion2(int flagOpcion1, float* aeroPrecio, float* latamPrecio, int* flagPrecioAero, int* flagPrecioLatam);
int calculadora_calcularCostosPrecios(float importe, float kms, float* debito, float* credito, float* bitcoin, float* precioKm);
int calculadora_calcularDiferencia(float *diferencia, float precioAero, float precioLatam);
int calculadora_calcularTodo(float importeAero, float* debitoAero, float* creditoAero, float* btcAero, float* kmAero,
							float importeLatam, float* debitoLatam, float* creditoLatam, float* btcLatam, float* kmLatam,
							float kms, float* diferencia, int* flagCalcularTodo);
int calculadora_opcion3(float aeroPrecio, float *aeroDebito, float* aeroCredito, float* aeroBtc, float* aeroKm,
						float latamPrecio, float* latamDebito, float* latamCredito, float* latamBtc, float* latamKm,
						float kms, float* diferencia, int flagOpcion1, int flagPrecioAero, int flagPrecioLatam, int* flagCalcularTodo);
void calculadora_mostrarParcialResultado(float precioDebito, float precioCredito, float precioBitcoin, float precioUnitario);
void calculadora_mostrarResultados(float precioAero, float precioLatam, float diferencia,
									float aeroDebito, float aeroCredito, float aeroBitcoin, float aeroUnitario,
									float latamDebito, float latamCredito, float latamBitcoin, float latamUnitario);
int calculadora_opcion4(int flagOpcion1, int flagPrecioAero, int flagPrecioLatam, float aeroPrecio, int flagCalcularTodo,
						float latamPrecio, float diferencia,
						float aeroDebito, float aeroCredito, float aeroBitcoin, float aeroUnitario,
						float latamDebito, float latamCredito, float latamBitcoin, float latamUnitario);
void calculadora_opcion5();
int calculadora_resetearValores(float* aeroPrecio, float* latamPrecio, float* kms,
								int* flagOpcion1, int* flagPrecioAero, int* flagPrecioLatam, int* flagCalcularTodo);
int calculadora_menu(float kms, int flagOpcion1, int flagOp2Aerolineas, int flagOp2Latam, float precioAeroLineas, float precioLatam);
void calculacodora_calculadora();


#endif /* CALCULADORA_H_ */
