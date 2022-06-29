/*
 * flycode.c
 *
 *  Created on: 28 jun. 2022
 *      Author: gonzalo
 */
#include "flycode.h"

int flycode_loadStatus(sFlycode list[], int len, char flycode[], char state[]){//el codigo y el tipo ya tiene que estar validados
	int retOk = 0;
	if(list != NULL && len > 0 && flycode != NULL && state != NULL){
		for(int i = 0; i < len; i++){
			if(strcmp(list[i].flycode, flycode) == 0){
                strcpy(state, list[i].statusStr);
				break;
                retOk = 1;
			}
		}
	}
	return retOk;
}

void flycode_printFlycodeRow(sFlycode flycode){

    printf("%-10s %-10s\n", flycode.flycode,
							flycode.statusStr);

}
void flycode_printFlycode(sFlycode flycode){

    printf("FLYCODE: %10s\nSTATUSFLIGHT: %s\n", flycode.flycode, flycode.statusStr);

}
int flycode_printFlycodes(sFlycode* list, int len){
	int retOK = 0;
	int flag = 1;
	if(list != NULL && len > 0){

        printf("\n*** LISTA DE FLYCODES ***\n");
        printf("FlyCode     StatusFlight\n");
        printf("----------------------------\n");
		for (int i=0; i<len; i++){
            flycode_printFlycodeRow(list[i]);
            flag=0;
		}
		if(flag){
			printf("no hay flycodes en el sistema\n");
		}
		retOK = 1;
	}
    return retOK;
}
int flycode_findFlycode(sFlycode* list, int len , char idQuery[], int* pIndice){
	int retOk = 0;
	if (list != NULL && len > 0 && idQuery != NULL && pIndice != NULL) {
		*pIndice = -1;
		for(int i = 0; i<len; i++) {
			if(strcmpi(idQuery, list[i].flycode) == 0){
				*pIndice = i;
				break;
			}
		}
		retOk = 1;
	}
	return retOk;
}
int flycode_isValidFlycode(sFlycode* list, int len, char flycode[]){

    int isValid = 0;
    int indice;
    if(flycode_findFlycode(list, len, flycode, &indice)){
        if(indice != -1){
            isValid = 1;
        }
    }
	return isValid;
}
