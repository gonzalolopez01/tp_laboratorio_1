#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#define SIZENOMBRE 128


static int isValidId(int id);
static int isValidName(char* nombre);
static int isValidHorasTrabajadas(int horasTrabajadas);
static int isValidSueldo(int sueldo);

/** \brief Constructor
 *
 * \param
 * \param
 * \return
 *
 */
Employee* employee_new()
{
	Employee* newEmployee;
	newEmployee = (Employee*)malloc(sizeof(Employee));

	return newEmployee;
}
/** \brief Constructor con parametros
 *
 * \param
 * \param
 * \return
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pEmployee;
	pEmployee = employee_new();

	if(pEmployee!=NULL)
	{
		if(!employee_setId(pEmployee, atoi(idStr)) &&
			!employee_setNombre(pEmployee, nombreStr) &&
			!employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr)) &&
			!employee_setSueldo(pEmployee, atoi(sueldoStr)))
		{
			return pEmployee;
		}else
		{
			employee_delete(pEmployee);
			pEmployee = NULL;
			return pEmployee;
		}
	}
	return NULL;
}
/** \brief libera de memoria heap un espacio reservado
 *
 * \param
 * \param
 * \return
 *
 */
void employee_delete(Employee* pEmployee)
{
	if(pEmployee!=NULL)
	{
		free(pEmployee);
	}
}
/** \brief Setter de Id
 *
 * \param
 * \param
 * \return
 *
 */
int employee_setId(Employee* this,int id)
{
	int success = -1;

	if(this!=NULL && isValidId(id))
	{
		this->id = id;
		success = 0;
	}
	return success;
}
int employee_getId(Employee* this,int* id)
{
	int success = -1;

	if(this!=NULL && (id!=NULL))
	{
		*id = this->id;
		success = 0;
	}
	return success;
}
/** \brief Setter de Nombre
 *
 * \param
 * \param
 * \return
 *
 */
int employee_setNombre(Employee* this,char* _nombre)
{
	int success = -1;

	if(this!=NULL && _nombre!= NULL && isValidName(_nombre) && strlen(_nombre)>0)
	{
		stringToProperName(_nombre);
		strcpy(this->nombre, _nombre);
		success = 0;
	}
	return success;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int success = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		success = 0;
	}
	return success;
}
/** \brief Setter de Horas trrabajadas
 *
 * \param
 * \param
 * \return
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int success = -1;

	if(this!=NULL && isValidHorasTrabajadas(horasTrabajadas))
	{
		this->horasTrabajadas = horasTrabajadas;
		success = 0;
	}
	return success;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int success;
	success = -1;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		success = 0;
	}
	return success;
}
/** \brief Setter de Sueldo
 *
 * \param
 * \param
 * \return
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int success;
	success = -1;

	if(this!=NULL && isValidSueldo(sueldo))
	{
		this->sueldo = sueldo;
		success = 0;
	}
	return success;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int success;
	success = -1;

	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo = this->sueldo;
		success = 0;
	}
	return success;
}
//-----------------*******************************-----------------------

/** \brief Setea los parametro, de cadena de caracteres los pasa a los tipos de variables correspondientes para cada campo
 *
 * \param
 * \param
 * \return
 *
 */
int employee_setParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo)
{
	int success = -1;
	if(id!=NULL && nombre!=NULL && horasTrabajadas!=NULL && sueldo!= NULL)
	{
		if(isStringANumber(id) && (!isStringNegativeNumber(id)) &&
			!(employee_inputNombre(nombre)) &&
			!(employee_inputHorasTrabajadas(horasTrabajadas)) &&
			!(employee_inputSueldo(sueldo)))
		{
			success = 0;
		}
	}
	return success;
}
/** \brief Input para el ingreso de atributos empleado
 *
 * \param
 * \param
 * \return
 *
 */
int employee_inputNombre(char* nombre)
{
	int success = -1;
	if(nombre!=NULL)
	{
		input_Text(nombre, SIZENOMBRE, "Ingrese nombre: ");
		while(!isStringAlpha(nombre))
		{
			input_Text(nombre, SIZENOMBRE, "Error, ingrese Nombre: ");
		}
		stringToProperName(nombre);
		success = 0;
	}
	return success;
}
/** \brief Input para el ingreso de atributos empleado
 *
 * \param
 * \param
 * \return
 *
 */
int employee_inputHorasTrabajadas(char *horasTrabajadas)
{
	int success = -1;
	if(horasTrabajadas!= NULL)
	{
		input_Text(horasTrabajadas, 10, "Ingrese las horas trabajadas: ");//consultar
		while(!(isStringANumber(horasTrabajadas)) && isStringNegativeNumber(horasTrabajadas)) //validacion, consultar
		{
			input_Text(horasTrabajadas, 10, "Error, valor invalido. Ingrese las horas trabajadas: ");
		}
		success = 0;
	}
	return success;
}
/** \brief Input para el ingreso de atributos empleado
 *
 * \param
 * \param
 * \return
 *
 */
