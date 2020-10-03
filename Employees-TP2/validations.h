#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

int isStringInteger(char string[]);
int stringToInteger(char string[],int*intNumber);

float stringToFloat(char string[],float*floatNumber);
int isStringFloat(char string[]);//funciona y con numero negativo. Devuelve 0 o 1

int isStringLetters(char[]);
int isSexMF(char string[]);

#endif // VALIDATIONS_H_INCLUDED
