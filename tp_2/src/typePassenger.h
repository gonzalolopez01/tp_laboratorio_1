/*
 * typePassenger.h
 *
 *  Created on: 28 jun. 2022
 *      Author: gonzalo
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

typedef struct{
    int id;
    char type[51];
}sTypePassenger;

#endif /* TYPEPASSENGER_H_ */

int typeP_loadType(sTypePassenger list[], int len, int id, char description[]);
void typeP_printTypeRow(sTypePassenger typeP);
int typeP_printTypes(sTypePassenger* list, int len);
int typeP_findType(sTypePassenger* list, int len , int idQuery, int* pIndice);
int typeP_isValidType(sTypePassenger* list, int len, int idType);
