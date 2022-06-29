/*
 * typePassenger.c
 *
 *  Created on: 28 jun. 2022
 *      Author: gonzalo
 */

#include "typePassenger.h"



int typeP_loadType(sTypePassenger list[], int len, int id, char description[]){
    int retOk = 0;
    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            if(list[i].id == id){
                strcpy(description, list[i].type);
                retOk = 1;
                break;
            }
        }
    }
    return retOk;
}

void typeP_printTypeRow(sTypePassenger typeP){

    printf("%4d %15s\n", typeP.id, typeP.type);

}
int typeP_printTypes(sTypePassenger* list, int len){
	int retOK = 0;
	int flag = 1;
	if(list != NULL && len > 0){

        printf("\n   *** TIPO DE PASAJEROS***\n");
        printf("   Id  Tipo de pasajeto\n");
        printf("-------------------------------\n");
		for (int i=0; i<len; i++){
            typeP_printTypeRow(list[i]);
            flag=0;
		}
		if(flag){
			printf("no hay tipos de pasajeros en el sistema\n");
		}
		retOK = 1;
	}
    return retOK;
}
int typeP_findType(sTypePassenger* list, int len , int idQuery, int* pIndice){
	int retOk = 0;
	if (list != NULL && len > 0 && pIndice != NULL) {
		*pIndice = -1;
		for(int i = 0; i<len; i++) {
			if(list[i].id == idQuery){
				*pIndice = i;

				break;
			}
		}
		retOk = 1;
	}
	return retOk;
}
int typeP_isValidType(sTypePassenger* list, int len, int idType){
    int isValid = 0;
    int indice;
    if(list != NULL && len > 0){
        if(typeP_findType(list, len, idType, &indice)){
            if(indice != -1){
                isValid = 1;
            }
        }
    }
	return isValid;
}
