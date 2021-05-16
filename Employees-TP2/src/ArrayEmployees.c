/*
 * ArrayEmployees.c
 *
 *  Created on: May 14, 2021
 *      Author: gonzalo
 */

#include "ArrayEmployees.h"


int Employees_idGenerator(int*idNumber)
{
	int outcome = 0;
	if(idNumber != NULL)
	{
		*idNumber=*idNumber + 1;
		outcome = 1;
	}
	return outcome;
}
int Employees_initEmployees(Employee* array, int length)
{
	int outcome;
	int i;

	if(array!=NULL)
	{
		for(i=0;i<length;i++)
		{
			(array+i)->isEmpty = 1;
		}
		outcome = 1;
	}
	return outcome;
}
int Employees_searchEmpty(Employee*array,int length,int*index)
{
	int outcome=-1;
	if(array!=NULL && length > 0 && index!=NULL)
	{
		*index = -1;//array lleno
		for(int i=0;i<length;i++)
		{
			if((array+i)->isEmpty == 1)
			{
				*index=i;
				break;
			}
		}
		outcome = 0;//no hubo error, dio posicion o array lleno
	}
	return outcome;
}
Employee Employees_loadEmployee()
{
	Employee auxiliar;


	V_inputAlpha(auxiliar.name, 51, "Ingrese Nombre: ", "Valor invalido, ingrese nombre: ");
	V_inputAlpha(auxiliar.lastname, 51, "Ingrese Apellido: ", "Valor invalido, ingrese apellido: ");
	auxiliar.salary = V_inputFloatNumberMin(15, "Ingrese Salario: ", "Error, ingrese salario: ", 1, "fuera de rango:");
	auxiliar.sector = V_inputIntNumberMin(15, "Ingrese sector: ", "Error, ingrese sector: ", 1, "Valor fuera de rango: ");

	return auxiliar;
}
int Employees_addEmployee(Employee* array,int length,int*idNumber)
{
	int outcome=0;
	if(array!=NULL && length > 0)
	{
		Employee auxiliar;
		int index;
		int searchEmpty;
		searchEmpty = Employees_searchEmpty(array, length, &index);

		if(searchEmpty == 0 && index != -1)
		{
			auxiliar = Employees_loadEmployee();
			Employees_idGenerator(idNumber);//sin ampersand porque dentro del puntero ya esta la dir
			*(array+index) = auxiliar;
			(array+index)->isEmpty = 0;
			(array+index)->id = *idNumber;

			outcome = 1;
		}
		else
		{
			printf("No hay mas espacio disponible\n");
		}
	}
	return outcome;
}
void Employee_printAnEmployee(Employee* anEmployee)
{
	printf("%-5d %-12s %-11s %-15.2f %d\n",anEmployee->id,anEmployee->lastname,
								anEmployee->name,anEmployee->salary,anEmployee->sector);
}
int Employee_printEmployees(Employee* array,int length)
{
	int i;
	int outcome = -1;
	int quantity = 0;
	if(array!=NULL)
	{
		printf("ID ||  APELLIDO  ||  NOMBRE ||  SALARIO  ||  SECTOR\n");
		for(i=0;i<length;i++)
		{
			if((array+i)->isEmpty == 0)
			Employee_printAnEmployee(array+i);
			quantity++;
		}
		if(quantity > 0)
		{
			outcome = 0;
		}
	}
	return outcome;
}
int Employee_findEmployeeById(Employee* array,int length)
{
	int index = -1;//-1: no se encontro el id
	if(array!=NULL)
	{
		int idNumber;
		idNumber = V_inputIntegerNumber(10, "Ingrese numero de Id: ", "Error, ingrese numero de Id: ");
		for(int i=0;i<length;i++)
		{
			if(idNumber == (array+i)->id && (array+i)->isEmpty == 0)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
int Employee_removeEmployee(Employee* array, int length)
{
	int outcome = -1;
	int flag = 0;
	int index;
	char answer;
	if(array!=NULL)
	{
		flag=Employee_printEmployees(array, length);
		if(flag == 0)
		{
			index = Employee_findEmployeeById(array, length);
			if(index == -1)
			{
				printf("No se encontro el id ingresado.\n");
			}
			else
			{
				Employee_printAnEmployee(array+index);
				printf("Esta por eliminar este empleado, presion 's' para confirmar");
				scanf("%c",&answer);
				if(answer=='s')
				{
					(array+index)->isEmpty = 1;//baja
					outcome = 0;
				}
			}
		}
	}
	return outcome;
}
int Employee_sortEmployee(Employee* array, int length,int order)
{
	int outcome=-1;
	Employee auxiliar;
	if(array!=NULL)
	{
		switch(order)
		{
		case 0:
			for(int i=0;i<length-1;i++)
			{

				for(int j=i+1;j<length;j++)
				{

					if((array+i)->isEmpty == 0 && (array+j)->isEmpty == 0)
					{
						if(strcmp((array+i)->lastname,(array+j)->lastname) > 0)
						{

							auxiliar = *(array+i);
							*(array+i) = *(array+j);
							*(array+j) = auxiliar;
						}
						else
						{
							if((strcmp((array+i)->lastname,(array+j)->lastname) == 0) &&
									((array+i)->sector > (array+j)->sector))
							{
								auxiliar = *(array+i);
								*(array+i) = *(array+j);
								*(array+j) = auxiliar;
							}
						}
					}
				}
			}
			break;
		case 1:
			for(int i=0;i<length-1;i++)
			{

				for(int j=i+1;j<length;j++)
				{

					if((array+i)->isEmpty == 0 && (array+j)->isEmpty == 0)
					{
						if(strcmp((array+i)->lastname,(array+j)->lastname) < 0)
						{

							auxiliar = *(array+i);
							*(array+i) = *(array+j);
							*(array+j) = auxiliar;
						}
						else
						{
							if((strcmp((array+i)->lastname,(array+j)->lastname) == 0) &&
									((array+i)->sector < (array+j)->sector))
							{
								auxiliar = *(array+i);
								*(array+i) = *(array+j);
								*(array+j) = auxiliar;
							}
						}
					}
				}
			}
			break;
		}

		outcome = 0;
	}
	return outcome;
}
//----------------------
int Employee_isOccupied(int isOccupied)
{
	int outcome = 0;
	if(isOccupied == 0)
	{
		outcome = 1;
	}
	return outcome;
}
int Employee_findOccupied(Employee* array,int length)
{
	int isOccupied;
	int outcome = -1;
	if(array!=NULL)
	{
		outcome = 0; //significa que no hay lugar ocupado
		for(int i=0;i<length;i++)
		{
			isOccupied = Employee_isOccupied((array+i)->isEmpty);
			if(isOccupied)
			{
				outcome = 1; //hay por lo menos un lugar ocupado
				break;
			}
		}
	}
	return outcome;
}
void Employee_Menu(Employee* array, int length, int*idNumber)
{
	if(array!=NULL)
	{
		int option;
		int isFull;
		if(array!=NULL)
		{
			do
			{
				isFull = Employee_findOccupied(array, length);
				//printf("hola: %d\n",isFull);
				if(isFull == 1)
				{
					option = V_menuOptionValidation(10, "1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.Salir\n", "Valor invalido, vuelva a ingresar opcion: \n",1,4,5, "Valor fuera de rango\n");
					switch(option)
					{
						case 1:
							Employees_addEmployee(array, length, idNumber);
							break;
						case 2:
							Employee_modifyMenu(array, length);
							break;
						case 3:
							Employee_removeEmployee(array, length);
							break;
						case 4:
							Employee_informMenu(array, length);
							break;
					}
				}
				else
				{
					option = V_menuOptionValidation(10, "1.ALTAS\n5.SALIR\n", "Valor invalido, vuelva a ingresar opcion: \n", 1, 1, 5, "Valor fuera de rango\n");
					switch(option)
					{
					case 1:
						Employees_addEmployee(array, length, idNumber);
						break;
					}
				}
			}while(option != 5);
		}
	}
}
void Employee_modifyMenu(Employee *array, int length)
{
	if(array!=NULL)
	{
		int index;
		int option;
		Employee_printEmployees(array, length);
		index = Employee_findEmployeeById(array, length);
		if (index != -1)
		{
			do
			{
				option = V_menuOptionValidation(10, "-MODIFICAR-\n1.Apellido\n2.Nombre\n3.Salario\n4.Sector\n5.Salir\n", "Valor invalido, vuelva a ingresar opcion: \n", 1, 4, 5, "Valor fuera de rando, ingrese opcion: \n");
				switch(option)
				{
					case 1:
						Employee_modify_Lastname(array, index);
						break;
					case 2:
						Employee_modify_Name(array, index);
						break;
					case 3:
						Employee_modify_Salary(array, index);
						break;
					case 4:
						Employee_modify_Sector(array, index);
						break;
				}
			}while(option != 5);
		}
		else
		{
			printf("No se encontro el numero de ID ingresado\n");
		}
	}
}
//---------------
int Employee_modify_Lastname(Employee* array,int index)
{
	int outcome = -1;
	char confirmation;
	char surname[51];
	if(array!=NULL)
	{
		V_inputAlpha(surname, 51, "Ingrese nuevo apellido: ", "Valor invalido, ingrese nuevo apellido: ");
		printf("Esta por realizar una modificacion, desea continuar? s/n: ");
		scanf("%c",&confirmation);
		if(confirmation == 's')
		{
			strcpy((array+index)->lastname,surname);
			printf("La modificacion se realizo con exito\n");
		}
		else
		{
			printf("La modificacion fue cancelada\n");
		}
		outcome = 0;
	}

	return outcome;
}
int Employee_modify_Name(Employee* array,int index)
{
	int outcome = -1;
	char confirmation;
	char name[51];
	if(array!=NULL)
	{
		V_inputAlpha(name, 51, "Ingrese nuevo nombre: ", "Valor invalido, ingrese nuevo nombre: ");
		printf("Esta por realizar una modificacion, desea continuar? s/n: ");
		scanf("%c",&confirmation);
		if(confirmation == 's')
		{
			strcpy((array+index)->name,name);
			printf("La modificacion se realizo con exito\n");
		}
		else
		{
			printf("La modificacion fue cancelada\n");
		}
		outcome = 0;
	}

	return outcome;
}
int Employee_modify_Salary(Employee* array,int index)
{
	int outcome = -1;
	char confirmation;
	float floatNumber;
	if(array!=NULL)
	{
		floatNumber = V_inputFloatNumberMin(10, "Ingrese nuevo salario: \n", "Valor invalido, ingrese nuevo salario: \n",1,"Valor fuera de rango\n");
		printf("Esta por realizar una modificacion, desea continuar? s/n: ");
		scanf("%c",&confirmation);
		if(confirmation == 's')
		{
			(array+index)->salary = floatNumber;
			printf("La modificacion se realizo con exito\n");
		}
		else
		{
			printf("La modificacion fue cancelada\n");
		}
		outcome = 0;
	}

	return outcome;
}
int Employee_modify_Sector(Employee* array,int index)
{
	int outcome = -1;
	char confirmation;
	int intNumber;
	if(array!=NULL)
	{
		intNumber = V_inputIntNumberMin(10, "Ingrese nuevo sector: \n","Error, ingrese nuevo sector: \n", 1, "Valor fuera de rango\n");
		printf("Esta por realizar una modificacion, desea continuar? s/n: ");
		scanf("%c",&confirmation);
		if(confirmation == 's')
		{
			(array+index)->sector = intNumber;
			printf("La modificacion se realizo con exito\n");
		}
		else
		{
			printf("La modificacion fue cancelada\n");
		}
		outcome = 0;
	}

	return outcome;
}
//---------------
void Employee_informMenu(Employee* array, int length)
{
	int option;
	if(array!=NULL)
	{
		do
		{
		option = V_menuOptionValidation(10, "INFORME\n1.Listar por apellido y sector de manera ascendente\n2.Listar por apellido y sector de manera descendente\n3.Informe Salarios\n4.Salir\n", "Valor invalido, ingrese una opcion: ", 1, 3, 4, "Valor fuera de rango\n");
		switch(option)
		{
			case 1:
				Employee_sortEmployee(array, length, 0);
				Employee_printEmployees(array, length);
				break;
			case 2:
				Employee_sortEmployee(array, length, 1);
				Employee_printEmployees(array, length);
				break;
			case 3:
				Employee_salaryInform(array, length);
				break;
		}

		}while(option != 4);
	}
}
void Employee_salaryInform(Employee* array, int length)
{
	float totalSalary = 0;
	float averageSalary = 0;
	int counter = 0;
	int overAverageSalaryCounter = 0;

	if(array!=NULL)
	{
		for(int i=0;i<length;i++)
		{
			if((array+i)->isEmpty == 0)
			{
				totalSalary = totalSalary + (array+i)->salary;
				counter++;
			}
		}
		averageSalary = totalSalary / counter;
		for(int i=0;i<length;i++)
		{
			if((array+i)->salary > averageSalary)
			{
				overAverageSalaryCounter++;
			}
		}
	}
	printf("TOTAL DE SALARIO ||  SALARIO PROMEDIO || EMPLEADO QUE SUPERAN EL PROMEDIO\n");
	printf("%-20.2f %-20.2f %-30d\n", totalSalary,averageSalary,overAverageSalaryCounter);
}
