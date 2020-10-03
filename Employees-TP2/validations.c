#include "validations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isStringInteger(char string[])//funciona y con numero negativo.
{
    int answer = 1;
    int i;
    int HyphenC = 0;

    i=0;
    while (string[i] != '\0')
    {
        if (string[i] < '0' || string[i] >'9') //(cadena[i] != '-' && (cadena[i] < '0' || cadena[i] >'9'))
        {
            if(string[i] == '-')
            {
                HyphenC++;
                if (HyphenC>1)
                {
                    answer = 0;
                    break;
                }
            }
            else
            {
                answer = 0;//no es numero
                break;
            }
        }
        i++;
    }
    return answer;//Dice si esta listo para pasar a numero
}


int stringToInteger(char string[],int*intNumber)//
{
    int outcome = 0;

    if (isStringInteger(string))
    {
        *intNumber=atoi(string);
    }
    else
    {
        //printf("no es posible pasar a numero entero\n");
        return outcome -1;
    }

    return outcome;

}

int isStringFloat(char string[])//funciona y con numero negativo. Devuelve 0 o 1
{
    int answer;
    int i;
    int HyphenC = 0;
    int DotCounter = 0;

    answer = 1; // es numero
    i=0;
    while (string[i] != '\0')
    {
        if (string[i] < '0' || string[i] >'9') //(cadena[i] != '-' && (cadena[i] < '0' || cadena[i] >'9'))
        {
            if(string[i] == '-')
            {
                HyphenC++;
                if (HyphenC>1)
                {
                    answer = 0;
                    break;
                }
            }
            else
            {
                if(string[i] == '.')
                {
                    DotCounter++;
                    if (DotCounter>1)
                    {
                        answer = 0;
                        break;
                    }
                }
                else
                {
                    answer = 0;//no es numero
                    break;
                }
            }
        }
        i++;
    }
    return answer;//Dice si esta listo para pasar a numero
}
float stringToFloat(char string[],float*floatNumber)//toma una cadena, la valida y la pasa a entero
{
    int outcome = 0;

    if (isStringFloat(string))
    {
        *floatNumber=atof(string);
    }
    else
    {
        //printf("no es posible pasar a numero flotante\n");
        return outcome -1;
    }

    return outcome;

}


int isStringLetters(char string[])
{

    int outcome = 0;
    int i=0;
    while(string[i] != '\0')
    {
        if((string[i]>=65 && string[i]<=90) || (string[i]>=97 && string[i] <= 122) || (string[i] == 32))
        {
            if(string[i]==32)
            {
                if(string[i--]!=((string[i]>=65 && string[i]<=90) || (string[i]>=97 && string[i] <= 122)) && (string[i++]!=((string[i]>=65 && string[i]<=90) || (string[i]>=97 && string[i] <= 122))))
                    outcome = 0;
            }
            else
            {
                outcome = 1;
            }
        }
        i++;
    }
    return outcome;
}
int isSexMF(char string[])//returns 1 if the letter is F or M
{
    int outcome = 0;
    int question;
    question=isStringLetters(string);
    if(question)
    {
        string[0]=tolower(string[0]);
        if ((strcmp(string,"f")==0) || (strcmp(string,"m")==0))
        {
                outcome =1;
        }
    }

    return outcome;
}
int ggets(char string[],int size) //funciona - toma la cadena   - PRIMERO
{
    int outcome = -1;

    fflush(stdin);
    fgets(string,size,stdin);
    string[strlen(string)-1]='\0';//Fix del fgets

    return outcome = 0;
}
int sizeValidation(char string[],int size) //funciona - ve el tamaño  - SEGUNDO
{
    int outcome = -1;
    while ((strlen(string)) > (size-3))
    {
        printf("Exece la longitud, intente nuevamente\n");
        fflush(stdin);
        ggets(string,size);
    }
    outcome = 1;
    return outcome;

}



