/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "inputs.h"
#include "flycode.h"
#include "passenger.h"
#include "typePassenger.h"

#define SP 2000
#define SFC 6
#define STP 3

int main(void) {
	setbuf(stdout,NULL);

	int pNid = 1;
	int isLoaded = 0;
	sTypePassenger types[STP] = {
								{100, "First Class"},
								{101, "Business"},
								{102, "Economy"}
								};
	sFlycode codes[SFC] = {
							{"XNY374", 1, "Activo"},
							{"WBA374", 1, "Activo"},
							{"RYT364", 0, "Inactivo"},
							{"XGY376", 1, "Activo"},
							{"JNT371", 0, "Inactivo"},
							{"XNY914", 0, "Inactivo"}
							};
	sPassenger passengers[SP];

	passengers_initPassengers(passengers, SP);

	//****HARCODEO PARA PROBAR INFORMES****
	//harcodearPassengers(passengers, SP, 10, &pNid);

	char salir = 'n';
		do{
			switch(passengers_menu()){
			case 1:
	            if(passengers_entryPassenger(passengers, SP, types, STP, codes, SFC, &pNid)){
	            	puts("El pasajero se cargo con exito!\n");
	            	isLoaded = 1;
	            }
				break;
			case 2:
				if(isLoaded){
					passengers_modifyPassenger(passengers, SP, types, STP, codes, SFC, &pNid);
				}else{
					puts("Primero debe cargar al menos un pasajero.\n");
				}
				break;
			case 3:
				if(isLoaded){
					passengers_removePassenger(passengers, SP, types, STP, codes, SFC);
				}else{
					puts("Primero debe cargar al menos un pasajero.\n");
				}
				break;
			case 4:
				if(isLoaded){
					passengers_Lists(passengers, SP, types, STP, codes, SFC);
				}else{
					puts("Primero debe cargar al menos un pasajero.\n");
				}
				break;
			case 5:
				if(isLoaded){
					passengers_sort(passengers, SP, types, STP, 1);
					passengers_printPassengers(passengers, SP, types, STP, codes, SFC);
				}else{
					puts("Primero debe cargar al menos un pasajero.\n");
				}
				break;
			case 6:
				salir = 's';
				printf("FIN DEL PROGRAMA\n");
				break;
			}
		}while(salir != 's');
	return EXIT_SUCCESS;
}
