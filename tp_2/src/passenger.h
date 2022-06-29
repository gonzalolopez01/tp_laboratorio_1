/*
 * passenger.h
 *
 *  Created on: 28 jun. 2022
 *      Author: gonzalo
 */
#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "typePassenger.h"
#include "flycode.h"
#include "string.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct{
    int id;
    char name[51]; //1
    char lastname[51]; //2
    float price; //3
    char flycode[10]; //4
    int typePassenger; //5
    int statusFlight; //6
    int isEmpty;
}sPassenger;

#endif /* PASSENGER_H_ */

int passengers_menu();
int harcodearPassengers(sPassenger* list, int len, int quantity, int* pNextId);
int passengers_initPassengers(sPassenger* list, int len);
int passengers_printPassengerRow(sPassenger passenger, sTypePassenger* types, int lenT, sFlycode* codes, int lenC);
int passengers_printPassenger(sPassenger passenger, sTypePassenger* types, int lenT, sFlycode* codes, int lenC);
int passengers_printPassengers(sPassenger list[], int len, sTypePassenger types[], int lenT, sFlycode codes[], int lenC);

int passengers_setId(int* id, int* pNextId);
int passengers_entryName(char name[]);
int passengers_entryLastaName(char lastName[]);
int passengers_entryFlycode(char* fCode, sFlycode flycodes[], int len);
int passengers_setStatusFlight(sFlycode flycodes[], int len, char fCode[], int* statusF);
int passengers_entryType(int* type, sTypePassenger* list, int len);
int passengers_entryPrice(float* price);

int passengers_findFree(sPassenger list[], int len, int* pIndex);

int passengers_entryPassenger(sPassenger passengers[], int lenP, sTypePassenger types[], int lenT, sFlycode codes[], int lenC, int* pNextId);
int passangers_addPassenger(sPassenger list[], int len, char name[], char lastName[], char flycode[], int type, float price, int statusFlight, int idea, int index);

int passengers_menuModify();
int passengers_findId(sPassenger* list, int len, int id, int* pIndice);
int passengers_modifyPassenger(sPassenger passengers[], int lenP, sTypePassenger types[], int lenT, sFlycode codes[], int lenC, int* pNextId);
int passengers_removePassenger(sPassenger passengers[], int lenP, sTypePassenger types[], int lenT, sFlycode codes[], int lenC);

int passengers_sort(sPassenger passengers[], int len, sTypePassenger types[], int lenT, int order);
int passengers_sortByCode(sPassenger passengers[], int len, sFlycode codes[], int lenC, int order);

int passengers_MenuLists();
int passengers_Lists(sPassenger passengers[], int lenP, sTypePassenger types[], int lenT, sFlycode codes[], int lenC);

int passengers_listsOption3(sPassenger list[], int len, sTypePassenger types[], int lenT, sFlycode codes[], int lenC);
int passengers_listsOption2(sPassenger passengers[], int len);
