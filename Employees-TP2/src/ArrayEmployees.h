/*
 * ArrayEmployees.h
 *
 *  Created on: May 14, 2021
 *      Author: gonzalo
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "validations.h"

typedef struct
{
	int id;
	char name[51];
	char lastname[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;



int Employees_initEmployees(Employee* array, int length);
int Employees_idGenerator(int*idNumber);
int Employees_searchEmpty(Employee*array,int length,int*index);
Employee Employees_loadEmployee();
int Employees_addEmployee(Employee* array,int length,int*idNumber);
void Employee_printAnEmployee(Employee* anEmployee);
int Employee_printEmployees(Employee* array,int length);
int Employee_findEmployeeById(Employee* array,int length);
int Employee_removeEmployee(Employee* array, int length);
int Employee_sortEmployee(Employee* array, int length,int order);
int Employee_isOccupied(int isOccupied);
int Employee_findOccupied(Employee* array,int length);
void Employee_Menu(Employee* array, int length, int*idNumber);
void Employee_modifyMenu(Employee *array, int length);
int Employee_modify_Lastname(Employee* array,int index);
int Employee_modify_Name(Employee* array,int index);
int Employee_modify_Salary(Employee* array,int index);
int Employee_modify_Sector(Employee* array,int index);
void Employee_informMenu(Employee* array, int length);
void Employee_salaryInform(Employee* array, int length);


#endif /* ARRAYEMPLOYEES_H_ */
