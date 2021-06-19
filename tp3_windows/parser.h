/*
 * parser.h
 *
 *  Created on: 8 jun. 2021
 *      Author: pame y gon
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);//h
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* PARSER_H_ */
