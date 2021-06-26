/*
 ============================================================================
 Name        : Employees-TP2.c
 Author      : Gonzalo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validations.h"


#define SE 1000

int main(void) {

	Employee list[SE];/*={{1,"Juan","Lopez",50000,1,0},
					{2,"Raul","Sanchez",70000,1,0},
					{3,"German","Lopez",80000,4,0},
					{4,"Maria","Crespo",75000,3,0},
					{5,"Julio","Lopez",75000,2,0}};*/ //cambiar el indice en init


	setbuf(stdout, NULL);
	int id=0;
	Employees_initEmployees(list, SE);
	Employee_Menu(list, SE, &id);
	/*float num;
	num = V_inputFloatNumberMin(10, "ingrese", "error, ing", 1,"errorRangeText");
	printf("%f",num);*/


	return EXIT_SUCCESS;
}
