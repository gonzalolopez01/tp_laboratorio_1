#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"
#include "inputs.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();//h
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);//h
void employee_delete(Employee* pEmployee);

int employee_setId(Employee* this,int id);//h
int employee_getId(Employee* this,int* id);//h

int employee_setNombre(Employee* this,char* nombre);//h
int employee_getNombre(Employee* this,char* nombre);//h

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);//h
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);//h

int employee_setSueldo(Employee* this,int sueldo);//h
int employee_getSueldo(Employee* this,int* sueldo);//h

////----------agregadas
int employee_setParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo);
int employee_showEmployee(Employee* pEmployee);

int employee_inputNombre(char* nombre);
int employee_inputHorasTrabajadas(char *horasTrabajadas);
int employee_inputSueldo(char *sueldo);
int employee_compareByID(void* pAuxiliary1, void* pAuxiliary2);
int employee_compareByName(void* pAuxiliary1, void* pAuxiliary2);
int employee_compareByHorasTrabajadas(void* pAuxiliary1, void* pAuxiliary2);
int employee_compareBySueldo(void* pAuxiliary1, void* pAuxiliary2);



#endif // employee_H_INCLUDED
