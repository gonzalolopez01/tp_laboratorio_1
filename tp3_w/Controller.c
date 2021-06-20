#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"


//static int menu_edit(int option,char*nombre,char*horasTrabajadas,char*sueldo);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int q=0;
	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile!=NULL)
	{
		q = parser_EmployeeFromText(pFile, pArrayListEmployee);
	}
	fclose(pFile);
    return q;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int q=0;
	FILE* pFile;
	pFile = fopen(path,"rb");
	if(pFile!=NULL)
	{
		q = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
	}
	fclose(pFile);
	return q;
}

/** \brief Alta de empleados
 *
 * \param path int* id
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int*id)
{
	int success = -1;
	char idStr[15];
	char nombreStr[50];
	char horasTrabajadasStr[20];
	char sueldoStr[15];
	Employee* pEmployee;
	sprintf(idStr,"%d",*id);
	if(pArrayListEmployee!=NULL)
	{
		printf("--------------------------------------\n");
		printf("--------------------------------------\n");
		printf("----------------ALTA------------------\n");
		printf("--------------------------------------\n");
		printf("--------------------------------------\n");
		if(!(employee_setParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr)))
		{
			pEmployee = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
			if(pEmployee!=NULL)
			{
				ll_add(pArrayListEmployee,pEmployee);
				*id = *id+1;
				success = 0;
			}
		}
	}
    return success;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int success = -1;
	Employee* pAux = NULL;
	int index;
	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		printf("--------------------------------------\n");
		printf("--------------------------------------\n");
		printf("-----------EDITAR EMPLEADO------------\n");
		printf("--------------------------------------\n");
		printf("--------------------------------------\n");
		input_IntNumberMin(&index, "NUMERO DE ID: ", "ERROR - NUMERO DE ID: ", 1, "VALOR INVALIDO");
		if((index = controller_getIndexByID(pArrayListEmployee, index)) != -1)
		{
			pAux = (Employee*)ll_get(pArrayListEmployee, index);
			employee_showEmployee(pAux);
			controller_editMenu(pArrayListEmployee,pAux,index);
			success = 0;
		}
		else
		{
			printf("No se encontro el ID\n");
		}
	}
    return success;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int success = -1;
	Employee* pAux = NULL;
	int index;
	char confirm;
	if(pArrayListEmployee!=NULL)
	{
		printf("--------------------------------------\n");
		printf("--------------------------------------\n");
		printf("--------------BAJA EMPLEADO-----------\n");
		printf("--------------------------------------\n");
		printf("--------------------------------------\n");
		input_IntNumberMin(&index, "NUMERO DE ID: ", "ERROR - NUMERO DE ID: ", 1, "VALOR INVALIDO");
		index = controller_getIndexByID(pArrayListEmployee, index);
		pAux = (Employee*)ll_get(pArrayListEmployee, index);
		if(index!=-1)
		{
			employee_showEmployee(pAux);
			confirm = input_ClosedQuestion("Este empleado se eliminara, desea continuar? 'S'/'N'", "Error, opcion invalida \n");
			if(confirm == 's')
			{
				ll_remove(pArrayListEmployee, index);
				employee_delete(pAux);
				printf("El empleado fue dado de baja\n");
				success = 0;
			}
			else
			{
				printf("No se realizaron los cambios\n");
			}
		}
		else
		{
			printf("No se encontro el ID\n");
		}

	}
    return success;
}

/** \brief Listar empleados
 *
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int success = -1;
	int i;
	int len;
	Employee* aux;
	if(pArrayListEmployee!=NULL)
	{
		len = ll_len(pArrayListEmployee);
		for(i=0; i<len; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);
			employee_showEmployee(aux);
		}
		success = 0;
	}
	return success;
}

/** \brief Ordenar empleados
 *
 * \
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int success = -1;
	if(pArrayListEmployee!=NULL)
	{
		controller_sortMenu(pArrayListEmployee);
		success = 0;
	}

    return success;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int success = -1;
	int len;
	int i;
	Employee* pAux;
	if (pArrayListEmployee!=NULL)
	{
		len = ll_len(pArrayListEmployee);
		FILE* pFile;
		pFile = fopen(path,"w");
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		if(pFile!=NULL && len > 0)
		{
			for(i=0; i<len; i++)
			{
				pAux = ll_get(pArrayListEmployee, i);
				if(pAux!=NULL)
				{
					fprintf(pFile,"%d,%s,%d,%d\n",pAux->id,
												  pAux->nombre,
												  pAux->horasTrabajadas,
												  pAux->sueldo);
				}
				else
				{
					break;
				}
			}
			if(i == len)
			{
				success = 0;
			}
		}
		fclose(pFile);
	}
	return success;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int success = -1;
	int len;
	int i;
	Employee* pAux;
	if (pArrayListEmployee!=NULL)
	{
		len = ll_len(pArrayListEmployee);
		FILE* pFile;
		pFile = fopen(path,"wb");
		if(pFile!=NULL && len > 0)
		{
			for(i=0; i<len; i++)
			{
				pAux = ll_get(pArrayListEmployee, i);
				if(pAux!=NULL)
				{
					fwrite(pAux,sizeof(Employee),1,pFile);
				}
				else
				{
					break;
				}
			}
			if(i == len)
			{
				success = 0;
			}
		}
		fclose(pFile);
	}

    return success;
}


//----------lo que agrego----------


/** \brief Lee el ultimo Id.
 *
 * \param path char*
 * \param int *id
 * \return int
 *
 */
