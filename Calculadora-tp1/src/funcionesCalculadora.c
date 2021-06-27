/*
 * funcionesCalculadora.c
 *
 *  Created on: Apr 17, 2021
 *      Author: gonzalo
 */

#include "funcionesCalculadora.h"
#include <stdio_ext.h>


float calculator_addition(float num1, float num2)
{
    float outcome;

    outcome = num1+num2;

    return outcome;
}
float calculator_subtraction(float num1, float num2)
{
    float outcome;

    outcome = num1-num2;

    return outcome;
}
float calculator_division(float num1, float num2)
{
    float outcome;

    outcome = num1/num2;

    return outcome;
}
float calculator_multiplication(float num1, float num2)
{
    float outcome;

    outcome = num1*num2;

    return outcome;
}

long int calculator_factorization(int num1)
{
    int i=0;
    long int number;
    number = num1;
    long int outcome;
    if (number ==0)
    {
    	outcome = 1;
    }
    else
    {
    	outcome = number;
        for (i=1;i<number;i++)
        {
        	outcome = outcome * i;
        }
    }

    return outcome;
}

float calculator_option1(char string[], int size)
{
	float number;

	number = V_ValidationInputFloatNumber(string, size, "1.Ingresar 1er operando A: ", "Valor invalido, Ingrese 1er operando A: ");
	return number;
}

float calculator_option2(char string[], int size)
{
	float number;

	number = V_ValidationInputFloatNumber(string, size, "2.Ingresar 2do operando B: ", "Valor invalido, Ingrese 2do operando B: ");

	return number;
}

void calculator_menu(float numberA, float numberB, int flagA, int flagB)
{
	if(flagA==0)
	{
		printf("1.Ingresar 1er operando A: 'x'\n");
	}
	else
	{
		printf("1.Ingresar 1er operando A: %.2f\n",numberA);
	}

	if(flagB==0)
	{
		printf("2.Ingresar 2do operando B: 'y'\n");
	}
	else
	{
		printf("2.Ingresar 2do operando B: %.2f\n",numberB);
	}

	printf("3.Calcular todas las operaciones\n");
	printf("    a)Calcular la suma (A+B)\n");
	printf("    b)Calcula la resta (A-B)\n");
	printf("    c)Calcular la division (A/B)\n");
	printf("    d)Calcular la multiplicacion (A*B)\n");
	printf("    e)Calcular el factorial (A!)\n");
}
void calculator_option4(int flag,float addition,float subtraction,float division,float multiplication,
						long int outcomeFactorizationA, long int outcomeFactorizationB,float numberB)
{
	if(flag==0)
	{
		printf("4.Informar resultados\n");
		printf("    a)El resultado de A+B es:\n");
		printf("    b)El resultado de A-B es:\n");
		printf("    c)El resultado de A/B es:\n");
		printf("    d)El resultado de A*B es:\n");
		printf("    e)El factorial de A es:   y El factorial de B es:   \n");
		printf("5.Salir\n");
		printf("Elija una opcion: \n");
	}
	else
	{
		printf("4.Resultados\n");
		printf("   a)El resultado de A+B es: %.2f\n",addition);
		printf("   b)El resultado de A-B es: %.2f\n",subtraction);
		if (numberB!=0)
		{
			printf("   c)El resultado de A/B es: %.2f\n",division);
			printf("   d)El resultado de A*B es: %.2f\n",multiplication);
			printf("   e)El factorial de A es: %ld\n",outcomeFactorizationA);
			printf("     El factorial de B es: %ld\n",outcomeFactorizationB);
		}
		else
		{
			printf("   c)No es posible dividir por cero\n");
			printf("   d)El resultado de A*B es: %.2f\n",multiplication);
			printf("   e)El factorial de A es: %ld\n",outcomeFactorizationA);
			printf("     El factorial de B es: %ld\n",outcomeFactorizationB);
		}
		printf("5.Salir\n");
		printf("Elija una opcion: \n");
	}
}
void clearscr()
{
	for(int i=0;i<50;i++)
		printf("\n");
}




