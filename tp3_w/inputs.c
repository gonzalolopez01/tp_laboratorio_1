/*
 * inputs.c
 *
 *  Created on: 8 jun. 2021
 *      Author: pame y gon
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "inputs.h"


//----------------INPUTS-------------------

int input_Text(char* string,int size,char* text)//recibe cadena + tamaño + Texto para el usuario
{
	int success = -1;
	if(string!=NULL)
	{
		printf("%s",text);
		ggets(string,size);//fgets
		sizeValidation(string,size);
		success = 0;
	}
	return success;
}



int input_DecimalNumber(float* floatNumber, char* text, char* errorText)// ***
{
	int success = -1;
	int size = 50;
	char string[size];
	if(floatNumber!=NULL)
	{
		input_Text(string, size, text);
		while(!(isStringFloatNumber(string)))
		{
			input_Text(string, size, errorText);
		}
		*floatNumber = atof(string);
		success = 0;
	}

	return success;
}

int input_IntegerNumber(int* intNumber, char* text, char* errorText)//***
{
	int size = 50;
	char string[size];
	int success = -1;
	if(intNumber!=NULL)
	{
		input_Text(string, size, text);
		while(!isStringIntegerNumber(string))
		{
			input_Text(string, size, errorText);
		}
		*intNumber = atoi(string);
		success = 0;
	}
	return success;
}
/*

int V_inputFloatNumberMin(float* floatNumber,int size, char text[250], char errorText[250],float min, char errorRangeText[250])
{
	int outcome;
	char string[size];
	if(floatNumber!=NULL)
	{
		do{
			outcome = 1;
			V_inputText(string, size, text);
			while(!(V_isStringFloatNumber(string)))
			{
				V_inputText(string, size, errorText);
			}
			*floatNumber = atof(string);
			if (*floatNumber < min)
			{
				printf("%s",errorRangeText);
				outcome = 0;
			}
		}while (*floatNumber < min);
	}
	return outcome;
}*/
int input_IntNumberMin(int*intNumber, char* text, char* errorText,int min, char* errorRangeText)
{
	int success = -1;
	if(intNumber!=NULL)
	{
		do{
			input_IntegerNumber(intNumber, text, errorText);
			if (*intNumber < min)
			{
				printf("%s ",errorRangeText);
				success = 0;
			}
		}while(*intNumber < min);
	}
	return success;
}
int input_IntNumberMinMax(int*intNumber, char* text, char* errorText,int min,int max, char* errorRangeText)
{
	int success = -1;
	if(intNumber!=NULL)
	{
		do
		{
			input_IntegerNumber(intNumber, text, errorText);
			if (*intNumber < min || *intNumber > max)
			{
				printf("%s ",errorRangeText);
			}
		}while(*intNumber < min || *intNumber > max);
		success = 0;
	}
	return success;
}
int input_MenuOption(int* option, char* text, char* errorText, int min, int max, int salir, char* errorRangeText)
{
	int success = -1;
	do{
		input_IntegerNumber(option, text, errorText);
		if ((*option < min || *option > max) && (*option != salir))
		{
			printf("%s ",errorRangeText);
		}
	}while ((*option < min || *option > max) && (*option != salir));
	return success = 0;
}
char input_ClosedQuestion(char* text, char* errorText)
{
	char returnAux;
	if(text!=NULL)
	{
		printf("%s",text);
		scanf("%c",&returnAux);
		while(!(returnAux == 's' || returnAux == 'n'))
		{
			printf("%s",errorText);
			printf("%s",text);
			scanf("%c",&returnAux);
		}
	}
	return returnAux;
}
/*

void V_inputAlphaNumeric(char string[],int size, char text[250],char errorText[250])
{
	V_inputText(string,size,text);
	while(!(V_isStringAlphaNumeric(string)))
	{
		V_inputText(string, size, errorText);
	}
}

void V_inputAlpha(char string[],int size, char text[250],char errorText[250])
{
	V_inputText(string,size,text);
	while(!(V_isStringAlpha(string)))
	{
		V_inputText(string, size, errorText);
	}
}*/


