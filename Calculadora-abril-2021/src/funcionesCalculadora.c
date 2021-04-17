/*
 * funcionesCalculadora.c
 *
 *  Created on: Apr 17, 2021
 *      Author: gonzalo
 */
#include "funcionesCalculadora.h"

float sumar(float num1, float num2)
{
    float resultado;

    resultado = num1+num2;

    return resultado;
}
float restar(float num1, float num2)
{
    float resultado;

    resultado = num1-num2;

    return resultado;
}
float dividir(float num1, float num2)
{
    float resultado;

    resultado = num1/num2;

    return resultado;
}
float multiplicar(float num1, float num2)
{
    float resultado;

    resultado = num1*num2;

    return resultado;
}

long int factorial(int num1)
{
    int i=0;
    long int numero;
    numero = num1;
    long int resultado;
    if (numero ==0)
    {
        resultado = 1;
    }
    else
    {
        resultado = numero;
        for (i=1;i<numero;i++)
        {
            resultado = resultado * i;
        }
    }

    return resultado;
}