int employee_inputSueldo(char *sueldo)
{
	int success = -1;
	if(sueldo!=NULL)
	{
		input_Text(sueldo, 10, "Ingrese sueldo: ");
		while(!(isStringANumber(sueldo)) && isStringNegativeNumber(sueldo))
		{
			input_Text(sueldo, 20, "Error, valor invalido. Ingrese sueldo: ");
		}
		success = 0;
	}
	return success;
}

//---------------------
int employee_compareByID(void* pAuxiliary1, void* pAuxiliary2)
{
	int compare = 0;
	Employee* pAux1;
	Employee* pAux2;
	pAux1 = (Employee*)pAuxiliary1;
	pAux2 = (Employee*)pAuxiliary2;
	int pAux1Id;
	int pAux2Id;
	employee_getId(pAux1, &pAux1Id);
	employee_getId(pAux2, &pAux2Id);

	if(pAux1!=NULL && pAux2!=NULL)
	{
		if(pAux1Id > pAux2Id)
		{
			compare = 1;
		}
		else
		{
			if(pAux1Id < pAux2Id)
			{
				compare = -1;
			}
		}
	}
	return compare;
}
/** \brief Criterio de ordenamiento
 *
 * \param
 * \param
 * \return
 *
 */
int employee_compareByName(void* pAuxiliary1, void* pAuxiliary2)
{
	int compare = 0;
	Employee* pAux1;
	Employee* pAux2;
	pAux1 = (Employee*)pAuxiliary1;
	pAux2 = (Employee*)pAuxiliary2;

	char pAux1Name[SIZENOMBRE];
	char pAux2Name[SIZENOMBRE];
	employee_getNombre(pAux1, pAux1Name);
	employee_getNombre(pAux2, pAux2Name);

	if(pAux1!=NULL && pAux2!=NULL)
	{
		compare = strcmp(pAux1Name,pAux2Name);
	}
	return compare;
}
/** \brief Criterio de ordenamiento
 *
 * \param
 * \param
 * \return
 *
 */
int employee_compareByHorasTrabajadas(void* pAuxiliary1, void* pAuxiliary2)
{
	int compare = 0;
	Employee* pAux1;
	Employee* pAux2;
	pAux1 = (Employee*)pAuxiliary1;
	pAux2 = (Employee*)pAuxiliary2;
	int pAux1Horas;
	int pAux2Horas;
	employee_getHorasTrabajadas(pAux1, &pAux1Horas);
	employee_getHorasTrabajadas(pAux2, &pAux2Horas);

	if(pAux1!=NULL && pAux2!=NULL)
	{
		if(pAux1Horas > pAux2Horas)
		{
			compare = 1;
		}
		else
		{
			if(pAux1Horas < pAux2Horas)
			{
				compare = -1;
			}
		}
	}
	return compare;
}
/** \brief Criterio de ordenamiento
 *
 * \param
 * \param
 * \return
 *
 */
int employee_compareBySueldo(void* pAuxiliary1, void* pAuxiliary2)
{
	int compare = 0;
	Employee* pAux1;
	Employee* pAux2;
	pAux1 = (Employee*)pAuxiliary1;
	pAux2 = (Employee*)pAuxiliary2;
	int pAux1Sueldo;
	int pAux2Sueldo;
	employee_getSueldo(pAux1, &pAux1Sueldo);
	employee_getSueldo(pAux2, &pAux2Sueldo);

	if(pAux1!=NULL && pAux2!=NULL)
	{
		if(pAux1Sueldo > pAux2Sueldo)
		{
			compare = 1;
		}
		else
		{
			if(pAux1Sueldo < pAux2Sueldo)
			{
				compare = -1;
			}
		}
	}
	return compare;
}
/** \brief Imprime un empleado
 *
 * \param
 * \param
 * \return
 *
 */
int employee_showEmployee(Employee* pEmployee)
{
	int success = -1;
	int id;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;

	if(pEmployee!=NULL)
	{
		employee_getId(pEmployee, &id);
		employee_getNombre(pEmployee, nombre);
		employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
		employee_getSueldo(pEmployee, &sueldo);
		printf("||%5d||%15s||%5d||%8d||\n", id, nombre, horasTrabajadas, sueldo);
		success = 0;
	}

	return success;
}
static int isValidId(int id)
{
	int answer = 0;
	if(id > 0)
	{
		answer = 1;
	}
	return answer;
}

static int isValidName(char* nombre)
{
	int answer = 0;
	if(isStringAlpha(nombre) && strlen(nombre)<SIZENOMBRE)
	{
		answer = 1;
    }
	return answer;
}
static int isValidHorasTrabajadas(int horasTrabajadas)
{
	int answer = 0;
	if(horasTrabajadas > -1)
	{
		answer = 1;
	}
	return answer;
}
static int isValidSueldo(int sueldo)
{
	int answer = 0;
	if(sueldo > -1)
	{
		answer = 1;
	}
	return answer;
}

