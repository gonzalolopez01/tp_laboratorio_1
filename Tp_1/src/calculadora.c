/*
 * calculadora.c
 *
 *  Created on: 14 abr. 2022
 *      Author: gonzalo
 */


#include "calculadora.h"

/// Opcion 1 del menu de opciones
/// @param kms: guarda los kilometros
/// @param flagOpcion1: flag que indica si se realizo el ingreso de kilometros
/// @return -1 Error, no realizo su funcion, 0 se ejecuto bien
int calculadora_opcion1(float* kms, int* flagOpcion1){
	int retorno = -1;
	if(kms!=NULL && flagOpcion1!=NULL){
		input_rationalNumberMin(kms, "Ingrese Kilometros: ", "Error, Ingrese Kilometros: ", 1, "Error, valor invalido, ");
		*flagOpcion1 = 0;
		retorno = 0;
	}
	return retorno;
}
//*********************************************************
/// ingresa precio
/// @param precio: guarda el precio
/// @return -1 Error, no realizo su funcion, 0 se ejecuto bien
int calculadora_ingresoPrecio(float* precio){
	int retorno = -1;
	if(precio != NULL){
		input_rationalNumberMin(precio, "Ingrese precio: ", "Error, valor invalido. ", 1, "Error, valor invalido. Ingrese precio: ");
		retorno = 0;
	}
	return retorno;
}
/// menu para el ingreso de precios
/// @param aeroPrecio: valor de precio
/// @param latamPrecio: valor de precio
/// @return retorna la opcion elegida
int calculadora_menuVuelos(float aeroPrecio, float latamPrecio){
		int opcion;
		printf("Ingreso de precios  \n");
		printf("1. Precio Aerolineas: $%.2f\n", aeroPrecio);
		printf("2. Precio Latam: $%.2f\n", latamPrecio);
		printf("3. Salir\n");

		input_IntNumberMinMax(&opcion, "", "Opcion invalida: ", 1, 3, "Valor fuera de rango. Ingrese opcion: ");

		return opcion;
}
/// realiza todos los ingresos
/// @param aeroPrecio: guarda precio
/// @param latamPrecio: guarda precio
/// @param flagAerolineas: indica si se guardo el precio o no (1 no, 0 si)
/// @param flagLatam: indica si se guardo el precio o no (1 no, 0 si)
/// @return -1 Error, no realizo su funcion, 0 se ejecuto bien
int calculadora_ingresoVuelos(float *aeroPrecio, float *latamPrecio, int *flagAerolineas, int* flagLatam){
	int retorno = -1;
	if(aeroPrecio != NULL && latamPrecio != NULL && flagAerolineas != NULL && flagLatam !=NULL){
		int opcion;

		do{
			switch(opcion = calculadora_menuVuelos(*aeroPrecio, *latamPrecio)){
			case 1:
				*flagAerolineas = calculadora_ingresoPrecio(aeroPrecio);
			break;
			case 2:
				*flagLatam = calculadora_ingresoPrecio(latamPrecio);
			break;
			}

		}while(opcion != 3);
	retorno = 0;
	}
	return retorno;
}
/// opcion 2 del menu
/// @param flagOpcion1: indica si se sentro a la opcion 1 o no (1 no, 0 si)
/// @param aeroPrecio: guarda valor de precio
/// @param latamPrecio: guarda valor de precio
/// @param flagPrecioAero: indica si se guardo el precio o no (1 no, 0 si)
/// @param flagPrecioLatam: indica si se guardo el precio o no (1 no, 0 si)
/// @return -1 Error, no realizo su funcion, 0 se ejecuto bien
int calculadora_opcion2(int flagOpcion1, float* aeroPrecio, float* latamPrecio, int* flagPrecioAero, int* flagPrecioLatam){
	int retorno = -1;
	if(aeroPrecio!=NULL && latamPrecio!=NULL && flagPrecioAero!=NULL && flagPrecioLatam!=NULL){
		if(flagOpcion1){
			printf("\nDEBE INGRESAR LOS KILOMETROS.\n\n");
		}else{
			calculadora_ingresoVuelos(aeroPrecio, latamPrecio, flagPrecioAero, flagPrecioLatam);
		}
		retorno = 0;
	}
	return retorno;
}
//******************************************************
/// realiza las operaciones sobre el precio ingresado
/// @param importe: valor del precio ingresado
/// @param kms: valor kms ingresados
/// @param debito: guarda el precio para debito
/// @param credito: guarda el precio para credito
/// @param bitcoin: guarda el precio en btc
/// @param precioKm: guarda el precio por km
/// @return-1 Error, no realizo su funcion, 0 se ejecuto bien
int calculadora_calcularCostosPrecios(float importe, float kms, float* debito, float* credito, float* bitcoin, float* precioKm){
	int retorno = -1;
	if(debito != NULL && credito != NULL && bitcoin != NULL && precioKm != NULL){
		operaciones_descontar(importe, debito);
		operaciones_interes(importe, credito);
		operaciones_bitcoin(importe, bitcoin);
		operaciones_precioKilometro(importe, kms, precioKm);
		retorno = 0;
	}
	return retorno;
}
/// realiza la diferencia entre 2 precio ingresados
/// @param diferencia: guarda el resultado de la diferencia entre los precios
/// @param precioAero: valor precio
/// @param precioLatam: valor precio
/// @return-1 Error, no realizo su funcion, 0 se ejecuto bien
int calculadora_calcularDiferencia(float *diferencia, float precioAero, float precioLatam){
	int retorno;
	if(diferencia != NULL){
		*diferencia = precioAero - precioLatam;
		if (*diferencia < 0){
			*diferencia = *diferencia * -1;
		}
		retorno = 0;
	}
	return retorno;
}
/// realiza todas la operaciones
/// @param importeAero: valor de precio
/// @param debitoAero: precio con debito
/// @param creditoAero: precio con credito
/// @param btcAero: precio en btc
/// @param kmAero: precio por km
/// @param importeLatam
/// @param debitoLatam
/// @param creditoLatam
/// @param btcLatam
/// @param kmLatam
/// @param kms: valor de kms
/// @param diferencia: la diferencia entre los precios ingresados
/// @param flagCalcularTodo: indica si se realizaron las operaciones o no (1 no, 0 si)
/// @return -1 Error, no realizo su funcion, 0 se ejecuto bien
int calculadora_calcularTodo(float importeAero, float* debitoAero, float* creditoAero, float* btcAero, float* kmAero,
							float importeLatam, float* debitoLatam, float* creditoLatam, float* btcLatam, float* kmLatam,
							float kms, float* diferencia, int* flagCalcularTodo){
	int retorno = -1;
	if(debitoAero!=NULL && creditoAero!=NULL && btcAero!=NULL && kmAero!=NULL
			&& debitoLatam!=NULL && creditoLatam!=NULL && btcLatam!=NULL && kmLatam!=NULL && flagCalcularTodo!=NULL){
		if(!calculadora_calcularCostosPrecios(importeAero, kms, debitoAero, creditoAero, btcAero, kmAero) &&
		     !calculadora_calcularCostosPrecios(importeLatam, kms, debitoLatam, creditoLatam, btcLatam, kmLatam) &&
		     !calculadora_calcularDiferencia(diferencia, importeAero, importeLatam)){

			*flagCalcularTodo = 0;
		}
		retorno = 0;
	}
	return retorno;
}
/// opcion3 del menu: calcular todos los costos
/// @param aeroPrecio: precio
/// @param aeroDebito: precio con debito
/// @param aeroCredito: precio con credito
/// @param aeroBtc: precio con btc
/// @param aeroKm: precio por km
/// @param latamPrecio
/// @param latamDebito
/// @param latamCredito
/// @param latamBtc
/// @param latamKm
/// @param kms: kilometros
/// @param diferencia: la diferencia entre los precios ingresados
/// @param flagOpcion1: indica si se ingreso a la opcion 1
/// @param flagPrecioAero: indica si se ingreso este precio
/// @param flagPrecioLatam: indica si se ingreso estre precio
/// @param flagCalcularTodo: indica si se realizaron todos los calculos
/// @return -1 Error, no realizo su funcion, 0 se ejecuto bien
int calculadora_opcion3(float aeroPrecio, float *aeroDebito, float* aeroCredito, float* aeroBtc, float* aeroKm,
						float latamPrecio, float* latamDebito, float* latamCredito, float* latamBtc, float* latamKm,
						float kms, float* diferencia, int flagOpcion1, int flagPrecioAero, int flagPrecioLatam, int* flagCalcularTodo){

	int retorno = -1;
	if(aeroDebito!=NULL && aeroCredito!=NULL && aeroBtc!=NULL && aeroKm!=NULL &&
			latamDebito!=NULL && latamCredito!=NULL && latamBtc!=NULL && latamKm!=NULL &&
			diferencia!=NULL && flagCalcularTodo!=NULL){


		if(flagOpcion1){
			printf("DEBE INGRESAR LOS KILOMETROS\n\n");
			//getchar(); ver como funciona
		}else{
			if(flagPrecioAero && flagPrecioLatam){
				printf("DEBE INICIAR EL INGRESO DE PRECIOS.\n\n");
			}else{
				if(!flagPrecioAero && flagPrecioLatam){
					printf("DEBE INGRESAR EL PRECIO DE LATAM. \n\n");
				}else{
					if(flagPrecioAero && !flagPrecioLatam){
						printf("DEBE INGRESAR EL PRECIO DE AEROLINEAS.\n\n");
					}
					else{
						calculadora_calcularTodo(aeroPrecio, aeroDebito, aeroCredito, aeroBtc, aeroKm, latamPrecio, latamDebito, latamCredito, latamBtc, latamKm, kms, diferencia, flagCalcularTodo);
						if(!*flagCalcularTodo){
							printf("\nLOS CALCULOS SE REALIZARON CON EXITO!!!\n\n");
						}else{
							printf("\nSURGIO UN PROBLEMA\n\n");
						}
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
//*************************************************
/// muestra los resultados parcialmente
/// @param precioDebito
/// @param precioCredito
/// @param precioBitcoin
/// @param precioUnitario
void calculadora_mostrarParcialResultado(float precioDebito, float precioCredito, float precioBitcoin, float precioUnitario){
	printf("a) Precio con tarjeta de debito: $%.2f\n", precioDebito);
	printf("b) Precio con tarjeta de credito: $%.2f\n", precioCredito);
	printf("c) Precio pagando con bitcoin: %.5f BTC\n", precioBitcoin);
	printf("d) Precio unitario: $%.5f\n", precioUnitario);
}
/// muestra todos los resultados de las operaciones
/// @param precioAero
/// @param precioLatam
/// @param diferencia
/// @param aeroDebito
/// @param aeroCredito
/// @param aeroBitcoin
/// @param aeroUnitario
/// @param latamDebito
/// @param latamCredito
/// @param latamBitcoin
/// @param latamUnitario
void calculadora_mostrarResultados(float precioAero, float precioLatam, float diferencia,
									float aeroDebito, float aeroCredito, float aeroBitcoin, float aeroUnitario,
									float latamDebito, float latamCredito, float latamBitcoin, float latamUnitario){

	printf("Precio Aerolineas: $%.2f\n", precioAero);
	calculadora_mostrarParcialResultado(aeroDebito, aeroCredito, aeroBitcoin, aeroUnitario);
	printf("\nPrecio Latam: $%.2f\n", precioLatam);
	calculadora_mostrarParcialResultado(latamDebito, latamCredito, latamBitcoin, latamUnitario);
	printf("\nLa direferencia de precio es: $%.2f\n", diferencia);


}

/// opcion 4: muestra los resultados de las operaciones y comprueba que se hayan realizado los pasos previos necesarios
/// @param flagOpcion1: indica si se ingreso a la opcion 1 o no
/// @param flagPrecioAero: indica si se ingreso este precio o no
/// @param flagPrecioLatam: indica si se ingreso este precio o no
/// @param aeroPrecio: valor de precio
/// @param flagCalcularTodo: indica si se realizaron todos los calculos o no
/// @param latamPrecio: valor de precio
/// @param diferencia: diferencia entre precios
/// @param aeroDebito: precion con debito
/// @param aeroCredito: precio con credito
/// @param aeroBitcoin: precio con btc
/// @param aeroUnitario: precio por km
/// @param latamDebito: precio debito
/// @param latamCredito: precio credito
/// @param latamBitcoin: precio en btc
/// @param latamUnitario: precio por km

int calculadora_opcion4(int flagOpcion1, int flagPrecioAero, int flagPrecioLatam, float aeroPrecio, int flagCalcularTodo,
						float latamPrecio, float diferencia,
						float aeroDebito, float aeroCredito, float aeroBitcoin, float aeroUnitario,
						float latamDebito, float latamCredito, float latamBitcoin, float latamUnitario){

	int retorno;

	if(flagOpcion1){
		printf("DEBE INGRESAR LOS KILOMETROS\n\n");
		getchar();
	}else{
		if(flagPrecioAero && flagPrecioLatam){
			printf("DEBE INICIAR EL INGRESO DE PRECIOS.\n\n");
		}else{
			if(!flagPrecioAero && flagPrecioLatam){
				printf("DEBE INGRESAR EL PRECIO DE LATAM. \n\n");
			}else{
				if(flagPrecioAero && !flagPrecioLatam){
					printf("DEBE INGRESAR EL PRECIO DE AEROLINEAS.\n\n");
				}else{
					if(flagCalcularTodo){
						printf("DEBE REALIZAR LOS CALCULOS. \n\n");
					}else{
						calculadora_mostrarResultados(aeroPrecio, latamPrecio, diferencia, aeroDebito, aeroCredito, aeroBitcoin, aeroUnitario, latamDebito, latamCredito, latamBitcoin, latamUnitario);
					}

				}
			}
		}
	}
	retorno = 0;

	return retorno;
}
//*********************************************
///
///realiza una carga forzada para corroborrar las operaciones
void calculadora_opcion5(){



	float aeroPrecio = 162295;
	float latamPrecio = 159339;
	float diferencia;

	float aeroDebito;
	float aeroCredito;
	float aeroBitcoin;
	float aeroUnitario;

	float latamDebito;
	float latamCredito;
	float latamBitcoin;
	float latamUnitario;

	float kms = 7090;

	calculadora_calcularCostosPrecios(aeroPrecio, kms, &aeroDebito, &aeroCredito, &aeroBitcoin, &aeroUnitario);
	calculadora_calcularCostosPrecios(latamPrecio, kms, &latamDebito, &latamCredito, &latamBitcoin, &latamUnitario);
	calculadora_calcularDiferencia(&diferencia, aeroPrecio, latamPrecio);
	printf("\n****CARGA FORZADA****\n");
	printf("KMS ingresado: %.2f \n\n", kms);
	calculadora_mostrarResultados(aeroPrecio, latamPrecio, diferencia, aeroDebito, aeroCredito, aeroBitcoin, aeroUnitario, latamDebito, latamCredito, latamBitcoin, latamUnitario);


}
//**************************************************
/// reestablece los valores a los iniciales
/// @param aeroPrecio
/// @param latamPrecio
/// @param kms
/// @param flagOpcion1
/// @param flagPrecioAero
/// @param flagPrecioLatam
/// @param flagCalcularTodo
/// @return -1 Error, no realizo su funcion, 0 se ejecuto bien
int calculadora_resetearValores(float* aeroPrecio, float* latamPrecio, float* kms,
								int* flagOpcion1, int* flagPrecioAero, int* flagPrecioLatam, int* flagCalcularTodo){
	int retorno = 1;
	if(aeroPrecio!=NULL && latamPrecio!=NULL && kms!=NULL &&
			flagOpcion1!=NULL && flagPrecioAero!=NULL && flagPrecioLatam && flagCalcularTodo!=NULL){

		*aeroPrecio = 0;
		*latamPrecio = 0;
		*kms = 0;
		*flagOpcion1 = 1;
		*flagPrecioAero = 1;
		*flagPrecioLatam = 1;
		*flagCalcularTodo = 1;

		retorno = 0;
	}

	return retorno;
}
/// menu que se muestra de manera dinamica segun el estado de las banderas
/// @param kms: valor de kms
/// @param flagOpcion1: indica el estado de la opcion1
/// @param flagOp2Aerolineas: indica el estado del ingreso de precio
/// @param flagOp2Latam: indica el estado del ingreso de precio
/// @param precioAeroLineas: valor de precio
/// @param precioLatam: valor de precio
/// @return retorna la opcion elegida
int calculadora_menu(float kms, int flagOpcion1, int flagOp2Aerolineas, int flagOp2Latam, float precioAeroLineas, float precioLatam){
	int opcion;

	printf("\n\n****CALCULADORA DE COSTOS****\n");
	if(flagOpcion1){
		printf("1. Ingresar Kilometros: 0\n");
	}else{
		printf("1. Ingresar Kilometros: %.2f km\n", kms);
	}
	if(flagOp2Aerolineas && flagOp2Latam){
		printf("2. Ingresar Precio de Vuelos:\n\t-Precio vuelo Aerolineas: $0.00\n\t-Precio vuelo Latam: $0.00\n");
	}else{
		if(!flagOp2Aerolineas && flagOp2Latam){//0 1
			printf("2. Ingresar Precio de Vuelos:\n\t-Precio vueloAerolineas: $%.2f\n\t-Precio vuelo Latam: $0.00\n", precioAeroLineas);
		}else{
			if(!flagOp2Aerolineas && !flagOp2Latam){// 0 0
				printf("2. Ingresar Precio de Vuelos:\n\t-Precio vueloAerolinea: $%.2f\n\t-Precio vuelo Latam: $%.2f\n", precioAeroLineas, precioLatam);
			}else{
				printf("2. Ingresar Precio de Vuelos:\n\t-Precio vueloAerolinea: $0.00\n\t-Precio vuelo Latam: $%.2f\n", precioLatam);
			}
		}
	}
	printf("3. Calcular todos los costos:\n");
	printf("\ta) Tarjeta de debito (descuento %%10)\n");
	printf("\tb) Tarjeta de crédito (interes %%25)\n");
	printf("\tc) Bitcoin (1BTC -> 4649830.87 Pesos Argentinos)\n");
	printf("\td) Mostrar precio por km (precio unitario)\n");
	printf("\te) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
	printf("4.Informar Resultados\n");
	printf("5.Carga forzada de datos\n");
	printf("6.Salir.\n");
	input_MenuOption(&opcion, "", "Valor invalido. Ingrese opcion: ", 1, 6, 6, "Opcion invalida. Ingrese opcion: ");

	return opcion;
}

///
/// llama a todas las funciones para iniciar el programa
void calculacodora_calculadora(){
	int opcion;

	float kms = 0;

	float aeroPrecio = 0;
	float aeroDebito;
	float aeroCredito;
	float aeroBtc;
	float aeroKm;

	float latamPrecio = 0;
	float latamDebito;
	float latamCredito;
	float latamBtc;
	float latamKm;

	float diferencia;

	int flagOpcion1 = 1;
	int flagPrecioAero = 1;
	int flagPrecioLatam = 1;
	int flagCalcularTodo = 1;



	do{
		opcion = calculadora_menu(kms, flagOpcion1, flagPrecioAero, flagPrecioLatam, aeroPrecio, latamPrecio);
		switch(opcion){
		case 1:
			calculadora_opcion1(&kms, &flagOpcion1);
			break;
		case 2:
			calculadora_opcion2(flagOpcion1, &aeroPrecio, &latamPrecio, &flagPrecioAero, &flagPrecioLatam);
			break;
		case 3:
			calculadora_opcion3(aeroPrecio, &aeroDebito, &aeroCredito, &aeroBtc, &aeroKm, latamPrecio, &latamDebito, &latamCredito, &latamBtc, &latamKm, kms, &diferencia, flagOpcion1, flagPrecioAero, flagPrecioLatam, &flagCalcularTodo);
			break;
		case 4:
			calculadora_opcion4(flagOpcion1, flagPrecioAero, flagPrecioLatam, aeroPrecio, flagCalcularTodo, latamPrecio, diferencia, aeroDebito, aeroCredito, aeroBtc, aeroKm, latamDebito, latamCredito, latamBtc, latamKm);
			if(!flagCalcularTodo){
				calculadora_resetearValores(&aeroPrecio, &latamPrecio, &kms, &flagOpcion1, &flagPrecioAero, &flagPrecioLatam, &flagCalcularTodo);
			}
			break;
		case 5:
			calculadora_opcion5();

			break;
		case 6:
			printf("\nFIN DEL PROGRAMA\n");
			break;
		}

	}while(opcion!= 6);
}
