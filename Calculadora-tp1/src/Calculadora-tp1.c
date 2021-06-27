/*
 ============================================================================
 Name        : Calculadora-tp1.c
 Author      : Gonzalo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "funcionesCalculadora.h"
#define S 10

void clearscr();

int main(void) {

	setbuf(stdout, NULL);

	int option;
	float numberA;
	float numberB;
	int flagA=0;
	int flagB=0;
	int flagResultados=0;
	char stringA[10];
	char stringB[10];
	char c;

	float addition;
	float subtraction;
	float division;
	float multiplication;
	int factorizationA;
	int factorizationB;
	long int outcomeFactorizationA;
	long int outcomeFactorizationB;


	do
	{
		calculator_menu(numberA,numberB,flagA,flagB);
		calculator_option4(flagResultados,addition,subtraction, division, multiplication,outcomeFactorizationA,outcomeFactorizationB,numberB);
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				numberA = calculator_option1(stringA, S);
				flagA=1;
				clearscr();
			break;
			case 2:
				numberB = calculator_option2(stringB, S);
				flagB=1;
				clearscr();

			break;
			case 3:
				if((flagA == 0) || flagB ==0)
				{
					printf("Primero debe completar el ingreso de valores");
					printf("Presion enter para continuar");
					__fpurge(stdin);
					scanf("%c",&c);
					clearscr();
					break;
				}
				addition         = calculator_addition(numberA, numberB);
				subtraction      = calculator_subtraction(numberA, numberB);
				if (numberB!=0)
					division     = calculator_division(numberA,numberB);
				multiplication   = calculator_multiplication(numberA,numberB);
				factorizationA   = numberA;
				factorizationB   = numberB;
				outcomeFactorizationA = calculator_factorization(factorizationA);
				outcomeFactorizationB = calculator_factorization(factorizationB);
				flagResultados = 1;
				printf ("operaciones realizadas\n");
				printf("Presion enter para continuar");
				__fpurge(stdin);
				scanf("%c",&c);
				while(c!='\n')
				{
					scanf("%c",&c);
				}

			break;
			case 4:
				{
					clearscr();
					void calculator_menu(float numberA,float numberB,int flagA, int flagB);
					calculator_option4(flagResultados,addition,subtraction, division, multiplication,outcomeFactorizationA,outcomeFactorizationB,numberB);
					printf("Presion enter para continuar");
					__fpurge(stdin);
					scanf("%c",&c);
					while(c!='\n')
					{
						scanf("%c",&c);
					}
					clearscr();
				}
				break;
			case 5:
				printf("Fin del programa");
			break;
		}
	}while(option!=5);

	return EXIT_SUCCESS;
}





