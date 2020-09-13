#include "funciones.h"

void calculadora()
{
    int opcion;
    float valorA;
    float valorB;
    int flagA=0;
    int flagB=0;
    char cadenaA[10];
    char cadenaB[10];

    float suma;
    float resta;
    float division;
    float multiplicacion;
    int valorAFactorial;
    int valorBFactorial;
    long int resultadoFactorialA;
    long int resultadoFactorialB;
    int verdadFactorialA;
    int verdadFactorialB;

    do
    {
        printf("1.Ingresar 1er operando A: %f\n",valorA);
        printf("2.Ingresar 2do operando B: %f\n",valorB);
        printf("3.Calcular todas las operaciones\n");
        printf("    a)Calcular la suma (A+B)\n");
        printf("    b)Calcula la resta (A-B)\n");
        printf("    c)Calcular la division (A/B)\n");
        printf("    d)Calcular la multiplicacion (A*B)\n");
        printf("    e)Calcular el factorial (A!)\n");
        printf("4.Informar resultados\n");
        printf("    a)El resultado de A+B es:\n");
        printf("    b)El resultado de A-B es:\n");
        printf("    c)El resultado de A/B es:\n");
        printf("    d)El resultado de A*B es:\n");
        printf("    e)El factorial de A es:   y El factorial de B es:   \n");
        printf("Elija una opcion: \n");
        printf("5.Salir\n");

        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("ingrese el valor de A: ");
                fflush(stdin);
                scanf("%s",&cadenaA);
                while(validacionToFloat(cadenaA) == 0)
                {
                    printf("valor invalido, ingrese valor nuevamente: ");
                    fflush(stdin);
                    scanf("%s",cadenaA);
                }
                valorA = pasarAFloat(cadenaA);
                flagA=1;
                system("cls");

            break;
            case 2:
                printf("ingrese el valor de B: ");
                fflush(stdin);
                scanf("%s",&cadenaB);
                while(validacionToFloat(cadenaB) == 0)
                {
                    printf("valor invalido, ingrese valor nuevamente: ");
                    fflush(stdin);
                    scanf("%s",cadenaB);
                }
                valorB = pasarAFloat(cadenaB);
                flagB=1;
                system("cls");

            break;
            case 3:
                if((flagA == 0) || flagB ==0)
                {
                    printf("Primero debe completar el ingreso de valores");
                    getch();
                    system("cls");
                    break;
                }
                suma=sumar(valorA,valorB);
                resta=restar(valorA,valorB);
                if (valorB!=0)
                    division=dividir(valorA,valorB);
                multiplicacion=multiplicar(valorA,valorB);
                valorAFactorial=valorA;
                valorBFactorial=valorB;
                resultadoFactorialA = factorial(valorAFactorial);
                resultadoFactorialB = factorial(valorBFactorial);
                printf ("operaciones realizadas");
                getch();
                system("cls");
            break;
            case 4:
                printf("El resultado A+B es: %f\n",suma);
                printf("El resulado de A-B es: %f\n",resta);
                if (valorB!=0)
                {
                    printf("El resultado de A/B es: %f\n",division);
                }
                else
                {
                    printf("No es posible dividir por cero");
                }
                printf("El resultado de A*B es: %f\n",multiplicacion);
                /*if (valorA-valorAFactorial)
                {
                    printf("no se puede realizar el factorial de numero con decimelas y numeor negativos");
                }
                else
                {
                }*/
                printf("El factorial de A es: %d\n",resultadoFactorialA);
                printf("El factorial de B es: %d\n",resultadoFactorialB);

                getch();
                system("cls");

                break;
            case 5:
                printf("Fin del programa");
            break;
        }

    }while(opcion!=5);
}


float cadenaToFloat(char cadena[10]) //la cade
{
    int nro;
    int i;
    int n;
    int m;
    int nros;
    int longitudCadena;
    int elementoEnteroCadena;
    int elementoDecimalCadena;
    float numero;
    float numeroFloat;
    float enterosFloat=0;
    float decimalesFloat=0;
    float numerosEnteros;
    int ascci[11];
    int cadenaEntero[10];
    int cadenaDecimal[10];
    int qEntero=0;
    int qDecimal=0;
    int punto;

    nros=48; //CODIGO ASCCI
    for (i=0;i<10;i++)
        ascci[i]=0;
    for (i=0; i<10; i++)
    {
        ascci[i]=ascci[i]+nros;
        nros++;
    }

    longitudCadena=strlen(cadena); //largo de la cadena

    for (i=0;i<longitudCadena;i++) //relleno parte entera parte decimal
    {
        if (cadena[i]!='.')
        {
            cadenaEntero[i]=(int)cadena[i];
            qEntero++;
        }
        else
        {
            punto=i+1;
            for (m=0;m<(longitudCadena-punto);m++)
            {
                i++;
                cadenaDecimal[m]=(int)cadena[i];
                qDecimal++;
            }
        }
    }

    for(i=0;i<qEntero;i++)
    {
        for(n=0;n<10;n++) //bucle de comparacion ASCCI
        {
            if (cadenaEntero[i] == ascci[n])
                {
                    numero=n;
                }
        }
        enterosFloat = enterosFloat + numero * (potencia(10,qEntero-i-1));
    }
    for(i=0;i<qDecimal;i++)
    {
        for(n=0;n<10;n++) //bucle de comparacion ASCCI
        {
            if (cadenaDecimal[i] == ascci[n])
                {
                    numero=n;
                }
        }
        decimalesFloat = decimalesFloat + numero * (potencia(10,(i+1)*-1));
    }
    numeroFloat=enterosFloat+decimalesFloat;
    return numeroFloat;
}

float potencia(float base, float exponente)
{
    float resultado=1;
    int i;

    if (exponente < 0)
    {
        exponente=exponente*-1;
        for(i=0;i<exponente;i++)
        {
            resultado=resultado*base;
        }
        resultado=1/resultado;
    }
    else
    {
        for(i=0;i<exponente;i++)
        {
            resultado=resultado*base;
        }
    }

    return resultado;
}

int validacionToFloat(char cadena[10]) //valor 1 si esta aprobado
{
    int nros;
    int i;
    int n;
    int qPuntos = 0;
    int valor = 1;

    if (cadena[0]=='-') //si es negativo
    {
        for(i=1;i<strlen(cadena);i++)
        {
            if ((cadena[i]>=48) && (cadena[i]<=57) || cadena[i] == 46 )
            {
                for(n=0;n<strlen(cadena);n++)
                {
                    if (cadena[n]==46)
                        qPuntos++;
                }
                if (qPuntos>1)
                    valor=0;
            }
            else
            {
                valor = 0;
            }
        }
    }
    else
    {
        for(i=0;i<strlen(cadena);i++) //si es positvo
        {
            if ((cadena[i]>=48) && (cadena[i]<=57) || cadena[i] == 46 )
            {
                for(n=0;n<strlen(cadena);n++)
                {
                    if (cadena[n]==46)
                        qPuntos++;
                }
                if (qPuntos>1)
                    valor=0;
            }
            else
            {
                valor = 0;
            }
        }
    }

    return valor;
}


float pasarAFloat(char cadena[10]) //la cadena ya aprobada en validacion se pasa a float
{
    int i=0;
    int n=0;
    float valor=1;
    int largo;
    largo = strlen(cadena);

    if(cadena[0] == '-')
    {
        for(i=n;i<largo;i++)
        {
            cadena[i]=cadena[i+1];
        }
        valor = (cadenaToFloat(cadena))*(-1);
    }
    else
    {
        valor = cadenaToFloat(cadena);

    }
return valor;
}

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