int controller_loadID(char* path, int *id)
{
	int success = -1;
	char _id[15];
	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile!=NULL && (fscanf(pFile,"%s\n", _id) == 1))
	{
		*id=atoi(_id);
		success = 0;
	}
	fclose(pFile);
    return success;
}
/** \brief Guarda el ultimo id en un archivo.
 *
 * \param path char*
 * \param int id
 * \return int
 *
 */
int controller_saveID(char* path , int id)
{
	int success = -1;
	FILE* pFile;
	pFile = fopen(path,"w");
	if(pFile!=NULL)
	{
		fprintf(pFile,"%d\n",id);
		success = 0;
	}
	fclose(pFile);
	return success;
}
/** \brief Menu de modificar
 *
 * \param
 * \param
 * \return
 *
 */
void controller_editMenu(LinkedList* pArrayListEmployee, Employee* pAux, int index)
{
	int option;
	char nombre[50];
	char horasTrabajadas[15];
	char sueldo[15];
	char confirm;
	int auxId;
	char auxNombre[50];
	int auxHorasTrabajadas;
	int auxSueldo;

	Employee* aux;
	aux = employee_new();

	employee_getId(pAux,&auxId);
	employee_getNombre(pAux, auxNombre);
	employee_getHorasTrabajadas(pAux, &auxHorasTrabajadas);
	employee_getSueldo(pAux, &auxSueldo);
	employee_setId(aux, auxId);
	employee_setNombre(aux, auxNombre);
	employee_setHorasTrabajadas(aux, auxHorasTrabajadas);
	employee_setSueldo(aux, auxSueldo);
	do
	{
		printf("----------------\n");
		printf("-----CAMPOS-----\n");
		printf("----------------\n");
		input_MenuOption(&option, "1.Nombre\n2.Horas Trabajadas\n3.Sueldo\n4.Salir\n",
						"Valor invalido reingrese opcion: ",1, 3, 4,"Opcion invalida");
		switch(option)
		{
			case 1:
				employee_inputNombre(nombre);
				employee_setNombre(aux, nombre);
				break;
			case 2:
				employee_inputHorasTrabajadas(horasTrabajadas);
				employee_setHorasTrabajadas(aux, atoi(horasTrabajadas));
				break;
			case 3:
				employee_inputSueldo(sueldo);
				employee_setSueldo(aux, atoi(sueldo));
				break;
			case 4:
				printf("\t---Datos Originales---\n");
				employee_showEmployee(pAux);
				printf("\t-------Cambios--------\n");
				employee_showEmployee(aux);
				confirm = input_ClosedQuestion("Desea realizar estos cambios? 'S'/'N'", "Erros, opcion invalida \n");
				if(confirm == 's')
				{
					ll_remove(pArrayListEmployee, index);
					employee_delete(pAux);
					ll_set(pArrayListEmployee, index, aux);
					controller_ListEmployee(pArrayListEmployee);
				}
				else
				{
					printf("No se realizaron los cambios\n");
					employee_delete(aux);
				}
				break;
		}
	}while(option != 4);

}
/** \brief Menu de los listados
 *
 * \param
 * \param
 * \return
 *
 */
