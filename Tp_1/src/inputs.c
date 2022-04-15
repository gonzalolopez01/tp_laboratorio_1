/*
 * inputs.c
 *
 *  Created on: 14 abr. 2022
 *      Author: GONZALO
 */

//#include <stdio_ext.h>


#include "inputs.h"

//----------------INPUTS-------------------

int input_Text(char* string,int size,char* text)//recibe cadena + tama�o + Texto para el usuario
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
int input_DecimalNumberMinMax(float* floatNumber, char* text, char* errorText, float min, float max, char* rangeText)// ***
{
	int success = -1;
	int size = 50;
	float aux;
	char string[size];
	if(floatNumber!=NULL)
	{
		do
		{
			input_Text(string, size, text);
			while(!(isStringFloatNumber(string)))
			{
				input_Text(string, size, errorText);
			}
			aux  = atof(string);
		}while (min >= aux && aux <=max);
		success = 0;
	}
	return success;
}
/*int input_DecimalNumberMin(float* floatNumber, char* text, char* errorText, float min, char* rangeText)// ***
{
	int success = -1;
	int size = 50;
	float aux;
	char string[size];
	if(floatNumber!=NULL)
	{
		do
		{
			input_Text(string, size, text);
			while(!((string)))
			{
				input_Text(string, size, errorText);
			}
			aux  = atof(string);
		}while (min < aux);
		success = 0;
	}
	return success;
}*/
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
int input_rationalNumber(float* floatNumber, char* text, char* errorText)
{
	int success = -1;
	int size = 50;
	char string[size];
	if(floatNumber!=NULL)
	{
		input_Text(string, size, text);
		while(!(isStringANumber(string)))
		{
			input_Text(string, size, errorText);
		}
		*floatNumber = atof(string);
		success = 0;
	}

	return success;
}
int input_rationalNumberMin(float* floatNumber, char* text, char* errorText, int min, char* errorRangeText)
{
	int success = -1;
	if(floatNumber!=NULL)
	{
		do{
			input_rationalNumber(floatNumber, text, errorText);
			if(*floatNumber < min){
				printf("%s ",errorRangeText);
			}
		}while (*floatNumber < min);
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
		//__fpurge(stdin);
		fflush(stdin);
		scanf("%c",&returnAux);
		while(!(returnAux == 's' || returnAux == 'n'))
		{
			printf("%s",errorText);
			printf("%s",text);
			//__fpurge(stdin);
			fflush(stdin);
			scanf("%c",&returnAux);
		}
	}
	return returnAux;
}
char input_sex(char* text, char* errorText)
{
	char returnAux;
	if(text!=NULL)
	{
		printf("%s",text);
		//__fpurge(stdin);
		fflush(stdin);
		scanf("%c",&returnAux);
		while(!(returnAux == 'm' || returnAux == 'f'))
		{
			printf("%s",errorText);
			printf("%s",text);
			//__fpurge(stdin);
			fflush(stdin);
			scanf("%c",&returnAux);
		}
	}
	return returnAux;
}


void input_AlphaText(char string[],int size, char text[250],char errorText[250])
{
	input_Text(string, size, text);
	while(!(isStringAlpha(string)))
	{
		input_Text(string, size, errorText);
	}
}

/*void V_inputAlpha(char string[],int size, char text[250],char errorText[250])
{string
	input_Text(string, size, text)(string,size,text);
	while(!(V_isStringAlpha(string)))
	{
		V_inputText(string, size, errorText);
	}
}*/
int input_date(int* dia, int* mes, int* anio, int anioMin, int anioMax)
{
	int returnAux = -1;
	int validation = 0;
	if(dia != NULL && mes != NULL && anio != NULL)
	{
		do
		{
			printf("Ingrese fecha [dd/mm/aaaa]: ");
			//__fpurge(stdin);
			fflush(stdin);
			validation = scanf("%d/%d/%d", dia, mes, anio);
			if(validation == 3)
			{
				if(!((*dia >= 1 && *dia <= 31) &&
					 (*mes >= 1 && *mes <= 12) &&
					 (*anio >= anioMin && *anio <= anioMax)))
				{
					printf("Fecha incorrecta. ");
					validation = 0;
				}
			}
			else
			{
				printf("Valor incorrecto. ");
			}
		}while(validation !=3);
		returnAux = 0;
	}
	return returnAux;
}