int ggets(char* string, int size) //Es el gets arreglado
{
	int success = -1;
	int index;

	if(string!=NULL)
	{
		fflush(stdin);//WINDOWS
		fgets(string,size,stdin);
		index = strlen(string)-1;
		if(string[index]=='\n')//fix del fgets
		{
			string[index] = '\0';
		}
	}

	return success = 0;
}
int sizeValidation(char* string, int size)
{
	int success = -1;
	if(string!=NULL)
	{
		while((strlen(string)) > (size-2))
		{
			printf("Exede la longitud disponible, intente nuevamente: ");
			fflush(stdin);
			ggets(string,size);
		}
		success = 1;
	}

	return success;
}
//------------------------------------------------------------------------------------
int stringToProperName(char* string)//for Windows
{
	int success = -1;
	if(string!=NULL)
	{
		if(isStringAlpha(string))
		{
			for(int i=0; i<(strlen(string)); i++)
			{
				if(i==0)
				{
					string[i] = toupper(string[i]);
				}
				else
				{
					if(string[i] == ' ')
					{
						string[i+1] = toupper(string[i+1]);
					}
				}
			}
		}
		success = 0;
	}
	return success;
}

//----------------------VALIDACIONES---------------------------------------------------
int isThereOneDot(char* string) //answer 1 = 1 punto. 0= 0 puntos o 2 o mas
{

	int i;
	int answer = 0;
	int dotCounter = 0;
	int size;
	if(string!=NULL)
	{
		size = strlen(string)-1;
		for (i=0;i<size;i++)
		{
			if(string[i] == 46)
			{
				dotCounter++;
				answer = 1;
				if(dotCounter > 1)
				{
					answer = 0;
				}

			}
		}
	}
	return answer;
}
int isStringNegativeNumber(char*string)
{
	int answer = 0;
	int size;
	int i;
	if(string!=NULL)
	{
		size = strlen(string)-1;
		for(i=0 ;i<size; i++)
		{
			if(i == 0 && string[i]=='-')
			{
				answer = 1;
			}
			else
			{
				if(string[i]=='-')
				{
					answer = 0;
					break;
				}
			}
		}
	}

	return answer;
}

int isStringANumber(char* string)
{
	int i;
	int size;
	int answer = 1;
	int dotCounter = 0;
	if(string!=NULL)
	{
		size = strlen(string);
		for(i=0; i<size; i++)
		{
			if(isdigit(string[i])==0)
			{
				if(string[i] == '.' || string[i] == '-')
				{
					if(i!=0 && string[i]=='-')
					{
						answer = 0;
						break;
					}
					else
					{
						if(string[i]=='.')
						{
							dotCounter++;
							if(dotCounter == 2)
							{
								answer = 0;
								break;
							}
						}

					}
				}
				else
				{
					answer = 0;
				}
			}
		}
	}
	return answer;
}

int isStringFloatNumber(char* string) // dice si la cadena es un numero decimal positivo o negativo
{
	int answer=0;
	if(string!=NULL && (isStringANumber(string)) && (isThereOneDot(string)))
	{
		answer = 1;
	}
	return answer;
}

int isStringIntegerNumber(char* string)
{
	int answer = 0;
	if(string!=NULL && isStringANumber(string) && !isThereOneDot(string))
	{
		answer = 1;
	}
	return answer;
}

int isStringAlphaNumeric(char*string)
{
	int size;
	int i;
	int answer = 1;
	size = strlen(string);
	for(i=0;i<size;i++)
	{
		if(!(isdigit(string[i]) || isalpha(string[i])))
		{
			answer = 0;
			break;
		}
	}
	return answer;
}

int isStringAlpha(char* string)
{
	int size;
	int i;
	int answer = 1;
	size = strlen(string);
	if(string!=NULL)
	{
		for(i=0;i<size;i++)
		{
			if(!(isalpha(string[i])))
			{
				if(string[i] != ' ') // con esto pruebo lo de borrar
				{
					if(string[i] != '-')
					{
						answer = 0;
						break;
					}
				}
			}
		}
	}


	return answer;
}

