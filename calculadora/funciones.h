#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
/** \brief reliza potencia
 *
 * \param pide base y expnente
 * \return la potencia
 */
float potencia(float base, float exponente);

/** \brief pasa una cadena a numero float
 *
 * \param cadena de caracteres
 * \return devuelve float
 *
 */
float cadenaToFloat(char cadena[10]);

/** \brief pasa a float cadena de caracateres luego de verificar si era un numero positivo o negativo
 *
 * \param cadena de caracteres
 * \return numeor en float
 *
 */
float pasarAFloat(char cadena[10]);

/** \brief suma dos numeros
 *
 * \param do valores float
 * \return suma en float
 *
 */
float sumar(float num1, float num2);

/** \brief resta dos valores
 *
 * \param 2 valores float
 * \return resultado en float
 *
 */

 /** \brief resta dos valores float
  * \param 2 valores float
  * \return resultado en float
  *
  */

float restar(float num1, float num2);
/** \brief division de dos valores
 *
 * \param 2 valores float
 * \param
 * \return devuelve disivion en float
 *
 */
float dividir(float num1, float num2);
/** \brief multiplica dos valores float
 *
 * \param
 * \param 2 valores float
 * \return resultado en float
 */

float multiplicar(float num1, float num2);
/** \brief reliza el factorial de numero enteros
 *
 * \param toma valores float
 * \param
 * \return resultado en entero
 *
 */
long int factorial(int num1);
/** \brief verifica que la cadena de caracteres contenga numeros para que puedan ser pasados a float
 *
 * \param cadena de caracteres
 * \param
 * \return un valor 0 o 1
 *
 */

int validacionToFloat(char cadena[10]);

void menu();
