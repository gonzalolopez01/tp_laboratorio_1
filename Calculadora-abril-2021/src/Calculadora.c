/*
 ============================================================================
 Name        : Calculadora.c
 Author      : Gonzalo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

int main(void){

	setbuf(stdout, NULL);

	return EXIT_SUCCESS;
}

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