void controller_sortMenu(LinkedList* pArrayListEmployee)
{
	int option;
	LinkedList* pClon;
	pClon = ll_clone(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && pClon!= NULL)
	{
		do
		{
			printf("--------------------------------------\n");
			printf("--------------------------------------\n");
			printf("---------------LISTADOS---------------\n");
			printf("--------------------------------------\n");
			printf("--------------------------------------\n");
			input_MenuOption(&option, "1.Listado por ID\n2.Listado por Nombre\n3.Listado por Horas Trabajadas\n4.Listado por Sueldo\n5.Salir",
							"Valor invalido reingrese opcion: ",1, 4, 5,"Opcion invalida");
			switch(option)
			{
				case 1:
					input_MenuOption(&option, "---------\n--ORDEN--\n---------\n1.Ascendente\n2.Descendente\n3.Salir\n", "Valor invalido. ", 1, 2, 3, "Valor fuera de rango ");
					if(option == 1)
					{
						ll_sort(pClon, employee_compareByID, 1);
						controller_ListEmployee(pClon);
					}
					else
					{
						ll_sort(pClon, employee_compareByID, 0);
						controller_ListEmployee(pClon);
					}
					break;
				case 2:
					input_MenuOption(&option, "---------\n--ORDEN--\n---------\n1.Ascendente\n2.Descendente\n3.Salir\n", "Valor invalido. ", 1, 2, 3, "Valor fuera de rango ");
					if(option == 1)
					{
						ll_sort(pClon, employee_compareByName, 1);
						controller_ListEmployee(pClon);
					}
					else
					{
						ll_sort(pClon, employee_compareByName, 0);
						controller_ListEmployee(pClon);
					}
					break;
				case 3:
					input_MenuOption(&option, "---------\n--ORDEN--\n---------\n1.Ascendente\n2.Descendente\n3.Salir\n", "Valor invalido. ", 1, 2, 3, "Valor fuera de rango ");
					if(option == 1)
					{
						ll_sort(pClon, employee_compareByHorasTrabajadas,1);
						controller_ListEmployee(pClon);
					}
					else
					{
						ll_sort(pClon, employee_compareByHorasTrabajadas,0);
						controller_ListEmployee(pClon);
					}
					break;

				case 4:
					input_MenuOption(&option, "---------\n--ORDEN--\n---------\n1.Ascendente\n2.Descendente\n3.Salir\n", "Valor invalido. ", 1, 2, 3, "Valor fuera de rango ");
					if(option == 1)
					{
						ll_sort(pClon, employee_compareBySueldo,1);
						controller_ListEmployee(pClon);
					}
					else
					{
						ll_sort(pClon, employee_compareBySueldo,0);
						controller_ListEmployee(pClon);
					}
					break;
			}
		}while(option != 5);
		ll_clear(pClon);
		ll_deleteLinkedList(pClon);
	}
}
/** \brief Funcion que obitene el index por medio del ingreso del id
 *
 * \param
 * \param
 * \return
 *
 */
