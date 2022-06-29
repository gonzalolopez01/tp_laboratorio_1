/*
 * flycode.h
 *
 *  Created on: 28 jun. 2022
 *      Author: gonzalo
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#ifndef FLYCODE_H_
#define FLYCODE_H_

typedef struct{
    char flycode[10];
    int statusFlight;
    char statusStr[10];
}sFlycode;

#endif /* FLYCODE_H_ */

int flycode_loadStatus(sFlycode list[], int len, char flycode[], char state[]);
void flycode_printFlycodeRow(sFlycode flycode);
void flycode_printFlycode(sFlycode flycode);
int flycode_printFlycodes(sFlycode* list, int len);
int flycode_findFlycode(sFlycode* list, int len , char idQuery[], int* pIndice);
int flycode_isValidFlycode(sFlycode* list, int len, char flycode[]);
