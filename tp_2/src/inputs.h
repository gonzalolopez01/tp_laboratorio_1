/*
 * inputs.h
 *
 *  Created on: 14 abr. 2022
 *      Author: gon
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef INPUTS_H_
#define INPUTS_H_

int ggets(char* string, int size); //Es el gets arreglado
int sizeValidation(char* string, int size);
int isThereOneDot(char* string); //answer 1 = 1 punto. 0= 0 puntos o 2 o mas
int isStringNegativeNumber(char*string);
int isStringANumber(char* string);
int isStringFloatNumber(char* string);
int isStringIntegerNumber(char* string);
int isStringAlphaNumeric(char* string);
int isStringAlpha(char* string);

int ggets(char* string, int size);
int sizeValidation(char* string, int size);

int input_Text(char* string, int size, char* text);
int input_DecimalNumber(float* floatNumber, char* text, char* errorText);
int input_DecimalNumberMin(float* floatNumber, char* text, char* errorText, int min, char* errorRangeText);
int input_DecimalNumberMinMax(float* floatNumber, char* text, char* errorText, float min, float max, char* rangeText);
int input_IntegerNumber(int* intNumber, char* text, char* errorText);
int input_IntNumberMin(int*intNumber, char* text, char* errorText,int min, char* errorRangeText);
int input_IntNumberMinMax(int*intNumber, char* text, char* errorText,int min,int max, char* errorRangeText);
int input_longlongIntegerNumber(long long int* llIntNumber, char* text, char* errorText);
int input_longlongIntNumberMin(long long int*llIntNumber, char* text, char* errorText,long long int min, char* errorRangeText);
int input_longlongIntNumberMinMax(long long int*llIntNumber, char* text, char* errorText,long long int min,long long int max, char* errorRangeText);
int input_MenuOption(int* option, char* text, char* errorText, int min, int max, int salir, char* errorRangeText);
char input_ClosedQuestion(char* text, char* errorText);
char input_sex(char* text, char* errorText);
void input_AlphaText(char string[], int size, char text[],char errorText[]);
int input_date(int* dia, int* mes, int* anio, int anioMin, int anioMax);

int stringToProperName(char* string);
int stringToUpper(char* string);

int input_strFileFormat(char* string, int size, char* text, char* errorText);
int isStrFileFormat(char* string);
int isThereFileBin(char* path);
int isThereFileTxt(char* path);



#endif /* INPUTS_H_ */
