/*
 * validaciones.c
 *
 *  Created on: Apr 17, 2021
 *      Author: gonzalo
 */

#include "validaciones.h"

int V_ggets(char string[], int size)
{
	int outcome = -1;
	int index;

	__fpurge(stdin);
	fgets(string,size,stdin);
	index = strlen(string) - 1;
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


void V_inputText(char string[],int size,char text[256])//1.Pregunta 2.ingreso y guardado en string
{
    printf("%s",text);
    V_ggets(string,size);
    V_sizeValidation(string,size);
}

int V_isDecimalNumber(char string[])
{
	int answer=1;
	int size;
	int i;
	int dotCounter=0;
	size = strlen(string);
	if(V_isThereDecimalDot(string))
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
		}
	}
	else
	{
		answer = 0;
	}

	return answer;
}

int V_isThereDecimalDot(char string[])
{
	int answer = 0;
	int i;
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
				break;
			}
		}
	}
	return answer;
}


