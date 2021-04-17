/*
 * validaciones.h
 *
 *  Created on: Apr 17, 2021
 *      Author: gonzalo
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

int V_ggets(char string[], int size);
int V_sizeValidation(char string[], int size);
void V_inputText(char string[],int size,char text[256]);
int V_isDecimalNumber(char string[]);
int V_isThereDecimalDot(char string[]);

#endif /* VALIDACIONES_H_ */