int ggets(char* string, int size) //Es el gets arreglado
{
	int success = -1;
	int index;

	if(string!=NULL)
	{
		fflush(stdin);//WINDOWS
		//__fpurge(stdin); //linux
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
		while((strlen(string)) > (size-2))//estaba en 2
		{
			printf("Exede la longitud disponible, intente nuevamente: ");
			//__fpurge(stdin);
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

//----------------------VALIDACIONES--//*AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa-------------------------------------------------
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

int isStringAlpha(char* string)//acepta espacios y guiones
{
	int size;
	int i;
	int answer = 0;
	size = strlen(string);
	if(string!=NULL && size > 0)
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
				else
				{
					if(size  == 1 || string[i-1] == ' ' )
					{
						answer = 0;
						break;
					}
				}
			}
			answer = 1;
		}
	}
	return answer;
}
int isStrFile(char* string){
	int answer;
	int dotcounter = 0;
	if(string != NULL){
		answer = 1;
		int size = strlen(string);
		if(size > 0){
			for(int i=0; i<size; i++){
				if(!isalpha(string[i])){//entra si no es alfa
					if(!isdigit(string[i])){//entra si no es digit
						if(string[i] == '.'){
							dotcounter++;
							if(dotcounter > 1){
								answer = 0;
								break;
							}
						}else{
							answer = 0;
							break;
						}
					}
				}
			}
		}
	}
	return answer;
}
int isStrFileFormat(char* string){//-1 error, 1 csv,txt, 2 bin,dat
	int answer = -1;
	if(string != NULL){
		answer = 1;//es csv o txt
		int index;
		int size = strlen(string);
		char aux[10];
		if(size > 0){
			for(int i=0; i<size; i++){ //esta parte llega hasta el punto
				if(!isalpha(*(string+i))){
					if(!isdigit(*(string+i))){
						if(*(string+i)=='.'){
							index = i+1;
							break;
						}
					}
				}
			}
		}
		if((size-index) != 3){
			answer = 0;
		}else{
			int i;
			for(i=0; i<3 ;i++){
				aux[i] = string[index+i];
			}
			aux[3]='\0';
			if(strcmp(aux,"dat") == 0 || strcmp(aux,"bin") == 0){ //csv
				answer = 2;//es bin o dat
			}else{
				if(!strcmp(aux,"csv") == 0 && !strcmp(aux,"txt") == 0){
				answer = 0;//no es csv ni txt
				}
			}
		}
	}
	return answer;
}
int isThereFileTxt(char* path){
	int returnAux = -1; //error de los punteros
	if (path != NULL){
		returnAux = 0;
		FILE* pFile = fopen(path,"r");
		if (pFile != NULL) {
			fclose(pFile);
			returnAux = 1;//el archivo existe (preguntar si sobre escribir)
		}
	}
	return returnAux;
}
int isThereFileBin(char* path){
	int returnAux = -1; //error de los punteros
	if (path != NULL){
		returnAux = 0;
		FILE* pFile = fopen(path,"rb");
		if (pFile != NULL) {
			fclose(pFile);
			returnAux = 1;//el archivo existe (preguntar si sobre escribir)
		}
	}
	return returnAux;
}
int input_strFileFormat(char* string, int size, char* text, char* errorText){
	int success = -1;
	if(string!=NULL){
		input_Text(string, size, text);
		while(isStrFile(string) == 0 || isStrFileFormat(string) == 0){
			input_Text(string, size, errorText);
		}
		success = 0;
	}
	return success;
}
