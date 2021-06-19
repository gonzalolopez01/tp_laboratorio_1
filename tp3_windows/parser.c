#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)//h
{
	int q = 0;
	char id[10];
	char nombre[50];
	char horasTrabajadas[10];
	char sueldo[10];
	Employee* pEmployee;
	if(pFile!=NULL && pArrayListEmployee!= NULL)
	{
		while(!feof(pFile))
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo) == 4)
			{
				pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				if(pEmployee!=NULL)
				{
					ll_add(pArrayListEmployee,pEmployee);
					q++;
				}
			}
		}
	}
    return q;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int q=0;
	Employee* pEmployee;
	if(pFile!=NULL && pArrayListEmployee!= NULL)
	{
		while(!feof(pFile))
		{

			pEmployee = employee_new();
			fread(pEmployee,sizeof(Employee),1,pFile);
			if(feof(pFile))
			{
				break;
			}
			ll_add(pArrayListEmployee,pEmployee);
		}
	}
    return q;
}
