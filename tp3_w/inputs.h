/*
 * inputs.h
 *
 *  Created on: 8 jun. 2021
 *      Author: pame y gon
 */

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

int input_Text(char* string,int size,char* text);
int input_DecimalNumber(float* floatNumber, char* text, char* errorText);
int input_IntegerNumber(int* intNumber, char* text, char* errorText);
int input_IntNumberMin(int*intNumber, char* text, char* errorText,int min, char* errorRangeText);
int input_IntNumberMinMax(int*intNumber, char* text, char* errorText,int min,int max, char* errorRangeText);
int input_MenuOption(int* option, char* text, char* errorText, int min, int max, int salir, char* errorRangeText);
char input_ClosedQuestion(char* text, char* errorText);

int stringToProperName(char* string);

int employee_inputId(char *id);
int employee_inputNombre(char* nombre);
int employee_inputHorasTrabajadas(char* horasTrabajadas);
int employee_inputSueldo(char* sueldo);
#endif /* INPUTS_H_ */
