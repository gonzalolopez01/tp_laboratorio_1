/*
 ============================================================================
 Name        : Validations2021.c
 Author      : Gonzalo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "validations.h"

//---------------------Ingreso de strings y validacion del tamaño------------------
int V_ggets(char string[], int size) //Es el gets arreglado
{
	int outcome = -1;
	int index;

	__fpurge(stdin);
	fgets(string,size,stdin);
	index = strlen(string)-1;
	if(string[index]=='\n')//fix del fgets
	{
		string[index] = '\0';
	}

	return outcome = 0;
}
int V_sizeValidation(char string[], int size)
{
	int outcome = -1;
	while((strlen(string)) > (size-3))
	{
		printf("Exede la longitud disponible, intente nuevamente:\n");
		__fpurge(stdin);
		V_ggets(string,size);
	}
	outcome = 1;
	return outcome;
}
void V_inputText(char string[],int size,char text[256])//recibe cadena + tamaño + Texto para el usuario
{
    printf("%s",text);
    V_ggets(string,size);//fgets
    V_sizeValidation(string,size);
}

//------------------Validacion de numeros-----------------------
int V_isStringNumbers(char string[])
{
	int i;
	int size;
	int answer = 1;
	size = strlen(string);
	for(i=0;i<size;i++)
	{
		if(!(isdigit(string[i]) || string[i] == '-' || string[i] == '.'))
		{
			answer = 0;
			break;
		}
	}
	return answer;
}
int V_isThereDecimalDot(char string[]) //answer 1 = 1 punto. 0= 0 puntos o 2 o mas
{

	int i;
	int answer = 0;
	int dotCounter = 0;
	int size;
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
	return answer;
}
int V_isStringDigit(char string[])
{
	int answer = 1;
	int size;
	size = strlen(string);
	int i;
	for (i=1;i<size;i++)
	{
		if(!(isdigit(string[i])))
		{
			answer = 0;
			break;
		}
	}
	return answer;
}
int V_isStringFloatNumber(char string[]) // dice si la cadena es un numero decimal positivo o negativo
{
	int answer=1;
	int size;
	int i;
	int dotCounter=0;
	size = strlen(string);
	if(V_isThereDecimalDot(string)) //cadena empezando con '.'
	{
		if(string[0] == '.')
		{
			for (i=1;i<size;i++)
			{
				if(!(isdigit(string[i])))
				{
					answer = 0;
					break;
				}
			}
		}
		else
		{
			if(isdigit(string[0]) || string[0] == '-')
			{
				for(i=1;i<size;i++)
				{
					if(string[i] == '.') //&& !(isdigit(string[i])))
					{
						dotCounter++;
						if(dotCounter>1)
						{
							answer = 0;
							break;
						}
					}
					else
					{
						if(isdigit(string[i]) != 1)
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
	else
	{
		if(string[0] == '-' || isdigit(string[0])) // string empezando con '-' o 'numero
		{
			for(i=1;i<size;i++)
			{
				if(isdigit(string[i]) != 1)
				{
					answer = 0;
					break;
				}
			}
		}
		else
		{
			answer = 0;
		}
	}

	return answer;
}
float V_InputFloatNumber(int size, char text[250], char errorText[250])// input, validation, and passage
{
	char string[size];
	float number;
	V_inputText(string, size, text);
	while(!(V_isStringFloatNumber(string)))
	{
		V_inputText(string, size, errorText);
	}
	number = atof(string);
	return number;
}
int V_isStringIntegerNumber(char string[])
{
	int answer=1;
	int size;
	int i;
	size = strlen(string);
	if((isdigit(string[0]) || string[0] == '-') && string[0] != '.')
	{
		for(i=1;i<size;i++)
		{
			if(isdigit(string[i]) != 1)
			{
				answer = 0;
				break;
			}
		}

	}
	else
	{
		answer = 0;
	}


	return answer;
}
int V_inputIntegerNumber(int size, char text[250], char errorText[250])
{
	char string[size];
	int number;
	V_inputText(string, size, text);

	while(!V_isStringIntegerNumber(string))
	{
		V_inputText(string, size, errorText);
	}
	number = atoi(string);
	return number;
}

//----------------------------Ingreso de numeros con limites
float V_inputFloatNumberMin(int size, char text[250], char errorText[250],float min,char errorRangeText[250])
{
	float number;
	char string[size];
	do{
		V_inputText(string, size, text);
		while(!(V_isStringFloatNumber(string)))
		{
			V_inputText(string, size, errorText);
		}
		number = atof(string);
		if (number < min)
		{
			printf("%s",errorRangeText);
		}
	}while (number < min);
	return number;
}
int V_inputIntNumberMin(int size, char text[250], char errorText[250],int min, char errorRangeText[250])
{
	char string[size];
	int number;
	do{
		V_inputText(string, size, text);
		while(!(V_isStringIntegerNumber(string)))
		{
			V_inputText(string, size, text);
		}
		number = atoi(string);
		if (number < min)
		{
			printf("%s",errorRangeText);
		}
	}while(number < min);
	return number;
}
int V_inputIntNumberMinMax(int size, char text[250], char errorText[250],int min,int max, char errorRangeText[250])
{
	char string[size];
	int number;
	do{
		V_inputText(string, size, text);
		while(!(V_isStringIntegerNumber(string)))
		{
			V_inputText(string, size, text);
		}
		number = atoi(string);
		if (number < min || number > max)
		{
			printf("%s",errorRangeText);
		}
	}while(number < min || number > max);
	return number;
}
int V_menuOptionValidation(int size, char text[250],char errorText[250],int min,int max, int salir, char errorRangeText[250])//devuelve el numero para la opcion
{
	int option;
	char string[size];
	do{
		V_inputText(string, size, text);
		while(!(V_isStringIntegerNumber(string)))
		{
			V_inputText(string, size, text);
		}
		option = atoi(string);
		if ((option < min || option > max) && (option != salir))
		{
			printf("%s",errorRangeText);
		}
	}while ((option < min || option > max) && (option != salir));
	return option;
}

//-------------------validacion alfa numericos-
/*int V_isStringAlphaNumeric(char string[]) //probarla
{
	int size;
	int i;
	int answer = 1;
	size = strlen(string);
	for(i=0;i<size;i++)
	{
		if(!((isdigit(string[i]) || isalpha(string[0]) || string[0]== '.' || string[0] == ',' || string[0] == '-')))
		{
			answer = 0;
			break;
		}
	}
	return answer;
}
void V_inputAlphaNumeric(char string[],int size, char text[250],char errorText[250])
{
	V_inputText(string,size,text);
	while(!(V_isStringAlphaNumeric(string)))
	{
		V_inputText(string, size, errorText);
	}
}*/
int V_isStringAlpha(char string[])
{
	int size;
	int i;
	int answer = 1;
	size = strlen(string);
	for(i=0;i<size;i++)
	{
		if(!(isalpha(string[i])))
		{
			answer = 0;
			break;
		}
	}
	return answer;
}
void V_inputAlpha(char string[],int size, char text[250],char errorText[250])
{
	V_inputText(string,size,text);
	while(!(V_isStringAlpha(string)))
	{
		V_inputText(string, size, errorText);
	}
}

