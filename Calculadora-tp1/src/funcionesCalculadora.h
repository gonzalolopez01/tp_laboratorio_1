/*
 * funcionesCalculadora.h
 *
 *  Created on: Apr 17, 2021
 *      Author: gonzalo
 */

#ifndef FUNCIONESCALCULADORA_H_
#define FUNCIONESCALCULADORA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
/**\calculator menu
 * \void function
 * \receives 2 float en 2 flags that check the state of the float variables
 */
void calculator_menu(float numberA,float numberB,int flagA, int flagB);
/**
 * \receives the numbers in string format and casts it to float
 *
 */
float calculator_option1(char string[], int size);
float calculator_option2(char string[], int size);
/*
 * controls the reporting option of the menu and shows the outcomes
 */

void calculator_option4(int flag,float addition,float subtraction,float division,float multiplication,
						long int outcomeFactorizationA, long int outcomeFactorizationB,float numberB);
/**
 * receives 2 float numbers and carries out the addition
 */
float calculator_addition(float num1, float num2);
/**
 * receives 2 float numbers and carries out the subtraction
 */
float calculator_subtraction(float num1, float num2);
/**
 * receives 2 float numbers and carries out the division
 */
float calculator_division(float num1, float num2);
/**
 * receives 2 float numbers and carries out the multiplication
 */
float calculator_multiplication(float num1, float num2);
/**
 * receives 1 float number and carries out the multiplication
 */
long int calculator_factorization(int num1);
/**
 * clears the screen, it's an option to the cls commans
 */
void clearscr();

/**
 * receives character strings and fixes the '\n' problem
 */
int V_ggets(char string[], int size);
/**
 * it is to check the size of the strings to prevent the overflow of the variable by limiting the length of the string
 */
int V_sizeValidation(char string[], int size);
void V_inputText(char string[],int size,char text[256]);
/**
 * by checking the characters of the string decides wether it has a decimal number format or not
 */
int V_isDecimalNumber(char string[]);
/**
 * looks for dots along the character strings. 1 dot returns 1,  0 dot or more than 1 = 0.
 */
int V_isThereDecimalDot(char string[]);
/**
 * says if the string is constituted by integer numbers
 */
int V_isStringIntegerNumber(char string[]);
/**
 * says wether the string has number format or not
 */
int V_isStringNumber(char string[]);
/**
 * this function is to input strings that are suitable for float format
 */
float V_ValidationInputFloatNumber(char string[],int size, char text[250], char errorText[250]);



#endif /* FUNCIONESCALCULADORA_H_ */
