/*
 * validations.h
 *
 *  Created on: May 13, 2021
 *      Author: gonzalo
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>




int V_ggets(char string[], int size);
int V_sizeValidation(char string[], int size);
void V_inputText(char string[],int size,char text[256]);
int V_isStringNumbers(char string[]);
int V_isThereDecimalDot(char string[]);
int V_isStringFloatNumber(char string[]);
int V_isStringIntegerNumber(char string[]);
float V_InputFloatNumber(int size, char text[250], char errorText[250]);
int V_inputIntegerNumber(int size, char text[250], char errorText[250]);
float V_inputFloatNumberMin(int size, char text[250], char errorText[250],float min, char errorRangeText[250]);
int V_isStringDigit(char string[]);
int V_inputIntNumberMin(int size, char text[250], char errorText[250],int min, char errorRangeText[250]);
int V_inputIntNumberMinMax(int size, char text[250], char errorText[250],int min,int max, char errorRangeText[250]);
void V_inputAlphaNumeric(char string[],int size, char text[250],char errorText[250]);
int V_menuOptionValidation(int size, char text[250],char errorText[250],int min,int max, int salir, char errorRangeText[250]);
int V_isStringAlpha(char string[]);
void V_inputAlpha(char string[],int size, char text[250],char errorText[250]);
int V_stringToProperName(char* string);


#endif /* VALIDATIONS_H_ */