int controller_getIndexByID(LinkedList* pArrayListEmployee,int ID)
{
	int len;
	int i;
	int index = -1;
	Employee* pAux;
	if(pArrayListEmployee!=NULL)
	{
		len = ll_len(pArrayListEmployee);
		if(len > 0)
		{
			for (i=0; i<len; i++)
			{
				pAux = ll_get(pArrayListEmployee, i);
				if(pAux!=NULL)
				{
					if(pAux->id == ID)
					{
						index = i;
						break;
					}
				}
			}
		}
	}
	return index;
}
/** \brief Menu principal
 *
 * \param
 * \param
 *
 *
 */
void controller_Menu(LinkedList* pArrayListEmployee)
{
	int saveListFlag = 0;
	int flag = 0;
	int option;
	char question;
	int pId;
	controller_loadID("idTxT.txt", &pId);

	do{
		printf("****************************************************************************\n");
		printf("Trabajo practico 3 - Implementacion biblioteca LinkedList \n");
		printf("****************************************************************************\n");
		printf("Menu:\n");
		printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
		printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
		printf("3. Alta de empleado\n");
		printf("4. Modificar datos de empleado\n");
		printf("5. Baja de empleado\n");
		printf("6. Listar empleados\n");
		printf("7. Ordenar empleados\n");
		printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
		printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
		printf("10. Salir\n");
		printf("*****************************************************************************\n");
		input_IntegerNumber(&option, "Ingrese la opcion deseada: ", "Error, valor incorrecto \n");
		switch(option)
		{
			case 1:
				//ll_clear(pArrayListEmployee);
				controller_loadFromText("data.csv",pArrayListEmployee);
				printf("La lista se cargo con exito\n");
				flag = 1;
				break;
			case 2:
				//ll_clear(pArrayListEmployee);
				controller_loadFromBinary("data.dat", pArrayListEmployee);
				printf("La lista se cargo con exito\n");
				flag = 1;
				break;
			case 3:
				if(!controller_addEmployee(pArrayListEmployee, &pId))
				{
					flag = 1;
				}
				break;
			case 4:
				if(!controller_editEmployee(pArrayListEmployee))
				{
					flag = 1;
				}
				break;
			case 5:
				controller_ListEmployee(pArrayListEmployee);
				if(!controller_removeEmployee(pArrayListEmployee))
				{
					flag = 1;
				}
				break;
			case 6:
				controller_ListEmployee(pArrayListEmployee);
				break;
			case 7:
				controller_sortEmployee(pArrayListEmployee);
				break;
			case 8:
				if(flag)
				{
					question = input_ClosedQuestion("Se guardaran los datos, desea continuar? 'S'/'N'\n","Opcion invalida \n");
					if(question == 's')
					{
						controller_saveAsText("data.csv", pArrayListEmployee);
						controller_saveID("idTxt.txt", pId);
						saveListFlag = 1;
					}
				}
				else
				{
					printf("--No hay modificaciones para guardar--\n");
				}

				break;
			case 9:
				if(flag)
				{
					question = input_ClosedQuestion("Se guardaran los datos, desea continuar? 'S'/'N'\n","Opcion invalida \n");
					if(question == 's')
					{
						controller_saveAsBinary("data.dat",pArrayListEmployee);
						controller_saveID("idTxt.txt", pId);
						saveListFlag = 1;
					}

				}
				else
				{
					printf("--No hay modificaciones para guardar--\n");
				}
				break;
			case 10:
				if(saveListFlag)
				{
					question = input_ClosedQuestion("Esta por salir del programa. Desea continuar? 'S'/'N': \n", "Opcion invalida \n");
					if(question == 's')
					{
						printf("---Fin del Programa---\n");
						option = 11;
					}
				}
				else
				{
					question = input_ClosedQuestion("No se guardaron los cambios. Desea salir de todos modos? 'S'/'N': \n", "Opcion invalida \n");
					if(question == 's')
					{
						printf("---Fin del Programa---\n");
						option = 11;
					}
				}
				break;
			default:
				printf("---opcion invalida---\n");
				break;
		}
	}while(option != 11);
}
